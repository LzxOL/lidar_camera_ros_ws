#!/bin/bash

# Continuously subscribe to LiDAR and both camera topics and validate the
# shared-memory timestamp propagation used by the hardware-triggered cameras.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

safe_source() {
    local setup_file="$1"
    if [[ ! -f "$setup_file" ]]; then
        return 0
    fi

    set +e +u
    # shellcheck disable=SC1090
    source "$setup_file" >/dev/null 2>&1
    local rc=$?
    set -euo pipefail
    return "$rc"
}

if ! command -v ros2 >/dev/null 2>&1; then
    safe_source /opt/ros/humble/setup.bash || true
    safe_source "$SCRIPT_DIR/install/setup.bash" || true
fi

if ! command -v ros2 >/dev/null 2>&1; then
    echo "[ERROR] 未找到 ros2 命令，请先 source ROS 环境。"
    exit 1
fi

LIDAR_TOPIC="/rslidar_points"
LEFT_TOPIC="/vimbax_camera_left/image_raw"
RIGHT_TOPIC="/vimbax_camera_right/image_raw"
SHM_PATH="/dev/shm/rslidar_gps_timestamp"
TIMEOUT_SEC=15
SAMPLES=30
MIN_MATCH_RATIO=0.90

while [[ $# -gt 0 ]]; do
    case $1 in
        --lidar-topic)
            LIDAR_TOPIC="$2"
            shift 2
            ;;
        --camera-topic|--left-topic)
            LEFT_TOPIC="$2"
            shift 2
            ;;
        --right-topic)
            RIGHT_TOPIC="$2"
            shift 2
            ;;
        --shared-memory)
            SHM_PATH="$2"
            shift 2
            ;;
        --timeout)
            TIMEOUT_SEC="$2"
            shift 2
            ;;
        --samples)
            SAMPLES="$2"
            shift 2
            ;;
        --min-match-ratio)
            MIN_MATCH_RATIO="$2"
            shift 2
            ;;
        --help|-h)
            echo "用法: $0 [选项]"
            echo "  --lidar-topic T       雷达话题，默认 /rslidar_points"
            echo "  --left-topic T        左相机话题，默认 /vimbax_camera_left/image_raw"
            echo "  --right-topic T       右相机话题，默认 /vimbax_camera_right/image_raw"
            echo "  --shared-memory P     共享内存路径"
            echo "  --timeout N           总采集超时秒数，默认 15"
            echo "  --samples N           每个话题目标样本数，默认 30"
            echo "  --min-match-ratio R   最低精确匹配率，默认 0.90"
            exit 0
            ;;
        *)
            echo "未知参数: $1"
            exit 1
            ;;
    esac
done

echo "============================================"
echo "LiDAR + 双相机时间戳同步检查"
echo "============================================"
echo "雷达话题:   $LIDAR_TOPIC"
echo "左相机话题: $LEFT_TOPIC"
echo "右相机话题: $RIGHT_TOPIC"
echo "共享内存:   $SHM_PATH"
echo "目标样本数: $SAMPLES"
echo "总超时:     ${TIMEOUT_SEC}s"
echo "============================================"

python3 - "$LIDAR_TOPIC" "$LEFT_TOPIC" "$RIGHT_TOPIC" "$SHM_PATH" \
    "$TIMEOUT_SEC" "$SAMPLES" "$MIN_MATCH_RATIO" <<'PY'
import math
import statistics
import struct
import sys
import time
from collections import Counter

import rclpy
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Image, PointCloud2


lidar_topic = sys.argv[1]
left_topic = sys.argv[2]
right_topic = sys.argv[3]
shm_path = sys.argv[4]
timeout_sec = float(sys.argv[5])
target_samples = int(sys.argv[6])
min_match_ratio = float(sys.argv[7])

if timeout_sec <= 0 or target_samples <= 0:
    raise SystemExit("[ERROR] --timeout 和 --samples 必须大于 0")
if not 0.0 < min_match_ratio <= 1.0:
    raise SystemExit("[ERROR] --min-match-ratio 必须在 (0, 1] 范围内")


def stamp_ns(msg):
    return msg.header.stamp.sec * 1_000_000_000 + msg.header.stamp.nanosec


def read_shm_snapshot(path):
    header_fmt = "<IIIIQ"
    entry_fmt = "<Qq"
    header_size = struct.calcsize(header_fmt)
    entry_size = struct.calcsize(entry_fmt)

    try:
        with open(path, "rb") as stream:
            data = stream.read()
    except OSError:
        return None

    if len(data) < header_size:
        return None

    magic, version, capacity, _reserved, committed = struct.unpack_from(header_fmt, data, 0)
    if magic != 0x52534754 or version != 2 or capacity <= 0:
        return None
    if len(data) < header_size + capacity * entry_size:
        return None

    oldest = max(1, committed - capacity + 1)
    entries = []
    for sequence in range(oldest, committed + 1):
        offset = header_size + ((sequence - 1) % capacity) * entry_size
        observed_sequence, timestamp = struct.unpack_from(entry_fmt, data, offset)
        if observed_sequence == sequence and timestamp > 0:
            entries.append((sequence, timestamp))

    return {
        "version": version,
        "capacity": capacity,
        "committed": committed,
        "entries": entries,
    }


class SyncCollector(Node):
    def __init__(self):
        super().__init__("lidar_camera_sync_checker")
        self.samples = {"lidar": [], "left": [], "right": []}
        qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=20,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
        )
        self.create_subscription(PointCloud2, lidar_topic, self._callback("lidar"), qos)
        self.create_subscription(Image, left_topic, self._callback("left"), qos)
        self.create_subscription(Image, right_topic, self._callback("right"), qos)

    def _callback(self, name):
        def receive(msg):
            if len(self.samples[name]) >= target_samples:
                return
            self.samples[name].append(
                {
                    "stamp": stamp_ns(msg),
                    "frame_id": msg.header.frame_id,
                    "arrival": time.monotonic_ns(),
                }
            )
        return receive

    def complete(self):
        return all(len(values) >= target_samples for values in self.samples.values())


def interval_summary(values):
    intervals = [(b - a) / 1e6 for a, b in zip(values, values[1:]) if b > a]
    if not intervals:
        return "无有效帧间隔"
    median = statistics.median(intervals)
    fps = 1000.0 / median if median > 0 else math.inf
    return (
        f"median={median:.3f} ms, mean={statistics.mean(intervals):.3f} ms, "
        f"约 {fps:.2f} Hz"
    )


def monotonic_errors(values):
    return sum(current <= previous for previous, current in zip(values, values[1:]))


def nearest_deltas_ms(reference, targets):
    if not reference:
        return []
    ordered = sorted(reference)
    result = []
    for target in targets:
        nearest = min(ordered, key=lambda value: abs(value - target))
        result.append((target - nearest) / 1e6)
    return result


def print_delta_stats(label, values):
    if not values:
        print(f"  {label}: 无有效样本")
        return
    print(
        f"  {label}: median={statistics.median(values):+.3f} ms, "
        f"mean={statistics.mean(values):+.3f} ms, "
        f"min={min(values):+.3f} ms, max={max(values):+.3f} ms"
    )


shm_before = read_shm_snapshot(shm_path)
try:
    rclpy.init(args=[])
    collector = SyncCollector()
except Exception as exc:
    if rclpy.ok():
        rclpy.shutdown()
    raise SystemExit(f"[ERROR] 无法创建 ROS 2 检查节点: {exc}")
deadline = time.monotonic() + timeout_sec

try:
    while not collector.complete() and time.monotonic() < deadline:
        rclpy.spin_once(collector, timeout_sec=0.1)
except KeyboardInterrupt:
    pass
finally:
    samples = collector.samples
    collector.destroy_node()
    rclpy.shutdown()

shm_after = read_shm_snapshot(shm_path)
stamps = {
    name: [sample["stamp"] for sample in values]
    for name, values in samples.items()
}

print("\n[1/4] 采集结果")
for name, label in (("lidar", "雷达"), ("left", "左相机"), ("right", "右相机")):
    print(f"  {label}: {len(stamps[name])}/{target_samples} 帧")

failures = []
for name, label in (("lidar", "雷达"), ("left", "左相机"), ("right", "右相机")):
    if len(stamps[name]) < target_samples:
        failures.append(f"{label}在超时前只收到 {len(stamps[name])} 帧")

print("\n[2/4] 单调性、重复值和帧率")
for name, label in (("lidar", "雷达"), ("left", "左相机"), ("right", "右相机")):
    values = stamps[name]
    duplicate_count = len(values) - len(set(values))
    ordering_errors = monotonic_errors(values)
    print(
        f"  {label}: {interval_summary(values)}, "
        f"重复时间戳={duplicate_count}, 非递增={ordering_errors}"
    )
    if duplicate_count:
        failures.append(f"{label}出现 {duplicate_count} 个重复时间戳")
    if ordering_errors:
        failures.append(f"{label}出现 {ordering_errors} 次时间戳非递增")

print("\n[3/4] 共享内存队列")
if shm_after is None:
    print("  [FAIL] 共享内存不存在或格式无效")
    failures.append("共享内存不存在或格式无效")
    shm_stamps = []
else:
    before_sequence = shm_before["committed"] if shm_before else 0
    after_sequence = shm_after["committed"]
    advanced = after_sequence - before_sequence if after_sequence >= before_sequence else after_sequence
    shm_stamps = [timestamp for _sequence, timestamp in shm_after["entries"]]
    print(
        f"  version={shm_after['version']}, capacity={shm_after['capacity']}, "
        f"committed={after_sequence}, 本次推进={advanced}"
    )
    if advanced <= 0:
        failures.append("采集期间共享内存序号没有推进")

print("\n[4/4] 精确匹配")
reference_stamps = set(stamps["lidar"]) | set(shm_stamps)
camera_reference_ratios = {}
for name, label in (("left", "左相机 -> LiDAR/共享内存"), ("right", "右相机 -> LiDAR/共享内存")):
    values = stamps[name]
    matched = sum(value in reference_stamps for value in values)
    ratio = matched / len(values) if values else 0.0
    camera_reference_ratios[name] = ratio
    print(f"  {label}: {matched}/{len(values)} ({ratio:.1%})")
    if ratio < min_match_ratio:
        failures.append(f"{label}精确匹配率 {ratio:.1%} 低于 {min_match_ratio:.1%}")

left_counter = Counter(stamps["left"])
right_counter = Counter(stamps["right"])
camera_pairs = sum((left_counter & right_counter).values())
camera_denominator = min(len(stamps["left"]), len(stamps["right"]))
camera_pair_ratio = camera_pairs / camera_denominator if camera_denominator else 0.0
print(
    f"  左右相机相同时间戳: {camera_pairs}/{camera_denominator} "
    f"({camera_pair_ratio:.1%})"
)
if camera_pair_ratio < min_match_ratio:
    failures.append(f"左右相机精确匹配率 {camera_pair_ratio:.1%} 低于 {min_match_ratio:.1%}")

print("\n补充：相机与已采集 LiDAR 话题的最近邻差值")
print_delta_stats("左相机 - LiDAR", nearest_deltas_ms(stamps["lidar"], stamps["left"]))
print_delta_stats("右相机 - LiDAR", nearest_deltas_ms(stamps["lidar"], stamps["right"]))

all_values = stamps["lidar"] + stamps["left"] + stamps["right"]
if all_values and max(all_values) < 1_000_000 * 1_000_000_000:
    failures.append("时间戳不像 GPS/Unix 绝对时间")

print("\n============================================")
if failures:
    print("[FAIL] 时间戳传播链路未通过：")
    for failure in failures:
        print(f"  - {failure}")
    result = 2
else:
    print("[PASS] LiDAR -> 共享内存 -> 双相机时间戳传播一致。")
    print("[NOTE] 该结果能验证软件时间戳链路和帧级一一对应；")
    print("       物理触发沿的电气延迟仍需示波器或相机触发计数器独立验证。")
    result = 0
print("============================================")
raise SystemExit(result)
PY

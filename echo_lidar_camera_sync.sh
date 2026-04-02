#!/bin/bash

# 连续抓取多轮雷达和相机消息头，做一个轻量但更可靠的时间戳同步检查。
#
# 用法:
#   ./echo_lidar_camera_sync.sh
#   ./echo_lidar_camera_sync.sh --samples 10
#   ./echo_lidar_camera_sync.sh --lidar-topic /rslidar_points --left-topic /vimbax_camera_left/image_raw --right-topic /vimbax_camera_right/image_raw

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
    echo "可尝试执行:"
    echo "  source /opt/ros/humble/setup.bash"
    echo "  source <your_ws>/install/setup.bash"
    exit 1
fi

LIDAR_TOPIC="/rslidar_points"
LEFT_TOPIC="/vimbax_camera_left/image_raw"
RIGHT_TOPIC="/vimbax_camera_right/image_raw"
TIMEOUT_SEC=8
SAMPLES=8

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
        --timeout)
            TIMEOUT_SEC="$2"
            shift 2
            ;;
        --samples)
            SAMPLES="$2"
            shift 2
            ;;
        --help|-h)
            echo "用法: $0 [选项]"
            echo "  --lidar-topic T   雷达话题，默认 /rslidar_points"
            echo "  --camera-topic T  左/单相机图像话题，默认 /vimbax_camera_left/image_raw"
            echo "  --left-topic T    同 --camera-topic"
            echo "  --right-topic T   右相机图像话题，默认 /vimbax_camera_right/image_raw"
            echo "  --timeout N       每轮单次抓取超时秒数，默认 8"
            echo "  --samples N       连续抓取轮数，默认 8"
            exit 0
            ;;
        *)
            echo "未知参数: $1"
            exit 1
            ;;
    esac
done

echo "============================================"
echo "时间戳同步检查"
echo "============================================"
echo "雷达话题:   $LIDAR_TOPIC"
echo "左相机话题: $LEFT_TOPIC"
echo "右相机话题: $RIGHT_TOPIC"
echo "采样轮数:   $SAMPLES"
echo "单轮超时:   ${TIMEOUT_SEC}s"
echo "============================================"

python3 - "$LIDAR_TOPIC" "$LEFT_TOPIC" "$RIGHT_TOPIC" "$TIMEOUT_SEC" "$SAMPLES" <<'PY'
import statistics
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

lidar_topic = sys.argv[1]
left_topic = sys.argv[2]
right_topic = sys.argv[3]
timeout_sec = float(sys.argv[4])
samples = int(sys.argv[5])


def capture_once(topic: str, timeout: float):
    cmd = ["ros2", "topic", "echo", topic, "--no-daemon", "--once"]
    try:
        proc = subprocess.run(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            timeout=timeout,
            check=False,
        )
    except subprocess.TimeoutExpired:
        return {"ok": False, "topic": topic, "reason": "timeout"}

    if proc.returncode != 0 or not proc.stdout.strip():
        return {"ok": False, "topic": topic, "reason": proc.stderr.strip() or f"returncode={proc.returncode}"}

    try:
        parsed = parse_stamp(proc.stdout)
        parsed["ok"] = True
        parsed["topic"] = topic
        return parsed
    except Exception as exc:
        return {"ok": False, "topic": topic, "reason": str(exc)}


def parse_stamp(text: str):
    sec = None
    nanosec = None
    frame_id = ""
    for raw_line in text.splitlines():
        line = raw_line.strip()
        if line.startswith("sec:"):
            sec = int(line.split(":", 1)[1].strip())
        elif line.startswith("nanosec:"):
            nanosec = int(line.split(":", 1)[1].strip())
        elif line.startswith("frame_id:"):
            frame_id = line.split(":", 1)[1].strip()
        if sec is not None and nanosec is not None and frame_id:
            break

    if sec is None or nanosec is None:
        raise RuntimeError("无法解析 header.stamp")

    stamp_ns = sec * 1_000_000_000 + nanosec
    return {
        "sec": sec,
        "nanosec": nanosec,
        "stamp_ns": stamp_ns,
        "frame_id": frame_id,
    }


def fmt_stamp(item):
    return f"{item['sec']}.{item['nanosec']:09d}"


def nearest_delta_ms(ref_ns_list, target_ns):
    nearest = min(ref_ns_list, key=lambda v: abs(v - target_ns))
    return (target_ns - nearest) / 1e6


def print_stats(label, values):
    if not values:
        print(f"{label}: 无有效样本")
        return
    values_sorted = sorted(values)
    avg = statistics.mean(values)
    med = statistics.median(values)
    minimum = values_sorted[0]
    maximum = values_sorted[-1]
    std = statistics.pstdev(values) if len(values) > 1 else 0.0
    print(f"{label}:")
    print(f"  count = {len(values)}")
    print(f"  mean  = {avg:+.3f} ms")
    print(f"  median= {med:+.3f} ms")
    print(f"  std   = {std:.3f} ms")
    print(f"  min   = {minimum:+.3f} ms")
    print(f"  max   = {maximum:+.3f} ms")


lidar_samples = []
left_samples = []
right_samples = []
round_camera_deltas = []

print("[1/2] 连续并发抓取消息头...")
for idx in range(samples):
    with ThreadPoolExecutor(max_workers=3) as pool:
        futures = {
            "lidar": pool.submit(capture_once, lidar_topic, timeout_sec),
            "left": pool.submit(capture_once, left_topic, timeout_sec),
            "right": pool.submit(capture_once, right_topic, timeout_sec),
        }

    lidar = futures["lidar"].result()
    left = futures["left"].result()
    right = futures["right"].result()

    print(f"  round {idx + 1:02d}: ", end="")
    statuses = []
    if lidar["ok"]:
        lidar_samples.append(lidar)
        statuses.append(f"lidar={fmt_stamp(lidar)}")
    else:
        statuses.append(f"lidar=ERR({lidar['reason']})")

    if left["ok"]:
        left_samples.append(left)
        statuses.append(f"left={fmt_stamp(left)}")
    else:
        statuses.append(f"left=ERR")

    if right["ok"]:
        right_samples.append(right)
        statuses.append(f"right={fmt_stamp(right)}")
    else:
        statuses.append(f"right=ERR")

    if left["ok"] and right["ok"]:
        round_camera_deltas.append((right["stamp_ns"] - left["stamp_ns"]) / 1e6)

    print(", ".join(statuses))

if not lidar_samples:
    print("[ERROR] 所有轮次都没有抓到雷达消息，无法验证。")
    sys.exit(1)

if not left_samples and not right_samples:
    print("[ERROR] 所有轮次都没有抓到相机消息，无法验证。")
    sys.exit(1)

print("[2/2] 统计时间戳差值...")
print("============================================")

latest_lidar = lidar_samples[-1]
print("最新样本:")
print(f"  雷达:   {fmt_stamp(latest_lidar)}  frame_id={latest_lidar['frame_id']}")
if left_samples:
    latest_left = left_samples[-1]
    print(f"  左相机: {fmt_stamp(latest_left)}  frame_id={latest_left['frame_id']}")
if right_samples:
    latest_right = right_samples[-1]
    print(f"  右相机: {fmt_stamp(latest_right)}  frame_id={latest_right['frame_id']}")

lidar_ns = [x["stamp_ns"] for x in lidar_samples]
left_to_lidar = [nearest_delta_ms(lidar_ns, x["stamp_ns"]) for x in left_samples]
right_to_lidar = [nearest_delta_ms(lidar_ns, x["stamp_ns"]) for x in right_samples]

print("============================================")
print_stats("左相机 - 最近雷达", left_to_lidar)
print_stats("右相机 - 最近雷达", right_to_lidar)
print_stats("右相机 - 左相机（同轮）", round_camera_deltas)

all_secs = [x["sec"] for x in lidar_samples + left_samples + right_samples]
if all_secs:
    min_sec = min(all_secs)
    max_sec = max(all_secs)
    print("============================================")
    print("时间量级检查:")
    print(f"  sec 范围 = [{min_sec}, {max_sec}]")
    if max_sec < 1_000_000:
        print("  [WARN] 时间戳秒数很小，像是设备本地运行时间，不像 GPS/Unix 绝对时间。")
    else:
        print("  [OK] 时间戳秒数像是真实绝对时间。")

print("============================================")
print("说明:")
print("  这份脚本比单次抓取更可靠，但仍属于轻量级验证。")
print("  如果左右相机偏差稳定接近 0，且相机与雷达偏差分布稳定，通常说明同步链路基本工作正常。")
print("============================================")
PY

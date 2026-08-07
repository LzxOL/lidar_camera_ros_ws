#!/bin/bash

# Entry point for LiDAR/camera timestamp validation. Normal validation delegates
# to echo_lidar_camera_sync.sh so both commands use the same pairing rules.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DURATION=15
SAMPLES=30
CAMERA_ONLY=false
VIEW_SHM=false
LIDAR_TOPIC="/rslidar_points"
LEFT_CAM_TOPIC="/vimbax_camera_left/image_raw"
RIGHT_CAM_TOPIC="/vimbax_camera_right/image_raw"
SHM_PATH="/dev/shm/rslidar_gps_timestamp"

while [[ $# -gt 0 ]]; do
    case $1 in
        --duration)
            DURATION="$2"
            shift 2
            ;;
        --samples)
            SAMPLES="$2"
            shift 2
            ;;
        --camera-only)
            CAMERA_ONLY=true
            shift
            ;;
        --shared-mem)
            VIEW_SHM=true
            shift
            ;;
        --lidar-topic)
            LIDAR_TOPIC="$2"
            shift 2
            ;;
        --camera-topic|--left-topic)
            LEFT_CAM_TOPIC="$2"
            shift 2
            ;;
        --right-topic)
            RIGHT_CAM_TOPIC="$2"
            shift 2
            ;;
        --help|-h)
            echo "用法: $0 [选项]"
            echo "  --duration N      总采集超时秒数，默认 15"
            echo "  --samples N       每个话题目标样本数，默认 30"
            echo "  --camera-only     只检查左右相机时间戳"
            echo "  --shared-mem      只查看共享内存队列"
            echo "  --lidar-topic T   雷达点云话题"
            echo "  --left-topic T    左相机图像话题"
            echo "  --right-topic T   右相机图像话题"
            exit 0
            ;;
        *)
            echo "未知参数: $1"
            exit 1
            ;;
    esac
done

if [[ "$VIEW_SHM" == true ]]; then
    python3 - "$SHM_PATH" <<'PY'
import struct
import sys
from datetime import datetime, timezone

path = sys.argv[1]
header_fmt = "<IIIIQ"
entry_fmt = "<Qq"
header_size = struct.calcsize(header_fmt)
entry_size = struct.calcsize(entry_fmt)

try:
    with open(path, "rb") as stream:
        data = stream.read()
except OSError as exc:
    raise SystemExit(f"[ERROR] 无法读取 {path}: {exc}")

if len(data) < header_size:
    raise SystemExit("[ERROR] 共享内存头不完整")

magic, version, capacity, _reserved, committed = struct.unpack_from(header_fmt, data, 0)
print(f"路径:         {path}")
print(f"magic:        0x{magic:08X}")
print(f"version:      {version}")
print(f"capacity:     {capacity}")
print(f"committed:    {committed}")

if magic != 0x52534754 or version != 2 or capacity <= 0:
    raise SystemExit("[ERROR] 共享内存格式无效")
if len(data) < header_size + capacity * entry_size:
    raise SystemExit("[ERROR] 共享内存队列不完整")

oldest = max(1, committed - capacity + 1)
entries = []
for sequence in range(oldest, committed + 1):
    offset = header_size + ((sequence - 1) % capacity) * entry_size
    observed_sequence, timestamp_ns = struct.unpack_from(entry_fmt, data, offset)
    if observed_sequence == sequence and timestamp_ns > 0:
        entries.append((sequence, timestamp_ns))

print(f"有效条目:     {len(entries)}")
if entries:
    sequence, timestamp_ns = entries[-1]
    timestamp_sec = timestamp_ns / 1e9
    utc = datetime.fromtimestamp(timestamp_sec, tz=timezone.utc)
    print(f"最新序号:     {sequence}")
    print(f"最新时间戳:   {timestamp_ns} ns")
    print(f"最新 UTC:     {utc.isoformat(timespec='microseconds')}")
    if len(entries) > 1:
        intervals = [
            (current[1] - previous[1]) / 1e6
            for previous, current in zip(entries, entries[1:])
            if current[1] > previous[1]
        ]
        if intervals:
            print(f"平均更新间隔: {sum(intervals) / len(intervals):.3f} ms")
PY
    exit 0
fi

if [[ -z "${ROS_DISTRO:-}" ]]; then
    # shellcheck disable=SC1091
    source /opt/ros/humble/setup.bash
    # shellcheck disable=SC1091
    source "$SCRIPT_DIR/install/setup.bash"
fi

if [[ "$CAMERA_ONLY" == true ]]; then
    exec python3 "$SCRIPT_DIR/camera_time_sync_check.py" \
        --left-topic "$LEFT_CAM_TOPIC" \
        --right-topic "$RIGHT_CAM_TOPIC" \
        --max-msgs "$SAMPLES" \
        --timeout "$DURATION"
fi

exec "$SCRIPT_DIR/echo_lidar_camera_sync.sh" \
    --lidar-topic "$LIDAR_TOPIC" \
    --left-topic "$LEFT_CAM_TOPIC" \
    --right-topic "$RIGHT_CAM_TOPIC" \
    --timeout "$DURATION" \
    --samples "$SAMPLES"

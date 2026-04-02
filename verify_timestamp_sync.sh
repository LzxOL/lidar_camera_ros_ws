#!/bin/bash

# ============================================================================
# 雷达 + 相机时间戳同步验证脚本
#
# 功能：
#   1. 显示实时雷达时间戳（GPS 绝对时间）
#   2. 显示实时相机时间戳（GPS 同步后 / 本地）
#   3. 计算并显示两者的时间差（ms）
#   4. 连续统计，输出平均值/最大值/最小值
#
# 用法:
#   ./verify_timestamp_sync.sh              # 默认验证（10 秒）
#   ./verify_timestamp_sync.sh --duration 30 # 指定验证时长（秒）
#   ./verify_timestamp_sync.sh --camera-only # 仅验证相机（不要求雷达）
#   ./verify_timestamp_sync.sh --shared-mem  # 直接查看 /dev/shm 内容
# ============================================================================

set -e

# 参数解析
DURATION=10
CAMERA_ONLY=false
VIEW_SHM=false
LIDAR_TOPIC="/rslidar_points"
LEFT_CAM_TOPIC="/vimbax_camera_left/image_raw"
RIGHT_CAM_TOPIC="/vimbax_camera_right/image_raw"

while [[ $# -gt 0 ]]; do
    case $1 in
        --duration)
            DURATION="$2"
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
        --camera-topic)
            LEFT_CAM_TOPIC="$2"
            shift 2
            ;;
        --help|-h)
            echo "用法: $0 [选项]"
            echo "  --duration N      验证时长（秒，默认 10）"
            echo "  --camera-only     仅验证相机（不要求雷达在线）"
            echo "  --shared-mem      直接查看共享内存内容"
            echo "  --lidar-topic T   雷达点云话题（默认 /rslidar_points）"
            echo "  --camera-topic T  左相机图像话题（默认 /vimbax_camera_left/image_raw）"
            echo "  --help, -h        显示此帮助"
            exit 0
            ;;
        *)
            echo "未知参数: $1"
            exit 1
            ;;
    esac
done

# Source ROS 环境
source /opt/ros/humble/setup.bash 2>/dev/null
source /home/root1/lzx_ws/project/lidar_camera_ros_ws/install/setup.bash 2>/dev/null

SHM_PATH="/dev/shm/rslidar_gps_timestamp"

read_shm_latest_timestamp_ns() {
    if ! command -v python3 &>/dev/null || [ ! -f "$SHM_PATH" ]; then
        return 0
    fi

    python3 - "$SHM_PATH" <<'PYEOF'
import struct
import sys

path = sys.argv[1]
magic_expected = 0x52534754
header_fmt = "<IIIIQ"
entry_fmt = "<Qq"
header_size = struct.calcsize(header_fmt)
entry_size = struct.calcsize(entry_fmt)

try:
    data = open(path, "rb").read()
    if len(data) < header_size:
        raise ValueError("shared memory too small")

    magic, version, capacity, _reserved, committed = struct.unpack_from(header_fmt, data, 0)
    if magic != magic_expected or version != 2 or capacity <= 0:
        raise ValueError("invalid shared memory header")
    if committed == 0:
        sys.exit(0)

    offset = header_size + ((committed - 1) % capacity) * entry_size
    if len(data) < offset + entry_size:
        raise ValueError("shared memory truncated")

    sequence, timestamp_ns = struct.unpack_from(entry_fmt, data, offset)
    if sequence != committed or timestamp_ns <= 0:
        raise ValueError("latest entry not committed")

    print(timestamp_ns)
except Exception:
    pass
PYEOF
}

show_shm_summary() {
    if ! command -v python3 &>/dev/null || [ ! -f "$SHM_PATH" ]; then
        return 0
    fi

    python3 - "$SHM_PATH" <<'PYEOF'
import struct
import sys
from datetime import datetime, timezone

path = sys.argv[1]
magic_expected = 0x52534754
header_fmt = "<IIIIQ"
entry_fmt = "<Qq"
header_size = struct.calcsize(header_fmt)
entry_size = struct.calcsize(entry_fmt)

try:
    data = open(path, "rb").read()
    if len(data) < header_size:
        raise ValueError("shared memory too small")

    magic, version, capacity, _reserved, committed = struct.unpack_from(header_fmt, data, 0)
    print(f"    magic/version: 0x{magic:08X} / {version}")
    print(f"    队列容量: {capacity}")
    print(f"    已提交条目: {committed}")

    if magic != magic_expected or version != 2 or capacity <= 0 or committed == 0:
        sys.exit(0)

    offset = header_size + ((committed - 1) % capacity) * entry_size
    if len(data) < offset + entry_size:
        raise ValueError("shared memory truncated")

    sequence, timestamp_ns = struct.unpack_from(entry_fmt, data, offset)
    if sequence != committed or timestamp_ns <= 0:
        sys.exit(0)

    ts_s = timestamp_ns / 1e9
    dt = datetime.fromtimestamp(ts_s, tz=timezone.utc)
    print(f"    最新序号: {sequence}")
    print(f"    最新时间: {timestamp_ns} ns")
    print(f"    UTC时间:  {dt.strftime('%Y-%m-%d %H:%M:%S')}.{int((ts_s % 1) * 1e6):06d}")
except Exception as exc:
    print(f"    [!] 共享内存解析失败: {exc}")
PYEOF
}

# --------------------------------------------------------------------------
# 模式 1: 直接查看共享内存
# --------------------------------------------------------------------------
if [ "$VIEW_SHM" = true ]; then
    echo "============================================"
    echo "查看 $SHM_PATH"
    echo "============================================"
    if [ -f "$SHM_PATH" ]; then
        echo "[*] 文件存在，读取内容..."
        SIZE=$(stat -c%s "$SHM_PATH" 2>/dev/null || stat -f%z "$SHM_PATH" 2>/dev/null)
        echo "    文件大小: $SIZE bytes"
        echo -n "    原始字节: "
        xxd -p "$SHM_PATH" 2>/dev/null | tr -d '\n'
        echo ""
        show_shm_summary
    else
        echo "[!] 文件不存在，雷达可能未启动或未写入共享内存"
    fi
    exit 0
fi

# --------------------------------------------------------------------------
# 模式 2: 时间戳对比
# --------------------------------------------------------------------------
echo "============================================"
echo "雷达 + 相机时间戳同步验证"
echo "============================================"
echo "  验证时长:   ${DURATION} 秒"
echo "  雷达话题:   $LIDAR_TOPIC"
echo "  左相机话题: $LEFT_CAM_TOPIC"
echo "  右相机话题: $RIGHT_CAM_TOPIC"
echo "  共享内存:   $SHM_PATH"
echo "============================================"

# 检查话题是否在线
echo ""
echo "[*] 检查话题在线状态..."
if [ "$CAMERA_ONLY" = false ]; then
    LIDAR_HZ=$(ros2 topic hz "$LIDAR_TOPIC" 2>/dev/null | grep -oP 'average rate: \K[\d.]+' || echo "0")
    LIDAR_HZ_FLT=$(echo "$LIDAR_HZ" | awk '{print ($1 > 0) ? 1 : 0}')
    if [ "$LIDAR_HZ_FLT" -eq 1 ]; then
        echo "    [OK] 雷达话题在线 (rate: ${LIDAR_HZ} Hz)"
    else
        echo "    [!] 雷达话题离线或无数据，跳过雷达验证"
        CAMERA_ONLY=true
    fi
fi

LEFT_HZ=$(ros2 topic hz "$LEFT_CAM_TOPIC" 2>/dev/null | grep -oP 'average rate: \K[\d.]+' || echo "0")
LEFT_HZ_FLT=$(echo "$LEFT_HZ" | awk '{print ($1 > 0) ? 1 : 0}')
if [ "$LEFT_HZ_FLT" -eq 1 ]; then
    echo "    [OK] 左相机话题在线 (rate: ${LEFT_HZ} Hz)"
else
    echo "    [!] 左相机话题离线"
fi

RIGHT_HZ=$(ros2 topic hz "$RIGHT_CAM_TOPIC" 2>/dev/null | grep -oP 'average rate: \K[\d.]+' || echo "0")
RIGHT_HZ_FLT=$(echo "$RIGHT_HZ" | awk '{print ($1 > 0) ? 1 : 0}')
if [ "$RIGHT_HZ_FLT" -eq 1 ]; then
    echo "    [OK] 右相机话题在线 (rate: ${RIGHT_HZ} Hz)"
else
    echo "    [!] 右相机话题离线"
fi

echo ""
echo "[*] 开始验证，持续 ${DURATION} 秒..."
echo ""

# 创建临时文件
TMPDIR=$(mktemp -d)
LIDAR_TS_FILE="$TMPDIR/lidar_ts.txt"
CAM_TS_FILE="$TMPDIR/cam_ts.txt"
SHM_FILE="$TMPDIR/shm_ts.txt"

cleanup() {
    rm -rf "$TMPDIR"
}
trap cleanup EXIT

# 后台任务 1: 采集雷达时间戳
echo "[*] 采集雷达时间戳 -> $LIDAR_TS_FILE"
timeout "${DURATION}s" ros2 topic echo "$LIDAR_TOPIC" --csv --once --interval -1 \
    2>/dev/null | awk -F',' '{print $1}' | grep -v '^$' | head -1000 \
    > "$LIDAR_TS_FILE" &
PID_LIDAR=$!

# 后台任务 2: 采集相机时间戳
echo "[*] 采集左相机时间戳 -> $CAM_TS_FILE"
timeout "${DURATION}s" ros2 topic echo "$LEFT_CAM_TOPIC" --csv --once --interval -1 \
    2>/dev/null | awk -F',' '{print $1}' | grep -v '^$' | head -1000 \
    > "$CAM_TS_FILE" &
PID_CAM=$!

# 后台任务 3: 定期查看共享内存
echo "[*] 采集共享内存时间戳 -> $SHM_FILE"
(
    while true; do
        if [ -f "$SHM_PATH" ]; then
            TS_NS=$(read_shm_latest_timestamp_ns)
            if [ -n "$TS_NS" ]; then
                echo "$TS_NS" >> "$SHM_FILE"
            fi
        fi
        sleep 0.05
    done
) &
PID_SHM=$!

# 等待采集完成
wait $PID_LIDAR 2>/dev/null || true
wait $PID_CAM 2>/dev/null || true
kill $PID_SHM 2>/dev/null || true
wait 2>/dev/null || true

echo ""
echo "============================================"
echo "采集完成，开始分析..."
echo "============================================"

# --------------------------------------------------------------------------
# 分析共享内存
# --------------------------------------------------------------------------
if [ -s "$SHM_FILE" ]; then
    SHM_LINES=$(wc -l < "$SHM_FILE")
    echo ""
    echo "[共享内存 $SHM_PATH]"
    echo "  采样数: $SHM_LINES"
    show_shm_summary
    if command -v python3 &>/dev/null; then
        python3 - "$SHM_FILE" <<'PYEOF'
import sys
from datetime import datetime, timezone
ts_ns = [int(x.strip()) for x in open(sys.argv[1]) if x.strip()]
if ts_ns:
    ts_s = ts_ns[-1] / 1e9
    dt = datetime.fromtimestamp(ts_s, tz=timezone.utc)
    print(f"  最新值: {ts_ns[-1]} ns  ({ts_s:.9f} s)")
    print(f"  UTC时间: {dt.strftime('%Y-%m-%d %H:%M:%S')}.{int((ts_s % 1)*1e6):06d}")
    if len(ts_ns) > 2:
        diffs = [ts_ns[i+1] - ts_ns[i] for i in range(len(ts_ns)-1) if ts_ns[i+1] > ts_ns[i]]
        if diffs:
            avg_ms = sum(diffs)/len(diffs)/1e6
            print(f"  平均更新间隔: {avg_ms:.2f} ms (~{1000/avg_ms:.1f} Hz)")
PYEOF
    fi
else
    echo "  [!] 无数据（雷达可能未写入共享内存）"
fi

# --------------------------------------------------------------------------
# 分析雷达时间戳
# --------------------------------------------------------------------------
echo ""
echo "[雷达 ($LIDAR_TOPIC) 时间戳]"
if [ -s "$LIDAR_TS_FILE" ]; then
    LIDAR_COUNT=$(wc -l < "$LIDAR_TS_FILE")
    echo "  帧数: $LIDAR_COUNT"
    # 提取前 3 个和后 3 个时间戳
    echo -n "  前 3 帧: "
    head -3 "$LIDAR_TS_FILE" | tr '\n' ' '
    echo ""
    echo -n "  后 3 帧: "
    tail -3 "$LIDAR_TS_FILE" | tr '\n' ' '
    echo ""
else
    echo "  [!] 无数据"
fi

# --------------------------------------------------------------------------
# 分析相机时间戳
# --------------------------------------------------------------------------
echo ""
echo "[左相机 ($LEFT_CAM_TOPIC) 时间戳]"
if [ -s "$CAM_TS_FILE" ]; then
    CAM_COUNT=$(wc -l < "$CAM_TS_FILE")
    echo "  帧数: $CAM_COUNT"
    echo -n "  前 3 帧: "
    head -3 "$CAM_TS_FILE" | tr '\n' ' '
    echo ""
    echo -n "  后 3 帧: "
    tail -3 "$CAM_TS_FILE" | tr '\n' ' '
    echo ""
else
    echo "  [!] 无数据"
fi

# --------------------------------------------------------------------------
# 时间戳差值分析（如果两者都有数据）
# --------------------------------------------------------------------------
echo ""
echo "[时间戳差值分析 (相机 - 雷达)]"
if [ -s "$LIDAR_TS_FILE" ] && [ -s "$CAM_TS_FILE" ] && command -v python3 &>/dev/null; then
    python3 - "$LIDAR_TS_FILE" "$CAM_TS_FILE" <<'PYEOF'
import sys
import numpy as np

def parse_ts(line):
    """解析 ROS 时间戳 (sec.nsec -> float seconds)"""
    line = line.strip()
    if '.' in line:
        parts = line.split('.')
        if len(parts) == 2:
            try:
                sec = int(parts[0])
                nsec = int(parts[1].ljust(9, '0')[:9])
                return sec + nsec / 1e9
            except:
                pass
    try:
        return float(line)
    except:
        return None

lidar_ts = [parse_ts(l) for l in open(sys.argv[1]) if l.strip()]
cam_ts   = [parse_ts(c) for c in open(sys.argv[2]) if c.strip()]
lidar_ts = [t for t in lidar_ts if t is not None]
cam_ts   = [t for t in cam_ts   if t is not None]

if lidar_ts and cam_ts:
    # 简单最近邻匹配：对于每个相机帧，找最近的雷达帧
    offsets_ms = []
    for ct in cam_ts:
        nearest = min(lidar_ts, key=lambda lt: abs(lt - ct))
        offset_ms = (ct - nearest) * 1000.0
        offsets_ms.append(offset_ms)
    
    offsets_ms = sorted(offsets_ms)
    n = len(offsets_ms)
    avg = sum(offsets_ms) / n
    std = np.std(offsets_ms)
    p50 = offsets_ms[n // 2]
    p05 = offsets_ms[int(n * 0.05)]
    p95 = offsets_ms[int(n * 0.95)]
    max_off = max(abs(o) for o in offsets_ms)
    
    print(f"  样本数: {n}")
    print(f"  平均偏移: {avg:+.3f} ms")
    print(f"  标准差:   {std:.3f} ms")
    print(f"  中位数:   {p50:+.3f} ms")
    print(f"  P5:       {p05:+.3f} ms")
    print(f"  P95:      {p95:+.3f} ms")
    print(f"  最大偏差: {max_off:.3f} ms")
    
    print("")
    if max_off < 1.0:
        print("  [PASS] 时间戳偏差 < 1ms，同步效果良好")
    elif max_off < 5.0:
        print("  [WARN] 时间戳偏差在 1~5ms 之间，可接受但有优化空间")
    else:
        print("  [FAIL] 时间戳偏差 > 5ms，请检查:")
        print("         1. 雷达和相机是否由同一 PPS 触发？")
        print("         2. 雷达 config.yaml 中 use_lidar_clock 是否为 true？")
        print("         3. 相机 launch 中 use_shared_memory_gps_time 是否为 true？")
else:
    print(f"  [!] 数据不足（雷达 {len(lidar_ts)} 帧, 相机 {len(cam_ts)} 帧）")
PYEOF
else
    echo "  [!] 数据不足或 python3 未安装"
fi

echo ""
echo "============================================"
echo "验证完成"
echo "============================================"

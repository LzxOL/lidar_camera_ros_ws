#!/bin/bash

# ============================================================================
# 雷达 + 相机 GPS 时间戳同步启动脚本
#
# 功能：
#   1. 启动 rslidar_sdk 雷达节点（发点云时写入 GPS 时间戳到 /dev/shm/rslidar_gps_timestamp）
#   2. 启动单相机或双相机，自动设置硬件触发 + GPS 时间戳同步
#   3. 自动设置硬件触发（可选）
#
# 前提条件：
#   - 雷达和相机由同一 PPS 信号触发
#   - 雷达配置 use_lidar_clock: true（config.yaml 中）
#
# 用法:
#   ./lidar_camera_gps_sync.sh              # 启动全部（雷达 + 双相机 + 硬件触发）
#   ./lidar_camera_gps_sync.sh --camera left       # 只启动左相机，不启动雷达
#   ./lidar_camera_gps_sync.sh --camera right      # 只启动右相机，不启动雷达
#   ./lidar_camera_gps_sync.sh --lidar-only   # 仅启动雷达
#   ./lidar_camera_gps_sync.sh --camera-only # 仅启动双相机（要求雷达已在运行）
#   ./lidar_camera_gps_sync.sh --no-trigger   # 启动全部但不配置硬件触发
#   ./lidar_camera_gps_sync.sh --camera-only --no-trigger --no-gps-sync
# ============================================================================

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WS_ROOT="$SCRIPT_DIR"

# 相机默认参数（集中在这里，便于现场调整）
# 曝光 120000 是 8hz
# 230000 -> 2.5
PIXEL_FORMAT="Mono8"
THROUGHPUT=450000000
EXPOSURE=100000.0
WIDTH=4512
HEIGHT=4512
LEFT_SERIAL="03R47"
RIGHT_SERIAL="06HV5"
LEFT_TOPIC="vimbax_camera_left"
RIGHT_TOPIC="vimbax_camera_right"
TIME_SYNC=true
TRIGGER_SOURCE="Line0"
CAMERA_SIDE="${CAMERA_SIDE:-both}"  # both, left, or right

# 启动模式默认值
LIDAR_ONLY=false
CAMERA_ONLY=false
HW_TRIGGER=true
USE_GPS_SYNC="$TIME_SYNC"
LIDAR_PID=""
CAMERA_PID=""
SHM_PATH="/dev/shm/rslidar_gps_timestamp"

cleanup() {
    local exit_code=$?
    trap - EXIT INT TERM
    for pid in "$CAMERA_PID" "$LIDAR_PID"; do
        if [[ -n "$pid" ]] && kill -0 "$pid" 2>/dev/null; then
            kill "$pid" 2>/dev/null || true
        fi
    done
    wait 2>/dev/null || true
    exit "$exit_code"
}

read_committed_sequence() {
    python3 - "$SHM_PATH" <<'PY' 2>/dev/null || true
import struct
import sys

header_format = "<IIIIQ"
header_size = struct.calcsize(header_format)
entry_size = struct.calcsize("<Qq")

try:
    with open(sys.argv[1], "rb") as stream:
        header = stream.read(header_size)
        file_size = stream.seek(0, 2)
    magic, version, capacity, _reserved, committed = struct.unpack(header_format, header)
    expected_size = header_size + capacity * entry_size
    if (
        magic == 0x52534754
        and version == 2
        and capacity == 256
        and file_size >= expected_size
    ):
        print(committed)
except (OSError, struct.error):
    pass
PY
}

ensure_cameras_not_in_use() {
    local running_camera_nodes

    running_camera_nodes="$(pgrep -af vimbax_camera_node || true)"
    if [[ -n "$running_camera_nodes" ]]; then
        echo "[ERROR] 检测到已有 vimbax_camera_node 进程正在占用相机："
        printf '%s\n' "$running_camera_nodes"
        echo "        请在原启动终端按 Ctrl+C 停止它，确认退出后再运行本脚本。"
        return 1
    fi
}

is_camera_online() {
    local expected_serial="$1"
    local serial_file serial vendor_file vendor

    for serial_file in /sys/bus/usb/devices/*/serial; do
        [[ -r "$serial_file" ]] || continue
        serial="$(tr -d '\n' < "$serial_file")"
        [[ "$serial" == "$expected_serial" ]] || continue
        vendor_file="${serial_file%/*}/idVendor"
        [[ -r "$vendor_file" ]] || continue
        vendor="$(tr '[:upper:]' '[:lower:]' < "$vendor_file" | tr -d '\n')"
        [[ "$vendor" == "1ab2" ]] && return 0
    done
    return 1
}

ensure_required_cameras_connected() {
    local -a missing=()
    local -a connected=()
    local serial_file serial vendor_file vendor

    for serial_file in /sys/bus/usb/devices/*/serial; do
        [[ -r "$serial_file" ]] || continue
        vendor_file="${serial_file%/*}/idVendor"
        [[ -r "$vendor_file" ]] || continue
        vendor="$(tr '[:upper:]' '[:lower:]' < "$vendor_file" | tr -d '\n')"
        [[ "$vendor" == "1ab2" ]] || continue
        serial="$(tr -d '\n' < "$serial_file")"
        [[ -n "$serial" ]] && connected+=("$serial")
    done

    if [[ "$CAMERA_SIDE" != right ]]; then
        is_camera_online "$LEFT_SERIAL" || missing+=("左相机 ${LEFT_SERIAL}")
    fi
    if [[ "$CAMERA_SIDE" != left ]]; then
        is_camera_online "$RIGHT_SERIAL" || missing+=("右相机 ${RIGHT_SERIAL}")
    fi
    if (( ${#missing[@]} == 0 )); then
        return 0
    fi

    echo "[ERROR] 未检测到所需的 Allied Vision USB 相机:"
    printf '        %s\n' "${missing[@]}"
    if (( ${#connected[@]} > 0 )); then
        echo "        当前检测到的 Allied Vision 序列号: ${connected[*]}"
    else
        echo "        当前未检测到 Allied Vision（vendor=1ab2）相机。"
    fi
    echo "        请检查 USB 连接、供电及 LEFT_SERIAL/RIGHT_SERIAL 配置后重试。"
    return 1
}

while [[ $# -gt 0 ]]; do
    case $1 in
        --lidar-only)
            LIDAR_ONLY=true
            shift
            ;;
        --camera-only)
            CAMERA_ONLY=true
            shift
            ;;
        --camera-side)
            [[ $# -ge 2 ]] || { echo "[ERROR] --camera-side 需要 left、right 或 both"; exit 1; }
            CAMERA_SIDE="$2"
            shift 2
            ;;
        --camera)
            [[ $# -ge 2 ]] || { echo "[ERROR] --camera 需要 left 或 right"; exit 1; }
            CAMERA_SIDE="$2"
            CAMERA_ONLY=true
            USE_GPS_SYNC=false
            shift 2
            ;;
        --no-trigger)
            HW_TRIGGER=false
            shift
            ;;
        --no-gps-sync)
            USE_GPS_SYNC=false
            shift
            ;;
        --gps-sync)
            USE_GPS_SYNC=true
            shift
            ;;
        --help|-h)
            echo "用法: $0 [选项]"
            echo "  --lidar-only      仅启动雷达"
            echo "  --camera-only    仅启动相机，不启动雷达"
            echo "  --camera S       只启动单个相机：left 或 right（不启动雷达）"
            echo "  --camera-side S  相机选择：both、left 或 right（默认 both）"
            echo "  --no-trigger     不配置硬件触发"
            echo "  --gps-sync       启用 GPS 时间戳同步"
            echo "  --no-gps-sync    不启用 GPS 时间戳同步"
            echo "  --help, -h       显示此帮助"
            exit 0
            ;;
        *)
            echo "未知参数: $1"
            exit 1
            ;;
    esac
done

if [[ "$CAMERA_SIDE" != both && "$CAMERA_SIDE" != left && "$CAMERA_SIDE" != right ]]; then
    echo "[ERROR] CAMERA_SIDE/--camera-side 必须是 both、left 或 right"
    exit 1
fi

# 单相机快捷模式不启动雷达、不配置硬件触发，也不读取雷达共享内存时间戳。
if [[ "$CAMERA_SIDE" != both ]]; then
    CAMERA_ONLY=true
    USE_GPS_SYNC=false
    HW_TRIGGER=false
fi

if [[ "$LIDAR_ONLY" == true && "$CAMERA_ONLY" == true ]]; then
    echo "[ERROR] --lidar-only 与 --camera-only 不能同时使用"
    exit 1
fi

START_LIDAR=true
START_CAMERAS=true
[[ "$CAMERA_ONLY" == true ]] && START_LIDAR=false
[[ "$LIDAR_ONLY" == true ]] && START_CAMERAS=false
[[ "$START_CAMERAS" == false ]] && HW_TRIGGER=false

echo "============================================"
echo "雷达 + 相机 GPS 时间戳同步"
echo "============================================"
echo "  雷达:       $([ "$START_LIDAR" = true ] && echo "启动" || echo "跳过")"
echo "  相机:       $([ "$START_CAMERAS" = true ] && echo "启动 ($CAMERA_SIDE)" || echo "跳过")"
echo "  硬件触发:   $([ "$HW_TRIGGER" = true ] && echo "是" || echo "否")"
echo "  GPS 时间戳: $([ "$USE_GPS_SYNC" = true ] && echo "是" || echo "否")"
echo "============================================"

# ROS 2 的 setup 脚本会读取可能未定义的环境变量（例如
# AMENT_TRACE_SETUP_FILES），所以加载环境时暂时关闭 nounset。
set +u
# shellcheck disable=SC1091
source /opt/ros/humble/setup.bash
# shellcheck disable=SC1091
source "$WS_ROOT/install/setup.bash"
set -u
trap cleanup EXIT INT TERM

# GPS 同步参数
GPS_SYNC_ARG=""
if [ "$USE_GPS_SYNC" = true ]; then
    GPS_SYNC_ARG="use_shared_memory_gps_time:=true"
    echo "[*] GPS 时间戳同步: 启用"
    echo "[*] 共享内存路径: $SHM_PATH"
else
    echo "[*] GPS 时间戳同步: 禁用（使用相机本地时间戳）"
fi

# --------------------------------------------------------------------------
# 1. 启动雷达
# --------------------------------------------------------------------------
if [[ "$START_LIDAR" == true ]]; then
    echo ""
    echo "[1/2] 启动激光雷达..."
    # This path belongs exclusively to this timestamp bridge. Removing it before
    # launching a new writer prevents a previous run from satisfying readiness.
    rm -f -- "$SHM_PATH"
    ros2 launch rslidar_sdk humble_start.py &
    LIDAR_PID=$!
    echo "    雷达节点 PID: $LIDAR_PID"

    if [[ "$USE_GPS_SYNC" == true ]]; then
        echo "    等待雷达写入有效 GPS 时间戳..."
        for _attempt in {1..80}; do
            committed_sequence="$(read_committed_sequence)"
            if [[ "${committed_sequence:-0}" =~ ^[0-9]+$ ]] && (( committed_sequence > 0 )); then
                echo "    共享内存已就绪，序号: $committed_sequence"
                break
            fi
            if ! kill -0 "$LIDAR_PID" 2>/dev/null; then
                echo "[ERROR] 雷达启动进程已退出"
                exit 1
            fi
            sleep 0.1
        done
        if [[ "${committed_sequence:-0}" == 0 ]]; then
            echo "[ERROR] 8 秒内未收到雷达 GPS 时间戳，停止启动相机"
            exit 1
        fi
    fi
fi

# --------------------------------------------------------------------------
# 2. 启动双相机
# --------------------------------------------------------------------------
if [[ "$START_CAMERAS" == true ]]; then
    ensure_cameras_not_in_use
    ensure_required_cameras_connected

    if [[ "$START_LIDAR" == false && "$USE_GPS_SYNC" == true ]]; then
        initial_sequence="$(read_committed_sequence)"
        live_sequence=""
        if [[ "${initial_sequence:-}" =~ ^[1-9][0-9]*$ ]]; then
            for _attempt in {1..30}; do
                sleep 0.1
                current_sequence="$(read_committed_sequence)"
                if [[ "${current_sequence:-}" =~ ^[1-9][0-9]*$ ]] &&
                    (( current_sequence != initial_sequence ))
                then
                    live_sequence="$current_sequence"
                    break
                fi
            done
        fi
        if [[ -z "$live_sequence" ]]; then
            echo "[ERROR] --camera-only + GPS 同步要求已有雷达进程写入共享内存"
            echo "        共享内存序号在 3 秒内没有推进，可能是上次运行的残留文件"
            echo "        请先启动雷达，或添加 --no-gps-sync"
            exit 1
        fi
        echo "    检测到共享内存持续更新，序号: $initial_sequence -> $live_sequence"
    fi
    echo ""
    echo "[2/2] 启动相机 ($CAMERA_SIDE)..."
    ACTIVE_LEFT_SERIAL="$LEFT_SERIAL"
    ACTIVE_RIGHT_SERIAL="$RIGHT_SERIAL"
    ACTIVE_LEFT_TOPIC="$LEFT_TOPIC"
    ACTIVE_RIGHT_TOPIC="$RIGHT_TOPIC"
    AUTOSTREAM=0
    if [[ "$CAMERA_SIDE" == left ]]; then
        ACTIVE_RIGHT_SERIAL="__disabled__"
        ACTIVE_RIGHT_TOPIC="__disabled__"
    elif [[ "$CAMERA_SIDE" == right ]]; then
        ACTIVE_LEFT_SERIAL="__disabled__"
        ACTIVE_LEFT_TOPIC="__disabled__"
    fi
    if [[ "$CAMERA_SIDE" != both ]]; then
        # 单相机无需等待双相机参数服务链，打开相机后直接发布图像。
        AUTOSTREAM=1
    fi
    CAMERA_ARGS=(
        "left_serial:=$ACTIVE_LEFT_SERIAL"
        "right_serial:=$ACTIVE_RIGHT_SERIAL"
        "left_topic:=$ACTIVE_LEFT_TOPIC"
        "right_topic:=$ACTIVE_RIGHT_TOPIC"
        "pixel_format:=$PIXEL_FORMAT"
        "device_throughput_limit:=$THROUGHPUT"
        "exposure_time:=$EXPOSURE"
        "width:=$WIDTH"
        "height:=$HEIGHT"
        "settings_file:=$WS_ROOT/config/camera_settings.xml"
        "autostream:=$AUTOSTREAM"
    )
    if [ -n "$GPS_SYNC_ARG" ]; then
        CAMERA_ARGS+=("$GPS_SYNC_ARG")
    fi

    ros2 launch vimbax_camera dual_camera_stream_launch.py "${CAMERA_ARGS[@]}" &
    CAMERA_PID=$!
    echo "    相机节点 PID: $CAMERA_PID"

    # 等待相机启动完成
    echo "    等待相机初始化..."
    sleep 5
    if ! kill -0 "$CAMERA_PID" 2>/dev/null; then
        echo "[ERROR] 相机启动进程已退出"
        exit 1
    fi

fi

# --------------------------------------------------------------------------
# 3. 配置硬件触发（可选）
# --------------------------------------------------------------------------
if [[ "$HW_TRIGGER" == true && "$START_CAMERAS" == true ]]; then
    echo ""
    echo "[*] 配置硬件触发..."
    TRIGGER_SOURCE="$TRIGGER_SOURCE" \
    EXPOSURE="$EXPOSURE" \
    ACTIVE_CAMERA_SIDE="$CAMERA_SIDE" \
    LEFT_SERIAL="$LEFT_SERIAL" \
    RIGHT_SERIAL="$RIGHT_SERIAL" \
    LEFT_TOPIC="$LEFT_TOPIC" \
    RIGHT_TOPIC="$RIGHT_TOPIC" \
    bash "$WS_ROOT/camera_hw_trigger_dual.sh"
fi

echo ""
echo "============================================"
echo "所有节点已启动"
echo "============================================"
if [[ "$START_LIDAR" == true ]]; then
    echo "  雷达 PID:  $LIDAR_PID"
fi
if [[ "$START_CAMERAS" == true ]]; then
    echo "  相机 PID:  $CAMERA_PID"
fi
echo ""
echo "验证命令:"
echo "  # 查看共享内存队列内容（含最新已提交时间戳）:"
echo "    ./verify_timestamp_sync.sh --shared-mem"
echo ""
echo "  # 查看雷达时间戳:"
echo "    ros2 topic echo /rslidar_points --csv | head -5"
echo ""
echo "  # 查看相机时间戳:"
echo "    ros2 topic echo /vimbax_camera_left/image_raw --csv | head -5"
echo ""
echo "  # 时间戳对比验证:"
echo "    ./verify_timestamp_sync.sh"
echo ""
echo "  # 停止所有节点: 在当前终端按 Ctrl+C"
echo "============================================"

# 保持运行并让任一子进程异常退出时触发统一清理。
wait -n

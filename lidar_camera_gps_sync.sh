#!/bin/bash

# ============================================================================
# 雷达 + 双目相机 GPS 时间戳同步启动脚本
#
# 功能：
#   1. 启动 rslidar_sdk 雷达节点（发点云时写入 GPS 时间戳到 /dev/shm/rslidar_gps_timestamp）
#   2. 启动双相机，自动设置硬件触发 + GPS 时间戳同步
#   3. 自动设置硬件触发（可选）
#
# 前提条件：
#   - 雷达和相机由同一 PPS 信号触发
#   - 雷达配置 use_lidar_clock: true（config.yaml 中）
#
# 用法:
#   ./lidar_camera_gps_sync.sh              # 启动全部（雷达 + 双相机 + 硬件触发）
#   ./lidar_camera_gps_sync.sh --lidar-only   # 仅启动雷达
#   ./lidar_camera_only --camera-only     # 仅启动双相机（不带硬件触发）
#   ./lidar_camera_gps_sync.sh --no-trigger   # 启动全部但不配置硬件触发
# ============================================================================

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WS_ROOT="$SCRIPT_DIR"

# 默认值
LIDAR_ONLY=false
CAMERA_ONLY=false
HW_TRIGGER=true
USE_GPS_SYNC=true

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
        --no-trigger)
            HW_TRIGGER=false
            shift
            ;;
        --no-gps-sync)
            USE_GPS_SYNC=false
            shift
            ;;
        --help|-h)
            echo "用法: $0 [选项]"
            echo "  --lidar-only      仅启动雷达"
            echo "  --camera-only    仅启动双相机"
            echo "  --no-trigger     不配置硬件触发"
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

echo "============================================"
echo "雷达 + 双目相机 GPS 时间戳同步"
echo "============================================"
echo "  雷达:       $([ "$LIDAR_ONLY" = true ] && echo "启动" || echo "启动")"
echo "  双相机:     $([ "$CAMERA_ONLY" = true ] && echo "启动" || echo "启动")"
echo "  硬件触发:   $([ "$HW_TRIGGER" = true ] && echo "是" || echo "否")"
echo "  GPS 时间戳: $([ "$USE_GPS_SYNC" = true ] && echo "是" || echo "否")"
echo "============================================"

# source ROS 环境
source /opt/ros/humble/setup.bash 2>/dev/null
source "$WS_ROOT/install/setup.bash" 2>/dev/null

# GPS 同步参数
GPS_SYNC_ARG=""
if [ "$USE_GPS_SYNC" = true ]; then
    GPS_SYNC_ARG="use_shared_memory_gps_time:=true"
    echo "[*] GPS 时间戳同步: 启用"
    echo "[*] 共享内存路径: /dev/shm/rslidar_gps_timestamp"
else
    echo "[*] GPS 时间戳同步: 禁用（使用相机本地时间戳）"
fi

# --------------------------------------------------------------------------
# 1. 启动雷达
# --------------------------------------------------------------------------
if [ "$CAMERA_ONLY" = false ]; then
    echo ""
    echo "[1/2] 启动激光雷达..."
    ros2 launch rslidar_sdk humble_start.py &
    LIDAR_PID=$!
    echo "    雷达节点 PID: $LIDAR_PID"
    sleep 2
fi

# --------------------------------------------------------------------------
# 2. 启动双相机
# --------------------------------------------------------------------------
if [ "$LIDAR_ONLY" = false ]; then
    echo ""
    echo "[2/2] 启动双相机..."
    CAMERA_ARGS=(
        "left_serial:=03R47"
        "right_serial:=06HV5"
        "left_topic:=vimbax_camera_left"
        "right_topic:=vimbax_camera_right"
        "pixel_format:=Mono8"
        "device_throughput_limit:=450000000"
        "exposure_time:=240000.0"
        "width:=4512"
        "height:=4512"
        "settings_file:=$WS_ROOT/config/camera_settings.xml"
        "autostream:=0"
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
fi

# --------------------------------------------------------------------------
# 3. 配置硬件触发（可选）
# --------------------------------------------------------------------------
if [ "$HW_TRIGGER" = true ] && [ "$LIDAR_ONLY" = false ]; then
    echo ""
    echo "[*] 配置硬件触发..."
    bash "$WS_ROOT/camera_hw_trigger_dual.sh"
fi

echo ""
echo "============================================"
echo "所有节点已启动"
echo "============================================"
if [ "$CAMERA_ONLY" = false ]; then
    echo "  雷达 PID:  $LIDAR_PID"
fi
if [ "$LIDAR_ONLY" = false ]; then
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
echo "  # 停止所有节点:"
echo "    kill $LIDAR_PID $CAMERA_PID 2>/dev/null; pkill -f rslidar_sdk; pkill -f vimbax_camera"
echo "============================================"

# 保持运行
wait

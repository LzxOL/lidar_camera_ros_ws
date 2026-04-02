#!/bin/bash

# 相机时间戳同步启动脚本
# 用法: ./camera_timestamp_sync.sh [--left-topic <topic>] [--right-topic <topic>] [--output-topic <topic>] [--offset-ms <ms>]
# 示例: ./camera_timestamp_sync.sh
# 示例: ./camera_timestamp_sync.sh --offset-ms 516.0

# 默认值
LEFT_TOPIC="/vimbax_camera_left/image_raw"
RIGHT_TOPIC="/vimbax_camera_right/image_raw"
OUTPUT_TOPIC="/vimbax_camera_right/image_sync"
OFFSET_MS="0.0"
DETECT_FRAMES="30"

# 解析参数
while [[ $# -gt 0 ]]; do
    case $1 in
        --left-topic)
            LEFT_TOPIC="$2"
            shift 2
            ;;
        --right-topic)
            RIGHT_TOPIC="$2"
            shift 2
            ;;
        --output-topic)
            OUTPUT_TOPIC="$2"
            shift 2
            ;;
        --offset-ms)
            OFFSET_MS="$2"
            shift 2
            ;;
        --detect-frames)
            DETECT_FRAMES="$2"
            shift 2
            ;;
        *)
            echo "未知参数: $1"
            shift
            ;;
    esac
done

# 检查是否需要 source ROS 环境
if [ -z "$ROS_DISTRO" ]; then
    echo "[时间戳同步] 正在 source ROS 环境..."
    source /opt/ros/humble/setup.bash
    source "/home/root1/lzx_ws/project/lidar_camera_ros_ws/install/setup.bash"
fi

echo "============================================"
echo "相机时间戳同步节点"
echo "============================================"
echo "左相机 topic:  ${LEFT_TOPIC}"
echo "右相机 topic:  ${RIGHT_TOPIC}"
echo "输出 topic:    ${OUTPUT_TOPIC}"
if [ "$OFFSET_MS" != "0.0" ]; then
echo "偏移量:        ${OFFSET_MS} ms (手动模式)"
else
echo "偏移量:        自动检测模式"
echo "检测帧数:      ${DETECT_FRAMES}"
fi
echo "============================================"

ros2 launch vimbax_camera camera_timestamp_sync_launch.py \
    left_topic:="${LEFT_TOPIC}" \
    right_topic:="${RIGHT_TOPIC}" \
    output_topic:="${OUTPUT_TOPIC}" \
    offset_ms:="${OFFSET_MS}" \
    detect_frames:="${DETECT_FRAMES}"

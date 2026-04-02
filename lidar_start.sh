#!/bin/bash

# 激光雷达启动脚本
# 用法: ./lidar_start.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cd "$SCRIPT_DIR"
source install/setup.bash

if [[ $# -gt 0 ]]; then
    echo "未知参数: $1"
    echo "用法: $0"
    exit 1
fi

echo "============================================"
echo "启动激光雷达工作空间"
echo "============================================"
echo "[1/1] 启动激光雷达..."

ros2 launch rslidar_sdk humble_start.py &
LIDAR_PID=$!

echo "  雷达节点 PID: $LIDAR_PID"
echo "============================================"
echo "雷达节点已启动"
echo "============================================"
echo "  雷达: PID $LIDAR_PID"
echo ""
echo "验证命令:"
echo "  ros2 topic hz /rslidar_points"
echo "  ros2 topic echo /rslidar_points --once"
echo ""
echo "按 Ctrl+C 停止所有节点"
echo "============================================"

wait

#!/usr/bin/env bash

# 按键保存单目/双目标定图片，同时生成一一对应的时间戳 CSV 和 rosbag2。
# 示例：
#   ./capture_calibration_samples.sh --mode stereo -o stereo_fisheye_calib
#   ./capture_calibration_samples.sh --mode mono-right -o mono_fisheye_calib

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROS_DISTRO_NAME="${ROS_DISTRO:-humble}"
ROS_SETUP="/opt/ros/${ROS_DISTRO_NAME}/setup.bash"

if [[ ! -r "${ROS_SETUP}" ]]; then
    echo "错误：找不到 ROS 2 环境文件 ${ROS_SETUP}" >&2
    exit 1
fi

# setup.bash 可能引用尚未定义的变量，source 时暂时关闭 nounset。
set +u
source "${ROS_SETUP}"
if [[ -r "${SCRIPT_DIR}/install/setup.bash" ]]; then
    source "${SCRIPT_DIR}/install/setup.bash"
fi
set -u

exec python3 "${SCRIPT_DIR}/capture_calibration_samples.py" "$@"

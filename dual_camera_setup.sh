#!/bin/bash

# Dual Camera 参数设置与启动脚本
# 用法:
#   ./dual_camera_setup.sh [--pixel_format <format>] [--throughput <value>] [--exposure <value>]
#                         [--width <value>] [--height <value>]
#                         [--left_serial <serial>] [--right_serial <serial>]
#                         [--left_topic <topic>] [--right_topic <topic>]
#                         [--time_sync <true|false>]
#
# 示例:
#   ./dual_camera_setup.sh
#   ./dual_camera_setup.sh --time_sync true
#   ./dual_camera_setup.sh --exposure 240000.0 --time_sync false

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROS_WS="${SCRIPT_DIR}"

# 默认值
PIXEL_FORMAT="Mono8"
THROUGHPUT=450000000
EXPOSURE=240000.0
WIDTH=4512
HEIGHT=4512
LEFT_SERIAL="03R47"
RIGHT_SERIAL="06HV5"
LEFT_TOPIC="vimbax_camera_left"
RIGHT_TOPIC="vimbax_camera_right"
TIME_SYNC=true
TRIGGER_SOURCE="Line0"

parse_bool() {
    local value="${1,,}"
    case "$value" in
        true|1|yes|on)
            echo "true"
            ;;
        false|0|no|off)
            echo "false"
            ;;
        *)
            return 1
            ;;
    esac
}

# 检测 Allied Vision USB 相机是否在线（vendor=1ab2）
is_camera_online() {
    local serial="$1"
    for dev in /sys/bus/usb/devices/*/serial; do
        if [[ -r "$dev" ]]; then
            local s
            s=$(cat "$dev" 2>/dev/null | tr -d '\n')
            if [[ "$s" == "$serial" ]]; then
                local vendor_file="${dev%/*}/idVendor"
                if [[ -r "$vendor_file" ]]; then
                    local vendor
                    vendor=$(cat "$vendor_file" 2>/dev/null | tr -d '\n')
                    [[ "$vendor" == "1ab2" ]] && return 0
                fi
            fi
        fi
    done
    return 1
}

reset_camera_timestamp() {
    local ns="$1"
    echo "[*] ${ns} TimestampReset..."
    ros2 service call /"${ns}"/features/command_run \
        vimbax_camera_msgs/srv/FeatureCommandRun \
        "{feature_name: 'TimestampReset', feature_module: {id: 0}}" 2>/dev/null
}

configure_camera() {
    local ns="$1"
    local serial="$2"
    local features="/${ns}/features"

    echo "--- 设置 ${serial} (${ns}) ---"
    echo "  [0] 停止推流和采集..."
    ros2 service call "${features}"/command_run vimbax_camera_msgs/srv/FeatureCommandRun \
        "{feature_name: 'AcquisitionStop', feature_module: {id: 0}}" 2>/dev/null
    sleep 0.3
    ros2 service call /"${ns}"/stream_stop vimbax_camera_msgs/srv/StreamStartStop "{}" 2>/dev/null
    sleep 0.3

    echo "  1. 设置 PixelFormat = ${PIXEL_FORMAT}"
    ros2 service call "${features}"/enum_set vimbax_camera_msgs/srv/FeatureEnumSet \
        "{feature_name: 'PixelFormat', feature_module: {id: 0}, value: '${PIXEL_FORMAT}'}" 2>/dev/null

    echo "  2. 设置 DeviceLinkThroughputLimit = ${THROUGHPUT}"
    ros2 service call "${features}"/int_set vimbax_camera_msgs/srv/FeatureIntSet \
        "{feature_name: 'DeviceLinkThroughputLimit', feature_module: {id: 0}, value: ${THROUGHPUT}}" 2>/dev/null

    echo "  3. 设置 ExposureTime = ${EXPOSURE}"
    ros2 service call "${features}"/float_set vimbax_camera_msgs/srv/FeatureFloatSet \
        "{feature_name: 'ExposureTime', feature_module: {id: 0}, value: ${EXPOSURE}}" 2>/dev/null

    echo "  4. 设置 Width = ${WIDTH}"
    ros2 service call "${features}"/int_set vimbax_camera_msgs/srv/FeatureIntSet \
        "{feature_name: 'Width', feature_module: {id: 0}, value: ${WIDTH}}" 2>/dev/null

    echo "  5. 设置 Height = ${HEIGHT}"
    ros2 service call "${features}"/int_set vimbax_camera_msgs/srv/FeatureIntSet \
        "{feature_name: 'Height', feature_module: {id: 0}, value: ${HEIGHT}}" 2>/dev/null

    echo "  [6] 重新启动推流..."
    sleep 0.3
    ros2 service call /"${ns}"/stream_start vimbax_camera_msgs/srv/StreamStartStop "{}" 2>/dev/null
    echo ""
}

setup_camera_hw_trigger() {
    local ns="$1"

    echo ""
    echo "========== 配置 ${ns} =========="

    echo "[1/9] 停止采集..."
    ros2 service call /"${ns}"/features/command_run \
        vimbax_camera_msgs/srv/FeatureCommandRun \
        "{feature_name: 'AcquisitionStop', feature_module: {id: 0}}" 2>/dev/null
    sleep 0.5

    echo "[2/9] 停止推流..."
    ros2 service call /"${ns}"/stream_stop \
        vimbax_camera_msgs/srv/StreamStartStop "{}" 2>/dev/null
    sleep 0.5

    echo "[3/9] TriggerSelector = FrameStart"
    ros2 service call /"${ns}"/features/enum_set \
        vimbax_camera_msgs/srv/FeatureEnumSet \
        "{feature_name: 'TriggerSelector', feature_module: {id: 0}, value: 'FrameStart'}" 2>/dev/null
    sleep 0.3

    echo "[4/9] TriggerMode = On"
    ros2 service call /"${ns}"/features/enum_set \
        vimbax_camera_msgs/srv/FeatureEnumSet \
        "{feature_name: 'TriggerMode', feature_module: {id: 0}, value: 'On'}" 2>/dev/null
    sleep 0.3

    echo "[5/9] TriggerSource = ${TRIGGER_SOURCE}"
    ros2 service call /"${ns}"/features/enum_set \
        vimbax_camera_msgs/srv/FeatureEnumSet \
        "{feature_name: 'TriggerSource', feature_module: {id: 0}, value: '${TRIGGER_SOURCE}'}" 2>/dev/null
    sleep 0.3

    echo "[6/9] TriggerActivation = RisingEdge"
    ros2 service call /"${ns}"/features/enum_set \
        vimbax_camera_msgs/srv/FeatureEnumSet \
        "{feature_name: 'TriggerActivation', feature_module: {id: 0}, value: 'RisingEdge'}" 2>/dev/null
    sleep 0.3

    echo "[7/9] ExposureMode = Timed"
    ros2 service call /"${ns}"/features/enum_set \
        vimbax_camera_msgs/srv/FeatureEnumSet \
        "{feature_name: 'ExposureMode', feature_module: {id: 0}, value: 'Timed'}" 2>/dev/null
    sleep 0.3

    echo "[8/9] ExposureTime = ${EXPOSURE} us"
    ros2 service call /"${ns}"/features/float_set \
        vimbax_camera_msgs/srv/FeatureFloatSet \
        "{feature_name: 'ExposureTime', feature_module: {id: 0}, value: ${EXPOSURE}}" 2>/dev/null
    sleep 0.3

    echo "[9/9] 启动推流..."
    ros2 service call /"${ns}"/stream_start \
        vimbax_camera_msgs/srv/StreamStartStop "{}" 2>/dev/null

    echo "========== ${ns} 配置完成 =========="
}

run_time_sync_setup() {
    echo ""
    echo "============================================"
    echo "Time Sync / 硬件触发配置"
    echo "============================================"

    if [[ $RIGHT_ONLINE -eq 1 ]]; then
        echo "第一步：停止右相机（释放USB带宽）"
        echo "[*] 停止右相机推流..."
        ros2 service call /"${RIGHT_NS}"/stream_stop \
            vimbax_camera_msgs/srv/StreamStartStop "{}" 2>/dev/null
        sleep 1
        echo "[*] 停止右相机采集..."
        ros2 service call /"${RIGHT_NS}"/features/command_run \
            vimbax_camera_msgs/srv/FeatureCommandRun \
            "{feature_name: 'AcquisitionStop', feature_module: {id: 0}}" 2>/dev/null
        sleep 1
        echo "[*] 右相机已停止，等待USB总线空闲 2s..."
        sleep 2
    fi

    if [[ $LEFT_ONLINE -eq 1 ]]; then
        echo ""
        echo "第二步：配置左相机 Time Sync"
        setup_camera_hw_trigger "${LEFT_NS}"
        echo "[*] 左相机配置完成，等待其URB传输稳定 3s..."
        sleep 3
    fi

    if [[ $RIGHT_ONLINE -eq 1 ]]; then
        echo ""
        echo "第三步：配置右相机 Time Sync"
        setup_camera_hw_trigger "${RIGHT_NS}"
    fi

    echo ""
    echo "第四步：统一重置相机时间戳"
    [[ $LEFT_ONLINE -eq 1 ]] && reset_camera_timestamp "${LEFT_NS}"
    [[ $RIGHT_ONLINE -eq 1 ]] && reset_camera_timestamp "${RIGHT_NS}"

    echo ""
    echo "============================================"
    echo "Time Sync / 硬件触发配置完成!"
    echo "============================================"
    echo "触发源: ${TRIGGER_SOURCE}"
    echo "曝光时间: ${EXPOSURE} us"
}

# 解析参数
while [[ $# -gt 0 ]]; do
    case $1 in
        --pixel_format)
            PIXEL_FORMAT="$2"
            shift 2
            ;;
        --throughput)
            THROUGHPUT="$2"
            shift 2
            ;;
        --exposure)
            EXPOSURE="$2"
            shift 2
            ;;
        --width)
            WIDTH="$2"
            shift 2
            ;;
        --height)
            HEIGHT="$2"
            shift 2
            ;;
        --left_serial)
            LEFT_SERIAL="$2"
            shift 2
            ;;
        --right_serial)
            RIGHT_SERIAL="$2"
            shift 2
            ;;
        --left_topic)
            LEFT_TOPIC="$2"
            shift 2
            ;;
        --right_topic)
            RIGHT_TOPIC="$2"
            shift 2
            ;;
        --time_sync)
            if ! TIME_SYNC="$(parse_bool "$2")"; then
                echo "[ERROR] --time_sync 仅支持 true/false、1/0、yes/no、on/off"
                exit 1
            fi
            shift 2
            ;;
        *)
            echo "未知参数: $1"
            exit 1
            ;;
    esac
done

# 检查是否需要 source ROS 环境
if [[ -z "${ROS_DISTRO:-}" ]]; then
    echo "[dual_camera_setup] 正在 source ROS 环境..."
    source /opt/ros/humble/setup.bash
    source "${ROS_WS}/install/setup.bash"
fi

# 检测相机连接状态
LEFT_ONLINE=0
RIGHT_ONLINE=0
LEFT_NS="${LEFT_TOPIC}"
RIGHT_NS="${RIGHT_TOPIC}"

echo "============================================"
echo "相机连接检测"
echo "============================================"
echo "左相机序列号: ${LEFT_SERIAL}"
echo "右相机序列号: ${RIGHT_SERIAL}"
echo "Time Sync: ${TIME_SYNC}"

if is_camera_online "${LEFT_SERIAL}"; then
    echo "左相机 (${LEFT_SERIAL}): 已连接"
    LEFT_ONLINE=1
else
    echo "左相机 (${LEFT_SERIAL}): 未检测到（将跳过）"
fi

if is_camera_online "${RIGHT_SERIAL}"; then
    echo "右相机 (${RIGHT_SERIAL}): 已连接"
    RIGHT_ONLINE=1
else
    echo "右相机 (${RIGHT_SERIAL}): 未检测到（将跳过）"
fi

if [[ $LEFT_ONLINE -eq 0 && $RIGHT_ONLINE -eq 0 ]]; then
    echo "============================================"
    echo "[ERROR] 未检测到任何相机，退出。"
    echo "============================================"
    exit 1
fi
echo "============================================"

# 启动 launch
echo "[1/2] 正在启动 Camera Launch..."
LAUNCH_ARGS=(
    left_serial:=${LEFT_SERIAL}
    right_serial:=${RIGHT_SERIAL}
    left_topic:=${LEFT_TOPIC}
    right_topic:=${RIGHT_TOPIC}
    pixel_format:=${PIXEL_FORMAT}
    device_throughput_limit:=${THROUGHPUT}
    exposure_time:=${EXPOSURE}
    width:=${WIDTH}
    height:=${HEIGHT}
    autostream:=0
    use_shared_memory_gps_time:=${TIME_SYNC}
)

ros2 launch vimbax_camera dual_camera_stream_launch.py "${LAUNCH_ARGS[@]}" &
LAUNCH_PID=$!
echo "[dual_camera_setup] Launch 进程 PID: ${LAUNCH_PID}"

echo "[2/2] 等待相机节点初始化和参数设置完成..."
sleep 8

# 基础参数设置
echo ""
echo "============================================"
echo "相机基础参数设置"
echo "============================================"

[[ $LEFT_ONLINE -eq 1 ]] && configure_camera "${LEFT_NS}" "${LEFT_SERIAL}"
[[ $RIGHT_ONLINE -eq 1 ]] && configure_camera "${RIGHT_NS}" "${RIGHT_SERIAL}"

if [[ "${TIME_SYNC}" == "true" ]]; then
    run_time_sync_setup
else
    echo ""
    echo "============================================"
    echo "重置相机时间戳 (TimestampReset)"
    echo "============================================"
    [[ $LEFT_ONLINE -eq 1 ]] && reset_camera_timestamp "${LEFT_NS}"
    [[ $RIGHT_ONLINE -eq 1 ]] && reset_camera_timestamp "${RIGHT_NS}"
fi

echo ""
echo "============================================"
echo "运行中的相机 topic:"
[[ $LEFT_ONLINE -eq 1 ]] && echo "  左相机: /${LEFT_NS}/image_raw  (${LEFT_SERIAL})"
[[ $RIGHT_ONLINE -eq 1 ]] && echo "  右相机: /${RIGHT_NS}/image_raw  (${RIGHT_SERIAL})"
echo "============================================"
echo "相机启动完成!"
[[ $LEFT_ONLINE -eq 1 && $RIGHT_ONLINE -eq 1 ]] && echo "双相机模式"
[[ $LEFT_ONLINE -eq 1 && $RIGHT_ONLINE -eq 0 ]] && echo "单相机模式（左）"
[[ $LEFT_ONLINE -eq 0 && $RIGHT_ONLINE -eq 1 ]] && echo "单相机模式（右）"
echo "Time Sync: ${TIME_SYNC}"
echo "Launch 进程仍在后台运行 (PID: ${LAUNCH_PID})"
echo "按 Ctrl+C 终止所有相机节点"
echo ""
if [[ "${TIME_SYNC}" == "true" ]]; then
    echo "已启用共享内存 GPS 时间戳 + 硬件触发配置"
    echo "检查命令:"
    echo "  ./echo_lidar_camera_sync.sh"
else
    echo "未启用 Time Sync。如需启用，请使用:"
    echo "  ./dual_camera_setup.sh --time_sync true"
fi
echo "============================================"

wait "${LAUNCH_PID}"

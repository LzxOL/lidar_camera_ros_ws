#!/bin/bash

# 双相机硬件触发配置脚本
# 默认 TriggerSource=Line0
# 支持单相机和双相机模式

# ============================================================
# 默认参数
# ============================================================
TRIGGER_SOURCE="${TRIGGER_SOURCE:-Line0}"
EXPOSURE="${EXPOSURE:-240000.0}"
LEFT_TOPIC="${LEFT_TOPIC:-vimbax_camera_left}"
RIGHT_TOPIC="${RIGHT_TOPIC:-vimbax_camera_right}"

# 检测相机是否在线
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

# 配置单相机硬件触发（参数已在前面设置好，只做停止/配置/启动/时间戳重置）
setup_camera_hw_trigger() {
    local ns="$1"
    echo ""
    echo "========== 配置 ${ns} =========="

    echo "[1/9] 停止采集..."
    ros2 service call /${ns}/features/command_run \
      vimbax_camera_msgs/srv/FeatureCommandRun \
      "{feature_name: 'AcquisitionStop', feature_module: {id: 0}}"
    sleep 0.5

    echo "[2/9] 停止推流..."
    ros2 service call /${ns}/stream_stop \
      vimbax_camera_msgs/srv/StreamStartStop "{}"
    sleep 0.5

    echo "[3/9] TriggerSelector = FrameStart"
    ros2 service call /${ns}/features/enum_set \
      vimbax_camera_msgs/srv/FeatureEnumSet \
      "{feature_name: 'TriggerSelector', feature_module: {id: 0}, value: 'FrameStart'}"
    sleep 0.3

    echo "[4/9] TriggerMode = On"
    ros2 service call /${ns}/features/enum_set \
      vimbax_camera_msgs/srv/FeatureEnumSet \
      "{feature_name: 'TriggerMode', feature_module: {id: 0}, value: 'On'}"
    sleep 0.3

    echo "[5/9] TriggerSource = ${TRIGGER_SOURCE}"
    ros2 service call /${ns}/features/enum_set \
      vimbax_camera_msgs/srv/FeatureEnumSet \
      "{feature_name: 'TriggerSource', feature_module: {id: 0}, value: '${TRIGGER_SOURCE}'}"
    sleep 0.3

    echo "[6/9] TriggerActivation = RisingEdge"
    ros2 service call /${ns}/features/enum_set \
      vimbax_camera_msgs/srv/FeatureEnumSet \
      "{feature_name: 'TriggerActivation', feature_module: {id: 0}, value: 'RisingEdge'}"
    sleep 0.3

    echo "[7/9] ExposureMode = Timed"
    ros2 service call /${ns}/features/enum_set \
      vimbax_camera_msgs/srv/FeatureEnumSet \
      "{feature_name: 'ExposureMode', feature_module: {id: 0}, value: 'Timed'}"
    sleep 0.3

    echo "[8/9] ExposureTime = ${EXPOSURE} us"
    ros2 service call /${ns}/features/float_set \
      vimbax_camera_msgs/srv/FeatureFloatSet \
      "{feature_name: 'ExposureTime', feature_module: {id: 0}, value: ${EXPOSURE}}"
    sleep 0.3

    echo "[9/9] 启动推流..."
    ros2 service call /${ns}/stream_start \
      vimbax_camera_msgs/srv/StreamStartStop "{}"

    echo "========== ${ns} 配置完成 =========="
}

# ============================================================
# 主逻辑
# ============================================================
source /opt/ros/humble/setup.bash 2>/dev/null
source /home/root1/lzx_ws/project/lidar_camera_ros_ws/install/setup.bash 2>/dev/null

LEFT_SERIAL="03R47"
RIGHT_SERIAL="06HV5"

LEFT_ONLINE=0
RIGHT_ONLINE=0

echo "============================================"
echo "硬件触发配置"
echo "============================================"
echo "左相机序列号: ${LEFT_SERIAL}"
echo "右相机序列号: ${RIGHT_SERIAL}"

if is_camera_online "${LEFT_SERIAL}"; then
    echo "左相机 (${LEFT_SERIAL}): 已连接"
    LEFT_ONLINE=1
else
    echo "左相机 (${LEFT_SERIAL}): 未检测到"
fi

if is_camera_online "${RIGHT_SERIAL}"; then
    echo "右相机 (${RIGHT_SERIAL}): 已连接"
    RIGHT_ONLINE=1
else
    echo "右相机 (${RIGHT_SERIAL}): 未检测到"
fi

if [[ $LEFT_ONLINE -eq 0 && $RIGHT_ONLINE -eq 0 ]]; then
    echo "[ERROR] 未检测到任何相机，退出。"
    exit 1
fi

# ============================================================
# 串行配置：必须先停右相机，再配左相机，再启动右相机
# 原因：右相机在连续采集模式（10Hz）占用~80% USB带宽，
#       如果左相机重启时右相机还在传，两路同时抢带宽导致URB丢包
# ============================================================

echo ""
echo "============================================"
echo "第一步：停止右相机（释放USB带宽）"
echo "============================================"
if [[ $RIGHT_ONLINE -eq 1 ]]; then
    echo "[*] 停止右相机推流..."
    ros2 service call /${RIGHT_TOPIC}/stream_stop \
      vimbax_camera_msgs/srv/StreamStartStop "{}"
    sleep 1
    echo "[*] 停止右相机采集..."
    ros2 service call /${RIGHT_TOPIC}/features/command_run \
      vimbax_camera_msgs/srv/FeatureCommandRun \
      "{feature_name: 'AcquisitionStop', feature_module: {id: 0}}"
    sleep 1
    echo "[*] 右相机已停止，等待USB总线空闲 2s..."
    sleep 2
fi

echo ""
echo "============================================"
echo "第二步：配置左相机"
echo "============================================"
if [[ $LEFT_ONLINE -eq 1 ]]; then
    setup_camera_hw_trigger "${LEFT_TOPIC}"

    echo ""
    echo "[*] 左相机 TimestampReset..."
    ros2 service call /${LEFT_TOPIC}/features/command_run \
      vimbax_camera_msgs/srv/FeatureCommandRun \
      "{feature_name: 'TimestampReset', feature_module: {id: 0}}"

    echo ""
    echo "[*] 左相机配置完成，等待其URB传输稳定 3s..."
    sleep 3
fi

echo ""
echo "============================================"
echo "第三步：配置右相机（硬件触发）"
echo "============================================"
if [[ $RIGHT_ONLINE -eq 1 ]]; then
    setup_camera_hw_trigger "${RIGHT_TOPIC}"

    echo ""
    echo "[*] 右相机 TimestampReset..."
    ros2 service call /${RIGHT_TOPIC}/features/command_run \
      vimbax_camera_msgs/srv/FeatureCommandRun \
      "{feature_name: 'TimestampReset', feature_module: {id: 0}}"
fi

echo ""
echo "============================================"
echo "硬件触发配置完成!"
echo "============================================"
echo "触发源: ${TRIGGER_SOURCE}"
echo "曝光时间: ${EXPOSURE} us"
echo ""
echo "验证命令:"
[[ $LEFT_ONLINE -eq 1 ]] && echo "  左相机帧率: ros2 topic hz /${LEFT_TOPIC}/image_raw"
[[ $RIGHT_ONLINE -eq 1 ]] && echo "  右相机帧率: ros2 topic hz /${RIGHT_TOPIC}/image_raw"
[[ $LEFT_ONLINE -eq 1 && $RIGHT_ONLINE -eq 1 ]] && echo "  双相机帧率: ros2 topic hz /${LEFT_TOPIC}/image_raw /${RIGHT_TOPIC}/image_raw"
echo "============================================"

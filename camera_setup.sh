#!/bin/bash

# Camera 参数设置脚本
# 用法: ./camera_setup.sh <camera_pid> [--pixel_format <format>] [--throughput <value>] [--exposure <value>] [--width <value>] [--height <value>] [--color_transform_enable <0|1>] [--ccm <r0c0,r0c1,r0c2,r1c0,r1c1,r1c2,r2c0,r2c1,r2c2>]
# 示例: ./camera_setup.sh 92281
# 示例: ./camera_setup.sh 92281 --pixel_format RGB8 --throughput 450000000 --exposure 750000.0 --width 4512 --height 4512
# 示例: ./camera_setup.sh 92281 --color_transform_enable 1

# 默认值
PIXEL_FORMAT="RGB8"
THROUGHPUT=450000000
EXPOSURE=240000.0
WIDTH=4512
HEIGHT=4512
COLOR_TRANSFORM_ENABLE=0

# 默认 CCM 矩阵值 (从 ColorChecker 标定得到的值)

CCM_MATRIX="0.57124758,-0.03391772,0.028312,-0.16821853,0.41293778,-0.12434534,0.22085547,0.11828595,0.48033197"

# 解析参数
CAMERA_PID=""

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
        --color_transform_enable)
            COLOR_TRANSFORM_ENABLE="$2"
            shift 2
            ;;
        --ccm)
            CCM_MATRIX="$2"
            shift 2
            ;;
        *)
            CAMERA_PID="$1"
            shift
            ;;
    esac
done

# 检查 camera_pid 是否提供
if [ -z "$CAMERA_PID" ]; then
    echo "错误: 请提供 camera_pid"
    echo "用法: $0 <camera_pid> [--pixel_format <format>] [--throughput <value>] [--exposure <value>] [--width <value>] [--height <value>] [--color_transform_enable <0|1>] [--ccm <r0c0,r0c1,r0c2,r1c0,r1c1,r1c2,r2c0,r2c1,r2c2>]"
    exit 1
fi

SERVICE_PREFIX="/vimbax_camera_${CAMERA_PID}/features"

echo "正在设置相机参数 (PID: ${CAMERA_PID})..."
echo "--------------------------------------------"

# 1. 设置 PixelFormat
echo "1. 设置 PixelFormat = ${PIXEL_FORMAT}"
ros2 service call ${SERVICE_PREFIX}/enum_set vimbax_camera_msgs/srv/FeatureEnumSet "{feature_name: 'PixelFormat', feature_module: {id: 0}, value: '${PIXEL_FORMAT}'}"

# 2. 设置 DeviceLinkThroughputLimit
echo "2. 设置 DeviceLinkThroughputLimit = ${THROUGHPUT}"
ros2 service call ${SERVICE_PREFIX}/int_set vimbax_camera_msgs/srv/FeatureIntSet "{feature_name: 'DeviceLinkThroughputLimit', feature_module: {id: 0}, value: ${THROUGHPUT}}"

# 3. 设置 ExposureTime
echo "3. 设置 ExposureTime = ${EXPOSURE}"
ros2 service call ${SERVICE_PREFIX}/float_set vimbax_camera_msgs/srv/FeatureFloatSet "{feature_name: 'ExposureTime', feature_module: {id: 0}, value: ${EXPOSURE}}"

# 4. 设置 Width
echo "4. 设置 Width = ${WIDTH}"
ros2 service call ${SERVICE_PREFIX}/int_set vimbax_camera_msgs/srv/FeatureIntSet "{feature_name: 'Width', feature_module: {id: 0}, value: ${WIDTH}}"

# 5. 设置 Height
echo "5. 设置 Height = ${HEIGHT}"
ros2 service call ${SERVICE_PREFIX}/int_set vimbax_camera_msgs/srv/FeatureIntSet "{feature_name: 'Height', feature_module: {id: 0}, value: ${HEIGHT}}"


echo "--------------------------------------------"
echo "相机参数设置完成!"
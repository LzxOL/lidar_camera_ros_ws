# Copyright (c) 2024 Allied Vision Technologies. All rights reserved.
# 基于 camera_setup.sh 默认参数的相机启动文件

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    # 相机ID（可选，不指定则自动选择第一个相机）
    camera_id_arg = DeclareLaunchArgument(
        'camera_id',
        default_value='',
        description='相机设备ID，如 DEV_1AB22C049FF1'
    )

    # 像素格式
    pixel_format_arg = DeclareLaunchArgument(
        'pixel_format',
        default_value='Mono8',
        description='像素格式，如 Mono8, RGB8'
    )

    # 分辨率
    width_arg = DeclareLaunchArgument(
        'width',
        default_value='4512',
        description='图像宽度'
    )

    height_arg = DeclareLaunchArgument(
        'height',
        default_value='4512',
        description='图像高度'
    )

    # 曝光时间（微秒）
    exposure_arg = DeclareLaunchArgument(
        'exposure',
        default_value='350000.0',
        description='曝光时间（微秒）'
    )

    # 吞吐量限制
    throughput_arg = DeclareLaunchArgument(
        'throughput',
        default_value='450000000',
        description='设备链路吞吐量限制'
    )

    return LaunchDescription([
        camera_id_arg,
        pixel_format_arg,
        width_arg,
        height_arg,
        exposure_arg,
        throughput_arg,

        Node(
            package='vimbax_camera',
            namespace='vimbax_camera',
            executable='vimbax_camera_node',
            name='vimbax_camera_node',
            parameters=[{
                # 相机ID（留空则自动选择第一个相机）
                'camera_id': LaunchConfiguration('camera_id'),

                # 自动开始/停止流
                'autostream': 1,

                # 相机参数配置文件
                'settings_file': '/home/root1/lzx_ws/project/lidar_camera_ros_ws/config/camera_settings.xml',

                # 覆盖配置文件中的参数（可选）
                # 'pixel_format': LaunchConfiguration('pixel_format'),
                # 'width': LaunchConfiguration('width'),
                # 'height': LaunchConfiguration('height'),
                # 'exposure_time': LaunchConfiguration('exposure'),
                # 'device_link_throughput_limit': LaunchConfiguration('throughput'),
            }],
            output='screen',
        )
    ])

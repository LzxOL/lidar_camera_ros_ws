#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Dual Camera Stream Launch 文件 - 仅启动左右两个相机推流，支持指定 topic 名称

用法:
    ros2 launch vimbax_camera dual_camera_stream_launch.py
    ros2 launch vimbax_camera dual_camera_stream_launch.py left_topic:=left_image right_topic:=right_image

参数:
    left_serial:       左相机序列号 (默认 03R47)
    right_serial:      右相机序列号 (默认 06HV5)
    left_topic:        左相机 topic 命名空间前缀 (默认 vimbax_camera_left)
    right_topic:       右相机 topic 命名空间前缀 (默认 vimbax_camera_right)
    pixel_format:      像素格式 (默认 Mono8)
    throughput:        设备链路吞吐量限制 (默认 450000000)
    exposure:          曝光时间，微秒 (默认 600000.0)
    width:             图像宽度 (默认 4512)
    height:            图像高度 (默认 4512)
    settings_file:     相机配置文件路径
    autostream:        启动后自动推流 (默认 1)

注意: 时间戳同步请使用独立的 launch 文件:
    ros2 launch vimbax_camera camera_timestamp_sync_launch.py
"""

from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    TimerAction,
    ExecuteProcess,
    OpaqueFunction,
    RegisterEventHandler,
)
from launch.event_handlers import OnProcessExit
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os


def _detect_allied_vision_serials():
    """
    通过 sysfs 检测 Allied Vision(USB vendor=1ab2) 设备序列号列表。
    返回: set(str)
    """
    serials = set()
    base = "/sys/bus/usb/devices"
    try:
        for name in os.listdir(base):
            dev = os.path.join(base, name)
            id_vendor = os.path.join(dev, "idVendor")
            serial = os.path.join(dev, "serial")
            if not os.path.isfile(id_vendor):
                continue
            try:
                with open(id_vendor, "r") as f:
                    vendor = f.read().strip().lower()
                if vendor != "1ab2":
                    continue
                if os.path.isfile(serial):
                    with open(serial, "r") as f:
                        s = f.read().strip()
                    if s:
                        serials.add(s)
            except Exception:
                continue
    except Exception:
        pass
    return serials


def _make_camera_actions(*, role: str, camera_id: str, pixel_format: str, throughput: str,
                         exposure: str, width: str, height: str, settings_file: str,
                         autostream: str, use_shm_gps_time: str):
    """
    为 left/right 角色生成 Node + 参数设置 TimerAction 列表。
    role: "left" or "right"
    camera_id: 可用序列号/extended id/cameraIdString
    autostream: 1=自动推流, 0=手动控制
    use_shm_gps_time: 是否从共享内存读取雷达 GPS 时间戳作为图像 header.stamp

    每个服务命令都等待前一个命令退出后才执行。不能依赖固定时间点，
    因为节点服务延迟就绪时会让多个固定 TimerAction 同时发起请求。
    """
    namespace = f"vimbax_camera_{role}"
    stream_prefix = f"/{namespace}"

    vimbax_camera_node = Node(
        package='vimbax_camera',
        executable='vimbax_camera_node',
        name='vimbax_camera_node',
        namespace=namespace,
        parameters=[{
            'camera_id': camera_id,
            'autostream': int(autostream),
            'settings_file': settings_file,
            'use_shared_memory_gps_time': use_shm_gps_time == 'true',
        }],
        output='screen',
    )

    stream_stop_cmd = ExecuteProcess(
        cmd=['ros2', 'service', 'call',
             f'{stream_prefix}/stream_stop',
             'vimbax_camera_msgs/srv/StreamStartStop', '{}'],
        shell=False,
        output='screen'
    )

    stream_start_cmd = ExecuteProcess(
        cmd=['ros2', 'service', 'call',
             f'{stream_prefix}/stream_start',
             'vimbax_camera_msgs/srv/StreamStartStop', '{}'],
        shell=False,
        output='screen'
    )

    def _enum_set(feature_name, value):
        return ExecuteProcess(
            cmd=['ros2', 'service', 'call',
                 f'{namespace}/features/enum_set',
                 'vimbax_camera_msgs/srv/FeatureEnumSet',
                 f'{{feature_name: {feature_name}, feature_module: {{id: 0}}, value: \'{value}\'}}'],
            shell=False,
            output='screen'
        )

    def _int_set(feature_name, value):
        return ExecuteProcess(
            cmd=['ros2', 'service', 'call',
                 f'{namespace}/features/int_set',
                 'vimbax_camera_msgs/srv/FeatureIntSet',
                 f'{{feature_name: {feature_name}, feature_module: {{id: 0}}, value: {value}}}'],
            shell=False,
            output='screen'
        )

    def _float_set(feature_name, value):
        return ExecuteProcess(
            cmd=['ros2', 'service', 'call',
                 f'{namespace}/features/float_set',
                 'vimbax_camera_msgs/srv/FeatureFloatSet',
                 f'{{feature_name: {feature_name}, feature_module: {{id: 0}}, value: {value}}}'],
            shell=False,
            output='screen'
        )

    def _command_run(feature_name):
        return ExecuteProcess(
            cmd=['ros2', 'service', 'call',
                 f'{namespace}/features/command_run',
                 'vimbax_camera_msgs/srv/FeatureCommandRun',
                 f'{{feature_name: {feature_name}, feature_module: {{id: 0}}}}'],
            shell=False,
            output='screen'
        )

    sequence = [
        _command_run('AcquisitionStop'),
        stream_stop_cmd,
        _enum_set('PixelFormat', pixel_format),
        _int_set('DeviceLinkThroughputLimit', throughput),
        _float_set('ExposureTime', exposure),
        _int_set('Width', width),
        _int_set('Height', height),
    ]
    if autostream == '0':
        sequence.append(stream_start_cmd)

    actions = [
        vimbax_camera_node,
        # 首条命令等待服务出现；后续命令由退出事件严格串接。
        TimerAction(period=2.0, actions=[sequence[0]]),
    ]
    for previous, following in zip(sequence, sequence[1:]):
        actions.append(RegisterEventHandler(
            OnProcessExit(
                target_action=previous,
                on_exit=[TimerAction(period=0.3, actions=[following])],
            )
        ))

    return actions


def launch_setup(context, *args, **kwargs):
    left_serial    = LaunchConfiguration('left_serial').perform(context)
    right_serial   = LaunchConfiguration('right_serial').perform(context)
    left_topic     = LaunchConfiguration('left_topic').perform(context)
    right_topic    = LaunchConfiguration('right_topic').perform(context)
    pixel_format   = LaunchConfiguration('pixel_format').perform(context)
    throughput     = LaunchConfiguration('device_throughput_limit').perform(context)
    exposure       = LaunchConfiguration('exposure_time').perform(context)
    width          = LaunchConfiguration('width').perform(context)
    height         = LaunchConfiguration('height').perform(context)
    settings_file  = LaunchConfiguration('settings_file').perform(context)
    autostream     = LaunchConfiguration('autostream').perform(context)
    use_shm_gps_time = LaunchConfiguration('use_shared_memory_gps_time').perform(context)

    connected_serials = _detect_allied_vision_serials()
    requested = [
        ("left", left_serial, left_topic),
        ("right", right_serial, right_topic),
    ]
    missing = [
        f"{role}_serial={serial}"
        for role, serial, topic in requested
        if topic and serial and serial not in connected_serials
    ]
    if missing:
        print(
            f"[dual_camera_stream_launch] Required camera not found: {', '.join(missing)}. "
            f"Connected Allied Vision serials={sorted(connected_serials)}."
        )
        return []

    actions = []

    if left_topic and left_serial and left_serial in connected_serials:
        role = left_topic.replace('vimbax_camera_', '') if left_topic.startswith('vimbax_camera_') else left_topic
        actions += _make_camera_actions(
            role=role,
            camera_id=left_serial,
            pixel_format=pixel_format,
            throughput=throughput,
            exposure=exposure,
            width=width,
            height=height,
            settings_file=settings_file,
            autostream=autostream,
            use_shm_gps_time=use_shm_gps_time,
        )

    if right_topic and right_serial and right_serial in connected_serials:
        role = right_topic.replace('vimbax_camera_', '') if right_topic.startswith('vimbax_camera_') else right_topic
        actions += _make_camera_actions(
            role=role,
            camera_id=right_serial,
            pixel_format=pixel_format,
            throughput=throughput,
            exposure=exposure,
            width=width,
            height=height,
            settings_file=settings_file,
            autostream=autostream,
            use_shm_gps_time=use_shm_gps_time,
        )

    if not actions:
        print(
            f"[dual_camera_stream_launch] No mapped camera found. "
            f"Connected serials={sorted(list(connected_serials))}, "
            f"left_serial={left_serial}, right_serial={right_serial}. "
            f"Please update left_serial/right_serial to match your camera serials."
        )

    return actions


def generate_launch_description():
    declared_arguments = [
        DeclareLaunchArgument(
            'left_serial',
            default_value='03R47',
            description='Left camera serial number'
        ),
        DeclareLaunchArgument(
            'right_serial',
            default_value='06HV5',
            description='Right camera serial number'
        ),
        DeclareLaunchArgument(
            'left_topic',
            default_value='vimbax_camera_left',
            description='Left camera topic namespace prefix (e.g., vimbax_camera_left)'
        ),
        DeclareLaunchArgument(
            'right_topic',
            default_value='vimbax_camera_right',
            description='Right camera topic namespace prefix (e.g., vimbax_camera_right)'
        ),
        DeclareLaunchArgument(
            'pixel_format',
            default_value='Mono8',
            description='Pixel format for the camera (e.g., BayerRG8, RGB8, Mono8)'
        ),
        DeclareLaunchArgument(
            'device_throughput_limit',
            default_value='450000000',
            description='Device link throughput limit in bits/s'
        ),
        DeclareLaunchArgument(
            'exposure_time',
            default_value='600000.0',
            description='Exposure time in microseconds'
        ),
        DeclareLaunchArgument(
            'width',
            default_value='4512',
            description='Image width in pixels'
        ),
        DeclareLaunchArgument(
            'height',
            default_value='4512',
            description='Image height in pixels'
        ),
        DeclareLaunchArgument(
            'settings_file',
            default_value='/home/root1/lzx_ws/project/lidar_camera_ros_ws/config/camera_settings.xml',
            description='Path to camera settings XML file'
        ),
        DeclareLaunchArgument(
            'autostream',
            default_value='0',
            description='Auto start streaming after node launch (0=manual, 1=auto)'
        ),
        DeclareLaunchArgument(
            'use_shared_memory_gps_time',
            default_value='false',
            description='Read LiDAR GPS timestamp from /dev/shm/rslidar_gps_timestamp and use it as '
                        'image header.stamp instead of camera local timestamp. '
                        'Requires radar running with use_lidar_clock=true. '
                        'Camera must be hardware-triggered by same PPS source as LiDAR.'
        ),
    ]

    return LaunchDescription(declared_arguments + [OpaqueFunction(function=launch_setup)])

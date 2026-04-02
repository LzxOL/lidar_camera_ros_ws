#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
VimbaX Camera Launch 文件 - 支持运行时参数配置

用法:
    ros2 launch vimbax_camera vimbax_camera_param_launch.py
    ros2 launch vimbax_camera vimbax_camera_param_launch.py color_correct:=true
    ros2 launch vimbax_camera vimbax_camera_param_launch.py color_correct:=false

参数:
    camera_id: 相机ID (如 92281)
    left_serial/right_serial: 左右相机的序列号(用于自动识别)
    color_correct:          是否同时启动颜色校正节点 (默认 true)
    use_cpp_node:          颜色校正使用 C++ 高性能版本 (默认 true, false=Python版)
    pixel_format: 像素格式 (默认 RGB8)
    throughput: 设备链路吞吐量限制 (默认 450000000)
    exposure: 曝光时间，微秒 (默认 600000.0)
    width: 图像宽度 (默认 4512)
    height: 图像高度 (默认 4512)
    settings_file: 相机配置文件路径
    lut_size:           LUT 维度 (默认 33)
    num_threads:        颜色校正线程数 0=auto (默认 0)
    enable_color_correction: 启用颜色校正 (默认 true)
    verbose:            详细日志 (默认 false)
    input_encoding:     输入图像编码 (默认 rgb8)
    output_encoding:    输出图像编码 (默认 rgb8)
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction, ExecuteProcess, OpaqueFunction, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
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
                         use_shm_gps_time: str):
    """
    为 left/right 角色生成 Node + 参数设置 TimerAction 列表。
    role: "left" or "right"
    camera_id: 可用序列号/extended id/cameraIdString
    use_shm_gps_time: 是否从共享内存读取雷达 GPS 时间戳作为图像 header.stamp

    流程（参考 dual_camera_setup.sh 成功模式）：
      t=0    : 启动 vimbax_camera_node (autostream=0, 不自动推流)
      t=1.5  : 等待节点初始化完成
      t=2.0  : AcquisitionStop      （停止采集）
      t=2.3  : stream_stop          （停止推流）
      t=2.8  : set PixelFormat      （设置像素格式）
      t=2.9  : set DeviceLinkThroughputLimit
      t=3.0  : set ExposureTime
      t=3.1  : set Width
      t=3.2  : set Height
      t=3.5  : stream_start         （启动推流）
    """
    namespace = f"vimbax_camera_{role}"
    stream_prefix = f"/{namespace}"          # stream_* 服务在节点 namespace 下

    # 注意：autostream 固定为 0，改为在参数设完后显式调用 stream_start
    vimbax_camera_node = Node(
        package='vimbax_camera',
        executable='vimbax_camera_node',
        name='vimbax_camera_node',
        namespace=namespace,
        parameters=[{
            'camera_id': camera_id,
            'autostream': 0,                 # 先不自动推流，等参数设完再开
            'settings_file': settings_file,
            'use_shared_memory_gps_time': use_shm_gps_time == 'true',
        }],
        output='screen',
    )

    # ---- 流控制 ----
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

    # ---- 参数设置（FeatureEnum / FeatureInt / FeatureFloat）----
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

    return [
        vimbax_camera_node,

        # 1. 等待节点初始化完成（约1.5秒）
        TimerAction(period=1.5, actions=[]),

        # 2. 先停止采集（与 dual_camera_setup.sh 一致）
        TimerAction(period=2.0, actions=[_command_run('AcquisitionStop')]),

        # 3. 等待0.3秒后停止推流（与脚本 sleep 0.3 一致）
        TimerAction(period=2.3, actions=[stream_stop_cmd]),

        # 4. 等待0.5秒后设置参数（与脚本 sleep 0.3+0.2 一致）
        TimerAction(period=2.8, actions=[_enum_set('PixelFormat', pixel_format)]),

        # 5. 设 DeviceLinkThroughputLimit
        TimerAction(period=2.9, actions=[_int_set('DeviceLinkThroughputLimit', throughput)]),

        # 6. 设 ExposureTime
        TimerAction(period=3.0, actions=[_float_set('ExposureTime', exposure)]),

        # 7. 设 Width
        TimerAction(period=3.1, actions=[_int_set('Width', width)]),

        # 8. 设 Height
        TimerAction(period=3.2, actions=[_int_set('Height', height)]),

        # 9. 启动推流
        TimerAction(period=3.5, actions=[stream_start_cmd]),
    ]


def _get_cc_launch_file(use_cpp: bool) -> str:
    """
    获取颜色校正 launch 文件的绝对路径。

    __file__ 解析为 install/vimbax_camera/share/vimbax_camera/launch/xxx.py
    目录结构:
      <ws>/install/vimbax_camera/           <- level4
      <ws>/install/                        <- level5 = workspace root
    """
    this_file = os.path.abspath(__file__)
    # level4: install/vimbax_camera
    level4 = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(this_file))))
    # level5: <workspace_root>/install/
    workspace_install = os.path.dirname(level4)

    def _try(ws_base: str) -> str:
        if use_cpp:
            return os.path.join(
                ws_base, 'vimbax_camera_color_correction_cpp', 'share',
                'vimbax_camera_color_correction_cpp', 'launch',
                'color_correction.launch.py'
            )
        else:
            return os.path.join(
                ws_base, 'vimbax_camera_color_correction', 'share',
                'vimbax_camera_color_correction', 'launch',
                'color_correction.launch.py'
            )

    # 优先从 install/ 空间查找（正常运行路径）
    install_path = _try(workspace_install)
    if os.path.exists(install_path):
        return install_path

    # 回退到 src/ 空间（开发时直接运行源码）
    src_path = _try(os.path.join(workspace_install, 'src'))
    return src_path


def launch_setup(context, *args, **kwargs):
    # 获取参数值
    camera_id        = LaunchConfiguration('camera_id').perform(context)
    left_serial      = LaunchConfiguration('left_serial').perform(context)
    right_serial     = LaunchConfiguration('right_serial').perform(context)
    color_correct    = LaunchConfiguration('color_correct').perform(context)
    use_cpp_node     = LaunchConfiguration('use_cpp_node').perform(context)
    pixel_format     = LaunchConfiguration('pixel_format').perform(context)
    throughput       = LaunchConfiguration('device_throughput_limit').perform(context)
    exposure         = LaunchConfiguration('exposure_time').perform(context)
    width            = LaunchConfiguration('width').perform(context)
    height           = LaunchConfiguration('height').perform(context)
    settings_file    = LaunchConfiguration('settings_file').perform(context)
    lut_size         = LaunchConfiguration('lut_size').perform(context)
    num_threads      = LaunchConfiguration('num_threads').perform(context)
    enable_cc        = LaunchConfiguration('enable_color_correction').perform(context)
    verbose          = LaunchConfiguration('verbose').perform(context)
    in_enc           = LaunchConfiguration('input_encoding').perform(context)
    out_enc          = LaunchConfiguration('output_encoding').perform(context)
    use_shm_gps_time = LaunchConfiguration('use_shared_memory_gps_time').perform(context)

    actions = []

    # -------------------------------------------------------------------------
    # 1. 相机节点（全部相机启动完成后推流，颜色校正在相机之后启动）
    # -------------------------------------------------------------------------
    # 兼容旧行为：如果显式传了 camera_id，只启动一个相机，namespace 仍按原逻辑 vimbax_camera_{camera_id}
    if camera_id:
        namespace = f'vimbax_camera_{camera_id}'

        vimbax_camera_node = Node(
            package='vimbax_camera',
            executable='vimbax_camera_node',
            name='vimbax_camera_node',
            namespace=namespace,
            parameters=[{
                'camera_id': camera_id,
                'autostream': 0,                 # 先停流，设完参数再开
                'settings_file': settings_file,
                'use_shared_memory_gps_time': use_shm_gps_time == 'true',
            }],
            output='screen',
        )

        def _enum_set(feature_name, value):
            return ExecuteProcess(
                cmd=['ros2', 'service', 'call',
                     f'{namespace}/features/enum_set',
                     'vimbax_camera_msgs/srv/FeatureEnumSet',
                     f'{{feature_name: {feature_name}, feature_module: {{id: 0}}, value: \'{value}\'}}'],
                shell=False, output='screen'
            )

        def _int_set(feature_name, value):
            return ExecuteProcess(
                cmd=['ros2', 'service', 'call',
                     f'{namespace}/features/int_set',
                     'vimbax_camera_msgs/srv/FeatureIntSet',
                     f'{{feature_name: {feature_name}, feature_module: {{id: 0}}, value: {value}}}'],
                shell=False, output='screen'
            )

        def _float_set(feature_name, value):
            return ExecuteProcess(
                cmd=['ros2', 'service', 'call',
                     f'{namespace}/features/float_set',
                     'vimbax_camera_msgs/srv/FeatureFloatSet',
                     f'{{feature_name: {feature_name}, feature_module: {{id: 0}}, value: {value}}}'],
                shell=False, output='screen'
            )

        def _command_run(feature_name):
            return ExecuteProcess(
                cmd=['ros2', 'service', 'call',
                     f'{namespace}/features/command_run',
                     'vimbax_camera_msgs/srv/FeatureCommandRun',
                     f'{{feature_name: {feature_name}, feature_module: {{id: 0}}}}'],
                shell=False, output='screen'
            )

        actions += [
            vimbax_camera_node,
            # 1. 等待节点初始化完成
            TimerAction(period=1.5, actions=[]),
            # 2. 先停止采集
            TimerAction(period=2.0, actions=[
                _command_run('AcquisitionStop'),
            ]),
            # 3. 等待后停止推流
            TimerAction(period=2.3, actions=[
                ExecuteProcess(cmd=['ros2', 'service', 'call',
                     f'{namespace}/stream_stop',
                     'vimbax_camera_msgs/srv/StreamStartStop', '{}'],
                    shell=False, output='screen')
            ]),
            # 4. 设置参数
            TimerAction(period=2.8, actions=[_enum_set('PixelFormat', pixel_format)]),
            TimerAction(period=2.9, actions=[_int_set('DeviceLinkThroughputLimit', throughput)]),
            TimerAction(period=3.0, actions=[_float_set('ExposureTime', exposure)]),
            TimerAction(period=3.1, actions=[_int_set('Width', width)]),
            TimerAction(period=3.2, actions=[_int_set('Height', height)]),
            # 5. 启动推流
            TimerAction(period=3.5, actions=[
                ExecuteProcess(cmd=['ros2', 'service', 'call',
                     f'{namespace}/stream_start',
                     'vimbax_camera_msgs/srv/StreamStartStop', '{}'],
                    shell=False, output='screen')
            ]),
        ]

    # 新行为：未传 camera_id 时，自动识别 left/right（按序列号）
    connected_serials = _detect_allied_vision_serials()

    if not camera_id:
        if left_serial and left_serial in connected_serials:
            actions += _make_camera_actions(
                role="left",
                camera_id=left_serial,
                pixel_format=pixel_format,
                throughput=throughput,
                exposure=exposure,
                width=width,
                height=height,
                settings_file=settings_file,
                use_shm_gps_time=use_shm_gps_time,
            )

        if right_serial and right_serial in connected_serials:
            actions += _make_camera_actions(
                role="right",
                camera_id=right_serial,
                pixel_format=pixel_format,
                throughput=throughput,
                exposure=exposure,
                width=width,
                height=height,
                settings_file=settings_file,
                use_shm_gps_time=use_shm_gps_time,
            )

    # -------------------------------------------------------------------------
    # 2. 颜色校正节点（color_correct==true 时嵌入，在相机启动后运行）
    # -------------------------------------------------------------------------
    if color_correct == 'true':
        cc_launch_path = _get_cc_launch_file(use_cpp_node == 'true')
        if os.path.exists(cc_launch_path):
            cc_ld = IncludeLaunchDescription(
                PythonLaunchDescriptionSource(cc_launch_path),
                launch_arguments={
                    'left_serial':               left_serial,
                    'right_serial':              right_serial,
                    'lut_size':                 lut_size,
                    'num_threads':              num_threads,
                    'enable_color_correction':  enable_cc,
                    'verbose':                  verbose,
                    'input_encoding':            in_enc,
                    'output_encoding':           out_enc,
                }.items()
            )
            # 相机 t=7.5s 开始推流，颜色校正节点在 t=8.5s 启动（确保相机已就绪）
            actions.append(TimerAction(period=12.0, actions=[cc_ld]))
        else:
            print(f"[vimbax_camera_param_launch] WARNING: color correction launch not found: {cc_launch_path}")
            print(f"[vimbax_camera_param_launch] Di d you build vimbax_camera_color_correction(_cpp)?")

    # 若只插了一个相机，但序列号不在 left/right 映射里：为了安全，不自动启动，提示用户显式指定
    if not actions:
        print(
            f"[vimbax_camera_param_launch] No mapped camera found. "
            f"Connected serials={sorted(list(connected_serials))}, "
            f"left_serial={left_serial}, right_serial={right_serial}. "
            f"Please pass camera_id:=<serial/extended-id> or update left_serial/right_serial."
        )

    return actions


def generate_launch_description():
    # 声明 launch 参数
    declared_arguments = [
        DeclareLaunchArgument(
            'camera_id',
            default_value='',
            description='Camera ID (PID). If empty, will auto-detect left/right cameras by serial.'
        ),
        DeclareLaunchArgument(
            'left_serial',
            default_value='03R47',
            description='Left camera serial number (used for auto left/right detection)'
        ),
        DeclareLaunchArgument(
            'right_serial',
            default_value='06HV5',
            description='Right camera serial number (used for auto left/right detection)'
        ),
        # ---- 颜色校正控制 ----
        DeclareLaunchArgument(
            'color_correct',
            default_value='true',
            description='Set to true to also launch color correction nodes after cameras start.'
        ),
        DeclareLaunchArgument(
            'use_cpp_node',
            default_value='true',
            description='Use C++ high-performance color correction node (true=C++, false=Python).'
        ),
        # ---- 相机参数 ----
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
        # ---- 颜色校正参数（透传到 color_correction launch）----
        DeclareLaunchArgument(
            'lut_size',
            default_value='33',
            description='3D LUT dimension size (typically 17, 33, or 65)'
        ),
        DeclareLaunchArgument(
            'num_threads',
            default_value='0',
            description='Number of threads for parallel processing (0 = auto)'
        ),
        DeclareLaunchArgument(
            'enable_color_correction',
            default_value='true',
            description='Enable color correction in the color correction node'
        ),
        DeclareLaunchArgument(
            'verbose',
            default_value='false',
            description='Enable verbose logging in the color correction node'
        ),
        DeclareLaunchArgument(
            'input_encoding',
            default_value='rgb8',
            description='Input image encoding (rgb8 or bgr8)'
        ),
        DeclareLaunchArgument(
            'output_encoding',
            default_value='rgb8',
            description='Output image encoding (rgb8 or bgr8)'
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

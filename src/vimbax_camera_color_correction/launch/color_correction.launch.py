#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Color Correction Python Node Launch 文件 - 支持 left/right 双相机自动识别

用法:
    ros2 launch vimbax_camera_color_correction color_correction.launch.py

自动检测已连接的 Allied Vision 相机，按 left_serial/right_serial 映射启动对应的
颜色校正节点（1~2 个）。每个节点使用对应的 LUT 文件:
    left  -> color_correction_lut_left.npy / .bin
    right -> color_correction_lut_right.npy / .bin

参数:
    left_serial/right_serial:   左右相机序列号 (默认 03R47/06HV5)
    lut_size:                   LUT 维度大小 (默认 33)
    use_lut:                    是否使用 LUT (默认 true)
    show_debug_image:           显示调试图像 (默认 false)
    output_encoding:             输出图像编码 (默认 rgb8)
    auto_detect_colorchecker:   自动检测 ColorChecker (默认 false)

输出话题:
    左相机: /color_corrected_left/image_raw
    右相机: /color_corrected_right/image_raw
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os


def _detect_allied_vision_serials():
    """
    通过 sysfs 检测 Allied Vision (USB vendor=1ab2) 设备序列号列表。
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


def _make_cc_node(*, role: str, lut_file: str, lut_binary_file: str,
                  lut_size: str, use_lut: str, show_debug: str,
                  output_encoding: str, auto_detect: str):
    """
    为 left/right 角色生成一个 Python 版 ColorCorrectionNode。

    话题映射（与 vimbax_camera_param_launch.py 的 namespace 保持一致）:
        输入:   /vimbax_camera_{role}/image_raw
                /vimbax_camera_{role}/camera_info
        输出:   /color_corrected_{role}/image_raw
                /color_corrected_{role}/camera_info
    """
    camera_ns = f"vimbax_camera_{role}"
    output_ns = f"color_corrected_{role}"

    return Node(
        package='vimbax_camera_color_correction',
        executable='color_correction_node',
        name=f'color_correction_{role}',
        namespace=output_ns,
        parameters=[{
            # ---- 话题映射 ----
            'input_topic':           f'/{camera_ns}/image_raw',
            'output_topic':          'image_raw',
            'camera_info_topic':     f'/{camera_ns}/camera_info',
            # ---- 文件路径 ----
            'ccm_file':              '',
            'lut_file':              lut_file,
            'lut_binary_file':      lut_binary_file,
            'lut_size':              int(lut_size),
            # ---- 行为开关 ----
            'use_lut':               use_lut == 'true',
            'auto_detect_colorchecker': False,
            'max_calibration_attempts': 1,
            'show_debug_image':      show_debug == 'true',
            # ---- 编码 ----
            'output_encoding':       output_encoding,
        }],
        output='screen',
    )


def launch_setup(context, *args, **kwargs):
    left_serial   = LaunchConfiguration('left_serial').perform(context)
    right_serial  = LaunchConfiguration('right_serial').perform(context)
    lut_size      = LaunchConfiguration('lut_size').perform(context)
    use_lut       = LaunchConfiguration('use_lut').perform(context)
    show_debug    = LaunchConfiguration('show_debug_image').perform(context)
    out_enc       = LaunchConfiguration('output_encoding').perform(context)
    auto_detect   = LaunchConfiguration('auto_detect_colorchecker').perform(context)

    base_dir = '/home/root1/lzx_ws/project/lidar_camera_ros_ws/config'

    connected = _detect_allied_vision_serials()
    actions = []

    if left_serial and left_serial in connected:
        actions.append(_make_cc_node(
            role="left",
            lut_file=os.path.join(base_dir, "color_correction_lut_left.npy"),
            lut_binary_file=os.path.join(base_dir, "color_correction_lut_left.bin"),
            lut_size=lut_size,
            use_lut=use_lut,
            show_debug=show_debug,
            output_encoding=out_enc,
            auto_detect=auto_detect,
        ))

    if right_serial and right_serial in connected:
        actions.append(_make_cc_node(
            role="right",
            lut_file=os.path.join(base_dir, "color_correction_lut_right.npy"),
            lut_binary_file=os.path.join(base_dir, "color_correction_lut_right.bin"),
            lut_size=lut_size,
            use_lut=use_lut,
            show_debug=show_debug,
            output_encoding=out_enc,
            auto_detect=auto_detect,
        ))

    if not actions:
        print(
            f"[color_correction.launch] No mapped camera found. "
            f"Connected serials={sorted(list(connected))}, "
            f"left_serial={left_serial}, right_serial={right_serial}. "
            f"Update left_serial/right_serial to match your camera serials."
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
            'lut_size',
            default_value='33',
            description='3D LUT dimension size (typically 17, 33, or 65)'
        ),
        DeclareLaunchArgument(
            'use_lut',
            default_value='true',
            description='Enable LUT-based color correction'
        ),
        DeclareLaunchArgument(
            'show_debug_image',
            default_value='false',
            description='Show debug image window (requires GUI)'
        ),
        DeclareLaunchArgument(
            'output_encoding',
            default_value='rgb8',
            description='Output image encoding (rgb8 or bgr8)'
        ),
        DeclareLaunchArgument(
            'auto_detect_colorchecker',
            default_value='false',
            description='Auto-detect ColorChecker for CCM calibration'
        ),
    ]

    return LaunchDescription(declared_arguments + [OpaqueFunction(function=launch_setup)])

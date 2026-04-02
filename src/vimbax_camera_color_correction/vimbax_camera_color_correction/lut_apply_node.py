#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import traceback

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image, CameraInfo
from std_msgs.msg import Bool, String
from cv_bridge import CvBridge

import cv2
import numpy as np


def apply_3d_lut(image_rgb_uint8, lut):
    """
    对 RGB uint8 图像应用 3D LUT（三线性插值）

    参数:
        image_rgb_uint8: H x W x 3, uint8, RGB
        lut: S x S x S x 3, float32/float64, range [0,1]

    返回:
        out_uint8: H x W x 3, uint8, RGB
    """
    img = image_rgb_uint8.astype(np.float32) / 255.0
    size = lut.shape[0]

    # 映射到 LUT 索引空间 [0, size-1]
    coords = img * (size - 1)

    r = coords[..., 0]
    g = coords[..., 1]
    b = coords[..., 2]

    r0 = np.floor(r).astype(np.int32)
    g0 = np.floor(g).astype(np.int32)
    b0 = np.floor(b).astype(np.int32)

    r1 = np.clip(r0 + 1, 0, size - 1)
    g1 = np.clip(g0 + 1, 0, size - 1)
    b1 = np.clip(b0 + 1, 0, size - 1)

    dr = (r - r0)[..., None]
    dg = (g - g0)[..., None]
    db = (b - b0)[..., None]

    c000 = lut[r0, g0, b0]
    c001 = lut[r0, g0, b1]
    c010 = lut[r0, g1, b0]
    c011 = lut[r0, g1, b1]
    c100 = lut[r1, g0, b0]
    c101 = lut[r1, g0, b1]
    c110 = lut[r1, g1, b0]
    c111 = lut[r1, g1, b1]

    c00 = c000 * (1.0 - db) + c001 * db
    c01 = c010 * (1.0 - db) + c011 * db
    c10 = c100 * (1.0 - db) + c101 * db
    c11 = c110 * (1.0 - db) + c111 * db

    c0 = c00 * (1.0 - dg) + c01 * dg
    c1 = c10 * (1.0 - dg) + c11 * dg

    out = c0 * (1.0 - dr) + c1 * dr
    out = np.clip(out * 255.0, 0, 255).astype(np.uint8)

    return out


class LutColorCorrectionNode(Node):
    """
    基于 3D LUT 的 ROS2 图像颜色校正节点

    功能:
    1. 订阅输入图像 topic
    2. 加载 .npy LUT 文件
    3. 对每帧图像应用 LUT 校正
    4. 发布校正后的图像
    5. 转发 camera_info
    """

    def __init__(self):
        super().__init__('lut_color_correction_node')

        # -----------------------------
        # Parameters
        # -----------------------------
        self.declare_parameter('input_topic', '/vimbax_camera_29036/image_raw')
        self.declare_parameter('output_topic', '/color_corrected/image_raw')
        self.declare_parameter('camera_info_topic', '/vimbax_camera_29036/camera_info')
        self.declare_parameter('output_camera_info_topic', '/color_corrected/camera_info')

        self.declare_parameter('input_encoding', 'rgb8')   # 输入图像编码
        self.declare_parameter('output_encoding', 'rgb8')  # 输出图像编码

        self.declare_parameter('lut_file', '/home/root1/lzx_ws/project/lidar_camera_ros_ws/config/color_correction_lut_left.npy')

        self.input_topic = self.get_parameter('input_topic').get_parameter_value().string_value
        self.output_topic = self.get_parameter('output_topic').get_parameter_value().string_value
        self.camera_info_topic = self.get_parameter('camera_info_topic').get_parameter_value().string_value
        self.output_camera_info_topic = self.get_parameter('output_camera_info_topic').get_parameter_value().string_value

        self.input_encoding = self.get_parameter('input_encoding').get_parameter_value().string_value
        self.output_encoding = self.get_parameter('output_encoding').get_parameter_value().string_value

        self.lut_file = self.get_parameter('lut_file').get_parameter_value().string_value

        # -----------------------------
        # Runtime
        # -----------------------------
        self.bridge = CvBridge()
        self.lut = None
        self.lut_enabled = False
        self.latest_camera_info = None

        # -----------------------------
        # Publishers
        # -----------------------------
        self.image_pub = self.create_publisher(Image, self.output_topic, 10)
        self.camera_info_pub = self.create_publisher(CameraInfo, self.output_camera_info_topic, 10)

        self.status_pub = self.create_publisher(Bool, '~/lut_loaded', 10)
        self.info_pub = self.create_publisher(String, '~/status', 10)

        # -----------------------------
        # Subscribers
        # -----------------------------
        self.image_sub = self.create_subscription(
            Image,
            self.input_topic,
            self.image_callback,
            10
        )

        self.camera_info_sub = self.create_subscription(
            CameraInfo,
            self.camera_info_topic,
            self.camera_info_callback,
            10
        )

        # 加载 LUT
        self.load_lut(self.lut_file)

        # 启动日志
        self.get_logger().info('LUT color correction node started')
        self.get_logger().info(f'Input topic: {self.input_topic}')
        self.get_logger().info(f'Output topic: {self.output_topic}')
        self.get_logger().info(f'CameraInfo in: {self.camera_info_topic}')
        self.get_logger().info(f'CameraInfo out: {self.output_camera_info_topic}')
        self.get_logger().info(f'Input encoding: {self.input_encoding}')
        self.get_logger().info(f'Output encoding: {self.output_encoding}')
        self.get_logger().info(f'LUT file: {self.lut_file}')

    def publish_status(self, ok: bool, text: str):
        msg_ok = Bool()
        msg_ok.data = ok
        self.status_pub.publish(msg_ok)

        msg_text = String()
        msg_text.data = text
        self.info_pub.publish(msg_text)

    def load_lut(self, lut_path: str):
        """
        加载 npy 格式的 3D LUT
        """
        try:
            if not lut_path:
                raise ValueError('lut_file is empty')

            if not os.path.exists(lut_path):
                raise FileNotFoundError(f'LUT file does not exist: {lut_path}')

            lut = np.load(lut_path)

            if lut.ndim != 4 or lut.shape[-1] != 3:
                raise ValueError(f'Invalid LUT shape: {lut.shape}, expected (size, size, size, 3)')

            if not (lut.shape[0] == lut.shape[1] == lut.shape[2]):
                raise ValueError(f'Invalid LUT shape: {lut.shape}, first 3 dims must be equal')

            self.lut = lut.astype(np.float32)
            self.lut_enabled = True

            self.get_logger().info(f'LUT loaded: {lut_path}')
            self.get_logger().info(f'LUT shape: {self.lut.shape}')
            self.get_logger().info(f'LUT min/max: {self.lut.min():.6f} / {self.lut.max():.6f}')

            self.publish_status(True, f'LUT loaded: {lut_path}')

        except Exception as e:
            self.lut = None
            self.lut_enabled = False
            self.get_logger().error(f'Failed to load LUT: {e}')
            traceback.print_exc()
            self.publish_status(False, f'Failed to load LUT: {e}')

    def apply_lut_to_bgr_image(self, image_bgr):
        """
        对 BGR 图像应用 LUT
        内部转换到 RGB，再应用 LUT，最后转回 BGR
        """
        if not self.lut_enabled or self.lut is None:
            return image_bgr

        try:
            image_rgb = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2RGB)
            corrected_rgb = apply_3d_lut(image_rgb, self.lut)
            corrected_bgr = cv2.cvtColor(corrected_rgb, cv2.COLOR_RGB2BGR)
            return corrected_bgr
        except Exception as e:
            self.get_logger().error(f'Error applying LUT: {e}')
            traceback.print_exc()
            return image_bgr

    def image_callback(self, msg: Image):
        """
        处理输入图像:
        - 读取 topic 图像
        - 应用 LUT
        - 发布输出图像
        """
        try:
            # 将 ROS 图像转换为 OpenCV 图像
            if self.input_encoding == 'rgb8':
                image_rgb = self.bridge.imgmsg_to_cv2(msg, 'rgb8')
                image_bgr = cv2.cvtColor(image_rgb, cv2.COLOR_RGB2BGR)
            elif self.input_encoding == 'bgr8':
                image_bgr = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
            else:
                image_any = self.bridge.imgmsg_to_cv2(msg, 'passthrough')
                enc = msg.encoding.lower()
                if enc == 'rgb8':
                    image_bgr = cv2.cvtColor(image_any, cv2.COLOR_RGB2BGR)
                elif enc == 'bgr8':
                    image_bgr = image_any
                else:
                    self.get_logger().error(f'Unsupported input encoding: {msg.encoding}')
                    return

            # 应用 LUT
            corrected_bgr = self.apply_lut_to_bgr_image(image_bgr)

            # 转回 ROS 图像
            if self.output_encoding == 'rgb8':
                corrected_rgb = cv2.cvtColor(corrected_bgr, cv2.COLOR_BGR2RGB)
                out_msg = self.bridge.cv2_to_imgmsg(corrected_rgb, encoding='rgb8')
            elif self.output_encoding == 'bgr8':
                out_msg = self.bridge.cv2_to_imgmsg(corrected_bgr, encoding='bgr8')
            else:
                self.get_logger().error(f'Unsupported output encoding: {self.output_encoding}')
                return

            out_msg.header = msg.header
            self.image_pub.publish(out_msg)

        except Exception as e:
            self.get_logger().error(f'Error processing image: {e}')
            traceback.print_exc()

    def camera_info_callback(self, msg: CameraInfo):
        """
        转发相机内参
        """
        self.latest_camera_info = msg
        self.camera_info_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = LutColorCorrectionNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
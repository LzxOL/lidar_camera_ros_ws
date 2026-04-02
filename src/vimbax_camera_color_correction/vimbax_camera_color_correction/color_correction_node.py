#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import json
import traceback

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image, CameraInfo
from std_msgs.msg import Float32MultiArray, Bool, String
from cv_bridge import CvBridge

import cv2
import numpy as np


def build_3d_lut_from_ccm_model(ccm_model, lut_size=33):
    """
    根据 OpenCV ColorCorrectionModel 采样生成 3D LUT

    参数:
        ccm_model: 已经 run() 过的 ColorCorrectionModel
        lut_size: LUT 尺寸，常用 17 / 33 / 65

    返回:
        lut: shape = (lut_size, lut_size, lut_size, 3), float32, range [0,1]
    """
    grid = np.linspace(0.0, 1.0, lut_size, dtype=np.float32)

    # RGB规则网格，保持 R,G,B 顺序
    rr, gg, bb = np.meshgrid(grid, grid, grid, indexing='ij')

    # 展平为 N x 3
    samples = np.stack([rr, gg, bb], axis=-1).reshape(-1, 3)

    # 转为 OpenCV infer 常用输入格式: (N,1,3)
    samples_img = samples.reshape((-1, 1, 3)).astype(np.float64)
    samples_img = np.ascontiguousarray(samples_img)

    corrected = ccm_model.infer(samples_img)
    corrected = np.asarray(corrected, dtype=np.float32).reshape(-1, 3)
    corrected = np.clip(corrected, 0.0, 1.0)

    lut = corrected.reshape(lut_size, lut_size, lut_size, 3)
    return lut


def apply_3d_lut(image_rgb_uint8, lut):
    """
    对 RGB uint8 图像应用 3D LUT（三线性插值）

    参数:
        image_rgb_uint8: H x W x 3, uint8, RGB
        lut: S x S x S x 3, float32, range [0,1]

    返回:
        out_uint8: H x W x 3, uint8, RGB
    """
    img = image_rgb_uint8.astype(np.float32) / 255.0
    size = lut.shape[0]

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


class ColorCorrectionNode(Node):
    """
    基于 OpenCV mcc + ccm + 3D LUT 的 ROS2 色彩校正节点

    流程:
    1. 订阅图像
    2. 自动检测 ColorChecker
    3. 用 OpenCV ColorCorrectionModel 标定
    4. 从模型采样生成 3D LUT
    5. 保存 LUT 到 .npy
    6. 后续每帧仅用 LUT 做颜色校正

    说明:
    - 输入 topic 默认是 RGB
    - 节点内部会转为 BGR 供 OpenCV 检测使用
    - LUT 应用时在 RGB 空间完成
    - 输出默认仍为 RGB
    """

    def __init__(self):
        super().__init__('color_correction_node')

        # -----------------------------
        # Parameters
        # -----------------------------
        self.declare_parameter('input_topic', '/vimbax_camera_6615/image_raw')
        self.declare_parameter('output_topic', '/color_corrected/image_raw')
        self.declare_parameter('camera_info_topic', '/vimbax_camera_6615/camera_info')
        self.declare_parameter('output_camera_info_topic', '/color_corrected/camera_info')

        self.declare_parameter('input_encoding', 'rgb8')
        self.declare_parameter('output_encoding', 'rgb8')

        self.declare_parameter('auto_detect_colorchecker', True)
        self.declare_parameter('max_calibration_attempts', 100)
        self.declare_parameter('chart_type', 'MCC24')   # MCC24, DigitalSG, Vinyl
        self.declare_parameter('max_checkers', 1)

        self.declare_parameter('lut_size', 33)
        self.declare_parameter('lut_file', '/home/root1/lzx_ws/project/lidar_camera_ros_ws/config/color_correction_lut_left.npy')
        self.declare_parameter('lut_binary_file', '/home/root1/lzx_ws/project/lidar_camera_ros_ws/config/color_correction_lut_left.bin')
        self.declare_parameter('save_lut_after_calibration', True)
        self.declare_parameter('save_debug_image', False)
        self.declare_parameter('debug_image_path', '/tmp/colorchecker_detected.png')

        self.input_topic = self.get_parameter('input_topic').get_parameter_value().string_value
        self.output_topic = self.get_parameter('output_topic').get_parameter_value().string_value
        self.camera_info_topic = self.get_parameter('camera_info_topic').get_parameter_value().string_value
        self.output_camera_info_topic = self.get_parameter('output_camera_info_topic').get_parameter_value().string_value

        self.input_encoding = self.get_parameter('input_encoding').get_parameter_value().string_value
        self.output_encoding = self.get_parameter('output_encoding').get_parameter_value().string_value

        self.auto_detect = self.get_parameter('auto_detect_colorchecker').get_parameter_value().bool_value
        self.max_attempts = self.get_parameter('max_calibration_attempts').get_parameter_value().integer_value
        self.chart_type_name = self.get_parameter('chart_type').get_parameter_value().string_value
        self.max_checkers = self.get_parameter('max_checkers').get_parameter_value().integer_value

        self.lut_size = self.get_parameter('lut_size').get_parameter_value().integer_value
        self.lut_file = self.get_parameter('lut_file').get_parameter_value().string_value
        self.lut_binary_file = self.get_parameter('lut_binary_file').get_parameter_value().string_value
        self.save_lut_after_calibration = self.get_parameter('save_lut_after_calibration').get_parameter_value().bool_value
        self.save_debug_image = self.get_parameter('save_debug_image').get_parameter_value().bool_value
        self.debug_image_path = self.get_parameter('debug_image_path').get_parameter_value().string_value

        # -----------------------------
        # OpenCV chart types
        # -----------------------------
        self.chart_type = self._get_mcc_chart_type(self.chart_type_name)
        self.ccm_chart_type = self._get_ccm_chart_type(self.chart_type_name)

        # -----------------------------
        # Runtime states
        # -----------------------------
        self.bridge = CvBridge()

        self.ccm = None
        self.ccm_model = None
        self.lut = None
        self.lut_enabled = False

        self.calibration_done = False
        self.calibration_attempts = 0
        self.colorchecker_detected = False

        self.latest_image_bgr = None
        self.latest_image_header = None
        self.latest_camera_info = None

        # -----------------------------
        # Publishers
        # -----------------------------
        self.image_pub = self.create_publisher(Image, self.output_topic, 10)
        self.camera_info_pub = self.create_publisher(CameraInfo, self.output_camera_info_topic, 10)

        self.ccm_pub = self.create_publisher(Float32MultiArray, '~/ccm_matrix', 10)
        self.calibration_status_pub = self.create_publisher(Bool, '~/calibration_status', 10)
        self.detection_status_pub = self.create_publisher(String, '~/detection_status', 10)

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

        # 定时自动标定
        self.calibration_timer = self.create_timer(1.0, self.try_calibration)

        self.calibration_status = Bool()
        self.calibration_status.data = False

        self.detection_status = String()
        self.detection_status.data = 'Idle'

        # 如果提供了 lut_file，并且存在，则直接加载
        if self.lut_file and os.path.exists(self.lut_file):
            self.load_lut(self.lut_file)

        # 启动日志
        self.get_logger().info('Color correction node started (OpenCV mcc/ccm + 3D LUT)')
        self.get_logger().info(f'Input topic: {self.input_topic}')
        self.get_logger().info(f'Output topic: {self.output_topic}')
        self.get_logger().info(f'CameraInfo in: {self.camera_info_topic}')
        self.get_logger().info(f'CameraInfo out: {self.output_camera_info_topic}')
        self.get_logger().info(f'Input encoding: {self.input_encoding}')
        self.get_logger().info(f'Output encoding: {self.output_encoding}')
        self.get_logger().info(f'Auto detect ColorChecker: {self.auto_detect}')
        self.get_logger().info(f'Chart type: {self.chart_type_name}')
        self.get_logger().info(f'Max calibration attempts: {self.max_attempts}')
        self.get_logger().info(f'LUT size: {self.lut_size}')

        if self.lut is not None:
            self.get_logger().info(f'Loaded LUT from: {self.lut_file}')
            self.get_logger().info(f'LUT shape: {self.lut.shape}')

        self.publish_status()

    # ------------------------------------------------------------------
    # Type mapping
    # ------------------------------------------------------------------
    def _get_mcc_chart_type(self, name: str):
        if name == 'MCC24':
            return cv2.mcc.MCC24
        elif name == 'DigitalSG':
            return cv2.mcc.DigitalSG
        elif name == 'Vinyl':
            return cv2.mcc.Vinyl
        else:
            self.get_logger().warn(f'Unknown chart_type "{name}", fallback to MCC24')
            return cv2.mcc.MCC24

    def _get_ccm_chart_type(self, name: str):
        if name == 'MCC24':
            return cv2.ccm.COLORCHECKER_Macbeth
        elif name == 'DigitalSG':
            if hasattr(cv2.ccm, 'COLORCHECKER_DigitalSG'):
                return cv2.ccm.COLORCHECKER_DigitalSG
            self.get_logger().warn('OpenCV does not provide COLORCHECKER_DigitalSG, fallback to Macbeth')
            return cv2.ccm.COLORCHECKER_Macbeth
        elif name == 'Vinyl':
            if hasattr(cv2.ccm, 'COLORCHECKER_Vinyl'):
                return cv2.ccm.COLORCHECKER_Vinyl
            self.get_logger().warn('OpenCV does not provide COLORCHECKER_Vinyl, fallback to Macbeth')
            return cv2.ccm.COLORCHECKER_Macbeth
        else:
            self.get_logger().warn(f'Unknown ccm chart_type "{name}", fallback to Macbeth')
            return cv2.ccm.COLORCHECKER_Macbeth

    def _create_detector(self):
        if hasattr(cv2.mcc, 'CCheckerDetector_create'):
            return cv2.mcc.CCheckerDetector_create()
        elif hasattr(cv2.mcc, 'CCheckerDetector'):
            return cv2.mcc.CCheckerDetector.create()
        else:
            raise RuntimeError('OpenCV mcc detector API not found. Please check opencv-contrib-python installation.')

    # ------------------------------------------------------------------
    # Status / IO
    # ------------------------------------------------------------------
    def publish_status(self):
        self.calibration_status_pub.publish(self.calibration_status)
        self.detection_status_pub.publish(self.detection_status)

    def publish_ccm(self):
        if self.ccm is None:
            return

        msg = Float32MultiArray()
        msg.data = self.ccm.flatten().astype(np.float32).tolist()
        self.ccm_pub.publish(msg)

    def save_lut(self, filename: str):
        if self.lut is None:
            self.get_logger().warn('No LUT to save')
            return

        try:
            if filename:
                dir_path = os.path.dirname(filename)
                if dir_path:
                    os.makedirs(dir_path, exist_ok=True)
            np.save(filename, self.lut)
            self.get_logger().info(f'Saved LUT to: {filename}')

            if self.lut_binary_file:
                self.save_lut_binary(self.lut_binary_file)
        except Exception as e:
            self.get_logger().error(f'Failed to save LUT file: {e}')

    def save_lut_binary(self, filename: str):
        """
        保存 C++ 可快速读取的二进制 LUT 文件。

        文件格式（原始 float32 binary，无压缩）：
        [header: 4 bytes]  lut_size (int32, little-endian)
        [data: lut_size^3 * 3 * 4 bytes]  float32 array in RGB order (little-endian)

        C++ 读取方式:
            std::ifstream f(path, std::ios::binary);
            int32_t size; f.read(reinterpret_cast<char*>(&size), 4);
            std::vector<float> data(size * size * size * 3);
            f.read(reinterpret_cast<char*>(data.data()), data.size() * sizeof(float));
        """
        try:
            lut = self.lut
            size = lut.shape[0]

            # 确保 RGB 顺序
            data = np.ascontiguousarray(lut, dtype=np.float32)

            dir_path = os.path.dirname(filename)
            if dir_path:
                os.makedirs(dir_path, exist_ok=True)

            with open(filename, 'wb') as f:
                # 写入 header: lut_size (int32, little-endian)
                f.write(size.to_bytes(4, byteorder='little', signed=False))
                # 写入数据: float32 RGB (little-endian)
                f.write(data.tobytes())

            self.get_logger().info(f'Saved C++ binary LUT to: {filename} (size={size}, bytes={data.nbytes})')
        except Exception as e:
            self.get_logger().error(f'Failed to save C++ binary LUT file: {e}')

    def load_lut(self, filename: str):
        try:
            lut = np.load(filename)

            if lut.ndim != 4 or lut.shape[-1] != 3:
                raise ValueError(f'Invalid LUT shape: {lut.shape}, expected (size,size,size,3)')

            if not (lut.shape[0] == lut.shape[1] == lut.shape[2]):
                raise ValueError(f'Invalid LUT shape: {lut.shape}, first 3 dims must be equal')

            self.lut = lut.astype(np.float32)
            self.lut_enabled = True
            self.calibration_done = True
            self.calibration_status.data = True
            self.detection_status.data = f'LUT loaded from file: {filename}'
            self.publish_status()

            self.get_logger().info(f'Loaded LUT from: {filename}')
            self.get_logger().info(f'LUT shape: {self.lut.shape}')
            self.get_logger().info(f'LUT min/max: {self.lut.min():.6f} / {self.lut.max():.6f}')

        except Exception as e:
            self.get_logger().error(f'Failed to load LUT file: {e}')
            traceback.print_exc()

        if self.lut_binary_file and self.lut is not None:
            self.save_lut_binary(self.lut_binary_file)

    # ------------------------------------------------------------------
    # Detection / calibration
    # ------------------------------------------------------------------
    def detect_colorchecker_opencv(self, image_bgr):
        try:
            detector = self._create_detector()
            ok = detector.process(image_bgr, self.chart_type, self.max_checkers)
            if not ok:
                return False, None

            checkers = detector.getListColorChecker()
            if checkers is None or len(checkers) == 0:
                return False, None

            return True, checkers[0]

        except Exception as e:
            self.get_logger().error(f'Error detecting ColorChecker: {e}')
            traceback.print_exc()
            return False, None

    def calibrate_and_build_lut(self, image_bgr, checker):
        """
        使用 ColorChecker 标定 CCM，然后生成 3D LUT
        """
        try:
            charts_rgb = checker.getChartsRGB()
            self.get_logger().info(f'ChartsRGB shape: {charts_rgb.shape}')

            # 与基础程序一致
            src = charts_rgb[:, 1].copy()
            src = src.astype(np.float64)
            if src.max() > 1.0:
                src = src / 255.0

            src = src.reshape((-1, 1, 3))
            src = np.ascontiguousarray(src)

            self.get_logger().info(f'src shape: {src.shape}, dtype: {src.dtype}')
            self.get_logger().info(f'src min/max: {src.min():.6f} / {src.max():.6f}')

            # 1) 标定 CCM
            self.ccm_model = cv2.ccm.ColorCorrectionModel(src, self.ccm_chart_type)
            self.ccm_model.run()

            self.ccm = self.ccm_model.getCCM()
            loss = self.ccm_model.getLoss()

            self.get_logger().info(f'CCM matrix:\n{self.ccm}')
            self.get_logger().info(f'CCM loss: {loss}')

            # 2) 生成 LUT
            self.lut = build_3d_lut_from_ccm_model(self.ccm_model, lut_size=self.lut_size)
            self.lut_enabled = True

            self.get_logger().info(f'LUT shape: {self.lut.shape}')
            self.get_logger().info(f'LUT min/max: {self.lut.min():.6f} / {self.lut.max():.6f}')

            # 3) 可选保存 debug 检测图
            if self.save_debug_image:
                try:
                    draw_img = image_bgr.copy()
                    if hasattr(cv2.mcc, 'CCheckerDraw'):
                        cdraw = cv2.mcc.CCheckerDraw.create(checker)
                        cdraw.draw(draw_img)
                        cv2.imwrite(self.debug_image_path, draw_img)
                        self.get_logger().info(f'Saved debug detection image to: {self.debug_image_path}')
                except Exception as e:
                    self.get_logger().warn(f'Failed to save debug image: {e}')

            # 4) 保存 LUT
            if self.save_lut_after_calibration and self.lut_file:
                self.save_lut(self.lut_file)

            self.calibration_done = True
            self.colorchecker_detected = True
            self.calibration_status.data = True
            self.detection_status.data = 'ColorChecker detected, LUT calibration completed'

            self.publish_ccm()
            self.publish_status()

            return True

        except Exception as e:
            self.get_logger().error(f'Error computing CCM/LUT: {e}')
            traceback.print_exc()
            return False

    def try_calibration(self):
        if not self.auto_detect:
            return

        # 已有可用 LUT 则不再重复标定
        if self.calibration_done and self.lut_enabled:
            return

        if self.latest_image_bgr is None:
            return

        if self.calibration_attempts >= self.max_attempts:
            self.detection_status.data = f'Max calibration attempts reached: {self.max_attempts}'
            self.publish_status()
            self.get_logger().warn(self.detection_status.data)
            self.calibration_done = True
            return

        success, checker = self.detect_colorchecker_opencv(self.latest_image_bgr)

        if success:
            self.get_logger().info('ColorChecker detected! Start CCM calibration and LUT generation...')
            self.detection_status.data = 'ColorChecker detected, computing CCM and LUT...'
            self.publish_status()

            ok = self.calibrate_and_build_lut(self.latest_image_bgr, checker)
            if ok:
                self.get_logger().warn('=' * 60)
                self.get_logger().warn('LUT CALIBRATION COMPLETED')
                self.get_logger().warn(f'CCM:\n{self.ccm}')
                self.get_logger().warn(f'LUT shape: {self.lut.shape}')
                self.get_logger().warn('=' * 60)
            else:
                self.calibration_attempts += 1
                self.detection_status.data = f'CCM/LUT computation failed ({self.calibration_attempts}/{self.max_attempts})'
                self.publish_status()
        else:
            self.colorchecker_detected = False
            self.calibration_attempts += 1
            self.detection_status.data = f'Searching for ColorChecker... ({self.calibration_attempts}/{self.max_attempts})'
            self.publish_status()

            if self.calibration_attempts % 10 == 0:
                self.get_logger().info(self.detection_status.data)

    # ------------------------------------------------------------------
    # Apply LUT
    # ------------------------------------------------------------------
    def apply_lut(self, image_bgr):
        """
        用 3D LUT 对图像进行颜色校正

        输入:
            image_bgr: uint8, BGR
        输出:
            corrected_bgr: uint8, BGR
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

    # ------------------------------------------------------------------
    # ROS callbacks
    # ------------------------------------------------------------------
    def image_callback(self, msg: Image):
        """
        处理输入图像
        约定输入为 RGB topic
        内部转成 BGR 给 OpenCV 检测使用
        LUT 应用时在 RGB 空间完成
        输出按 output_encoding 发布
        """
        try:
            if self.input_encoding == 'rgb8':
                cv_image_rgb = self.bridge.imgmsg_to_cv2(msg, 'rgb8')
                cv_image_bgr = cv2.cvtColor(cv_image_rgb, cv2.COLOR_RGB2BGR)
            elif self.input_encoding == 'bgr8':
                cv_image_bgr = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
            else:
                cv_image = self.bridge.imgmsg_to_cv2(msg, 'passthrough')
                if msg.encoding.lower() == 'rgb8':
                    cv_image_bgr = cv2.cvtColor(cv_image, cv2.COLOR_RGB2BGR)
                elif msg.encoding.lower() == 'bgr8':
                    cv_image_bgr = cv_image
                else:
                    self.get_logger().error(f'Unsupported image encoding: {msg.encoding}')
                    return

            self.latest_image_bgr = cv_image_bgr.copy()
            self.latest_image_header = msg.header

            # 运行时只用 LUT
            if self.lut_enabled and self.lut is not None:
                corrected_bgr = self.apply_lut(cv_image_bgr)
            else:
                corrected_bgr = cv_image_bgr

            if self.output_encoding == 'rgb8':
                corrected_rgb = cv2.cvtColor(corrected_bgr, cv2.COLOR_BGR2RGB)
                output_msg = self.bridge.cv2_to_imgmsg(corrected_rgb, encoding='rgb8')
            elif self.output_encoding == 'bgr8':
                output_msg = self.bridge.cv2_to_imgmsg(corrected_bgr, encoding='bgr8')
            else:
                self.get_logger().error(f'Unsupported output encoding: {self.output_encoding}')
                return

            output_msg.header = msg.header
            self.image_pub.publish(output_msg)

        except Exception as e:
            self.get_logger().error(f'Error processing image: {e}')
            traceback.print_exc()

    def camera_info_callback(self, msg: CameraInfo):
        self.latest_camera_info = msg
        self.camera_info_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = ColorCorrectionNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
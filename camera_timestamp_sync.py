#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
相机时间戳同步节点（支持自动检测偏移量）

功能:
    订阅右相机图像，重发图像并校正时间戳使其与左相机同步。

工作原理:
    相机启动时，USB 枚举顺序决定了两个相机的初始化时间差，
    这个差值是恒定的。本节点通过比较同一物理时刻的左右帧时间戳，
    自动计算出这个偏移量。

用法:
    # 方式1: 自动检测偏移量（推荐）
    ./camera_timestamp_sync.py --auto

    # 方式2: launch 启动（自动检测）
    ros2 launch vimbax_camera dual_camera_stream_launch.py time_sync:=true time_offset_ms:=0

    # 方式3: 手动指定偏移量
    ./camera_timestamp_sync.py --offset-ms 516.0

    # 方式4: 从缓存文件读取（camera_time_sync_check.py 生成的）
    ./camera_timestamp_sync.py --auto-offset

参数:
    left_topic:      左相机话题 (默认 /vimbax_camera_left/image_raw)
    right_topic:     右相机话题 (默认 /vimbax_camera_right/image_raw)
    output_topic:    校正后右相机话题 (默认 /vimbax_camera_right/image_sync)
    offset_ms:        手动指定偏移量，毫秒 (默认 0.0)
    auto:             启用自动检测模式 (默认 true)
    detect_frames:    自动检测时使用的帧数 (默认 30)
    converge_thresh:  判定收敛的阈值，毫秒 (默认 5.0)
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import argparse
import os
import numpy as np


class CameraTimestampSync(Node):
    """
    时间戳同步节点

    两种工作模式:
    1. 自动检测模式 (auto=True):
       - 订阅左右相机，同时缓冲帧
       - 寻找时间戳最接近的左右帧对，计算 offset
       - 累计 N 帧后取中位数作为最终偏移量
       - 收敛后开始发布校正后的右相机帧

    2. 手动模式 (auto=False, offset_ms != 0):
       - 直接用指定的偏移量发布
    """

    def __init__(self, left_topic: str, right_topic: str, output_topic: str,
                 offset_ms: float, auto: bool, detect_frames: int, converge_thresh: float):
        super().__init__('camera_timestamp_sync')

        self.left_topic = left_topic
        self.right_topic = right_topic
        self.output_topic = output_topic
        self.manual_offset_ns = int(offset_ms * 1e6)  # 毫秒 -> 纳秒
        self.auto = auto
        self.detect_frames = detect_frames
        self.converge_thresh_ns = int(converge_thresh * 1e6)

        # 状态
        self.left_buf: list[tuple] = []   # [(stamp_ns, stamp_sec, msg), ...]
        self.right_buf: list[tuple] = []  # [(stamp_ns, stamp_sec, msg), ...]
        self.detected_offset_ns: int | None = None
        self.phase: str = 'manual' if (not auto or offset_ms != 0.0) else 'detecting'
        self.offsets_measured: list[int] = []
        self._detected_logged = False

        # 发布
        self.pub = self.create_publisher(Image, output_topic, 10)

        # 订阅
        self.sub_left = self.create_subscription(
            Image, left_topic, self._left_cb, 10
        )
        self.sub_right = self.create_subscription(
            Image, right_topic, self._right_cb, 10
        )

        if self.phase == 'manual':
            self.get_logger().info(
                f'时间戳同步节点已启动 [手动模式]  '
                f'偏移量: {offset_ms:.3f} ms'
            )
        else:
            self.get_logger().info(
                f'时间戳同步节点已启动 [自动检测模式]  '
                f'需 {detect_frames} 帧后收敛'
            )
        self.get_logger().info(f'  左相机: {left_topic}')
        self.get_logger().info(f'  右相机: {right_topic}')
        self.get_logger().info(f'  输出:   {output_topic}')

    # ------------------------------------------------------------------ callbacks
    def _left_cb(self, msg: Image):
        stamp_ns = msg.header.stamp.sec * 1_000_000_000 + msg.header.stamp.nanosec
        self.left_buf.append((stamp_ns, msg))
        self._trim(self.left_buf)

    def _right_cb(self, msg: Image):
        stamp_ns = msg.header.stamp.sec * 1_000_000_000 + msg.header.stamp.nanosec
        self.right_buf.append((stamp_ns, msg))
        self._trim(self.right_buf)
        self._process()

    # ------------------------------------------------------------------ helpers
    @staticmethod
    def _trim(buf: list, max_size: int = 50):
        """限制缓冲区大小"""
        if len(buf) > max_size:
            del buf[:-max_size]

    def _stamp(self, msg: Image) -> int:
        """从 Image msg 提取 stamp（纳秒）"""
        return msg.header.stamp.sec * 1_000_000_000 + msg.header.stamp.nanosec

    # ------------------------------------------------------------------ core logic
    def _process(self):
        """
        核心检测逻辑:
        1. 从 left_buf 取最新帧，在 right_buf 中找同一时刻的帧（时间差最小）
        2. 计算 offset = right_stamp - left_stamp
        3. 累计后取中位数判断收敛
        """
        if self.phase != 'detecting':
            return
        if len(self.left_buf) < 2 or len(self.right_buf) < 2:
            return

        # 以左相机最新帧为基准，找右相机中时间最接近的帧
        left_stamp_ns, left_msg = self.left_buf[-1]

        best_offset = None
        best_diff = float('inf')
        for r_stamp_ns, _ in self.right_buf:
            offset = r_stamp_ns - left_stamp_ns
            diff = abs(offset)
            if diff < best_diff:
                best_diff = diff
                best_offset = offset

        if best_offset is None:
            return

        self.offsets_measured.append(best_offset)

        # 至少需要足够多的样本才统计
        if len(self.offsets_measured) < self.detect_frames:
            return

        # 取中位数（鲁棒估计，过滤掉异常帧配对）
        median_offset = int(np.median(self.offsets_measured[-self.detect_frames:]))

        # 判断是否收敛（最近 detect_frames 个值的标准差小于阈值）
        recent = np.array(self.offsets_measured[-self.detect_frames:], dtype=np.int64)
        std_ns = int(np.std(recent))

        if std_ns <= self.converge_thresh_ns:
            self.detected_offset_ns = median_offset
            self.phase = 'synced'
            offset_ms = self.detected_offset_ns / 1_000_000.0
            self.get_logger().info(
                f'★ 偏移量已收敛: {offset_ms:.3f} ms  '
                f'(标准差: {std_ns/1_000_000:.3f} ms, 样本: {len(self.offsets_measured)} 帧)'
            )
            self.get_logger().info(
                f'★ 开始发布校正后图像到 {self.output_topic}'
            )
            # 立即发布缓冲区中积压的右相机帧
            self._flush_backlog()
        else:
            # 尚未收敛，每 10 帧报告一次进度
            if len(self.offsets_measured) % 10 == 0:
                rough_ms = median_offset / 1_000_000.0
                self.get_logger().info(
                    f'检测中... 当前偏移量: {rough_ms:.3f} ms  '
                    f'标准差: {std_ns/1_000_000:.3f}/{self.converge_thresh_ns/1_000_000:.3f} ms  '
                    f'({len(self.offsets_measured)}/{self.detect_frames} 帧)'
                )

    def _flush_backlog(self):
        """同步后，把缓冲区中积压的帧立即发布"""
        if not self.right_buf:
            return
        for _, msg in self.right_buf:
            self._publish_corrected(msg)

    # ------------------------------------------------------------------ 发布
    def _publish_corrected(self, msg: Image):
        """发布校正后的图像"""
        new_msg = Image()
        new_msg.header = msg.header
        new_msg.height = msg.height
        new_msg.width = msg.width
        new_msg.encoding = msg.encoding
        new_msg.is_bigendian = msg.is_bigendian
        new_msg.step = msg.step
        new_msg.data = msg.data

        offset_ns = self.manual_offset_ns if self.phase == 'manual' else self.detected_offset_ns
        new_stamp_ns = self._stamp(msg) - offset_ns

        if new_stamp_ns < 0:
            return  # 时间戳无效则丢弃

        new_msg.header.stamp.sec = new_stamp_ns // 1_000_000_000
        new_msg.header.stamp.nanosec = new_stamp_ns % 1_000_000_000

        self.pub.publish(new_msg)

    def _try_sync_and_publish(self, msg: Image):
        """
        收到右相机帧时的处理:
        - detecting 阶段：只缓冲，不发布
        - synced 阶段：校正后发布
        - manual 阶段：直接校正后发布
        """
        if self.phase == 'detecting':
            return  # 还在检测，不发布
        self._publish_corrected(msg)

    # ------------------------------------------------------------------ 改造 right_cb 为转发
    # 为避免循环调用，这里覆盖 _right_cb 的末尾行为
    # （已在 _right_cb 末尾调用 _try_sync_and_publish）
    def _right_cb_final(self, msg: Image):
        """在原 _right_cb 末尾调用，触发同步发布"""
        self._try_sync_and_publish(msg)


# ---------------------------------------------------------------------------
# monkey-patch: 给原类加上同步发布
def _right_cb_patched(self, msg: Image):
    stamp_ns = msg.header.stamp.sec * 1_000_000_000 + msg.header.stamp.nanosec
    self.right_buf.append((stamp_ns, msg))
    self._trim(self.right_buf)
    self._process()
    self._try_sync_and_publish(msg)


CameraTimestampSync._right_cb = _right_cb_patched


# ---------------------------------------------------------------------------
def main():
    parser = argparse.ArgumentParser(
        description='相机时间戳同步节点',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  %(prog)s --auto
  %(prog)s --offset-ms 516.0
  %(prog)s --auto-offset
        """
    )
    parser.add_argument(
        '--left-topic',
        default='/vimbax_camera_left/image_raw',
        help='左相机话题 (默认: /vimbax_camera_left/image_raw)'
    )
    parser.add_argument(
        '--right-topic',
        default='/vimbax_camera_right/image_raw',
        help='右相机话题 (默认: /vimbax_camera_right/image_raw)'
    )
    parser.add_argument(
        '--output-topic',
        default='/vimbax_camera_right/image_sync',
        help='校正后输出话题 (默认: /vimbax_camera_right/image_sync)'
    )
    parser.add_argument(
        '--offset-ms',
        type=float, default=0.0,
        help='手动偏移量，毫秒 (默认: 0.0)'
    )
    parser.add_argument(
        '--auto',
        action='store_true', default=True,
        help='启用自动检测模式 (默认: True)'
    )
    parser.add_argument(
        '--no-auto',
        action='store_false', dest='auto',
        help='禁用自动检测，使用 --offset-ms'
    )
    parser.add_argument(
        '--auto-offset',
        action='store_true',
        help='从缓存文件读取偏移量 (由 camera_time_sync_check.py 生成)'
    )
    parser.add_argument(
        '--detect-frames',
        type=int, default=30,
        help='自动检测使用的帧数 (默认: 30)'
    )
    parser.add_argument(
        '--converge-thresh',
        type=float, default=5.0,
        help='判定收敛的阈值，毫秒 (默认: 5.0)'
    )

    # 过滤掉 ROS2 追加的运行时参数，避免 argparse 报错
    # ROS2 launch 运行时会追加: <exec_path> /tmp/launch_params_xxx --ros-args -r __node:=xxx --params-file /tmp/xxx
    # argparse 只能处理真正的命令行参数，把所有 ROS 追加的都过滤掉
    filtered_argv = []
    skip_next = False
    for i, a in enumerate(sys.argv):
        if i == 0:
            continue  # 跳过可执行文件路径本身
        if skip_next:
            skip_next = False
            continue
        # 遇到 --ros-args 后面的全部跳过（从它开始往后都是 ROS 运行时参数）
        if a == '--ros-args':
            break
        # 跳过 /tmp/launch_params_xxx（ROS launch 传给可执行文件的首个参数）
        if a.startswith('/tmp/launch_params_'):
            continue
        # 跳过 --params-file 及其后的值
        if a == '--params-file':
            skip_next = True
            continue
        filtered_argv.append(a)
    args = parser.parse_args(filtered_argv)

    # 处理 auto-offset
    if args.auto_offset:
        cache_file = '/tmp/vimbax_camera_time_offset.txt'
        if os.path.exists(cache_file):
            try:
                with open(cache_file, 'r') as f:
                    args.offset_ms = float(f.read().strip())
                print(f'[时间戳同步] 从缓存读取偏移量: {args.offset_ms:.3f} ms')
            except (ValueError, IOError):
                pass
        else:
            print(f'[时间戳同步] 未找到缓存文件 {cache_file}，改用自动检测模式')
            args.auto = True
            args.offset_ms = 0.0

    # 如果手动指定了非零偏移量，禁用自动检测
    if args.offset_ms != 0.0:
        args.auto = False

    if args.auto and args.offset_ms == 0.0:
        print(f'[时间戳同步] 模式: 自动检测 (需 {args.detect_frames} 帧收敛)')
        print(f'[时间戳同步] 收敛阈值: {args.converge_thresh} ms')
    else:
        print(f'[时间戳同步] 模式: 手动 ({args.offset_ms:.3f} ms)')

    rclpy.init(args=sys.argv)
    node = CameraTimestampSync(
        left_topic=args.left_topic,
        right_topic=args.right_topic,
        output_topic=args.output_topic,
        offset_ms=args.offset_ms,
        auto=args.auto,
        detect_frames=args.detect_frames,
        converge_thresh=args.converge_thresh,
    )

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print('\n时间戳同步节点已关闭')
    finally:
        node.destroy_node()


if __name__ == '__main__':
    import sys
    main()

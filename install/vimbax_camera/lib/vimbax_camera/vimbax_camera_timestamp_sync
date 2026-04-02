#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
相机时间戳同步节点（支持自动检测偏移量）

订阅右相机图像，重发图像并校正时间戳使其与左相机同步。

相机启动时，USB 枚举顺序决定了两个相机的初始化时间差，这个差值是恒定的。
本节点通过比较同一物理时刻的左右帧时间戳，自动计算出这个偏移量。

用法:
    ./camera_timestamp_sync.py --auto
    ./camera_timestamp_sync.py --offset-ms 516.0
    ./camera_timestamp_sync.py --auto-offset

参数:
    left_topic:      左相机话题 (默认 /vimbax_camera_left/image_raw)
    right_topic:     右相机话题 (默认 /vimbax_camera_right/image_raw)
    output_topic:    校正后右相机话题 (默认 /vimbax_camera_right/image_sync)
    offset_ms:       手动指定偏移量，毫秒 (默认 0.0)
    detect_frames:   自动检测时使用的帧数 (默认 30)
    converge_thresh: 判定收敛的阈值，毫秒 (默认 5.0)
"""

import sys
import argparse
import os

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import numpy as np


class CameraTimestampSync(Node):

    def __init__(self, left_topic: str, right_topic: str, output_topic: str,
                 offset_ms: float, detect_frames: int, converge_thresh: float):
        super().__init__('camera_timestamp_sync')

        self.left_topic = left_topic
        self.right_topic = right_topic
        self.output_topic = output_topic
        self.manual_offset_ns = int(offset_ms * 1e6)  # ms -> ns
        self.detect_frames = detect_frames
        self.converge_thresh_ns = int(converge_thresh * 1e6)

        # 状态
        self.left_buf: list[tuple] = []
        self.right_buf: list[tuple] = []
        self.detected_offset_ns: int | None = None
        self.phase: str = 'manual' if offset_ms != 0.0 else 'detecting'
        self.offsets_measured: list[int] = []
        self._last_detected_period: int | None = None

        # 帧间隔统计
        self._left_intervals_ns: list[int] = []
        self._right_intervals_ns: list[int] = []
        self._expected_frame_interval_ns: int | None = None

        # 订阅 + 发布
        self.pub = self.create_publisher(Image, output_topic, 10)
        self.create_subscription(Image, left_topic, self._left_cb, 10)
        self.create_subscription(Image, right_topic, self._right_cb, 10)

        self.get_logger().info(f'时间戳同步节点已启动 [{"手动" if self.phase == "manual" else "自动检测"}模式]')
        self.get_logger().info(f'  左相机: {left_topic}')
        self.get_logger().info(f'  右相机: {right_topic}')
        self.get_logger().info(f'  输出:   {output_topic}')
        if self.phase == 'detecting':
            self.get_logger().info(f'  需 {detect_frames} 帧后收敛')

    # ------------------------------------------------------------------ 回调
    def _left_cb(self, msg: Image):
        stamp_ns = self._stamp(msg)
        self.left_buf.append((stamp_ns, msg))
        self._trim(self.left_buf)
        self._update_intervals(stamp_ns, is_left=True)

    def _right_cb(self, msg: Image):
        stamp_ns = self._stamp(msg)
        self.right_buf.append((stamp_ns, msg))
        self._trim(self.right_buf)
        self._update_intervals(stamp_ns, is_left=False)
        self._process()
        if self.phase != 'detecting':
            self._publish_corrected(msg)

    # ------------------------------------------------------------------ 辅助
    def _trim(self, buf: list, max_size: int = 200):
        if len(buf) > max_size:
            del buf[:-max_size]

    def _stamp(self, msg: Image) -> int:
        return msg.header.stamp.sec * 1_000_000_000 + msg.header.stamp.nanosec

    def _update_intervals(self, stamp_ns: int, is_left: bool):
        buf = self.left_buf if is_left else self.right_buf
        intervals = self._left_intervals_ns if is_left else self._right_intervals_ns
        if len(buf) >= 2:
            interval = stamp_ns - buf[-2][0]
            if 100_000_000 < interval < 10_000_000_000:
                intervals.append(interval)
                all_intervals = self._left_intervals_ns + self._right_intervals_ns
                if len(all_intervals) >= 4:
                    self._expected_frame_interval_ns = int(np.median(all_intervals[-40:]))

    # ------------------------------------------------------------------ 核心检测
    def _process(self):
        if self.phase != 'detecting':
            return
        if len(self.left_buf) < 2 or len(self.right_buf) < 2:
            return

        total_intervals = len(self._left_intervals_ns) + len(self._right_intervals_ns)
        if total_intervals < 10:
            return

        frame_ns = self._expected_frame_interval_ns or 600_000_000
        right_stamp_ns, _ = self.right_buf[-1]

        # 遍历周期候选 (-4 ~ +4)，找最佳匹配
        best_score = -1.0
        best_offset = 0
        best_period = 0

        for period in range(-4, 5):
            expected_left = right_stamp_ns - period * frame_ns
            best_diff = min(abs(l - expected_left) for l, _ in self.left_buf)
            if best_diff == float('inf'):
                continue

            phase_conf = 1.0 / (1.0 + best_diff / frame_ns)
            period_penalty = min(abs(period) * 0.12, 0.5)
            score = phase_conf * (1.0 - period_penalty)

            # 历史稳定性惩罚
            if self._last_detected_period is not None and abs(period - self._last_detected_period) > 2:
                score *= 0.5

            if score > best_score:
                best_score = score
                best_offset = right_stamp_ns - self._get_nearest_left(expected_left)
                best_period = period

        self._last_detected_period = best_period
        self.offsets_measured.append(best_offset)

        if len(self.offsets_measured) < self.detect_frames:
            return

        recent = np.array(self.offsets_measured[-self.detect_frames:], dtype=np.int64)
        median_offset = int(np.median(recent))
        std_ns = int(np.std(recent))

        adaptive_thresh = max(self.converge_thresh_ns, 50_000_000)
        if std_ns <= adaptive_thresh:
            self.detected_offset_ns = median_offset
            self.phase = 'synced'
            self.get_logger().info(
                f'★ 偏移量已收敛: {median_offset/1e6:.3f} ms  '
                f'(标准差: {std_ns/1e6:.3f} ms, 样本: {len(self.offsets_measured)} 帧)'
            )
            self.get_logger().info(f'★ 开始发布校正后图像到 {self.output_topic}')
            # 发布积压帧
            for _, msg in self.right_buf:
                self._publish_corrected(msg)
        elif len(self.offsets_measured) % 10 == 0:
            self.get_logger().info(
                f'检测中... 周期: period={best_period}, 置信度: {best_score*100:.0f}%  '
                f'偏移: {median_offset/1e6:.3f} ms  '
                f'标准差: {std_ns/1e6:.3f} ms  ({len(self.offsets_measured)}/{self.detect_frames})'
            )

    def _get_nearest_left(self, target_ns: int) -> int:
        """从左缓冲区中找时间戳最接近 target_ns 的帧"""
        return min(self.left_buf, key=lambda x: abs(x[0] - target_ns))[0]

    # ------------------------------------------------------------------ 发布
    def _publish_corrected(self, msg: Image):
        offset_ns = self.manual_offset_ns if self.phase == 'manual' else self.detected_offset_ns
        new_stamp_ns = self._stamp(msg) - offset_ns
        if new_stamp_ns < 0:
            return

        new_msg = Image()
        new_msg.header = msg.header
        new_msg.height = msg.height
        new_msg.width = msg.width
        new_msg.encoding = msg.encoding
        new_msg.is_bigendian = msg.is_bigendian
        new_msg.step = msg.step
        new_msg.data = msg.data
        new_msg.header.stamp.sec = new_stamp_ns // 1_000_000_000
        new_msg.header.stamp.nanosec = new_stamp_ns % 1_000_000_000
        self.pub.publish(new_msg)


# ---------------------------------------------------------------------------
def main():
    parser = argparse.ArgumentParser(description='相机时间戳同步节点')
    parser.add_argument('--left-topic', default='/vimbax_camera_left/image_raw')
    parser.add_argument('--right-topic', default='/vimbax_camera_right/image_raw')
    parser.add_argument('--output-topic', default='/vimbax_camera_right/image_sync')
    parser.add_argument('--offset-ms', type=float, default=0.0)
    parser.add_argument('--auto', action='store_true', default=True)
    parser.add_argument('--no-auto', action='store_false', dest='auto')
    parser.add_argument('--auto-offset', action='store_true')
    parser.add_argument('--detect-frames', type=int, default=30)
    parser.add_argument('--converge-thresh', type=float, default=5.0)

    # 过滤 ROS2 追加的参数
    filtered_argv = []
    skip_next = False
    for i, a in enumerate(sys.argv):
        if i == 0:
            continue
        if skip_next:
            skip_next = False
            continue
        if a == '--ros-args':
            break
        if a.startswith('/tmp/launch_params_'):
            continue
        if a == '--params-file':
            skip_next = True
            continue
        filtered_argv.append(a)
    args = parser.parse_args(filtered_argv)

    # 处理缓存偏移
    if args.auto_offset:
        cache = '/tmp/vimbax_camera_time_offset.txt'
        if os.path.exists(cache):
            try:
                args.offset_ms = float(open(cache).read().strip())
                print(f'[时间戳同步] 从缓存读取偏移量: {args.offset_ms:.3f} ms')
            except (ValueError, IOError):
                print(f'[时间戳同步] 缓存读取失败，改用自动检测')
                args.offset_ms = 0.0
        else:
            print(f'[时间戳同步] 未找到缓存，改用自动检测')
            args.offset_ms = 0.0

    if args.offset_ms != 0.0:
        args.auto = False

    print(f'[时间戳同步] 模式: {"手动 " + str(args.offset_ms) + " ms" if not args.auto else "自动检测 (" + str(args.detect_frames) + " 帧)"}')

    rclpy.init(args=sys.argv)
    node = CameraTimestampSync(
        left_topic=args.left_topic,
        right_topic=args.right_topic,
        output_topic=args.output_topic,
        offset_ms=args.offset_ms,
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
    main()

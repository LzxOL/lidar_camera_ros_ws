#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
相机时间戳同步验证工具

用法:
    # 直接运行（使用默认 topic）
    ./camera_time_sync_check.py

    # 指定 topic
    ./camera_time_sync_check.py --left-topic /vimbax_camera_left/image_raw --right-topic /vimbax_camera_right/image_raw

    # 指定采样数量和超时
    ./camera_time_sync_check.py --max-msgs 20 --timeout 10.0

功能:
    1. 订阅左右相机 image 话题
    2. 记录并对比时间戳
    3. 分析时间差统计
    4. 判断是否同步
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import argparse
import sys
import os


# 缓存文件路径（供 camera_timestamp_sync.py 自动读取）
CACHE_FILE = '/tmp/vimbax_camera_time_offset.txt'


def _write_offset_cache(offset_ms: float):
    """将偏移量写入缓存文件，供同步节点自动读取"""
    try:
        with open(CACHE_FILE, 'w') as f:
            f.write(f'{offset_ms:.3f}')
        return True
    except IOError:
        return False


def _clear_offset_cache():
    """清除缓存文件"""
    try:
        if os.path.exists(CACHE_FILE):
            os.remove(CACHE_FILE)
    except IOError:
        pass


class CameraTimeSyncChecker(Node):
    def __init__(self, left_topic: str, right_topic: str, max_msgs: int, timeout: float):
        super().__init__('camera_time_sync_checker')

        self.left_topic = left_topic
        self.right_topic = right_topic
        self.max_msgs = max_msgs
        self.timeout = timeout

        self.left_times = []      # (seq, stamp)
        self.right_times = []    # (seq, stamp)
        self.left_last_stamp = None
        self.right_last_stamp = None

        self.sub_left = self.create_subscription(
            Image, left_topic, self.left_cb, 10
        )
        self.sub_right = self.create_subscription(
            Image, right_topic, self.right_cb, 10
        )

        self.timer = self.create_timer(timeout, self.timeout_cb)

        self.get_logger().info(f"左相机 topic: {left_topic}")
        self.get_logger().info(f"右相机 topic: {right_topic}")
        self.get_logger().info(f"采样数量: {max_msgs}, 超时时间: {timeout}s")

    def stamp_to_sec(self, stamp) -> float:
        """将 ROS2 时间戳转换为秒"""
        return stamp.sec + stamp.nanosec * 1e-9

    def left_cb(self, msg: Image):
        t = self.stamp_to_sec(msg.header.stamp)
        seq = msg.header.stamp.sec * 1e9 + msg.header.stamp.nanosec

        self.left_times.append((seq, t))
        self.left_last_stamp = t

        if len(self.left_times) <= self.max_msgs:
            print(f"  [LEFT]  seq={msg.header.frame_id:<10} stamp={t:.9f}  (nsec={msg.header.stamp.nanosec})")

        if len(self.left_times) >= self.max_msgs and len(self.right_times) >= self.max_msgs:
            self.analyze_and_shutdown()

    def right_cb(self, msg: Image):
        t = self.stamp_to_sec(msg.header.stamp)
        seq = msg.header.stamp.sec * 1e9 + msg.header.stamp.nanosec

        self.right_times.append((seq, t))
        self.right_last_stamp = t

        if len(self.right_times) <= self.max_msgs:
            print(f"  [RIGHT] seq={msg.header.frame_id:<10} stamp={t:.9f}  (nsec={msg.header.stamp.nanosec})")

        if len(self.left_times) >= self.max_msgs and len(self.right_times) >= self.max_msgs:
            self.analyze_and_shutdown()

    def _do_shutdown(self):
        self.timer.cancel()
        rclpy.shutdown()

    def timeout_cb(self):
        """超时回调"""
        if len(self.left_times) > 0 or len(self.right_times) > 0:
            print(f"\n[超时] 等待超时，开始分析已收到的数据...")
            self.analyze_and_shutdown()
        else:
            print(f"\n[错误] 在 {self.timeout}s 内未收到任何消息！")
            print(f"  请检查相机是否正在发布话题。")
            print(f"  尝试查看当前话题列表:")
            print(f"    ros2 topic list | grep image")
            self._do_shutdown()

    def analyze_and_shutdown(self):
        """分析并输出结果"""
        self.timer.cancel()

        print("\n" + "=" * 70)
        print("相机时间戳同步分析报告")
        print("=" * 70)

        # 基本信息
        print(f"\n[基本信息]")
        print(f"  左相机 topic: {self.left_topic}")
        print(f"  右相机 topic: {self.right_topic}")
        print(f"  左相机收到消息数: {len(self.left_times)}")
        print(f"  右相机收到消息数: {len(self.right_times)}")

        if len(self.left_times) == 0 or len(self.right_times) == 0:
            print(f"\n[错误] 某个相机没有收到消息，无法进行同步分析！")
            self._do_shutdown()

        # 计算帧率
        left_intervals = []
        for i in range(1, len(self.left_times)):
            interval = self.left_times[i][1] - self.left_times[i-1][1]
            left_intervals.append(interval)

        right_intervals = []
        for i in range(1, len(self.right_times)):
            interval = self.right_times[i][1] - self.right_times[i-1][1]
            right_intervals.append(interval)

        if left_intervals:
            avg_left_interval = sum(left_intervals) / len(left_intervals)
            left_fps = 1.0 / avg_left_interval if avg_left_interval > 0 else 0
            print(f"\n[帧率分析]")
            print(f"  左相机平均帧间隔: {avg_left_interval*1000:.2f} ms (约 {left_fps:.1f} fps)")
        else:
            print(f"\n[帧率分析] 左相机数据不足")

        if right_intervals:
            avg_right_interval = sum(right_intervals) / len(right_intervals)
            right_fps = 1.0 / avg_right_interval if avg_right_interval > 0 else 0
            print(f"  右相机平均帧间隔: {avg_right_interval*1000:.2f} ms (约 {right_fps:.1f} fps)")
        else:
            print(f"  右相机数据不足")

        # 时间戳对比分析
        print(f"\n[时间戳对比分析]")

        # 使用时间最近邻匹配（而不是索引配对）
        # 对于每对相邻的左右帧，找到时间戳最接近的配对
        matched_diffs = []

        # 将右相机时间按升序排列，逐一与左相机匹配
        right_used = set()
        left_used = set()

        # 创建左右时间戳的完整列表用于配对
        all_pairs = []
        for li, (left_seq, left_t) in enumerate(self.left_times):
            for ri, (right_seq, right_t) in enumerate(self.right_times):
                diff = abs(left_t - right_t)
                all_pairs.append((diff, li, ri, left_t, right_t))

        # 按时间差排序，选择互不重叠的最佳配对
        all_pairs.sort()

        for diff, li, ri, left_t, right_t in all_pairs:
            if li in left_used or ri in right_used:
                continue
            left_used.add(li)
            right_used.add(ri)
            matched_diffs.append(diff)
            print(f"  配对[{len(matched_diffs)-1:2d}]: LEFT={left_t:.9f}  RIGHT={right_t:.9f}  差值={diff*1000:.3f} ms")

        if not matched_diffs:
            # 如果没有匹配到，使用简单索引配对作为后备
            print("  (时间匹配失败，改用索引配对)")
            for i in range(min(len(self.left_times), len(self.right_times))):
                left_t = self.left_times[i][1]
                right_t = self.right_times[i][1]
                diff = abs(left_t - right_t)
                matched_diffs.append(diff)
                print(f"  配对[{i:2d}]: LEFT={left_t:.9f}  RIGHT={right_t:.9f}  差值={diff*1000:.3f} ms")

        # 计算平均时间差（用于软件同步补偿）
        if matched_diffs:
            avg_diff = sum(matched_diffs) / len(matched_diffs)
            avg_diff_ms = avg_diff * 1000.0
            print(f"\n[补偿偏移量]")
            print(f"  ★ 检测到时间差: {avg_diff_ms:.3f} ms")
            # 写入缓存文件，供 camera_timestamp_sync.py 自动读取
            if _write_offset_cache(avg_diff_ms):
                print(f"  ★ 已写入缓存: {CACHE_FILE}")
                print(f"  ★ 下次使用同步节点时加参数: --auto-offset")
            else:
                print(f"  ✗ 写入缓存失败，请手动指定: --offset-ms {avg_diff_ms:.3f}")

        if matched_diffs:
            avg_diff = sum(matched_diffs) / len(matched_diffs)
            max_diff = max(matched_diffs)
            min_diff = min(matched_diffs)

            print(f"\n[同步性统计]")
            print(f"  平均时间差: {avg_diff*1000:.3f} ms")
            print(f"  最大时间差: {max_diff*1000:.3f} ms")
            print(f"  最小时间差: {min_diff*1000:.3f} ms")

            # 判断同步状态
            print(f"\n[同步性判断]")
            if avg_diff < 0.001:  # < 1ms
                status = "✓ 同步良好 (时间差 < 1ms)"
                status_color = "\033[92m"  # 绿色
            elif avg_diff < 0.01:  # < 10ms
                status = "⚠ 基本同步 (时间差 1-10ms)"
                status_color = "\033[93m"  # 黄色
            elif avg_diff < 0.1:  # < 100ms
                status = "✗ 轻微不同步 (时间差 10-100ms)"
                status_color = "\033[91m"  # 红色
            else:
                status = "✗ 不同步 (时间差 > 100ms)"
                status_color = "\033[91m"  # 红色

            print(f"  {status_color}{status}\033[0m")

            # 建议
            print(f"\n[建议]")
            if avg_diff >= 0.1:
                print(f"  ⚠ 时间戳差异较大，建议检查:")
                print(f"    1. 是否使用了硬件触发模式")
                print(f"    2. 两台相机是否使用同一时钟源 (use_sim_time)")
                print(f"    3. 检查相机固件时间同步设置")
            elif avg_diff >= 0.01:
                print(f"  ⚠ 时间戳存在轻微偏差，建议检查:")
                print(f"    1. 确认相机使用了硬件时间戳而非软件时间戳")
                print(f"    2. 检查 USB 驱动的延迟设置")
            else:
                print(f"  ✓ 时间戳同步正常，无需特别处理")

        # 绝对时间检查
        print(f"\n[绝对时间戳]")
        if self.left_last_stamp and self.right_last_stamp:
            abs_diff = abs(self.left_last_stamp - self.right_last_stamp)
            print(f"  左相机最新时间戳: {self.left_last_stamp:.9f}")
            print(f"  右相机最新时间戳: {self.right_last_stamp:.9f}")
            print(f"  绝对时间差: {abs_diff*1000:.3f} ms")

            import time
            now = time.time()
            drift_left = abs(self.left_last_stamp - now)
            drift_right = abs(self.right_last_stamp - now)
            print(f"  当前系统时间: {now:.9f}")
            print(f"  左相机与系统时间偏差: {drift_left:.3f} s")
            print(f"  右相机与系统时间偏差: {drift_right:.3f} s")

            if drift_left > 1 or drift_right > 1:
                print(f"\n  ⚠ 警告: 相机时间戳与系统时间偏差较大！")
                print(f"    这可能意味着相机使用的是软件时间戳。")

        print("\n" + "=" * 70)

        self._do_shutdown()


def main():
    parser = argparse.ArgumentParser(
        description='相机时间戳同步验证工具',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  %(prog)s                                      # 使用默认参数
  %(prog)s --left-topic /left/image_raw         # 指定左相机 topic
  %(prog)s --max-msgs 20 --timeout 5.0          # 采样20条，超时5秒
        """
    )
    parser.add_argument(
        '--left-topic', '-l',
        default='/vimbax_camera_left/image_raw',
        help='左相机 image topic (默认: /vimbax_camera_left/image_raw)'
    )
    parser.add_argument(
        '--right-topic', '-r',
        default='/vimbax_camera_right/image_sync',
        help='右相机 image topic (默认: /vimbax_camera_right/image_raw)'
    )
    parser.add_argument(
        '--max-msgs', '-m',
        type=int, default=10,
        help='采样消息数量 (默认: 10)'
    )
    parser.add_argument(
        '--timeout', '-t',
        type=float, default=10.0,
        help='超时时间秒 (默认: 10.0)'
    )

    # 过滤掉 ROS2 追加的运行时参数，避免 argparse 报错
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

    rclpy.init(args=sys.argv)

    node = CameraTimeSyncChecker(
        left_topic=args.left_topic,
        right_topic=args.right_topic,
        max_msgs=args.max_msgs,
        timeout=args.timeout
    )

    print("\n" + "=" * 70)
    print("相机时间戳同步验证工具")
    print("=" * 70)
    print(f"\n正在等待并记录消息...\n")

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("\n用户中断")
    finally:
        node.destroy_node()


if __name__ == '__main__':
    main()

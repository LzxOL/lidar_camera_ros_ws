#!/usr/bin/env python3
"""Interactively save selected mono/stereo ROS images and a matching rosbag2.

Press Space or Enter to request one new sample.  In stereo mode, a sample is
written only when the left/right Image.header.stamp values satisfy the chosen
tolerance (exact equality by default).  In stereo-async mode, one fresh image
from each side is saved without requiring timestamp alignment.  A visualization
window is also shown by default; clicking it with the left mouse button requests
a new sample.
"""

from __future__ import annotations

import argparse
import csv
import json
import os
from collections import deque
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
import select
import sys
import termios
import time
import tty
from typing import Any, Deque, Optional

import cv2
from cv_bridge import CvBridge
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from rclpy.serialization import serialize_message
import rosbag2_py
from sensor_msgs.msg import Image


STEREO_MODES = ("stereo", "stereo-async")
LEFT_MODES = STEREO_MODES + ("mono-left",)
RIGHT_MODES = STEREO_MODES + ("mono-right",)


@dataclass
class Frame:
    message: Image
    stamp_ns: int
    arrival_id: int


def stamp_to_ns(message: Image) -> int:
    return int(message.header.stamp.sec) * 1_000_000_000 + int(
        message.header.stamp.nanosec
    )


def stamp_text(stamp_ns: int) -> str:
    return f"{stamp_ns // 1_000_000_000}.{stamp_ns % 1_000_000_000:09d}"


class CalibrationCapture(Node):
    def __init__(self, args: argparse.Namespace) -> None:
        super().__init__("calibration_sample_capture")
        self.args = args
        self.bridge = CvBridge()
        self.arrival_id = 0
        self.sample_index = 0
        self.pending = False
        self.request_after_arrival_id = 0
        self.request_time = 0.0
        self.last_timeout_candidate_delta_ns: Optional[int] = None
        self.left_frames: Deque[Frame] = deque(maxlen=args.queue_size)
        self.right_frames: Deque[Frame] = deque(maxlen=args.queue_size)
        self.latest_left_frame: Optional[Frame] = None
        self.latest_right_frame: Optional[Frame] = None
        self.latest_left_image: Optional[Any] = None
        self.latest_right_image: Optional[Any] = None
        self.displayed_left_arrival_id = 0
        self.displayed_right_arrival_id = 0
        self.window_name = "Calibration Capture"
        self.visualization_enabled = False

        self.session_dir = args.output.expanduser().resolve()
        if self.session_dir.exists():
            raise RuntimeError(
                f"输出目录已存在，为避免覆盖数据已停止：{self.session_dir}"
            )
        self.left_dir = self.session_dir / "images" / "left"
        self.right_dir = self.session_dir / "images" / "right"
        self.left_dir.mkdir(parents=True, exist_ok=False)
        self.right_dir.mkdir(parents=True, exist_ok=False)

        self.csv_path = self.session_dir / "timestamps.csv"
        self.csv_file = self.csv_path.open("w", newline="", encoding="utf-8")
        self.csv_writer = csv.DictWriter(
            self.csv_file,
            fieldnames=[
                "sample_index",
                "mode",
                "left_file",
                "left_stamp_sec",
                "left_stamp_nanosec",
                "left_stamp_ns",
                "right_file",
                "right_stamp_sec",
                "right_stamp_nanosec",
                "right_stamp_ns",
                "delta_ns",
                "sync_ok",
            ],
        )
        self.csv_writer.writeheader()
        self.csv_file.flush()

        self.bag_dir = self.session_dir / "bag" / "selected_images"
        self.bag_dir.parent.mkdir(parents=True, exist_ok=True)
        self.writer = rosbag2_py.SequentialWriter()
        self.writer.open(
            rosbag2_py.StorageOptions(
                uri=str(self.bag_dir), storage_id=args.storage_id
            ),
            rosbag2_py.ConverterOptions(
                input_serialization_format="cdr",
                output_serialization_format="cdr",
            ),
        )

        image_qos = QoSProfile(depth=5, reliability=ReliabilityPolicy.RELIABLE)
        if args.mode in LEFT_MODES:
            self._create_bag_topic(args.left_topic)
            self.left_subscription = self.create_subscription(
                Image,
                args.left_topic,
                self._left_callback,
                image_qos,
            )
        if args.mode in RIGHT_MODES:
            self._create_bag_topic(args.right_topic)
            self.right_subscription = self.create_subscription(
                Image,
                args.right_topic,
                self._right_callback,
                image_qos,
            )

        metadata = {
            "created_at": datetime.now().astimezone().isoformat(),
            "mode": args.mode,
            "left_topic": args.left_topic,
            "right_topic": args.right_topic,
            "max_delta_ns": args.max_delta_ns,
            "requires_timestamp_sync": args.mode == "stereo",
            "capture_timeout_sec": args.capture_timeout,
            "image_format": "png",
            "bag_storage_id": args.storage_id,
            "note": (
                "The bag contains only manually selected sensor_msgs/msg/Image "
                "messages. Bag record timestamps use each message header stamp."
            ),
        }
        (self.session_dir / "session.json").write_text(
            json.dumps(metadata, ensure_ascii=False, indent=2) + "\n",
            encoding="utf-8",
        )

    def _create_bag_topic(self, topic: str) -> None:
        self.writer.create_topic(
            rosbag2_py.TopicMetadata(
                name=topic,
                type="sensor_msgs/msg/Image",
                serialization_format="cdr",
            )
        )

    def _make_frame(self, message: Image) -> Frame:
        self.arrival_id += 1
        return Frame(message, stamp_to_ns(message), self.arrival_id)

    def _left_callback(self, message: Image) -> None:
        frame = self._make_frame(message)
        self.left_frames.append(frame)
        self.latest_left_frame = frame
        if self.pending:
            if self.args.mode == "mono-left":
                self._save_mono("left", frame)
            elif self.args.mode in STEREO_MODES:
                self._try_save_stereo()

    def _right_callback(self, message: Image) -> None:
        frame = self._make_frame(message)
        self.right_frames.append(frame)
        self.latest_right_frame = frame
        if self.pending:
            if self.args.mode == "mono-right":
                self._save_mono("right", frame)
            elif self.args.mode in STEREO_MODES:
                self._try_save_stereo()

    def request_capture(self) -> None:
        if self.pending:
            print("[等待中] 上一次采集请求尚未完成，请等待新图像。", flush=True)
            return
        self.pending = True
        self.request_after_arrival_id = self.arrival_id
        self.request_time = time.monotonic()
        self.last_timeout_candidate_delta_ns = None
        if self.args.mode == "stereo":
            print(
                "[等待] 正在等待按键后到达、且时间戳满足要求的左右图像……",
                flush=True,
            )
        elif self.args.mode == "stereo-async":
            print(
                "[等待] 正在等待按键后左右各到达一张新图像（不检查时间戳对齐）……",
                flush=True,
            )
        else:
            print("[等待] 正在等待按键后到达的一张新图像……", flush=True)

    def start_visualization(self) -> None:
        """Create the live image window and make left-click a capture request."""
        if not os.environ.get("DISPLAY") and not os.environ.get("WAYLAND_DISPLAY"):
            print("[警告] 未检测到图形显示环境，已关闭可视化窗口。", flush=True)
            return
        try:
            cv2.namedWindow(self.window_name, cv2.WINDOW_NORMAL)
            cv2.setMouseCallback(self.window_name, self._on_mouse)
        except cv2.error as exc:
            print(f"[警告] 无法创建可视化窗口，已退回终端按键模式：{exc}", flush=True)
            return
        self.visualization_enabled = True
        print(
            "可视化窗口已启动：左键点击图像即可保存下一张/下一组图像。",
            flush=True,
        )

    def _on_mouse(self, event: int, _x: int, _y: int, _flags: int, _param: Any) -> None:
        if event == cv2.EVENT_LBUTTONDOWN:
            self.request_capture()

    def _to_display_image(self, message: Image) -> Optional[Any]:
        """Convert a ROS image to an OpenCV image accepted by imshow."""
        try:
            image = self.bridge.imgmsg_to_cv2(message, desired_encoding="bgr8")
        except Exception as exc:
            self.get_logger().warning(f"可视化图像转换失败：{exc}")
            return None
        if image is None or getattr(image, "size", 0) == 0:
            return None
        return image

    @staticmethod
    def _resize_for_display(image: Any, height: int = 600) -> Any:
        if image.shape[0] == height:
            return image
        width = max(1, round(image.shape[1] * height / image.shape[0]))
        return cv2.resize(image, (width, height), interpolation=cv2.INTER_AREA)

    def update_visualization(self) -> None:
        if not self.visualization_enabled:
            return

        if (
            self.latest_left_frame is not None
            and self.latest_left_frame.arrival_id != self.displayed_left_arrival_id
        ):
            self.latest_left_image = self._to_display_image(self.latest_left_frame.message)
            self.displayed_left_arrival_id = self.latest_left_frame.arrival_id
        if (
            self.latest_right_frame is not None
            and self.latest_right_frame.arrival_id != self.displayed_right_arrival_id
        ):
            self.latest_right_image = self._to_display_image(self.latest_right_frame.message)
            self.displayed_right_arrival_id = self.latest_right_frame.arrival_id

        panels = []
        if self.args.mode in LEFT_MODES:
            if self.latest_left_image is not None:
                left = self.latest_left_image.copy()
                cv2.putText(
                    left, "LEFT", (20, 36), cv2.FONT_HERSHEY_SIMPLEX,
                    1.0, (0, 255, 0), 2, cv2.LINE_AA,
                )
                panels.append(self._resize_for_display(left))
        if self.args.mode in RIGHT_MODES:
            if self.latest_right_image is not None:
                right = self.latest_right_image.copy()
                cv2.putText(
                    right, "RIGHT", (20, 36), cv2.FONT_HERSHEY_SIMPLEX,
                    1.0, (0, 255, 0), 2, cv2.LINE_AA,
                )
                panels.append(self._resize_for_display(right))

        if not panels:
            display = np.zeros((600, 800, 3), dtype=np.uint8)
            cv2.putText(
                display, "Waiting for camera images...", (40, 310),
                cv2.FONT_HERSHEY_SIMPLEX, 1.0, (255, 255, 255), 2, cv2.LINE_AA,
            )
        elif len(panels) == 1:
            display = panels[0]
        else:
            target_height = min(panel.shape[0] for panel in panels)
            panels = [self._resize_for_display(panel, target_height) for panel in panels]
            display = cv2.hconcat(panels)

        status = "WAITING - click / Space / Enter to capture"
        if self.pending:
            if self.args.mode == "stereo":
                status = "CAPTURING - waiting for a new synchronized image"
            elif self.args.mode == "stereo-async":
                status = "CAPTURING - waiting for fresh left/right images"
            else:
                status = "CAPTURING - waiting for a new image"
        cv2.putText(
            display, status, (20, display.shape[0] - 18),
            cv2.FONT_HERSHEY_SIMPLEX, 0.65, (0, 255, 255), 2, cv2.LINE_AA,
        )
        cv2.imshow(self.window_name, display)

    def close_visualization(self) -> None:
        if not self.visualization_enabled:
            return
        try:
            cv2.destroyWindow(self.window_name)
            cv2.waitKey(1)
        except cv2.error:
            pass

    def check_timeout(self) -> None:
        if not self.pending:
            return
        if time.monotonic() - self.request_time < self.args.capture_timeout:
            return
        self.pending = False
        detail = ""
        if self.last_timeout_candidate_delta_ns is not None:
            detail = (
                f"；期间最近的左右时间戳差为 "
                f"{self.last_timeout_candidate_delta_ns} ns"
            )
        hint = "请检查话题、触发和时间戳同步后再次按键。"
        if self.args.mode == "stereo-async":
            hint = "请检查左右话题和触发后再次按键。"
        elif self.args.mode in ("mono-left", "mono-right"):
            hint = "请检查话题和触发后再次按键。"
        print(
            f"[超时] {self.args.capture_timeout:g} 秒内没有得到可保存样本{detail}。"
            f"{hint}",
            flush=True,
        )

    def _is_valid_stamp(self, frame: Frame) -> bool:
        return self.args.allow_zero_stamp or frame.stamp_ns != 0

    def _fresh(self, frames: Deque[Frame]) -> list[Frame]:
        return [
            frame
            for frame in frames
            if frame.arrival_id > self.request_after_arrival_id
            and self._is_valid_stamp(frame)
        ]

    def _try_save_stereo(self) -> None:
        left_candidates = self._fresh(self.left_frames)
        right_candidates = self._fresh(self.right_frames)
        if not left_candidates or not right_candidates:
            return

        if self.args.mode == "stereo-async":
            left = left_candidates[-1]
            right = right_candidates[-1]
        else:
            left, right = min(
                (
                    (left_frame, right_frame)
                    for left_frame in left_candidates
                    for right_frame in right_candidates
                ),
                key=lambda pair: (
                    abs(pair[0].stamp_ns - pair[1].stamp_ns),
                    -max(pair[0].arrival_id, pair[1].arrival_id),
                ),
            )
        delta_ns = abs(left.stamp_ns - right.stamp_ns)
        self.last_timeout_candidate_delta_ns = delta_ns
        if self.args.mode == "stereo" and delta_ns > self.args.max_delta_ns:
            return
        self._save_stereo(left, right, delta_ns)

    def _write_png_temp(self, message: Image, final_path: Path) -> Path:
        image = self.bridge.imgmsg_to_cv2(message, desired_encoding="passthrough")
        temp_path = final_path.with_suffix(".tmp.png")
        ok = cv2.imwrite(
            str(temp_path), image, [cv2.IMWRITE_PNG_COMPRESSION, self.args.png_compression]
        )
        if not ok:
            raise RuntimeError(f"OpenCV 无法写入图片：{temp_path}")
        return temp_path

    def _save_mono(self, side: str, frame: Frame) -> None:
        if frame.arrival_id <= self.request_after_arrival_id:
            return
        if not self._is_valid_stamp(frame):
            return
        next_index = self.sample_index + 1
        filename = f"{next_index:06d}_{side}_{frame.stamp_ns}.png"
        image_dir = self.left_dir if side == "left" else self.right_dir
        final_path = image_dir / filename
        temp_path: Optional[Path] = None
        try:
            temp_path = self._write_png_temp(frame.message, final_path)
            os.replace(temp_path, final_path)
            topic = self.args.left_topic if side == "left" else self.args.right_topic
            self.writer.write(topic, serialize_message(frame.message), frame.stamp_ns)
            row = self._empty_row(next_index)
            row[f"{side}_file"] = str(final_path.relative_to(self.session_dir))
            row[f"{side}_stamp_sec"] = frame.message.header.stamp.sec
            row[f"{side}_stamp_nanosec"] = frame.message.header.stamp.nanosec
            row[f"{side}_stamp_ns"] = frame.stamp_ns
            row["sync_ok"] = True
            self.csv_writer.writerow(row)
            self.csv_file.flush()
        except Exception as exc:  # Keep the interactive collector alive.
            if temp_path is not None:
                temp_path.unlink(missing_ok=True)
            final_path.unlink(missing_ok=True)
            print(f"[错误] 本次图片保存失败：{exc}", flush=True)
            return

        self.sample_index = next_index
        self.pending = False
        print(
            f"[已保存 #{next_index:06d}] {side} "
            f"stamp={stamp_text(frame.stamp_ns)}  {filename}",
            flush=True,
        )

    def _save_stereo(self, left: Frame, right: Frame, delta_ns: int) -> None:
        next_index = self.sample_index + 1
        left_name = f"{next_index:06d}_left_{left.stamp_ns}.png"
        right_name = f"{next_index:06d}_right_{right.stamp_ns}.png"
        left_path = self.left_dir / left_name
        right_path = self.right_dir / right_name
        temp_paths: list[Path] = []
        try:
            left_temp = self._write_png_temp(left.message, left_path)
            temp_paths.append(left_temp)
            right_temp = self._write_png_temp(right.message, right_path)
            temp_paths.append(right_temp)
            os.replace(left_temp, left_path)
            os.replace(right_temp, right_path)
            self.writer.write(
                self.args.left_topic,
                serialize_message(left.message),
                left.stamp_ns,
            )
            self.writer.write(
                self.args.right_topic,
                serialize_message(right.message),
                right.stamp_ns,
            )
            self.csv_writer.writerow(
                {
                    "sample_index": next_index,
                    "mode": self.args.mode,
                    "left_file": str(left_path.relative_to(self.session_dir)),
                    "left_stamp_sec": left.message.header.stamp.sec,
                    "left_stamp_nanosec": left.message.header.stamp.nanosec,
                    "left_stamp_ns": left.stamp_ns,
                    "right_file": str(right_path.relative_to(self.session_dir)),
                    "right_stamp_sec": right.message.header.stamp.sec,
                    "right_stamp_nanosec": right.message.header.stamp.nanosec,
                    "right_stamp_ns": right.stamp_ns,
                    "delta_ns": delta_ns,
                    "sync_ok": delta_ns <= self.args.max_delta_ns,
                }
            )
            self.csv_file.flush()
        except Exception as exc:  # Keep the interactive collector alive.
            for path in temp_paths:
                path.unlink(missing_ok=True)
            left_path.unlink(missing_ok=True)
            right_path.unlink(missing_ok=True)
            print(f"[错误] 本次双目图片保存失败：{exc}", flush=True)
            return

        self.sample_index = next_index
        self.pending = False
        if self.args.mode == "stereo-async":
            sync_text = "未要求对齐"
        else:
            sync_text = "完全一致" if delta_ns == 0 else "阈值内"
        print(
            f"[已保存 #{next_index:06d}] 左右时间戳差={delta_ns} ns "
            f"({sync_text})",
            flush=True,
        )

    def _empty_row(self, index: int) -> dict[str, object]:
        return {
            "sample_index": index,
            "mode": self.args.mode,
            "left_file": "",
            "left_stamp_sec": "",
            "left_stamp_nanosec": "",
            "left_stamp_ns": "",
            "right_file": "",
            "right_stamp_sec": "",
            "right_stamp_nanosec": "",
            "right_stamp_ns": "",
            "delta_ns": "",
            "sync_ok": True,
        }

    def close(self) -> None:
        self.csv_file.flush()
        self.csv_file.close()
        self.writer.close()


class Keyboard:
    def __init__(self) -> None:
        if not sys.stdin.isatty():
            raise RuntimeError("此脚本需要在交互式终端中运行")
        self.fd = sys.stdin.fileno()
        self.previous = termios.tcgetattr(self.fd)

    def __enter__(self) -> "Keyboard":
        tty.setcbreak(self.fd)
        return self

    def __exit__(self, *_args: object) -> None:
        termios.tcsetattr(self.fd, termios.TCSADRAIN, self.previous)

    def read_key(self) -> Optional[str]:
        readable, _, _ = select.select([sys.stdin], [], [], 0.0)
        if not readable:
            return None
        return sys.stdin.read(1)


def parse_args() -> argparse.Namespace:
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    parser = argparse.ArgumentParser(
        description=(
            "按空格或回车保存一张单目图片、一组时间戳匹配的双目图片，"
            "或一组不要求时间戳对齐的双目图片，"
            "同时生成 PNG、timestamps.csv 和只含已选帧的 rosbag2。"
        )
    )
    parser.add_argument(
        "--mode",
        choices=STEREO_MODES + ("mono-left", "mono-right"),
        default="stereo",
        help="采集模式；stereo 要求双目时间戳匹配，stereo-async 不要求对齐（默认：stereo）",
    )
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        default=Path(f"calibration_capture_{timestamp}"),
        help="新建的输出目录；目录已存在时拒绝覆盖",
    )
    parser.add_argument(
        "--left-topic",
        default="/vimbax_camera_left/image_raw",
        help="左相机 sensor_msgs/Image 话题",
    )
    parser.add_argument(
        "--right-topic",
        default="/vimbax_camera_right/image_raw",
        help="右相机 sensor_msgs/Image 话题",
    )
    parser.add_argument(
        "--max-delta-ns",
        type=int,
        default=0,
        help="双目允许的最大绝对时间戳差，默认 0（必须完全一致）",
    )
    parser.add_argument(
        "--capture-timeout",
        type=float,
        default=5.0,
        help="每次按键等待新图像/匹配图像的秒数（默认：5）",
    )
    parser.add_argument(
        "--queue-size",
        type=int,
        default=30,
        help="每侧用于匹配的缓存帧数（默认：30）",
    )
    parser.add_argument(
        "--png-compression",
        type=int,
        choices=range(0, 10),
        default=1,
        metavar="0..9",
        help="PNG 压缩级别；0 最快、9 最小（默认：1）",
    )
    parser.add_argument(
        "--storage-id",
        default="sqlite3",
        help="rosbag2 存储插件（默认：sqlite3）",
    )
    parser.add_argument(
        "--allow-zero-stamp",
        action="store_true",
        help="允许保存 header.stamp=0 的图像（默认拒绝）",
    )
    parser.add_argument(
        "--no-visualization",
        action="store_true",
        help="不启动 OpenCV 可视化窗口，仅使用终端按键",
    )
    args = parser.parse_args()
    if args.max_delta_ns < 0:
        parser.error("--max-delta-ns 不能为负数")
    if args.capture_timeout <= 0:
        parser.error("--capture-timeout 必须大于 0")
    if args.queue_size < 2:
        parser.error("--queue-size 必须至少为 2")
    return args


def main() -> int:
    args = parse_args()
    rclpy.init(args=[])
    node: Optional[CalibrationCapture] = None
    try:
        node = CalibrationCapture(args)
        print("\n========== 标定图像按键采集 ==========")
        print(f"模式：{args.mode}")
        if args.mode in LEFT_MODES:
            print(f"左话题：{args.left_topic}")
        if args.mode in RIGHT_MODES:
            print(f"右话题：{args.right_topic}")
        if args.mode == "stereo":
            print(f"双目最大时间戳差：{args.max_delta_ns} ns")
        elif args.mode == "stereo-async":
            print("双目时间戳对齐：不要求，左右各收到一张新图像即保存")
        print(f"输出目录：{node.session_dir}")
        print("按 [空格] 或 [回车]：等待并保存下一张/下一组新图像")
        print("可视化窗口左键点击：等待并保存下一张/下一组新图像")
        print("按 [q]：结束并安全关闭 bag\n")

        if not args.no_visualization:
            node.start_visualization()

        with Keyboard() as keyboard:
            while rclpy.ok():
                rclpy.spin_once(node, timeout_sec=0.03)
                node.check_timeout()
                node.update_visualization()
                gui_key = cv2.waitKey(1) & 0xFF if node.visualization_enabled else -1
                if gui_key in (ord(" "), 13, 10):
                    node.request_capture()
                elif gui_key != -1 and chr(gui_key).lower() == "q":
                    break
                key = keyboard.read_key()
                if key in (" ", "\r", "\n"):
                    node.request_capture()
                elif key is not None and key.lower() == "q":
                    break
    except KeyboardInterrupt:
        pass
    except Exception as exc:
        print(f"[致命错误] {exc}", file=sys.stderr)
        return 1
    finally:
        if node is not None:
            node.close_visualization()
            try:
                node.close()
            except Exception as exc:
                print(f"[警告] 关闭输出时发生错误：{exc}", file=sys.stderr)
            print(
                f"\n采集结束，共保存 {node.sample_index} 个样本。\n"
                f"数据目录：{node.session_dir}",
                flush=True,
            )
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

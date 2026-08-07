#!/usr/bin/env python3
"""Export exact-timestamp stereo image pairs from a ROS 2 bag as side-by-side PNGs."""

import argparse
from pathlib import Path

import cv2
import numpy as np
import rosbag2_py
from rclpy.serialization import deserialize_message
from sensor_msgs.msg import Image


def stamp_ns(image: Image) -> int:
    return image.header.stamp.sec * 1_000_000_000 + image.header.stamp.nanosec


def image_array(image: Image) -> np.ndarray:
    if image.encoding != "mono8":
        raise ValueError(f"Only mono8 images are supported, got {image.encoding!r}")
    if image.step != image.width:
        raise ValueError(
            f"mono8 image step must equal width, got step={image.step}, width={image.width}"
        )
    return np.frombuffer(image.data, dtype=np.uint8).reshape(image.height, image.width)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("bag", type=Path, help="ROS 2 bag directory")
    parser.add_argument("output", type=Path, help="New directory for combined PNG images")
    args = parser.parse_args()

    if args.output.exists():
        raise SystemExit(f"[ERROR] Output path already exists: {args.output}")
    args.output.mkdir(parents=True)

    topics = {
        "/vimbax_camera_left/image_raw": "left",
        "/vimbax_camera_right/image_raw": "right",
    }
    reader = rosbag2_py.SequentialReader()
    reader.open(
        rosbag2_py.StorageOptions(uri=str(args.bag), storage_id="sqlite3"),
        rosbag2_py.ConverterOptions("cdr", "cdr"),
    )

    pending: dict[int, dict[str, Image]] = {}
    exported = 0
    try:
        while reader.has_next():
            topic, data, _bag_timestamp = reader.read_next()
            side = topics.get(topic)
            if side is None:
                continue

            image = deserialize_message(data, Image)
            timestamp = stamp_ns(image)
            pair = pending.setdefault(timestamp, {})
            if side in pair:
                raise RuntimeError(f"Duplicate {side} frame with timestamp {timestamp}")
            pair[side] = image
            if len(pair) != 2:
                continue

            left, right = pair["left"], pair["right"]
            if (left.width, left.height) != (right.width, right.height):
                raise RuntimeError(
                    f"Size mismatch at {timestamp}: "
                    f"left={left.width}x{left.height}, right={right.width}x{right.height}"
                )
            combined = cv2.hconcat([image_array(left), image_array(right)])
            destination = args.output / f"{exported:03d}_{timestamp}.png"
            if not cv2.imwrite(str(destination), combined, [cv2.IMWRITE_PNG_COMPRESSION, 3]):
                raise RuntimeError(f"Failed to write {destination}")
            del pending[timestamp]
            exported += 1
            if exported % 10 == 0:
                print(f"Exported {exported} pairs")
    except Exception:
        raise

    if pending:
        unmatched = sorted(pending)
        raise SystemExit(f"[ERROR] {len(unmatched)} unmatched timestamps remain: {unmatched[:10]}")
    if exported == 0:
        raise SystemExit("[ERROR] No stereo image pairs found")
    print(f"[PASS] Exported {exported} exact-timestamp stereo pairs to {args.output}")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Convert a DJI still-image dataset to mono8 PNGs and a ROS 1 Image bag.

The image timestamp is parsed from DJI_YYYYMMDDhhmmss_<index>_D.JPG.  Output
is deliberately separate from the original images so the source dataset is
never modified.
"""

import argparse
import re
import sys
from datetime import datetime, timedelta, timezone
from pathlib import Path

import cv2
import numpy as np
from rosbags.rosbag1 import Writer
from rosbags.typesys import Stores, get_typestore


PATTERN = re.compile(r"DJI_(\d{8})(\d{6})_(\d+)_D\.JPG$")
LOCAL_TZ = timezone(timedelta(hours=8))


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("source", type=Path, help="Directory containing DJI_*.JPG images")
    parser.add_argument("--topic", required=True, help="ROS image topic for the output bag")
    return parser.parse_args()


def main():
    args = parse_args()
    source = args.source.resolve()
    if not source.is_dir():
        raise RuntimeError("source directory does not exist: {}".format(source))

    records = []
    for path in source.glob("DJI_*.JPG"):
        match = PATTERN.fullmatch(path.name)
        if not match:
            raise RuntimeError("unexpected DJI filename: {}".format(path.name))
        stamp = datetime.strptime(match.group(1) + match.group(2), "%Y%m%d%H%M%S")
        records.append((stamp.replace(tzinfo=LOCAL_TZ), int(match.group(3)), path))
    records.sort(key=lambda record: (record[0], record[1]))
    if not records:
        raise RuntimeError("no DJI images found in: {}".format(source))

    mono_dir = source.with_name(source.name + "_mono8")
    bag_path = source.with_name(source.name + "_mono8.bag")
    if bag_path.exists():
        raise RuntimeError("refusing to overwrite existing output bag: {}".format(bag_path))
    if mono_dir.exists() and not mono_dir.is_dir():
        raise RuntimeError("mono8 output exists but is not a directory: {}".format(mono_dir))
    mono_dir.mkdir(exist_ok=True)
    print("Converting {} images to {}".format(len(records), mono_dir), flush=True)
    mono_records = []
    for sequence, (stamp, source_index, path) in enumerate(records):
        output = mono_dir / (path.stem + ".png")
        image = cv2.imread(str(output), cv2.IMREAD_GRAYSCALE) if output.exists() else None
        if image is None:
            image = cv2.imread(str(path), cv2.IMREAD_GRAYSCALE)
            if image is None:
                raise RuntimeError("cannot decode: {}".format(path))
            if not cv2.imwrite(str(output), image):
                raise RuntimeError("cannot write: {}".format(output))
        mono_records.append((stamp, source_index, output, image.shape))
        if (sequence + 1) % 10 == 0 or sequence + 1 == len(records):
            print("  mono8: {}/{}".format(sequence + 1, len(records)), flush=True)

    typestore = get_typestore(Stores.ROS1_NOETIC)
    image_type = "sensor_msgs/msg/Image"
    Image = typestore.types[image_type]
    Header = typestore.types["std_msgs/msg/Header"]
    Time = typestore.types["builtin_interfaces/msg/Time"]

    print("Writing ROS 1 bag {}".format(bag_path), flush=True)
    writer = Writer(bag_path)
    writer.open()
    try:
        connection = writer.add_connection(args.topic, image_type, typestore=typestore)
        for sequence, (stamp, _source_index, path, shape) in enumerate(mono_records):
            image = cv2.imread(str(path), cv2.IMREAD_GRAYSCALE)
            if image is None or image.shape != shape:
                raise RuntimeError("cannot re-read mono8 image: {}".format(path))
            height, width = image.shape
            stamp_ns = int(stamp.timestamp() * 1_000_000_000)
            message = Image(
                header=Header(
                    seq=sequence,
                    stamp=Time(sec=stamp_ns // 1_000_000_000, nanosec=stamp_ns % 1_000_000_000),
                    frame_id=source.name,
                ),
                height=height,
                width=width,
                encoding="mono8",
                is_bigendian=0,
                step=width,
                data=np.ascontiguousarray(image, dtype=np.uint8).reshape(-1),
            )
            writer.write(connection, stamp_ns, typestore.serialize_ros1(message, image_type))
            if (sequence + 1) % 10 == 0 or sequence + 1 == len(mono_records):
                print("  bag: {}/{}".format(sequence + 1, len(mono_records)), flush=True)
    finally:
        writer.close()

    print("Completed: {} mono8 images and {}".format(len(mono_records), bag_path), flush=True)


if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print("ERROR: {}".format(exc), file=sys.stderr)
        sys.exit(1)

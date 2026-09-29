#!/usr/bin/env python3
"""Convert timestamp-named phone JPEGs to mono8 PNGs and a ROS1 image bag.

Accepted names are IMG_YYYYMMDD_HHMMSS.jpg (case-insensitive).  The original
images are never modified; PNGs and the bag are written beside the dataset.
"""

from __future__ import annotations

import argparse
import re
from datetime import datetime, timedelta, timezone
from pathlib import Path

import cv2
import numpy as np
from rosbags.rosbag1 import Writer
from rosbags.typesys import Stores, get_typestore


NAME_RE = re.compile(r"IMG_(\d{8})_(\d{6})\.jpe?g$", re.IGNORECASE)
LOCAL_TZ = timezone(timedelta(hours=8))
IMAGE_TYPE = "sensor_msgs/msg/Image"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("dataset", type=Path)
    parser.add_argument("bag", type=Path)
    parser.add_argument("topic")
    args = parser.parse_args()

    dataset = args.dataset.resolve()
    if args.bag.exists():
        raise SystemExit("Refusing to overwrite existing bag: {}".format(args.bag))
    mono_dir = dataset / "mono8"
    records = []
    for source in dataset.iterdir():
        if not source.is_file():
            continue
        match = NAME_RE.fullmatch(source.name)
        if match is None:
            continue
        stamp = datetime.strptime(match.group(1) + match.group(2), "%Y%m%d%H%M%S")
        stamp_ns = int(stamp.replace(tzinfo=LOCAL_TZ).timestamp() * 1_000_000_000)
        records.append((stamp_ns, source, mono_dir / (source.stem + ".png")))
    records.sort(key=lambda item: (item[0], item[1].name))
    if not records:
        raise SystemExit("No supported phone JPEG files found in {}".format(dataset))

    converted = []
    previous_stamp = -1
    for index, (stamp_ns, source, destination) in enumerate(records, start=1):
        stamp_ns = max(stamp_ns, previous_stamp + 1)
        previous_stamp = stamp_ns
        mono = cv2.imread(str(destination), cv2.IMREAD_GRAYSCALE) if destination.exists() else None
        if mono is None:
            image = cv2.imread(str(source), cv2.IMREAD_COLOR)
            if image is None:
                raise RuntimeError("Cannot decode {}".format(source))
            mono = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
            destination.parent.mkdir(parents=True, exist_ok=True)
            if not cv2.imwrite(str(destination), mono, [cv2.IMWRITE_PNG_COMPRESSION, 3]):
                raise RuntimeError("Cannot write {}".format(destination))
        converted.append((stamp_ns, destination, mono.shape))
        if index % 20 == 0 or index == len(records):
            print("mono8: {}/{}".format(index, len(records)), flush=True)

    typestore = get_typestore(Stores.ROS1_NOETIC)
    Image = typestore.types[IMAGE_TYPE]
    Header = typestore.types["std_msgs/msg/Header"]
    Time = typestore.types["builtin_interfaces/msg/Time"]
    args.bag.parent.mkdir(parents=True, exist_ok=True)
    writer = Writer(args.bag)
    writer.open()
    try:
        connection = writer.add_connection(args.topic, IMAGE_TYPE, typestore=typestore)
        for sequence, (stamp_ns, path, shape) in enumerate(converted):
            image = cv2.imread(str(path), cv2.IMREAD_GRAYSCALE)
            if image is None or image.shape != shape:
                raise RuntimeError("Cannot reload {}".format(path))
            height, width = image.shape
            message = Image(
                header=Header(seq=sequence,
                              stamp=Time(sec=stamp_ns // 1_000_000_000,
                                         nanosec=stamp_ns % 1_000_000_000),
                              frame_id="aprilgrid_iqoo"),
                height=height, width=width, encoding="mono8", is_bigendian=0,
                step=width, data=np.ascontiguousarray(image).reshape(-1),
            )
            writer.write(connection, stamp_ns, typestore.serialize_ros1(message, IMAGE_TYPE))
            if (sequence + 1) % 20 == 0 or sequence + 1 == len(converted):
                print("bag: {}/{}".format(sequence + 1, len(converted)), flush=True)
    finally:
        writer.close()
    print("Created mono8 images: {}".format(mono_dir))
    print("Created ROS1 bag: {}".format(args.bag))


if __name__ == "__main__":
    main()

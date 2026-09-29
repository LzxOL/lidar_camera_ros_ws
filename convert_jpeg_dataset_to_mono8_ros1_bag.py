#!/usr/bin/env python3
"""Convert DJI JPEG calibration images to mono8 PNGs and one ROS1 image bag."""

from __future__ import annotations

import argparse
import re
from datetime import datetime, timedelta, timezone
from pathlib import Path

import cv2
import numpy as np
from rosbags.rosbag1 import Writer
from rosbags.typesys import Stores, get_typestore


IMAGE_TYPE = 'sensor_msgs/msg/Image'
NAME_RE = re.compile(r'DJI_(\d{8})(\d{6})_(\d+)_D\.JPG$')
LOCAL_TZ = timezone(timedelta(hours=8))


def convert_image(source: Path, destination: Path) -> tuple[int, int]:
    if destination.exists():
        image = cv2.imread(str(destination), cv2.IMREAD_GRAYSCALE)
        if image is not None:
            return image.shape[1], image.shape[0]
    image = cv2.imread(str(source), cv2.IMREAD_COLOR)
    if image is None:
        raise RuntimeError(f'Cannot decode image: {source}')
    mono8 = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    destination.parent.mkdir(parents=True, exist_ok=True)
    if not cv2.imwrite(str(destination), mono8, [cv2.IMWRITE_PNG_COMPRESSION, 3]):
        raise RuntimeError(f'Cannot write mono8 image: {destination}')
    return mono8.shape[1], mono8.shape[0]


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('dataset', type=Path, help='Directory containing DJI JPEG files')
    parser.add_argument('bag', type=Path, help='New ROS1 .bag output path')
    parser.add_argument('topic', help='ROS image topic for the output bag')
    args = parser.parse_args()

    dataset = args.dataset.resolve()
    mono_root = dataset / 'mono8'
    if args.bag.exists():
        raise SystemExit(f'Refusing to overwrite existing bag: {args.bag}')

    entries: list[tuple[int, int, Path, Path]] = []
    for source in dataset.glob('DJI_*_D.JPG'):
        match = NAME_RE.fullmatch(source.name)
        if match is None:
            continue
        stamp = datetime.strptime(match.group(1) + match.group(2), '%Y%m%d%H%M%S')
        stamp_ns = int(stamp.replace(tzinfo=LOCAL_TZ).timestamp() * 1_000_000_000)
        destination = mono_root / f'{source.stem}.png'
        entries.append((stamp_ns, int(match.group(3)), source, destination))
    entries.sort(key=lambda item: (item[0], item[1]))
    if not entries:
        raise SystemExit(f'No DJI JPEG images found in {dataset}')

    converted: list[tuple[int, Path, int, int]] = []
    previous_stamp = -1
    for index, (stamp_ns, _source_index, source, destination) in enumerate(entries, start=1):
        # Preserve chronological ordering even if two source filenames share a
        # second-resolution capture time.
        stamp_ns = max(stamp_ns, previous_stamp + 1)
        previous_stamp = stamp_ns
        width, height = convert_image(source, destination)
        converted.append((stamp_ns, destination, width, height))
        if index % 20 == 0 or index == len(entries):
            print(f'mono8: {index}/{len(entries)}', flush=True)

    typestore = get_typestore(Stores.ROS1_NOETIC)
    Image = typestore.types[IMAGE_TYPE]
    Header = typestore.types['std_msgs/msg/Header']
    Time = typestore.types['builtin_interfaces/msg/Time']
    args.bag.parent.mkdir(parents=True, exist_ok=True)
    writer = Writer(args.bag)
    writer.open()
    connection = writer.add_connection(args.topic, IMAGE_TYPE, typestore=typestore)
    try:
        for sequence, (stamp_ns, path, width, height) in enumerate(converted):
            image = cv2.imread(str(path), cv2.IMREAD_GRAYSCALE)
            if image is None or image.shape != (height, width):
                raise RuntimeError(f'Cannot reload mono8 image: {path}')
            msg = Image(
                header=Header(
                    seq=sequence,
                    stamp=Time(sec=stamp_ns // 1_000_000_000,
                               nanosec=stamp_ns % 1_000_000_000),
                    frame_id='camera',
                ),
                height=height,
                width=width,
                encoding='mono8',
                is_bigendian=0,
                step=width,
                data=np.ascontiguousarray(image).reshape(-1),
            )
            writer.write(connection, stamp_ns,
                         typestore.serialize_ros1(msg, IMAGE_TYPE))
            if (sequence + 1) % 20 == 0 or sequence + 1 == len(converted):
                print(f'bag: {sequence + 1}/{len(converted)}', flush=True)
    finally:
        writer.close()

    print(f'Created mono8 images: {mono_root}')
    print(f'Created ROS1 bag: {args.bag}')


if __name__ == '__main__':
    main()

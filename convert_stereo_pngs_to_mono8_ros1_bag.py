#!/usr/bin/env python3
"""Convert a stereo calibration PNG set to mono8 images and a ROS1 bag."""

from __future__ import annotations

import argparse
import csv
from pathlib import Path

import cv2
import numpy as np
from rosbags.rosbag1 import Writer
from rosbags.typesys import Stores, get_typestore


IMAGE_TYPE = 'sensor_msgs/msg/Image'
TOPICS = {
    'left': '/vimbax_camera_left/image_raw',
    'right': '/vimbax_camera_right/image_raw',
}


def to_mono8(source: Path, destination: Path) -> tuple[int, int]:
    if destination.exists():
        mono8 = cv2.imread(str(destination), cv2.IMREAD_GRAYSCALE)
        if mono8 is not None:
            return mono8.shape[1], mono8.shape[0]
        # An interrupted PNG write may leave a truncated derived image.  It is
        # safe to regenerate it from the untouched source image below.
    image = cv2.imread(str(source), cv2.IMREAD_UNCHANGED)
    if image is None:
        raise RuntimeError(f'Cannot decode image: {source}')
    if image.ndim == 2:
        mono8 = image
    elif image.ndim == 3 and image.shape[2] == 3:
        mono8 = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    elif image.ndim == 3 and image.shape[2] == 4:
        mono8 = cv2.cvtColor(image, cv2.COLOR_BGRA2GRAY)
    else:
        raise RuntimeError(f'Unsupported image shape {image.shape}: {source}')
    if mono8.dtype != np.uint8:
        mono8 = cv2.convertScaleAbs(mono8)
    destination.parent.mkdir(parents=True, exist_ok=True)
    if not cv2.imwrite(str(destination), mono8, [cv2.IMWRITE_PNG_COMPRESSION, 3]):
        raise RuntimeError(f'Cannot write mono8 image: {destination}')
    return mono8.shape[1], mono8.shape[0]


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('session', type=Path, help='Dataset session directory')
    parser.add_argument('bag', type=Path, help='New ROS1 .bag output path')
    parser.add_argument('--side', choices=('left', 'right'),
                        help='Convert only one camera side (default: both)')
    args = parser.parse_args()

    session = args.session.resolve()
    csv_path = session / 'timestamps.csv'
    mono_root = session / 'images_mono8'
    if args.bag.exists():
        raise SystemExit(f'Refusing to overwrite existing bag: {args.bag}')
    # A previous run may have been interrupted during image conversion.  Reuse
    # valid existing mono8 PNGs and only create the missing ones.
    mono_root.mkdir(parents=True, exist_ok=True)

    sides = (args.side,) if args.side else ('left', 'right')
    records: list[tuple[int, str, Path, Path]] = []
    with csv_path.open(newline='') as handle:
        for row in csv.DictReader(handle):
            for side in sides:
                source = session / row[f'{side}_file']
                destination = mono_root / side / source.name
                records.append((int(row[f'{side}_stamp_ns']), side, source, destination))

    records.sort(key=lambda record: record[0])
    converted: list[tuple[int, str, Path, int, int]] = []
    for index, (stamp_ns, side, source, destination) in enumerate(records, start=1):
        width, height = to_mono8(source, destination)
        converted.append((stamp_ns, side, destination, width, height))
        if index % 20 == 0 or index == len(records):
            print(f'mono8: {index}/{len(records)}', flush=True)

    typestore = get_typestore(Stores.ROS1_NOETIC)
    Image = typestore.types[IMAGE_TYPE]
    Header = typestore.types['std_msgs/msg/Header']
    Time = typestore.types['builtin_interfaces/msg/Time']
    args.bag.parent.mkdir(parents=True, exist_ok=True)
    writer = Writer(args.bag)
    writer.open()
    connections = {
        side: writer.add_connection(topic, IMAGE_TYPE, typestore=typestore)
        for side, topic in TOPICS.items() if side in sides
    }
    try:
        for sequence, (stamp_ns, side, path, width, height) in enumerate(converted):
            image = cv2.imread(str(path), cv2.IMREAD_GRAYSCALE)
            if image is None or image.shape != (height, width):
                raise RuntimeError(f'Cannot reload mono8 image: {path}')
            msg = Image(
                header=Header(
                    seq=sequence,
                    stamp=Time(sec=stamp_ns // 1_000_000_000,
                               nanosec=stamp_ns % 1_000_000_000),
                    frame_id=f'vimbax_camera_{side}',
                ),
                height=height,
                width=width,
                encoding='mono8',
                is_bigendian=0,
                step=width,
                data=np.ascontiguousarray(image).reshape(-1),
            )
            writer.write(connections[side], stamp_ns,
                         typestore.serialize_ros1(msg, IMAGE_TYPE))
            if (sequence + 1) % 20 == 0 or sequence + 1 == len(converted):
                print(f'bag: {sequence + 1}/{len(converted)}', flush=True)
    finally:
        writer.close()

    print(f'Created mono8 images: {mono_root}')
    print(f'Created ROS1 bag: {args.bag}')


if __name__ == '__main__':
    main()

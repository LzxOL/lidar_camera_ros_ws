#!/usr/bin/env python
"""Convert timestamp-named 8-bit MVS BMP images to a ROS1 mono8 bag."""

from __future__ import print_function

import argparse
import calendar
import os
import re
import time

import cv2
import rosbag
import rospy
from sensor_msgs.msg import Image


NAME_RE = re.compile(r"Image_(\d{8})(\d{6})(\d{3})\.bmp$", re.IGNORECASE)


def stamp_from_name(name):
    match = NAME_RE.match(name)
    if match is None:
        return None
    parsed = time.strptime(match.group(1) + match.group(2), "%Y%m%d%H%M%S")
    # The absolute timezone is irrelevant to calibration, but UTC conversion
    # keeps timestamps deterministic across host/container timezone settings.
    return calendar.timegm(parsed) + int(match.group(3)) / 1000.0


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source")
    parser.add_argument("bag")
    parser.add_argument("--topic", default="/mvs_camera/image_raw")
    args = parser.parse_args()

    records = []
    for name in os.listdir(args.source):
        stamp = stamp_from_name(name)
        if stamp is not None:
            records.append((stamp, name))
    records.sort()
    if not records:
        raise RuntimeError("No Image_YYYYMMDDHHMMSSmmm.bmp files found")
    if os.path.exists(args.bag):
        raise RuntimeError("Refusing to overwrite existing bag: " + args.bag)

    with rosbag.Bag(args.bag, "w") as output:
        for seq, (stamp_seconds, name) in enumerate(records):
            path = os.path.join(args.source, name)
            image = cv2.imread(path, cv2.IMREAD_GRAYSCALE)
            if image is None:
                raise RuntimeError("Cannot decode " + path)
            if image.dtype.name != "uint8" or len(image.shape) != 2:
                raise RuntimeError("Expected 8-bit grayscale BMP: " + path)

            height, width = image.shape
            stamp = rospy.Time.from_sec(stamp_seconds)
            message = Image()
            message.header.seq = seq
            message.header.stamp = stamp
            message.header.frame_id = "mvs_camera"
            message.height = height
            message.width = width
            message.encoding = "mono8"
            message.is_bigendian = 0
            message.step = width
            message.data = image.tostring()
            output.write(args.topic, message, stamp)

            if (seq + 1) % 20 == 0 or seq + 1 == len(records):
                print("bag: {}/{}".format(seq + 1, len(records)))

    print("Created {} with {} images on {}".format(args.bag, len(records), args.topic))


if __name__ == "__main__":
    main()

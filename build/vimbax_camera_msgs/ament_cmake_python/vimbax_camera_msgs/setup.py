from setuptools import find_packages
from setuptools import setup

setup(
    name='vimbax_camera_msgs',
    version='1.0.2',
    packages=find_packages(
        include=('vimbax_camera_msgs', 'vimbax_camera_msgs.*')),
)

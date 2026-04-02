from setuptools import find_packages
from setuptools import setup

setup(
    name='vimbax_camera_examples',
    version='1.0.2',
    packages=find_packages(
        include=('vimbax_camera_examples', 'vimbax_camera_examples.*')),
)

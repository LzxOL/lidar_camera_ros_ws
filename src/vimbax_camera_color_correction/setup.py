import os
from glob import glob
from setuptools import setup

package_name = 'vimbax_camera_color_correction'

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
        (os.path.join('share', package_name), ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='User',
    maintainer_email='user@example.com',
    description='Color correction node using OpenCV ColorChecker and CCM',
    license='BSD',
    tests_require=['ament_lint_auto'],
    entry_points={
        'console_scripts': [
            'color_correction_node = ' + package_name + '.color_correction_node:main',
            'lut_apply_node = ' + package_name + '.lut_apply_node:main',
        ],
    },
)

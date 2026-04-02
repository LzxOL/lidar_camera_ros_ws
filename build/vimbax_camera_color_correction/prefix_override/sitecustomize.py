import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/root1/lzx_ws/project/lidar_camera_ros_ws/install/vimbax_camera_color_correction'

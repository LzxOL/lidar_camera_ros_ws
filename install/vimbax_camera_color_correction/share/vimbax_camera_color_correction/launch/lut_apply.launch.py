from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    input_topic_arg = DeclareLaunchArgument(
        'input_topic',
        default_value='/vimbax_camera/image_raw',
        description='输入图像话题'
    )

    output_topic_arg = DeclareLaunchArgument(
        'output_topic',
        default_value='/color_corrected/image_raw',
        description='输出图像话题'
    )

    camera_info_topic_arg = DeclareLaunchArgument(
        'camera_info_topic',
        default_value='/vimbax_camera/camera_info',
        description='相机信息话题'
    )

    output_camera_info_topic_arg = DeclareLaunchArgument(
        'output_camera_info_topic',
        default_value='/color_corrected/camera_info',
        description='输出相机信息话题'
    )

    input_encoding_arg = DeclareLaunchArgument(
        'input_encoding',
        default_value='rgb8',
        description='输入图像编码 (rgb8 或 bgr8)'
    )

    output_encoding_arg = DeclareLaunchArgument(
        'output_encoding',
        default_value='rgb8',
        description='输出图像编码 (rgb8 或 bgr8)'
    )

    lut_file_arg = DeclareLaunchArgument(
        'lut_file',
        default_value='/home/root1/lzx_ws/project/lidar_camera_ros_ws/config/color_correction_lut.npy',
        description='3D LUT .npy 文件路径（由 color_correction_node 标定生成）'
    )

    return LaunchDescription([
        input_topic_arg,
        output_topic_arg,
        camera_info_topic_arg,
        output_camera_info_topic_arg,
        input_encoding_arg,
        output_encoding_arg,
        lut_file_arg,

        Node(
            package='vimbax_camera_color_correction',
            executable='lut_apply_node',
            namespace='lut_apply',
            name='lut_apply_node',
            parameters=[{
                'input_topic': LaunchConfiguration('input_topic'),
                'output_topic': LaunchConfiguration('output_topic'),
                'camera_info_topic': LaunchConfiguration('camera_info_topic'),
                'output_camera_info_topic': LaunchConfiguration('output_camera_info_topic'),
                'input_encoding': LaunchConfiguration('input_encoding'),
                'output_encoding': LaunchConfiguration('output_encoding'),
                'lut_file': LaunchConfiguration('lut_file'),
            }],
            output='screen',
        )
    ])

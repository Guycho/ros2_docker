from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_package',
            executable='my_node',
            name='pin_state_publisher',
            output='screen',
            parameters=[
                # Add parameters here if needed
            ],
        ),
    ])
#!/bin/bash

set -e

# setup ros2 environment
source "$ROS2_WS/setup.bash"

if [ -d "/home/ws/install" ]; then
    source "/home/ws/install/setup.bash"
fi

# if install directory is present, source it
if [ -d "./install" ]; then
    source "install/setup.bash"
fi

exec "$@"
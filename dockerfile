FROM ros:humble

ARG USERNAME=root
ARG USER_UID=1000
ARG USER_GID=$USER_UID

ARG APT_PACKAGES=" \
    build-essential \
    sudo \
    git \
    wget \
    curl \
    unzip \
    gdb \
    ca-certificates \
    nano \
    ninja-build \
    python3-pip \
    pybind11-dev \
    python3-distutils \
    libi2c-dev \
    wireless-tools \
    "

# install packages
RUN apt-get update && \
    apt-get upgrade -yqq && \
    apt-get install -q -y --no-install-recommends ${APT_PACKAGES} && \
    echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME && \
    chmod 0440 /etc/sudoers.d/$USERNAME && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Install pigpio from source
RUN wget https://github.com/joan2937/pigpio/archive/master.zip -O pigpio.zip && \
    unzip pigpio.zip && \
    cd pigpio-master && \
    make && \
    make install && \
    cd .. && \
    rm -rf pigpio.zip pigpio-master
    
# RUN apt-get update && \
# apt-get upgrade -yqq && \
# apt-get install -q -y --no-install-recommends ${APT_PACKAGES}
# echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME && \
# chmod 0440 /etc/sudoers.d/$USERNAME && \
# apt-get clean && \
# rm -rf /var/lib/apt/lists/*

ENV ROS2_WS=/opt/ros/humble

COPY ./ros2_entrypoint.sh /home/ros2_docker/ros2_entrypoint.sh
COPY ./ros2_ws /home/ws/

WORKDIR /home/ws/

# RUN rm -rf build install log
# RUN colcon build --symlink-install

# ENV SHELL=/bin/bash

USER $USERNAME

# Add $ROS2_WS source to bashrc
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "source /home/ws/install/setup.bash" >> ~/.bashrc

# Set execute permissions for the entry point script
RUN chmod +x /home/ros2_docker/ros2_entrypoint.sh

ENTRYPOINT ["/home/ros2_docker/ros2_entrypoint.sh"]
CMD ["bash"]
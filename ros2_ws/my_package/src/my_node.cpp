#include "my_package/my_node.hpp"

PinStatePublisher::PinStatePublisher() 
    : Node("pin_state_publisher"), pinReader(17) { // Assuming pin 17
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("pin_state", 10);
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&PinStatePublisher::publishPinState, this)
    );
}

void PinStatePublisher::publishPinState() {
    auto message = std_msgs::msg::Int32();
    message.data = pinReader.readPinState();
    RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.data);
    publisher_->publish(message);
}

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PinStatePublisher>());
    rclcpp::shutdown();
    return 0;
}
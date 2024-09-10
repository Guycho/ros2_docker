#ifndef MY_PACKAGE__MY_NODE_HPP_
#define MY_PACKAGE__MY_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include "my_package/PinReader.hpp"

class PinStatePublisher : public rclcpp::Node {
public:
    PinStatePublisher();

private:
    void publishPinState();

    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    PinReader pinReader;
};

#endif // MY_PACKAGE__MY_NODE_HPP_
#include <rclcpp/rclcpp.hpp>
#include <wiringPi.h>

class MotorNode : public rclcpp::Node
{
public:
    MotorNode(int pin) : Node("motor_node"), pin_(pin)
    {
        if (wiringPiSetup() == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to initialize WiringPi");
            throw std::runtime_error("WiringPi init failed");
        }

        pinMode(pin_, OUTPUT);

        // Simple timer to blink PWM-like signal
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&MotorNode::togglePin, this)
        );
    }

private:
    void togglePin()
    {
        digitalWrite(pin_, state_);
        state_ = !state_;
    }

    int pin_;
    int state_ = LOW;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    int pin = 0;  // WiringPi pin 0 (GPIO 17)
    if (argc > 1) pin = std::stoi(argv[1]);

    auto node = std::make_shared<MotorNode>(pin);
    RCLCPP_INFO(node->get_logger(), "Starting motor node on WiringPi pin %d", pin);

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
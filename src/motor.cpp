#include <rclcpp/rclcpp.hpp>
#include <wiringPi.h>

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  wiringPiSetup();
  pinMode(17, OUTPUT);

  auto node = rclcpp::Node::make_shared("gpio_node");

  while (rclcpp::ok()) {
    digitalWrite(17, HIGH);
    delay(500);
    digitalWrite(17, LOW);
    delay(500);
  }

  rclcpp::shutdown();
  return 0;
}
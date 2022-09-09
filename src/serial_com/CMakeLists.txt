cmake_minimum_required(VERSION 3.5)
project(serial_com)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(serial_arduino src/serial_arduino.cpp)
ament_target_dependencies(serial_arduino rclcpp std_msgs)

install(TARGETS
  serial_arduino
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

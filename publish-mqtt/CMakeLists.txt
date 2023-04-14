# Set the minimum version of CMake required to build the project
cmake_minimum_required(VERSION 3.8)

# Set the project name
set(CMAKE_CXX_STANDARD 17)

# Set the C++ standard to use
project(publish-mqtt)

# Add a subdirectory for the source code
add_subdirectory(inc/paho.mqtt.cpp)

file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the main executable
add_executable(publish-mqtt ${SOURCES})

# Link the required libraries to the executable
target_link_libraries(publish-mqtt PRIVATE paho-mqttpp3)

# the target "publish-mqtt" depends on the target "paho-mqttpp3"
add_dependencies(publish-mqtt paho-mqttpp3)

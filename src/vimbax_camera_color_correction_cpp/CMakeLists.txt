cmake_minimum_required(VERSION 3.8)
project(vimbax_camera_color_correction_cpp)

# C++ standard
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Source files
set(NODE_SOURCE_FILES
  src/color_lut.cpp
  src/color_correction_node.cpp
)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(image_transport REQUIRED)
find_package(camera_info_manager REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)

# Enable OpenMP (optional but recommended for performance)
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  message(STATUS "OpenMP found, enabling parallel processing")
else()
  message(STATUS "OpenMP not found, building without parallel processing")
endif()

# Create library
add_library(${PROJECT_NAME} SHARED ${NODE_SOURCE_FILES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Compile features
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99 cxx_std_17)

# All dependencies - using plain signature to match ament_target_dependencies
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  rclcpp_components
  image_transport
  camera_info_manager
  cv_bridge
  sensor_msgs
  std_msgs
  OpenCV
)

# Add OpenMP if available - use plain signature
if(OpenMP_CXX_FOUND)
  target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_CXX)
endif()

# Export
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(
  rclcpp
  rclcpp_components
  image_transport
  camera_info_manager
  cv_bridge
  sensor_msgs
  std_msgs
  OpenCV
)

# Register as component
rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "vimbax_camera_color_correction::ColorCorrectionNode"
  EXECUTABLE color_correction_cpp_node
  EXECUTOR MultiThreadedExecutor
)

# Install
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/
  DESTINATION include
)

# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# Install config directory (from project root)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/../../config
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL
)

ament_package()

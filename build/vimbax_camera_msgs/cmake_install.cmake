# Install script for directory: /home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/root1/lzx_ws/project/lidar_camera_ros_ws/install/vimbax_camera_msgs")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_interfaces" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/vimbax_camera_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vimbax_camera_msgs/vimbax_camera_msgs" TYPE DIRECTORY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_c/vimbax_camera_msgs/" REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/environment" TYPE FILE FILES "/opt/ros/humble/lib/python3.10/site-packages/ament_package/template/environment_hook/library_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/environment" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/library_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/libvimbax_camera_msgs__rosidl_generator_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_c.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_c.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vimbax_camera_msgs/vimbax_camera_msgs" TYPE DIRECTORY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_typesupport_fastrtps_c/vimbax_camera_msgs/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_c.so"
         OLD_RPATH "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_c.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vimbax_camera_msgs/vimbax_camera_msgs" TYPE DIRECTORY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_typesupport_introspection_c/vimbax_camera_msgs/" REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/libvimbax_camera_msgs__rosidl_typesupport_introspection_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_c.so"
         OLD_RPATH "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_c.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/libvimbax_camera_msgs__rosidl_typesupport_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_c.so"
         OLD_RPATH "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_c.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vimbax_camera_msgs/vimbax_camera_msgs" TYPE DIRECTORY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_cpp/vimbax_camera_msgs/" REGEX "/[^/]*\\.hpp$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vimbax_camera_msgs/vimbax_camera_msgs" TYPE DIRECTORY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_typesupport_fastrtps_cpp/vimbax_camera_msgs/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_fastrtps_cpp.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vimbax_camera_msgs/vimbax_camera_msgs" TYPE DIRECTORY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_typesupport_introspection_cpp/vimbax_camera_msgs/" REGEX "/[^/]*\\.hpp$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/libvimbax_camera_msgs__rosidl_typesupport_introspection_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_introspection_cpp.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/libvimbax_camera_msgs__rosidl_typesupport_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_typesupport_cpp.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/environment" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/environment" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs-1.0.2-py3.10.egg-info" TYPE DIRECTORY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_python/vimbax_camera_msgs/vimbax_camera_msgs.egg-info/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs" TYPE DIRECTORY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_py/vimbax_camera_msgs/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/usr/bin/python3" "-m" "compileall"
        "/home/root1/lzx_ws/project/lidar_camera_ros_ws/install/vimbax_camera_msgs/local/lib/python3.10/dist-packages/vimbax_camera_msgs"
      )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_py/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so"
         OLD_RPATH "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_py/vimbax_camera_msgs:/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_fastrtps_c.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_py/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so"
         OLD_RPATH "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_py/vimbax_camera_msgs:/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_introspection_c.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_py/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so"
         OLD_RPATH "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_py/vimbax_camera_msgs:/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/vimbax_camera_msgs/vimbax_camera_msgs_s__rosidl_typesupport_c.cpython-310-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_py.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_py.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_py.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_generator_py/vimbax_camera_msgs/libvimbax_camera_msgs__rosidl_generator_py.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_py.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_py.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_py.so"
         OLD_RPATH "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvimbax_camera_msgs__rosidl_generator_py.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/msg/FeatureFlags.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/msg/FeatureInfo.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/msg/EventDataEntry.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/msg/EventData.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/msg/Error.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/msg/FeatureModule.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/msg/TriggerInfo.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureIntGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureIntSet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureIntInfoGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureFloatGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureFloatSet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureFloatInfoGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureStringGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureStringSet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureStringInfoGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureBoolGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureBoolSet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureCommandIsDone.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureCommandRun.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureEnumGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureEnumSet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureEnumInfoGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureEnumAsIntGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureEnumAsStringGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureRawGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureRawSet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureRawInfoGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureAccessModeGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeatureInfoQuery.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/FeaturesListGet.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/SettingsLoadSave.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/Status.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/StreamStartStop.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/SubscribeEvent.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/UnsubscribeEvent.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_adapter/vimbax_camera_msgs/srv/ConnectionStatus.idl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/msg/FeatureFlags.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/msg/FeatureInfo.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/msg/EventDataEntry.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/msg/EventData.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/msg/Error.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/msg/FeatureModule.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/msg" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/msg/TriggerInfo.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureIntGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureIntGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureIntGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureIntSet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureIntSet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureIntSet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureIntInfoGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureIntInfoGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureIntInfoGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureFloatGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureFloatGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureFloatGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureFloatSet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureFloatSet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureFloatSet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureFloatInfoGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureFloatInfoGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureFloatInfoGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureStringGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureStringGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureStringGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureStringSet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureStringSet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureStringSet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureStringInfoGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureStringInfoGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureStringInfoGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureBoolGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureBoolGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureBoolGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureBoolSet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureBoolSet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureBoolSet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureCommandIsDone.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureCommandIsDone_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureCommandIsDone_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureCommandRun.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureCommandRun_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureCommandRun_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureEnumGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureEnumSet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumSet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumSet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureEnumInfoGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumInfoGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumInfoGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureEnumAsIntGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumAsIntGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumAsIntGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureEnumAsStringGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumAsStringGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureEnumAsStringGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureRawGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureRawGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureRawGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureRawSet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureRawSet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureRawSet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureRawInfoGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureRawInfoGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureRawInfoGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureAccessModeGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureAccessModeGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureAccessModeGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeatureInfoQuery.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureInfoQuery_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeatureInfoQuery_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/FeaturesListGet.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeaturesListGet_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/FeaturesListGet_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/SettingsLoadSave.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/SettingsLoadSave_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/SettingsLoadSave_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/Status.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/Status_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/Status_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/StreamStartStop.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/StreamStartStop_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/StreamStartStop_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/SubscribeEvent.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/SubscribeEvent_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/SubscribeEvent_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/UnsubscribeEvent.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/UnsubscribeEvent_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/UnsubscribeEvent_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/srv/ConnectionStatus.srv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/ConnectionStatus_Request.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/srv" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/srv/ConnectionStatus_Response.msg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/vimbax_camera_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/vimbax_camera_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/environment" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/environment" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_index/share/ament_index/resource_index/packages/vimbax_camera_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_cExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_generator_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_generator_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_generator_cExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_introspection_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_introspection_cExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_introspection_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_introspection_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_introspection_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_introspection_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_introspection_cExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_cExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_cExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_cExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_cExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_cExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_cExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_cExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_cppExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_cppExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_generator_cppExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_cppExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_cppExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_generator_cppExport.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cppExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cppExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cppExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cppExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cppExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cppExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_typesupport_fastrtps_cppExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_introspection_cppExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_introspection_cppExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_introspection_cppExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_introspection_cppExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_introspection_cppExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_introspection_cppExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_introspection_cppExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_cppExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_cppExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_cppExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_cppExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/vimbax_camera_msgs__rosidl_typesupport_cppExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_cppExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/vimbax_camera_msgs__rosidl_typesupport_cppExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_pyExport.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_pyExport.cmake"
         "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_generator_pyExport.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_pyExport-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake/export_vimbax_camera_msgs__rosidl_generator_pyExport.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_generator_pyExport.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/CMakeFiles/Export/a735e1a6c48709134ac33f7387f45e9d/export_vimbax_camera_msgs__rosidl_generator_pyExport-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/rosidl_cmake-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs/cmake" TYPE FILE FILES
    "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_core/vimbax_camera_msgsConfig.cmake"
    "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/ament_cmake_core/vimbax_camera_msgsConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vimbax_camera_msgs" TYPE FILE FILES "/home/root1/lzx_ws/project/lidar_camera_ros_ws/src/vimbax_ros2_driver/vimbax_camera_msgs/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/vimbax_camera_msgs__py/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/root1/lzx_ws/project/lidar_camera_ros_ws/build/vimbax_camera_msgs/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

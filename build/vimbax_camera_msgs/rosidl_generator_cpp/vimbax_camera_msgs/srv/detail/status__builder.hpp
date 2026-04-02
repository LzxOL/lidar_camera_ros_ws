// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/Status.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::Status_Request>()
{
  return ::vimbax_camera_msgs::srv::Status_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_Status_Response_mac_address
{
public:
  explicit Init_Status_Response_mac_address(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::Status_Response mac_address(::vimbax_camera_msgs::srv::Status_Response::_mac_address_type arg)
  {
    msg_.mac_address = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_ip_address
{
public:
  explicit Init_Status_Response_ip_address(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_mac_address ip_address(::vimbax_camera_msgs::srv::Status_Response::_ip_address_type arg)
  {
    msg_.ip_address = std::move(arg);
    return Init_Status_Response_mac_address(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_trigger_info
{
public:
  explicit Init_Status_Response_trigger_info(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_ip_address trigger_info(::vimbax_camera_msgs::srv::Status_Response::_trigger_info_type arg)
  {
    msg_.trigger_info = std::move(arg);
    return Init_Status_Response_ip_address(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_pixel_format
{
public:
  explicit Init_Status_Response_pixel_format(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_trigger_info pixel_format(::vimbax_camera_msgs::srv::Status_Response::_pixel_format_type arg)
  {
    msg_.pixel_format = std::move(arg);
    return Init_Status_Response_trigger_info(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_frame_rate
{
public:
  explicit Init_Status_Response_frame_rate(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_pixel_format frame_rate(::vimbax_camera_msgs::srv::Status_Response::_frame_rate_type arg)
  {
    msg_.frame_rate = std::move(arg);
    return Init_Status_Response_pixel_format(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_height
{
public:
  explicit Init_Status_Response_height(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_frame_rate height(::vimbax_camera_msgs::srv::Status_Response::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_Status_Response_frame_rate(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_width
{
public:
  explicit Init_Status_Response_width(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_height width(::vimbax_camera_msgs::srv::Status_Response::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_Status_Response_height(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_streaming
{
public:
  explicit Init_Status_Response_streaming(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_width streaming(::vimbax_camera_msgs::srv::Status_Response::_streaming_type arg)
  {
    msg_.streaming = std::move(arg);
    return Init_Status_Response_width(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_transport_layer_id
{
public:
  explicit Init_Status_Response_transport_layer_id(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_streaming transport_layer_id(::vimbax_camera_msgs::srv::Status_Response::_transport_layer_id_type arg)
  {
    msg_.transport_layer_id = std::move(arg);
    return Init_Status_Response_streaming(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_interface_id
{
public:
  explicit Init_Status_Response_interface_id(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_transport_layer_id interface_id(::vimbax_camera_msgs::srv::Status_Response::_interface_id_type arg)
  {
    msg_.interface_id = std::move(arg);
    return Init_Status_Response_transport_layer_id(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_device_serial_number
{
public:
  explicit Init_Status_Response_device_serial_number(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_interface_id device_serial_number(::vimbax_camera_msgs::srv::Status_Response::_device_serial_number_type arg)
  {
    msg_.device_serial_number = std::move(arg);
    return Init_Status_Response_interface_id(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_device_user_id
{
public:
  explicit Init_Status_Response_device_user_id(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_device_serial_number device_user_id(::vimbax_camera_msgs::srv::Status_Response::_device_user_id_type arg)
  {
    msg_.device_user_id = std::move(arg);
    return Init_Status_Response_device_serial_number(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_device_id
{
public:
  explicit Init_Status_Response_device_id(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_device_user_id device_id(::vimbax_camera_msgs::srv::Status_Response::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return Init_Status_Response_device_user_id(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_device_firmware_version
{
public:
  explicit Init_Status_Response_device_firmware_version(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_device_id device_firmware_version(::vimbax_camera_msgs::srv::Status_Response::_device_firmware_version_type arg)
  {
    msg_.device_firmware_version = std::move(arg);
    return Init_Status_Response_device_id(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_model_name
{
public:
  explicit Init_Status_Response_model_name(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_device_firmware_version model_name(::vimbax_camera_msgs::srv::Status_Response::_model_name_type arg)
  {
    msg_.model_name = std::move(arg);
    return Init_Status_Response_device_firmware_version(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_display_name
{
public:
  explicit Init_Status_Response_display_name(::vimbax_camera_msgs::srv::Status_Response & msg)
  : msg_(msg)
  {}
  Init_Status_Response_model_name display_name(::vimbax_camera_msgs::srv::Status_Response::_display_name_type arg)
  {
    msg_.display_name = std::move(arg);
    return Init_Status_Response_model_name(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

class Init_Status_Response_error
{
public:
  Init_Status_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Status_Response_display_name error(::vimbax_camera_msgs::srv::Status_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return Init_Status_Response_display_name(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::Status_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::Status_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_Status_Response_error();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__BUILDER_HPP_

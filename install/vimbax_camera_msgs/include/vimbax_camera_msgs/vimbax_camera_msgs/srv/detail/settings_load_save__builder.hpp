// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/SettingsLoadSave.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__SETTINGS_LOAD_SAVE__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__SETTINGS_LOAD_SAVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/settings_load_save__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_SettingsLoadSave_Request_filename
{
public:
  Init_SettingsLoadSave_Request_filename()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vimbax_camera_msgs::srv::SettingsLoadSave_Request filename(::vimbax_camera_msgs::srv::SettingsLoadSave_Request::_filename_type arg)
  {
    msg_.filename = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::SettingsLoadSave_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::SettingsLoadSave_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_SettingsLoadSave_Request_filename();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_SettingsLoadSave_Response_error
{
public:
  Init_SettingsLoadSave_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vimbax_camera_msgs::srv::SettingsLoadSave_Response error(::vimbax_camera_msgs::srv::SettingsLoadSave_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::SettingsLoadSave_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::SettingsLoadSave_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_SettingsLoadSave_Response_error();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__SETTINGS_LOAD_SAVE__BUILDER_HPP_

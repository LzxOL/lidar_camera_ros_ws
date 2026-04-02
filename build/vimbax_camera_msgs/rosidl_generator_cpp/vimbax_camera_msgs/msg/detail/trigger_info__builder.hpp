// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:msg/TriggerInfo.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/msg/detail/trigger_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace msg
{

namespace builder
{

class Init_TriggerInfo_source
{
public:
  explicit Init_TriggerInfo_source(::vimbax_camera_msgs::msg::TriggerInfo & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::msg::TriggerInfo source(::vimbax_camera_msgs::msg::TriggerInfo::_source_type arg)
  {
    msg_.source = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::TriggerInfo msg_;
};

class Init_TriggerInfo_mode
{
public:
  explicit Init_TriggerInfo_mode(::vimbax_camera_msgs::msg::TriggerInfo & msg)
  : msg_(msg)
  {}
  Init_TriggerInfo_source mode(::vimbax_camera_msgs::msg::TriggerInfo::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_TriggerInfo_source(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::TriggerInfo msg_;
};

class Init_TriggerInfo_selector
{
public:
  Init_TriggerInfo_selector()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriggerInfo_mode selector(::vimbax_camera_msgs::msg::TriggerInfo::_selector_type arg)
  {
    msg_.selector = std::move(arg);
    return Init_TriggerInfo_mode(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::TriggerInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::msg::TriggerInfo>()
{
  return vimbax_camera_msgs::msg::builder::Init_TriggerInfo_selector();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__BUILDER_HPP_

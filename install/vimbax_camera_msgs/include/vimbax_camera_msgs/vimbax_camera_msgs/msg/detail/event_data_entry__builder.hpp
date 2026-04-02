// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:msg/EventDataEntry.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/msg/detail/event_data_entry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace msg
{

namespace builder
{

class Init_EventDataEntry_value
{
public:
  explicit Init_EventDataEntry_value(::vimbax_camera_msgs::msg::EventDataEntry & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::msg::EventDataEntry value(::vimbax_camera_msgs::msg::EventDataEntry::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::EventDataEntry msg_;
};

class Init_EventDataEntry_name
{
public:
  Init_EventDataEntry_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EventDataEntry_value name(::vimbax_camera_msgs::msg::EventDataEntry::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_EventDataEntry_value(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::EventDataEntry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::msg::EventDataEntry>()
{
  return vimbax_camera_msgs::msg::builder::Init_EventDataEntry_name();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__BUILDER_HPP_

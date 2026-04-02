// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__ERROR__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__ERROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/msg/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace msg
{

namespace builder
{

class Init_Error_text
{
public:
  explicit Init_Error_text(::vimbax_camera_msgs::msg::Error & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::msg::Error text(::vimbax_camera_msgs::msg::Error::_text_type arg)
  {
    msg_.text = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::Error msg_;
};

class Init_Error_code
{
public:
  Init_Error_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Error_text code(::vimbax_camera_msgs::msg::Error::_code_type arg)
  {
    msg_.code = std::move(arg);
    return Init_Error_text(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::Error msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::msg::Error>()
{
  return vimbax_camera_msgs::msg::builder::Init_Error_code();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__ERROR__BUILDER_HPP_

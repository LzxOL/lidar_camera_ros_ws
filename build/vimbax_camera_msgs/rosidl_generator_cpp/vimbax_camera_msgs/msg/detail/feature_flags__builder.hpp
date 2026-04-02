// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureFlags.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/msg/detail/feature_flags__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace msg
{

namespace builder
{

class Init_FeatureFlags_flag_modify_write
{
public:
  explicit Init_FeatureFlags_flag_modify_write(::vimbax_camera_msgs::msg::FeatureFlags & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::msg::FeatureFlags flag_modify_write(::vimbax_camera_msgs::msg::FeatureFlags::_flag_modify_write_type arg)
  {
    msg_.flag_modify_write = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureFlags msg_;
};

class Init_FeatureFlags_flag_volatile
{
public:
  explicit Init_FeatureFlags_flag_volatile(::vimbax_camera_msgs::msg::FeatureFlags & msg)
  : msg_(msg)
  {}
  Init_FeatureFlags_flag_modify_write flag_volatile(::vimbax_camera_msgs::msg::FeatureFlags::_flag_volatile_type arg)
  {
    msg_.flag_volatile = std::move(arg);
    return Init_FeatureFlags_flag_modify_write(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureFlags msg_;
};

class Init_FeatureFlags_flag_write
{
public:
  explicit Init_FeatureFlags_flag_write(::vimbax_camera_msgs::msg::FeatureFlags & msg)
  : msg_(msg)
  {}
  Init_FeatureFlags_flag_volatile flag_write(::vimbax_camera_msgs::msg::FeatureFlags::_flag_write_type arg)
  {
    msg_.flag_write = std::move(arg);
    return Init_FeatureFlags_flag_volatile(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureFlags msg_;
};

class Init_FeatureFlags_flag_read
{
public:
  explicit Init_FeatureFlags_flag_read(::vimbax_camera_msgs::msg::FeatureFlags & msg)
  : msg_(msg)
  {}
  Init_FeatureFlags_flag_write flag_read(::vimbax_camera_msgs::msg::FeatureFlags::_flag_read_type arg)
  {
    msg_.flag_read = std::move(arg);
    return Init_FeatureFlags_flag_write(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureFlags msg_;
};

class Init_FeatureFlags_flag_none
{
public:
  Init_FeatureFlags_flag_none()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureFlags_flag_read flag_none(::vimbax_camera_msgs::msg::FeatureFlags::_flag_none_type arg)
  {
    msg_.flag_none = std::move(arg);
    return Init_FeatureFlags_flag_read(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureFlags msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::msg::FeatureFlags>()
{
  return vimbax_camera_msgs::msg::builder::Init_FeatureFlags_flag_none();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__BUILDER_HPP_

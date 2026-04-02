// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureModule.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/msg/detail/feature_module__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace msg
{

namespace builder
{

class Init_FeatureModule_id
{
public:
  Init_FeatureModule_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vimbax_camera_msgs::msg::FeatureModule id(::vimbax_camera_msgs::msg::FeatureModule::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureModule msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::msg::FeatureModule>()
{
  return vimbax_camera_msgs::msg::builder::Init_FeatureModule_id();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__BUILDER_HPP_

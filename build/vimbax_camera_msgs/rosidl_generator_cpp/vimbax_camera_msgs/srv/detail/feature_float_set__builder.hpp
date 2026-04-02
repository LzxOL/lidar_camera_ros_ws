// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureFloatSet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_SET__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_SET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_float_set__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureFloatSet_Request_value
{
public:
  explicit Init_FeatureFloatSet_Request_value(::vimbax_camera_msgs::srv::FeatureFloatSet_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureFloatSet_Request value(::vimbax_camera_msgs::srv::FeatureFloatSet_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureFloatSet_Request msg_;
};

class Init_FeatureFloatSet_Request_feature_module
{
public:
  explicit Init_FeatureFloatSet_Request_feature_module(::vimbax_camera_msgs::srv::FeatureFloatSet_Request & msg)
  : msg_(msg)
  {}
  Init_FeatureFloatSet_Request_value feature_module(::vimbax_camera_msgs::srv::FeatureFloatSet_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return Init_FeatureFloatSet_Request_value(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureFloatSet_Request msg_;
};

class Init_FeatureFloatSet_Request_feature_name
{
public:
  Init_FeatureFloatSet_Request_feature_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureFloatSet_Request_feature_module feature_name(::vimbax_camera_msgs::srv::FeatureFloatSet_Request::_feature_name_type arg)
  {
    msg_.feature_name = std::move(arg);
    return Init_FeatureFloatSet_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureFloatSet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureFloatSet_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureFloatSet_Request_feature_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureFloatSet_Response_error
{
public:
  Init_FeatureFloatSet_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vimbax_camera_msgs::srv::FeatureFloatSet_Response error(::vimbax_camera_msgs::srv::FeatureFloatSet_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureFloatSet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureFloatSet_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureFloatSet_Response_error();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_SET__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureFloatGet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_GET__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_GET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_float_get__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureFloatGet_Request_feature_module
{
public:
  explicit Init_FeatureFloatGet_Request_feature_module(::vimbax_camera_msgs::srv::FeatureFloatGet_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureFloatGet_Request feature_module(::vimbax_camera_msgs::srv::FeatureFloatGet_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureFloatGet_Request msg_;
};

class Init_FeatureFloatGet_Request_feature_name
{
public:
  Init_FeatureFloatGet_Request_feature_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureFloatGet_Request_feature_module feature_name(::vimbax_camera_msgs::srv::FeatureFloatGet_Request::_feature_name_type arg)
  {
    msg_.feature_name = std::move(arg);
    return Init_FeatureFloatGet_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureFloatGet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureFloatGet_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureFloatGet_Request_feature_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureFloatGet_Response_error
{
public:
  explicit Init_FeatureFloatGet_Response_error(::vimbax_camera_msgs::srv::FeatureFloatGet_Response & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureFloatGet_Response error(::vimbax_camera_msgs::srv::FeatureFloatGet_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureFloatGet_Response msg_;
};

class Init_FeatureFloatGet_Response_value
{
public:
  Init_FeatureFloatGet_Response_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureFloatGet_Response_error value(::vimbax_camera_msgs::srv::FeatureFloatGet_Response::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_FeatureFloatGet_Response_error(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureFloatGet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureFloatGet_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureFloatGet_Response_value();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_GET__BUILDER_HPP_

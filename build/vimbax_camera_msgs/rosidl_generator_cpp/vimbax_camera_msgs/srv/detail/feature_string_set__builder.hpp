// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureStringSet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_STRING_SET__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_STRING_SET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_string_set__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureStringSet_Request_value
{
public:
  explicit Init_FeatureStringSet_Request_value(::vimbax_camera_msgs::srv::FeatureStringSet_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureStringSet_Request value(::vimbax_camera_msgs::srv::FeatureStringSet_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureStringSet_Request msg_;
};

class Init_FeatureStringSet_Request_feature_module
{
public:
  explicit Init_FeatureStringSet_Request_feature_module(::vimbax_camera_msgs::srv::FeatureStringSet_Request & msg)
  : msg_(msg)
  {}
  Init_FeatureStringSet_Request_value feature_module(::vimbax_camera_msgs::srv::FeatureStringSet_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return Init_FeatureStringSet_Request_value(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureStringSet_Request msg_;
};

class Init_FeatureStringSet_Request_feature_name
{
public:
  Init_FeatureStringSet_Request_feature_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureStringSet_Request_feature_module feature_name(::vimbax_camera_msgs::srv::FeatureStringSet_Request::_feature_name_type arg)
  {
    msg_.feature_name = std::move(arg);
    return Init_FeatureStringSet_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureStringSet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureStringSet_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureStringSet_Request_feature_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureStringSet_Response_error
{
public:
  Init_FeatureStringSet_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vimbax_camera_msgs::srv::FeatureStringSet_Response error(::vimbax_camera_msgs::srv::FeatureStringSet_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureStringSet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureStringSet_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureStringSet_Response_error();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_STRING_SET__BUILDER_HPP_

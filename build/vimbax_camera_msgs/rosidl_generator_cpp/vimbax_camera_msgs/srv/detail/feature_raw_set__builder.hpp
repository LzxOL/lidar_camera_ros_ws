// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureRawSet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_SET__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_SET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_raw_set__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureRawSet_Request_buffer
{
public:
  explicit Init_FeatureRawSet_Request_buffer(::vimbax_camera_msgs::srv::FeatureRawSet_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureRawSet_Request buffer(::vimbax_camera_msgs::srv::FeatureRawSet_Request::_buffer_type arg)
  {
    msg_.buffer = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawSet_Request msg_;
};

class Init_FeatureRawSet_Request_feature_module
{
public:
  explicit Init_FeatureRawSet_Request_feature_module(::vimbax_camera_msgs::srv::FeatureRawSet_Request & msg)
  : msg_(msg)
  {}
  Init_FeatureRawSet_Request_buffer feature_module(::vimbax_camera_msgs::srv::FeatureRawSet_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return Init_FeatureRawSet_Request_buffer(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawSet_Request msg_;
};

class Init_FeatureRawSet_Request_feature_name
{
public:
  Init_FeatureRawSet_Request_feature_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureRawSet_Request_feature_module feature_name(::vimbax_camera_msgs::srv::FeatureRawSet_Request::_feature_name_type arg)
  {
    msg_.feature_name = std::move(arg);
    return Init_FeatureRawSet_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawSet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureRawSet_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureRawSet_Request_feature_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureRawSet_Response_error
{
public:
  Init_FeatureRawSet_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vimbax_camera_msgs::srv::FeatureRawSet_Response error(::vimbax_camera_msgs::srv::FeatureRawSet_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawSet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureRawSet_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureRawSet_Response_error();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_SET__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureRawGet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_GET__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_GET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_raw_get__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureRawGet_Request_feature_module
{
public:
  explicit Init_FeatureRawGet_Request_feature_module(::vimbax_camera_msgs::srv::FeatureRawGet_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureRawGet_Request feature_module(::vimbax_camera_msgs::srv::FeatureRawGet_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawGet_Request msg_;
};

class Init_FeatureRawGet_Request_feature_name
{
public:
  Init_FeatureRawGet_Request_feature_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureRawGet_Request_feature_module feature_name(::vimbax_camera_msgs::srv::FeatureRawGet_Request::_feature_name_type arg)
  {
    msg_.feature_name = std::move(arg);
    return Init_FeatureRawGet_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawGet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureRawGet_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureRawGet_Request_feature_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureRawGet_Response_error
{
public:
  explicit Init_FeatureRawGet_Response_error(::vimbax_camera_msgs::srv::FeatureRawGet_Response & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureRawGet_Response error(::vimbax_camera_msgs::srv::FeatureRawGet_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawGet_Response msg_;
};

class Init_FeatureRawGet_Response_buffer_size
{
public:
  explicit Init_FeatureRawGet_Response_buffer_size(::vimbax_camera_msgs::srv::FeatureRawGet_Response & msg)
  : msg_(msg)
  {}
  Init_FeatureRawGet_Response_error buffer_size(::vimbax_camera_msgs::srv::FeatureRawGet_Response::_buffer_size_type arg)
  {
    msg_.buffer_size = std::move(arg);
    return Init_FeatureRawGet_Response_error(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawGet_Response msg_;
};

class Init_FeatureRawGet_Response_buffer
{
public:
  Init_FeatureRawGet_Response_buffer()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureRawGet_Response_buffer_size buffer(::vimbax_camera_msgs::srv::FeatureRawGet_Response::_buffer_type arg)
  {
    msg_.buffer = std::move(arg);
    return Init_FeatureRawGet_Response_buffer_size(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureRawGet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureRawGet_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureRawGet_Response_buffer();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_GET__BUILDER_HPP_

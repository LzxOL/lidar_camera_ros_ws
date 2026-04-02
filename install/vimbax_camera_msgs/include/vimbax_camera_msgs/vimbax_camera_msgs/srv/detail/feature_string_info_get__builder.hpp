// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureStringInfoGet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_STRING_INFO_GET__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_STRING_INFO_GET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_string_info_get__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureStringInfoGet_Request_feature_module
{
public:
  explicit Init_FeatureStringInfoGet_Request_feature_module(::vimbax_camera_msgs::srv::FeatureStringInfoGet_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureStringInfoGet_Request feature_module(::vimbax_camera_msgs::srv::FeatureStringInfoGet_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureStringInfoGet_Request msg_;
};

class Init_FeatureStringInfoGet_Request_feature_name
{
public:
  Init_FeatureStringInfoGet_Request_feature_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureStringInfoGet_Request_feature_module feature_name(::vimbax_camera_msgs::srv::FeatureStringInfoGet_Request::_feature_name_type arg)
  {
    msg_.feature_name = std::move(arg);
    return Init_FeatureStringInfoGet_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureStringInfoGet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureStringInfoGet_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureStringInfoGet_Request_feature_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureStringInfoGet_Response_error
{
public:
  explicit Init_FeatureStringInfoGet_Response_error(::vimbax_camera_msgs::srv::FeatureStringInfoGet_Response & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureStringInfoGet_Response error(::vimbax_camera_msgs::srv::FeatureStringInfoGet_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureStringInfoGet_Response msg_;
};

class Init_FeatureStringInfoGet_Response_max_length
{
public:
  Init_FeatureStringInfoGet_Response_max_length()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureStringInfoGet_Response_error max_length(::vimbax_camera_msgs::srv::FeatureStringInfoGet_Response::_max_length_type arg)
  {
    msg_.max_length = std::move(arg);
    return Init_FeatureStringInfoGet_Response_error(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureStringInfoGet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureStringInfoGet_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureStringInfoGet_Response_max_length();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_STRING_INFO_GET__BUILDER_HPP_

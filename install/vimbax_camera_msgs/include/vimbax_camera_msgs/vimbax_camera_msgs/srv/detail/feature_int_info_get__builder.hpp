// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureIntInfoGet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INT_INFO_GET__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INT_INFO_GET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_int_info_get__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureIntInfoGet_Request_feature_module
{
public:
  explicit Init_FeatureIntInfoGet_Request_feature_module(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureIntInfoGet_Request feature_module(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureIntInfoGet_Request msg_;
};

class Init_FeatureIntInfoGet_Request_feature_name
{
public:
  Init_FeatureIntInfoGet_Request_feature_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureIntInfoGet_Request_feature_module feature_name(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Request::_feature_name_type arg)
  {
    msg_.feature_name = std::move(arg);
    return Init_FeatureIntInfoGet_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureIntInfoGet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureIntInfoGet_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureIntInfoGet_Request_feature_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureIntInfoGet_Response_error
{
public:
  explicit Init_FeatureIntInfoGet_Response_error(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response error(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response msg_;
};

class Init_FeatureIntInfoGet_Response_inc
{
public:
  explicit Init_FeatureIntInfoGet_Response_inc(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response & msg)
  : msg_(msg)
  {}
  Init_FeatureIntInfoGet_Response_error inc(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response::_inc_type arg)
  {
    msg_.inc = std::move(arg);
    return Init_FeatureIntInfoGet_Response_error(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response msg_;
};

class Init_FeatureIntInfoGet_Response_max
{
public:
  explicit Init_FeatureIntInfoGet_Response_max(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response & msg)
  : msg_(msg)
  {}
  Init_FeatureIntInfoGet_Response_inc max(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response::_max_type arg)
  {
    msg_.max = std::move(arg);
    return Init_FeatureIntInfoGet_Response_inc(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response msg_;
};

class Init_FeatureIntInfoGet_Response_min
{
public:
  Init_FeatureIntInfoGet_Response_min()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureIntInfoGet_Response_max min(::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_FeatureIntInfoGet_Response_max(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureIntInfoGet_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureIntInfoGet_Response_min();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INT_INFO_GET__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureInfoQuery.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_info_query__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureInfoQuery_Request_feature_module
{
public:
  explicit Init_FeatureInfoQuery_Request_feature_module(::vimbax_camera_msgs::srv::FeatureInfoQuery_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureInfoQuery_Request feature_module(::vimbax_camera_msgs::srv::FeatureInfoQuery_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureInfoQuery_Request msg_;
};

class Init_FeatureInfoQuery_Request_feature_names
{
public:
  Init_FeatureInfoQuery_Request_feature_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureInfoQuery_Request_feature_module feature_names(::vimbax_camera_msgs::srv::FeatureInfoQuery_Request::_feature_names_type arg)
  {
    msg_.feature_names = std::move(arg);
    return Init_FeatureInfoQuery_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureInfoQuery_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureInfoQuery_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureInfoQuery_Request_feature_names();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureInfoQuery_Response_error
{
public:
  explicit Init_FeatureInfoQuery_Response_error(::vimbax_camera_msgs::srv::FeatureInfoQuery_Response & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureInfoQuery_Response error(::vimbax_camera_msgs::srv::FeatureInfoQuery_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureInfoQuery_Response msg_;
};

class Init_FeatureInfoQuery_Response_feature_info
{
public:
  Init_FeatureInfoQuery_Response_feature_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureInfoQuery_Response_error feature_info(::vimbax_camera_msgs::srv::FeatureInfoQuery_Response::_feature_info_type arg)
  {
    msg_.feature_info = std::move(arg);
    return Init_FeatureInfoQuery_Response_error(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureInfoQuery_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureInfoQuery_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureInfoQuery_Response_feature_info();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__BUILDER_HPP_

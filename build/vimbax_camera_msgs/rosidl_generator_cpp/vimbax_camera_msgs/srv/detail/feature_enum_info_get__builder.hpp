// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureEnumInfoGet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ENUM_INFO_GET__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ENUM_INFO_GET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/feature_enum_info_get__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureEnumInfoGet_Request_feature_module
{
public:
  explicit Init_FeatureEnumInfoGet_Request_feature_module(::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Request & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Request feature_module(::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Request::_feature_module_type arg)
  {
    msg_.feature_module = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Request msg_;
};

class Init_FeatureEnumInfoGet_Request_feature_name
{
public:
  Init_FeatureEnumInfoGet_Request_feature_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureEnumInfoGet_Request_feature_module feature_name(::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Request::_feature_name_type arg)
  {
    msg_.feature_name = std::move(arg);
    return Init_FeatureEnumInfoGet_Request_feature_module(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureEnumInfoGet_Request_feature_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_FeatureEnumInfoGet_Response_error
{
public:
  explicit Init_FeatureEnumInfoGet_Response_error(::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response error(::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response msg_;
};

class Init_FeatureEnumInfoGet_Response_available_values
{
public:
  explicit Init_FeatureEnumInfoGet_Response_available_values(::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response & msg)
  : msg_(msg)
  {}
  Init_FeatureEnumInfoGet_Response_error available_values(::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response::_available_values_type arg)
  {
    msg_.available_values = std::move(arg);
    return Init_FeatureEnumInfoGet_Response_error(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response msg_;
};

class Init_FeatureEnumInfoGet_Response_possible_values
{
public:
  Init_FeatureEnumInfoGet_Response_possible_values()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureEnumInfoGet_Response_available_values possible_values(::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response::_possible_values_type arg)
  {
    msg_.possible_values = std::move(arg);
    return Init_FeatureEnumInfoGet_Response_available_values(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::FeatureEnumInfoGet_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_FeatureEnumInfoGet_Response_possible_values();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ENUM_INFO_GET__BUILDER_HPP_

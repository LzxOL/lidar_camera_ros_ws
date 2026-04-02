// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureInfo.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/msg/detail/feature_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace msg
{

namespace builder
{

class Init_FeatureInfo_polling_time
{
public:
  explicit Init_FeatureInfo_polling_time(::vimbax_camera_msgs::msg::FeatureInfo & msg)
  : msg_(msg)
  {}
  ::vimbax_camera_msgs::msg::FeatureInfo polling_time(::vimbax_camera_msgs::msg::FeatureInfo::_polling_time_type arg)
  {
    msg_.polling_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureInfo msg_;
};

class Init_FeatureInfo_flags
{
public:
  explicit Init_FeatureInfo_flags(::vimbax_camera_msgs::msg::FeatureInfo & msg)
  : msg_(msg)
  {}
  Init_FeatureInfo_polling_time flags(::vimbax_camera_msgs::msg::FeatureInfo::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_FeatureInfo_polling_time(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureInfo msg_;
};

class Init_FeatureInfo_data_type
{
public:
  explicit Init_FeatureInfo_data_type(::vimbax_camera_msgs::msg::FeatureInfo & msg)
  : msg_(msg)
  {}
  Init_FeatureInfo_flags data_type(::vimbax_camera_msgs::msg::FeatureInfo::_data_type_type arg)
  {
    msg_.data_type = std::move(arg);
    return Init_FeatureInfo_flags(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureInfo msg_;
};

class Init_FeatureInfo_unit
{
public:
  explicit Init_FeatureInfo_unit(::vimbax_camera_msgs::msg::FeatureInfo & msg)
  : msg_(msg)
  {}
  Init_FeatureInfo_data_type unit(::vimbax_camera_msgs::msg::FeatureInfo::_unit_type arg)
  {
    msg_.unit = std::move(arg);
    return Init_FeatureInfo_data_type(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureInfo msg_;
};

class Init_FeatureInfo_sfnc_namespace
{
public:
  explicit Init_FeatureInfo_sfnc_namespace(::vimbax_camera_msgs::msg::FeatureInfo & msg)
  : msg_(msg)
  {}
  Init_FeatureInfo_unit sfnc_namespace(::vimbax_camera_msgs::msg::FeatureInfo::_sfnc_namespace_type arg)
  {
    msg_.sfnc_namespace = std::move(arg);
    return Init_FeatureInfo_unit(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureInfo msg_;
};

class Init_FeatureInfo_display_name
{
public:
  explicit Init_FeatureInfo_display_name(::vimbax_camera_msgs::msg::FeatureInfo & msg)
  : msg_(msg)
  {}
  Init_FeatureInfo_sfnc_namespace display_name(::vimbax_camera_msgs::msg::FeatureInfo::_display_name_type arg)
  {
    msg_.display_name = std::move(arg);
    return Init_FeatureInfo_sfnc_namespace(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureInfo msg_;
};

class Init_FeatureInfo_category
{
public:
  explicit Init_FeatureInfo_category(::vimbax_camera_msgs::msg::FeatureInfo & msg)
  : msg_(msg)
  {}
  Init_FeatureInfo_display_name category(::vimbax_camera_msgs::msg::FeatureInfo::_category_type arg)
  {
    msg_.category = std::move(arg);
    return Init_FeatureInfo_display_name(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureInfo msg_;
};

class Init_FeatureInfo_name
{
public:
  Init_FeatureInfo_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureInfo_category name(::vimbax_camera_msgs::msg::FeatureInfo::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_FeatureInfo_category(msg_);
  }

private:
  ::vimbax_camera_msgs::msg::FeatureInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::msg::FeatureInfo>()
{
  return vimbax_camera_msgs::msg::builder::Init_FeatureInfo_name();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__BUILDER_HPP_

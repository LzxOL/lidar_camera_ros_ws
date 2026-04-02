// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureInfo.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/msg/detail/feature_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'flags'
#include "vimbax_camera_msgs/msg/detail/feature_flags__traits.hpp"

namespace vimbax_camera_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FeatureInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: category
  {
    out << "category: ";
    rosidl_generator_traits::value_to_yaml(msg.category, out);
    out << ", ";
  }

  // member: display_name
  {
    out << "display_name: ";
    rosidl_generator_traits::value_to_yaml(msg.display_name, out);
    out << ", ";
  }

  // member: sfnc_namespace
  {
    out << "sfnc_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.sfnc_namespace, out);
    out << ", ";
  }

  // member: unit
  {
    out << "unit: ";
    rosidl_generator_traits::value_to_yaml(msg.unit, out);
    out << ", ";
  }

  // member: data_type
  {
    out << "data_type: ";
    rosidl_generator_traits::value_to_yaml(msg.data_type, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    to_flow_style_yaml(msg.flags, out);
    out << ", ";
  }

  // member: polling_time
  {
    out << "polling_time: ";
    rosidl_generator_traits::value_to_yaml(msg.polling_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeatureInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: category
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "category: ";
    rosidl_generator_traits::value_to_yaml(msg.category, out);
    out << "\n";
  }

  // member: display_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "display_name: ";
    rosidl_generator_traits::value_to_yaml(msg.display_name, out);
    out << "\n";
  }

  // member: sfnc_namespace
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sfnc_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.sfnc_namespace, out);
    out << "\n";
  }

  // member: unit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "unit: ";
    rosidl_generator_traits::value_to_yaml(msg.unit, out);
    out << "\n";
  }

  // member: data_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_type: ";
    rosidl_generator_traits::value_to_yaml(msg.data_type, out);
    out << "\n";
  }

  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags:\n";
    to_block_style_yaml(msg.flags, out, indentation + 2);
  }

  // member: polling_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "polling_time: ";
    rosidl_generator_traits::value_to_yaml(msg.polling_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vimbax_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vimbax_camera_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vimbax_camera_msgs::msg::FeatureInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::msg::FeatureInfo & msg)
{
  return vimbax_camera_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::msg::FeatureInfo>()
{
  return "vimbax_camera_msgs::msg::FeatureInfo";
}

template<>
inline const char * name<vimbax_camera_msgs::msg::FeatureInfo>()
{
  return "vimbax_camera_msgs/msg/FeatureInfo";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::msg::FeatureInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::msg::FeatureInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::msg::FeatureInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__TRAITS_HPP_

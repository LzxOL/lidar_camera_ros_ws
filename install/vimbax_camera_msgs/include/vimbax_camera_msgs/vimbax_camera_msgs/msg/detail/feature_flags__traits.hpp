// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureFlags.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/msg/detail/feature_flags__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vimbax_camera_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FeatureFlags & msg,
  std::ostream & out)
{
  out << "{";
  // member: flag_none
  {
    out << "flag_none: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_none, out);
    out << ", ";
  }

  // member: flag_read
  {
    out << "flag_read: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_read, out);
    out << ", ";
  }

  // member: flag_write
  {
    out << "flag_write: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_write, out);
    out << ", ";
  }

  // member: flag_volatile
  {
    out << "flag_volatile: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_volatile, out);
    out << ", ";
  }

  // member: flag_modify_write
  {
    out << "flag_modify_write: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_modify_write, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeatureFlags & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: flag_none
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag_none: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_none, out);
    out << "\n";
  }

  // member: flag_read
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag_read: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_read, out);
    out << "\n";
  }

  // member: flag_write
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag_write: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_write, out);
    out << "\n";
  }

  // member: flag_volatile
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag_volatile: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_volatile, out);
    out << "\n";
  }

  // member: flag_modify_write
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag_modify_write: ";
    rosidl_generator_traits::value_to_yaml(msg.flag_modify_write, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureFlags & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::msg::FeatureFlags & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::msg::FeatureFlags & msg)
{
  return vimbax_camera_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::msg::FeatureFlags>()
{
  return "vimbax_camera_msgs::msg::FeatureFlags";
}

template<>
inline const char * name<vimbax_camera_msgs::msg::FeatureFlags>()
{
  return "vimbax_camera_msgs/msg/FeatureFlags";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::msg::FeatureFlags>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::msg::FeatureFlags>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vimbax_camera_msgs::msg::FeatureFlags>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__TRAITS_HPP_

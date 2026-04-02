// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__ERROR__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__ERROR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/msg/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vimbax_camera_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Error & msg,
  std::ostream & out)
{
  out << "{";
  // member: code
  {
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << ", ";
  }

  // member: text
  {
    out << "text: ";
    rosidl_generator_traits::value_to_yaml(msg.text, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Error & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << "\n";
  }

  // member: text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "text: ";
    rosidl_generator_traits::value_to_yaml(msg.text, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Error & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::msg::Error & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::msg::Error & msg)
{
  return vimbax_camera_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::msg::Error>()
{
  return "vimbax_camera_msgs::msg::Error";
}

template<>
inline const char * name<vimbax_camera_msgs::msg::Error>()
{
  return "vimbax_camera_msgs/msg/Error";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::msg::Error>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::msg::Error>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::msg::Error>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__ERROR__TRAITS_HPP_

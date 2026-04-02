// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureModule.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/msg/detail/feature_module__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vimbax_camera_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FeatureModule & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeatureModule & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureModule & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::msg::FeatureModule & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::msg::FeatureModule & msg)
{
  return vimbax_camera_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::msg::FeatureModule>()
{
  return "vimbax_camera_msgs::msg::FeatureModule";
}

template<>
inline const char * name<vimbax_camera_msgs::msg::FeatureModule>()
{
  return "vimbax_camera_msgs/msg/FeatureModule";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::msg::FeatureModule>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::msg::FeatureModule>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vimbax_camera_msgs::msg::FeatureModule>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__TRAITS_HPP_

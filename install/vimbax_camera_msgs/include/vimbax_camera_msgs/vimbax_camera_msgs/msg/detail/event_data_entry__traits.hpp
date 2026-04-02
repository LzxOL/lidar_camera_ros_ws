// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:msg/EventDataEntry.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/msg/detail/event_data_entry__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vimbax_camera_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EventDataEntry & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EventDataEntry & msg,
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

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EventDataEntry & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::msg::EventDataEntry & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::msg::EventDataEntry & msg)
{
  return vimbax_camera_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::msg::EventDataEntry>()
{
  return "vimbax_camera_msgs::msg::EventDataEntry";
}

template<>
inline const char * name<vimbax_camera_msgs::msg::EventDataEntry>()
{
  return "vimbax_camera_msgs/msg/EventDataEntry";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::msg::EventDataEntry>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::msg::EventDataEntry>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::msg::EventDataEntry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__TRAITS_HPP_

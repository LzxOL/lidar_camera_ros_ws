// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:msg/EventData.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/msg/detail/event_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'entries'
#include "vimbax_camera_msgs/msg/detail/event_data_entry__traits.hpp"

namespace vimbax_camera_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EventData & msg,
  std::ostream & out)
{
  out << "{";
  // member: entries
  {
    if (msg.entries.size() == 0) {
      out << "entries: []";
    } else {
      out << "entries: [";
      size_t pending_items = msg.entries.size();
      for (auto item : msg.entries) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EventData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: entries
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.entries.size() == 0) {
      out << "entries: []\n";
    } else {
      out << "entries:\n";
      for (auto item : msg.entries) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EventData & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::msg::EventData & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::msg::EventData & msg)
{
  return vimbax_camera_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::msg::EventData>()
{
  return "vimbax_camera_msgs::msg::EventData";
}

template<>
inline const char * name<vimbax_camera_msgs::msg::EventData>()
{
  return "vimbax_camera_msgs/msg/EventData";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::msg::EventData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::msg::EventData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::msg::EventData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA__TRAITS_HPP_

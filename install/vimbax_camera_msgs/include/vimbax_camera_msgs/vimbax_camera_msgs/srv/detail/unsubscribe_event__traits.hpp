// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:srv/UnsubscribeEvent.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/srv/detail/unsubscribe_event__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UnsubscribeEvent_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UnsubscribeEvent_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UnsubscribeEvent_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vimbax_camera_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vimbax_camera_msgs::srv::UnsubscribeEvent_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::UnsubscribeEvent_Request & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::UnsubscribeEvent_Request>()
{
  return "vimbax_camera_msgs::srv::UnsubscribeEvent_Request";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::UnsubscribeEvent_Request>()
{
  return "vimbax_camera_msgs/srv/UnsubscribeEvent_Request";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::UnsubscribeEvent_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::UnsubscribeEvent_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::srv::UnsubscribeEvent_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UnsubscribeEvent_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UnsubscribeEvent_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UnsubscribeEvent_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vimbax_camera_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vimbax_camera_msgs::srv::UnsubscribeEvent_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::UnsubscribeEvent_Response & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::UnsubscribeEvent_Response>()
{
  return "vimbax_camera_msgs::srv::UnsubscribeEvent_Response";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::UnsubscribeEvent_Response>()
{
  return "vimbax_camera_msgs/srv/UnsubscribeEvent_Response";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::UnsubscribeEvent_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::UnsubscribeEvent_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vimbax_camera_msgs::srv::UnsubscribeEvent_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vimbax_camera_msgs::srv::UnsubscribeEvent>()
{
  return "vimbax_camera_msgs::srv::UnsubscribeEvent";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::UnsubscribeEvent>()
{
  return "vimbax_camera_msgs/srv/UnsubscribeEvent";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::UnsubscribeEvent>
  : std::integral_constant<
    bool,
    has_fixed_size<vimbax_camera_msgs::srv::UnsubscribeEvent_Request>::value &&
    has_fixed_size<vimbax_camera_msgs::srv::UnsubscribeEvent_Response>::value
  >
{
};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::UnsubscribeEvent>
  : std::integral_constant<
    bool,
    has_bounded_size<vimbax_camera_msgs::srv::UnsubscribeEvent_Request>::value &&
    has_bounded_size<vimbax_camera_msgs::srv::UnsubscribeEvent_Response>::value
  >
{
};

template<>
struct is_service<vimbax_camera_msgs::srv::UnsubscribeEvent>
  : std::true_type
{
};

template<>
struct is_service_request<vimbax_camera_msgs::srv::UnsubscribeEvent_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vimbax_camera_msgs::srv::UnsubscribeEvent_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__TRAITS_HPP_

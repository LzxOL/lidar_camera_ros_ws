// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:srv/ConnectionStatus.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/srv/detail/connection_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ConnectionStatus_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ConnectionStatus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ConnectionStatus_Request & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::srv::ConnectionStatus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::ConnectionStatus_Request & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::ConnectionStatus_Request>()
{
  return "vimbax_camera_msgs::srv::ConnectionStatus_Request";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::ConnectionStatus_Request>()
{
  return "vimbax_camera_msgs/srv/ConnectionStatus_Request";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::ConnectionStatus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::ConnectionStatus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vimbax_camera_msgs::srv::ConnectionStatus_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ConnectionStatus_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: connected
  {
    out << "connected: ";
    rosidl_generator_traits::value_to_yaml(msg.connected, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ConnectionStatus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "connected: ";
    rosidl_generator_traits::value_to_yaml(msg.connected, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ConnectionStatus_Response & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::srv::ConnectionStatus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::ConnectionStatus_Response & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::ConnectionStatus_Response>()
{
  return "vimbax_camera_msgs::srv::ConnectionStatus_Response";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::ConnectionStatus_Response>()
{
  return "vimbax_camera_msgs/srv/ConnectionStatus_Response";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::ConnectionStatus_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::ConnectionStatus_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vimbax_camera_msgs::srv::ConnectionStatus_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vimbax_camera_msgs::srv::ConnectionStatus>()
{
  return "vimbax_camera_msgs::srv::ConnectionStatus";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::ConnectionStatus>()
{
  return "vimbax_camera_msgs/srv/ConnectionStatus";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::ConnectionStatus>
  : std::integral_constant<
    bool,
    has_fixed_size<vimbax_camera_msgs::srv::ConnectionStatus_Request>::value &&
    has_fixed_size<vimbax_camera_msgs::srv::ConnectionStatus_Response>::value
  >
{
};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::ConnectionStatus>
  : std::integral_constant<
    bool,
    has_bounded_size<vimbax_camera_msgs::srv::ConnectionStatus_Request>::value &&
    has_bounded_size<vimbax_camera_msgs::srv::ConnectionStatus_Response>::value
  >
{
};

template<>
struct is_service<vimbax_camera_msgs::srv::ConnectionStatus>
  : std::true_type
{
};

template<>
struct is_service_request<vimbax_camera_msgs::srv::ConnectionStatus_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vimbax_camera_msgs::srv::ConnectionStatus_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__TRAITS_HPP_

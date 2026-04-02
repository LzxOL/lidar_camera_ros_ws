// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:srv/Status.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/srv/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Status_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status_Request & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::srv::Status_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::Status_Request & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::Status_Request>()
{
  return "vimbax_camera_msgs::srv::Status_Request";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::Status_Request>()
{
  return "vimbax_camera_msgs/srv/Status_Request";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::Status_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::Status_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vimbax_camera_msgs::srv::Status_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__traits.hpp"
// Member 'trigger_info'
#include "vimbax_camera_msgs/msg/detail/trigger_info__traits.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Status_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: error
  {
    out << "error: ";
    to_flow_style_yaml(msg.error, out);
    out << ", ";
  }

  // member: display_name
  {
    out << "display_name: ";
    rosidl_generator_traits::value_to_yaml(msg.display_name, out);
    out << ", ";
  }

  // member: model_name
  {
    out << "model_name: ";
    rosidl_generator_traits::value_to_yaml(msg.model_name, out);
    out << ", ";
  }

  // member: device_firmware_version
  {
    out << "device_firmware_version: ";
    rosidl_generator_traits::value_to_yaml(msg.device_firmware_version, out);
    out << ", ";
  }

  // member: device_id
  {
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << ", ";
  }

  // member: device_user_id
  {
    out << "device_user_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_user_id, out);
    out << ", ";
  }

  // member: device_serial_number
  {
    out << "device_serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.device_serial_number, out);
    out << ", ";
  }

  // member: interface_id
  {
    out << "interface_id: ";
    rosidl_generator_traits::value_to_yaml(msg.interface_id, out);
    out << ", ";
  }

  // member: transport_layer_id
  {
    out << "transport_layer_id: ";
    rosidl_generator_traits::value_to_yaml(msg.transport_layer_id, out);
    out << ", ";
  }

  // member: streaming
  {
    out << "streaming: ";
    rosidl_generator_traits::value_to_yaml(msg.streaming, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: frame_rate
  {
    out << "frame_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_rate, out);
    out << ", ";
  }

  // member: pixel_format
  {
    out << "pixel_format: ";
    rosidl_generator_traits::value_to_yaml(msg.pixel_format, out);
    out << ", ";
  }

  // member: trigger_info
  {
    if (msg.trigger_info.size() == 0) {
      out << "trigger_info: []";
    } else {
      out << "trigger_info: [";
      size_t pending_items = msg.trigger_info.size();
      for (auto item : msg.trigger_info) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: ip_address
  {
    out << "ip_address: ";
    rosidl_generator_traits::value_to_yaml(msg.ip_address, out);
    out << ", ";
  }

  // member: mac_address
  {
    out << "mac_address: ";
    rosidl_generator_traits::value_to_yaml(msg.mac_address, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error:\n";
    to_block_style_yaml(msg.error, out, indentation + 2);
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

  // member: model_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "model_name: ";
    rosidl_generator_traits::value_to_yaml(msg.model_name, out);
    out << "\n";
  }

  // member: device_firmware_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_firmware_version: ";
    rosidl_generator_traits::value_to_yaml(msg.device_firmware_version, out);
    out << "\n";
  }

  // member: device_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << "\n";
  }

  // member: device_user_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_user_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_user_id, out);
    out << "\n";
  }

  // member: device_serial_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.device_serial_number, out);
    out << "\n";
  }

  // member: interface_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "interface_id: ";
    rosidl_generator_traits::value_to_yaml(msg.interface_id, out);
    out << "\n";
  }

  // member: transport_layer_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "transport_layer_id: ";
    rosidl_generator_traits::value_to_yaml(msg.transport_layer_id, out);
    out << "\n";
  }

  // member: streaming
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "streaming: ";
    rosidl_generator_traits::value_to_yaml(msg.streaming, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: frame_rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_rate: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_rate, out);
    out << "\n";
  }

  // member: pixel_format
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pixel_format: ";
    rosidl_generator_traits::value_to_yaml(msg.pixel_format, out);
    out << "\n";
  }

  // member: trigger_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.trigger_info.size() == 0) {
      out << "trigger_info: []\n";
    } else {
      out << "trigger_info:\n";
      for (auto item : msg.trigger_info) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: ip_address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ip_address: ";
    rosidl_generator_traits::value_to_yaml(msg.ip_address, out);
    out << "\n";
  }

  // member: mac_address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mac_address: ";
    rosidl_generator_traits::value_to_yaml(msg.mac_address, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status_Response & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::srv::Status_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::Status_Response & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::Status_Response>()
{
  return "vimbax_camera_msgs::srv::Status_Response";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::Status_Response>()
{
  return "vimbax_camera_msgs/srv/Status_Response";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::Status_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::Status_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::srv::Status_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vimbax_camera_msgs::srv::Status>()
{
  return "vimbax_camera_msgs::srv::Status";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::Status>()
{
  return "vimbax_camera_msgs/srv/Status";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::Status>
  : std::integral_constant<
    bool,
    has_fixed_size<vimbax_camera_msgs::srv::Status_Request>::value &&
    has_fixed_size<vimbax_camera_msgs::srv::Status_Response>::value
  >
{
};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::Status>
  : std::integral_constant<
    bool,
    has_bounded_size<vimbax_camera_msgs::srv::Status_Request>::value &&
    has_bounded_size<vimbax_camera_msgs::srv::Status_Response>::value
  >
{
};

template<>
struct is_service<vimbax_camera_msgs::srv::Status>
  : std::true_type
{
};

template<>
struct is_service_request<vimbax_camera_msgs::srv::Status_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vimbax_camera_msgs::srv::Status_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__TRAITS_HPP_

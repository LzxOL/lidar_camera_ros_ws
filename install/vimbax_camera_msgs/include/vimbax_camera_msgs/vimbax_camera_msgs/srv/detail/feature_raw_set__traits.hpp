// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureRawSet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_SET__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_SET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/srv/detail/feature_raw_set__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'feature_module'
#include "vimbax_camera_msgs/msg/detail/feature_module__traits.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const FeatureRawSet_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: feature_name
  {
    out << "feature_name: ";
    rosidl_generator_traits::value_to_yaml(msg.feature_name, out);
    out << ", ";
  }

  // member: feature_module
  {
    out << "feature_module: ";
    to_flow_style_yaml(msg.feature_module, out);
    out << ", ";
  }

  // member: buffer
  {
    if (msg.buffer.size() == 0) {
      out << "buffer: []";
    } else {
      out << "buffer: [";
      size_t pending_items = msg.buffer.size();
      for (auto item : msg.buffer) {
        rosidl_generator_traits::character_value_to_yaml(item, out);
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
  const FeatureRawSet_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feature_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feature_name: ";
    rosidl_generator_traits::value_to_yaml(msg.feature_name, out);
    out << "\n";
  }

  // member: feature_module
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feature_module:\n";
    to_block_style_yaml(msg.feature_module, out, indentation + 2);
  }

  // member: buffer
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.buffer.size() == 0) {
      out << "buffer: []\n";
    } else {
      out << "buffer:\n";
      for (auto item : msg.buffer) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::character_value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureRawSet_Request & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::srv::FeatureRawSet_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::FeatureRawSet_Request & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::FeatureRawSet_Request>()
{
  return "vimbax_camera_msgs::srv::FeatureRawSet_Request";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::FeatureRawSet_Request>()
{
  return "vimbax_camera_msgs/srv/FeatureRawSet_Request";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::FeatureRawSet_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::FeatureRawSet_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::srv::FeatureRawSet_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__traits.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const FeatureRawSet_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: error
  {
    out << "error: ";
    to_flow_style_yaml(msg.error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeatureRawSet_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureRawSet_Response & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::srv::FeatureRawSet_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::FeatureRawSet_Response & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::FeatureRawSet_Response>()
{
  return "vimbax_camera_msgs::srv::FeatureRawSet_Response";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::FeatureRawSet_Response>()
{
  return "vimbax_camera_msgs/srv/FeatureRawSet_Response";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::FeatureRawSet_Response>
  : std::integral_constant<bool, has_fixed_size<vimbax_camera_msgs::msg::Error>::value> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::FeatureRawSet_Response>
  : std::integral_constant<bool, has_bounded_size<vimbax_camera_msgs::msg::Error>::value> {};

template<>
struct is_message<vimbax_camera_msgs::srv::FeatureRawSet_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vimbax_camera_msgs::srv::FeatureRawSet>()
{
  return "vimbax_camera_msgs::srv::FeatureRawSet";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::FeatureRawSet>()
{
  return "vimbax_camera_msgs/srv/FeatureRawSet";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::FeatureRawSet>
  : std::integral_constant<
    bool,
    has_fixed_size<vimbax_camera_msgs::srv::FeatureRawSet_Request>::value &&
    has_fixed_size<vimbax_camera_msgs::srv::FeatureRawSet_Response>::value
  >
{
};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::FeatureRawSet>
  : std::integral_constant<
    bool,
    has_bounded_size<vimbax_camera_msgs::srv::FeatureRawSet_Request>::value &&
    has_bounded_size<vimbax_camera_msgs::srv::FeatureRawSet_Response>::value
  >
{
};

template<>
struct is_service<vimbax_camera_msgs::srv::FeatureRawSet>
  : std::true_type
{
};

template<>
struct is_service_request<vimbax_camera_msgs::srv::FeatureRawSet_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vimbax_camera_msgs::srv::FeatureRawSet_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_RAW_SET__TRAITS_HPP_

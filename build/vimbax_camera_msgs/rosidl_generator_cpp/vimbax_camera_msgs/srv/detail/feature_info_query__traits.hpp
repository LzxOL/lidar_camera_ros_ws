// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureInfoQuery.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__TRAITS_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vimbax_camera_msgs/srv/detail/feature_info_query__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'feature_module'
#include "vimbax_camera_msgs/msg/detail/feature_module__traits.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const FeatureInfoQuery_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: feature_names
  {
    if (msg.feature_names.size() == 0) {
      out << "feature_names: []";
    } else {
      out << "feature_names: [";
      size_t pending_items = msg.feature_names.size();
      for (auto item : msg.feature_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: feature_module
  {
    out << "feature_module: ";
    to_flow_style_yaml(msg.feature_module, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeatureInfoQuery_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feature_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.feature_names.size() == 0) {
      out << "feature_names: []\n";
    } else {
      out << "feature_names:\n";
      for (auto item : msg.feature_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: feature_module
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feature_module:\n";
    to_block_style_yaml(msg.feature_module, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureInfoQuery_Request & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::srv::FeatureInfoQuery_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::FeatureInfoQuery_Request & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::FeatureInfoQuery_Request>()
{
  return "vimbax_camera_msgs::srv::FeatureInfoQuery_Request";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::FeatureInfoQuery_Request>()
{
  return "vimbax_camera_msgs/srv/FeatureInfoQuery_Request";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::FeatureInfoQuery_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::FeatureInfoQuery_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::srv::FeatureInfoQuery_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'feature_info'
#include "vimbax_camera_msgs/msg/detail/feature_info__traits.hpp"
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__traits.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const FeatureInfoQuery_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: feature_info
  {
    if (msg.feature_info.size() == 0) {
      out << "feature_info: []";
    } else {
      out << "feature_info: [";
      size_t pending_items = msg.feature_info.size();
      for (auto item : msg.feature_info) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: error
  {
    out << "error: ";
    to_flow_style_yaml(msg.error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeatureInfoQuery_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feature_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.feature_info.size() == 0) {
      out << "feature_info: []\n";
    } else {
      out << "feature_info:\n";
      for (auto item : msg.feature_info) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error:\n";
    to_block_style_yaml(msg.error, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureInfoQuery_Response & msg, bool use_flow_style = false)
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
  const vimbax_camera_msgs::srv::FeatureInfoQuery_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vimbax_camera_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vimbax_camera_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vimbax_camera_msgs::srv::FeatureInfoQuery_Response & msg)
{
  return vimbax_camera_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vimbax_camera_msgs::srv::FeatureInfoQuery_Response>()
{
  return "vimbax_camera_msgs::srv::FeatureInfoQuery_Response";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::FeatureInfoQuery_Response>()
{
  return "vimbax_camera_msgs/srv/FeatureInfoQuery_Response";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::FeatureInfoQuery_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::FeatureInfoQuery_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vimbax_camera_msgs::srv::FeatureInfoQuery_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vimbax_camera_msgs::srv::FeatureInfoQuery>()
{
  return "vimbax_camera_msgs::srv::FeatureInfoQuery";
}

template<>
inline const char * name<vimbax_camera_msgs::srv::FeatureInfoQuery>()
{
  return "vimbax_camera_msgs/srv/FeatureInfoQuery";
}

template<>
struct has_fixed_size<vimbax_camera_msgs::srv::FeatureInfoQuery>
  : std::integral_constant<
    bool,
    has_fixed_size<vimbax_camera_msgs::srv::FeatureInfoQuery_Request>::value &&
    has_fixed_size<vimbax_camera_msgs::srv::FeatureInfoQuery_Response>::value
  >
{
};

template<>
struct has_bounded_size<vimbax_camera_msgs::srv::FeatureInfoQuery>
  : std::integral_constant<
    bool,
    has_bounded_size<vimbax_camera_msgs::srv::FeatureInfoQuery_Request>::value &&
    has_bounded_size<vimbax_camera_msgs::srv::FeatureInfoQuery_Response>::value
  >
{
};

template<>
struct is_service<vimbax_camera_msgs::srv::FeatureInfoQuery>
  : std::true_type
{
};

template<>
struct is_service_request<vimbax_camera_msgs::srv::FeatureInfoQuery_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vimbax_camera_msgs::srv::FeatureInfoQuery_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__TRAITS_HPP_

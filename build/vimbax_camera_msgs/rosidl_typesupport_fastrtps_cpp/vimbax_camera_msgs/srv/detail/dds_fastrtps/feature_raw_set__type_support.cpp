// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vimbax_camera_msgs:srv/FeatureRawSet.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/srv/detail/feature_raw_set__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vimbax_camera_msgs/srv/detail/feature_raw_set__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace vimbax_camera_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vimbax_camera_msgs::msg::FeatureModule &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vimbax_camera_msgs::msg::FeatureModule &);
size_t get_serialized_size(
  const vimbax_camera_msgs::msg::FeatureModule &,
  size_t current_alignment);
size_t
max_serialized_size_FeatureModule(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vimbax_camera_msgs
cdr_serialize(
  const vimbax_camera_msgs::srv::FeatureRawSet_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: feature_name
  cdr << ros_message.feature_name;
  // Member: feature_module
  vimbax_camera_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.feature_module,
    cdr);
  // Member: buffer
  {
    cdr << ros_message.buffer;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vimbax_camera_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vimbax_camera_msgs::srv::FeatureRawSet_Request & ros_message)
{
  // Member: feature_name
  cdr >> ros_message.feature_name;

  // Member: feature_module
  vimbax_camera_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.feature_module);

  // Member: buffer
  {
    cdr >> ros_message.buffer;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vimbax_camera_msgs
get_serialized_size(
  const vimbax_camera_msgs::srv::FeatureRawSet_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: feature_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.feature_name.size() + 1);
  // Member: feature_module

  current_alignment +=
    vimbax_camera_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.feature_module, current_alignment);
  // Member: buffer
  {
    size_t array_size = ros_message.buffer.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.buffer[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vimbax_camera_msgs
max_serialized_size_FeatureRawSet_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: feature_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: feature_module
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vimbax_camera_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_FeatureModule(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: buffer
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vimbax_camera_msgs::srv::FeatureRawSet_Request;
    is_plain =
      (
      offsetof(DataType, buffer) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FeatureRawSet_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vimbax_camera_msgs::srv::FeatureRawSet_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FeatureRawSet_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vimbax_camera_msgs::srv::FeatureRawSet_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FeatureRawSet_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vimbax_camera_msgs::srv::FeatureRawSet_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FeatureRawSet_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FeatureRawSet_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FeatureRawSet_Request__callbacks = {
  "vimbax_camera_msgs::srv",
  "FeatureRawSet_Request",
  _FeatureRawSet_Request__cdr_serialize,
  _FeatureRawSet_Request__cdr_deserialize,
  _FeatureRawSet_Request__get_serialized_size,
  _FeatureRawSet_Request__max_serialized_size
};

static rosidl_message_type_support_t _FeatureRawSet_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FeatureRawSet_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<vimbax_camera_msgs::srv::FeatureRawSet_Request>()
{
  return &vimbax_camera_msgs::srv::typesupport_fastrtps_cpp::_FeatureRawSet_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vimbax_camera_msgs, srv, FeatureRawSet_Request)() {
  return &vimbax_camera_msgs::srv::typesupport_fastrtps_cpp::_FeatureRawSet_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace vimbax_camera_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vimbax_camera_msgs::msg::Error &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vimbax_camera_msgs::msg::Error &);
size_t get_serialized_size(
  const vimbax_camera_msgs::msg::Error &,
  size_t current_alignment);
size_t
max_serialized_size_Error(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vimbax_camera_msgs
cdr_serialize(
  const vimbax_camera_msgs::srv::FeatureRawSet_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: error
  vimbax_camera_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.error,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vimbax_camera_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vimbax_camera_msgs::srv::FeatureRawSet_Response & ros_message)
{
  // Member: error
  vimbax_camera_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.error);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vimbax_camera_msgs
get_serialized_size(
  const vimbax_camera_msgs::srv::FeatureRawSet_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: error

  current_alignment +=
    vimbax_camera_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.error, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vimbax_camera_msgs
max_serialized_size_FeatureRawSet_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: error
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vimbax_camera_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Error(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vimbax_camera_msgs::srv::FeatureRawSet_Response;
    is_plain =
      (
      offsetof(DataType, error) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FeatureRawSet_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vimbax_camera_msgs::srv::FeatureRawSet_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FeatureRawSet_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vimbax_camera_msgs::srv::FeatureRawSet_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FeatureRawSet_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vimbax_camera_msgs::srv::FeatureRawSet_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FeatureRawSet_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FeatureRawSet_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FeatureRawSet_Response__callbacks = {
  "vimbax_camera_msgs::srv",
  "FeatureRawSet_Response",
  _FeatureRawSet_Response__cdr_serialize,
  _FeatureRawSet_Response__cdr_deserialize,
  _FeatureRawSet_Response__get_serialized_size,
  _FeatureRawSet_Response__max_serialized_size
};

static rosidl_message_type_support_t _FeatureRawSet_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FeatureRawSet_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<vimbax_camera_msgs::srv::FeatureRawSet_Response>()
{
  return &vimbax_camera_msgs::srv::typesupport_fastrtps_cpp::_FeatureRawSet_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vimbax_camera_msgs, srv, FeatureRawSet_Response)() {
  return &vimbax_camera_msgs::srv::typesupport_fastrtps_cpp::_FeatureRawSet_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _FeatureRawSet__callbacks = {
  "vimbax_camera_msgs::srv",
  "FeatureRawSet",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vimbax_camera_msgs, srv, FeatureRawSet_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vimbax_camera_msgs, srv, FeatureRawSet_Response)(),
};

static rosidl_service_type_support_t _FeatureRawSet__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FeatureRawSet__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vimbax_camera_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<vimbax_camera_msgs::srv::FeatureRawSet>()
{
  return &vimbax_camera_msgs::srv::typesupport_fastrtps_cpp::_FeatureRawSet__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vimbax_camera_msgs, srv, FeatureRawSet)() {
  return &vimbax_camera_msgs::srv::typesupport_fastrtps_cpp::_FeatureRawSet__handle;
}

#ifdef __cplusplus
}
#endif

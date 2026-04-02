// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vimbax_camera_msgs:msg/FeatureFlags.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/msg/detail/feature_flags__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vimbax_camera_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vimbax_camera_msgs/msg/detail/feature_flags__struct.h"
#include "vimbax_camera_msgs/msg/detail/feature_flags__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _FeatureFlags__ros_msg_type = vimbax_camera_msgs__msg__FeatureFlags;

static bool _FeatureFlags__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FeatureFlags__ros_msg_type * ros_message = static_cast<const _FeatureFlags__ros_msg_type *>(untyped_ros_message);
  // Field name: flag_none
  {
    cdr << (ros_message->flag_none ? true : false);
  }

  // Field name: flag_read
  {
    cdr << (ros_message->flag_read ? true : false);
  }

  // Field name: flag_write
  {
    cdr << (ros_message->flag_write ? true : false);
  }

  // Field name: flag_volatile
  {
    cdr << (ros_message->flag_volatile ? true : false);
  }

  // Field name: flag_modify_write
  {
    cdr << (ros_message->flag_modify_write ? true : false);
  }

  return true;
}

static bool _FeatureFlags__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FeatureFlags__ros_msg_type * ros_message = static_cast<_FeatureFlags__ros_msg_type *>(untyped_ros_message);
  // Field name: flag_none
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->flag_none = tmp ? true : false;
  }

  // Field name: flag_read
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->flag_read = tmp ? true : false;
  }

  // Field name: flag_write
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->flag_write = tmp ? true : false;
  }

  // Field name: flag_volatile
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->flag_volatile = tmp ? true : false;
  }

  // Field name: flag_modify_write
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->flag_modify_write = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vimbax_camera_msgs
size_t get_serialized_size_vimbax_camera_msgs__msg__FeatureFlags(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FeatureFlags__ros_msg_type * ros_message = static_cast<const _FeatureFlags__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name flag_none
  {
    size_t item_size = sizeof(ros_message->flag_none);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flag_read
  {
    size_t item_size = sizeof(ros_message->flag_read);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flag_write
  {
    size_t item_size = sizeof(ros_message->flag_write);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flag_volatile
  {
    size_t item_size = sizeof(ros_message->flag_volatile);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flag_modify_write
  {
    size_t item_size = sizeof(ros_message->flag_modify_write);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FeatureFlags__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vimbax_camera_msgs__msg__FeatureFlags(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vimbax_camera_msgs
size_t max_serialized_size_vimbax_camera_msgs__msg__FeatureFlags(
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

  // member: flag_none
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: flag_read
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: flag_write
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: flag_volatile
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: flag_modify_write
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vimbax_camera_msgs__msg__FeatureFlags;
    is_plain =
      (
      offsetof(DataType, flag_modify_write) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FeatureFlags__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vimbax_camera_msgs__msg__FeatureFlags(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FeatureFlags = {
  "vimbax_camera_msgs::msg",
  "FeatureFlags",
  _FeatureFlags__cdr_serialize,
  _FeatureFlags__cdr_deserialize,
  _FeatureFlags__get_serialized_size,
  _FeatureFlags__max_serialized_size
};

static rosidl_message_type_support_t _FeatureFlags__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FeatureFlags,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, msg, FeatureFlags)() {
  return &_FeatureFlags__type_support;
}

#if defined(__cplusplus)
}
#endif

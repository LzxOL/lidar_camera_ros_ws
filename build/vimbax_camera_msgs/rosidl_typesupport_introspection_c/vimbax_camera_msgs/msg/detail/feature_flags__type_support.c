// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vimbax_camera_msgs:msg/FeatureFlags.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vimbax_camera_msgs/msg/detail/feature_flags__rosidl_typesupport_introspection_c.h"
#include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vimbax_camera_msgs/msg/detail/feature_flags__functions.h"
#include "vimbax_camera_msgs/msg/detail/feature_flags__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__msg__FeatureFlags__init(message_memory);
}

void vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_fini_function(void * message_memory)
{
  vimbax_camera_msgs__msg__FeatureFlags__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_message_member_array[5] = {
  {
    "flag_none",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__msg__FeatureFlags, flag_none),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flag_read",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__msg__FeatureFlags, flag_read),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flag_write",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__msg__FeatureFlags, flag_write),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flag_volatile",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__msg__FeatureFlags, flag_volatile),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flag_modify_write",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__msg__FeatureFlags, flag_modify_write),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_message_members = {
  "vimbax_camera_msgs__msg",  // message namespace
  "FeatureFlags",  // message name
  5,  // number of fields
  sizeof(vimbax_camera_msgs__msg__FeatureFlags),
  vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_message_member_array,  // message members
  vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, FeatureFlags)() {
  if (!vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__msg__FeatureFlags__rosidl_typesupport_introspection_c__FeatureFlags_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

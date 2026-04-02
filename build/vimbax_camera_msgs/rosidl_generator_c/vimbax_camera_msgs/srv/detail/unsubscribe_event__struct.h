// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:srv/UnsubscribeEvent.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/UnsubscribeEvent in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__UnsubscribeEvent_Request
{
  rosidl_runtime_c__String name;
} vimbax_camera_msgs__srv__UnsubscribeEvent_Request;

// Struct for a sequence of vimbax_camera_msgs__srv__UnsubscribeEvent_Request.
typedef struct vimbax_camera_msgs__srv__UnsubscribeEvent_Request__Sequence
{
  vimbax_camera_msgs__srv__UnsubscribeEvent_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__UnsubscribeEvent_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/UnsubscribeEvent in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__UnsubscribeEvent_Response
{
  uint8_t structure_needs_at_least_one_member;
} vimbax_camera_msgs__srv__UnsubscribeEvent_Response;

// Struct for a sequence of vimbax_camera_msgs__srv__UnsubscribeEvent_Response.
typedef struct vimbax_camera_msgs__srv__UnsubscribeEvent_Response__Sequence
{
  vimbax_camera_msgs__srv__UnsubscribeEvent_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__UnsubscribeEvent_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__STRUCT_H_

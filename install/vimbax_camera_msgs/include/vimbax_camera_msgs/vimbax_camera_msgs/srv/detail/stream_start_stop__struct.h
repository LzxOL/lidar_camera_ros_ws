// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:srv/StreamStartStop.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__STREAM_START_STOP__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__STREAM_START_STOP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/StreamStartStop in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__StreamStartStop_Request
{
  uint8_t structure_needs_at_least_one_member;
} vimbax_camera_msgs__srv__StreamStartStop_Request;

// Struct for a sequence of vimbax_camera_msgs__srv__StreamStartStop_Request.
typedef struct vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence
{
  vimbax_camera_msgs__srv__StreamStartStop_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__struct.h"

/// Struct defined in srv/StreamStartStop in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__StreamStartStop_Response
{
  vimbax_camera_msgs__msg__Error error;
} vimbax_camera_msgs__srv__StreamStartStop_Response;

// Struct for a sequence of vimbax_camera_msgs__srv__StreamStartStop_Response.
typedef struct vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence
{
  vimbax_camera_msgs__srv__StreamStartStop_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__STREAM_START_STOP__STRUCT_H_

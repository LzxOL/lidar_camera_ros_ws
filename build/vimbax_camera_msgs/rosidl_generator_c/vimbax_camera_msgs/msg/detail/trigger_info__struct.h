// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:msg/TriggerInfo.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'selector'
// Member 'mode'
// Member 'source'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TriggerInfo in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__msg__TriggerInfo
{
  rosidl_runtime_c__String selector;
  rosidl_runtime_c__String mode;
  rosidl_runtime_c__String source;
} vimbax_camera_msgs__msg__TriggerInfo;

// Struct for a sequence of vimbax_camera_msgs__msg__TriggerInfo.
typedef struct vimbax_camera_msgs__msg__TriggerInfo__Sequence
{
  vimbax_camera_msgs__msg__TriggerInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__msg__TriggerInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__STRUCT_H_

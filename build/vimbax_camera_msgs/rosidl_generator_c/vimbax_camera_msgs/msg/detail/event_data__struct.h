// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:msg/EventData.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'entries'
#include "vimbax_camera_msgs/msg/detail/event_data_entry__struct.h"

/// Struct defined in msg/EventData in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__msg__EventData
{
  vimbax_camera_msgs__msg__EventDataEntry__Sequence entries;
} vimbax_camera_msgs__msg__EventData;

// Struct for a sequence of vimbax_camera_msgs__msg__EventData.
typedef struct vimbax_camera_msgs__msg__EventData__Sequence
{
  vimbax_camera_msgs__msg__EventData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__msg__EventData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA__STRUCT_H_

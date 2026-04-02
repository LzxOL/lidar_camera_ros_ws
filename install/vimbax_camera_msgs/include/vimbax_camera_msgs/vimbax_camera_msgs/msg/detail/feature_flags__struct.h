// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:msg/FeatureFlags.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FeatureFlags in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__msg__FeatureFlags
{
  bool flag_none;
  bool flag_read;
  bool flag_write;
  bool flag_volatile;
  bool flag_modify_write;
} vimbax_camera_msgs__msg__FeatureFlags;

// Struct for a sequence of vimbax_camera_msgs__msg__FeatureFlags.
typedef struct vimbax_camera_msgs__msg__FeatureFlags__Sequence
{
  vimbax_camera_msgs__msg__FeatureFlags * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__msg__FeatureFlags__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__STRUCT_H_

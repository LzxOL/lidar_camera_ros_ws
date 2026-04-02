// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:msg/FeatureInfo.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__STRUCT_H_

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
// Member 'category'
// Member 'display_name'
// Member 'sfnc_namespace'
// Member 'unit'
#include "rosidl_runtime_c/string.h"
// Member 'flags'
#include "vimbax_camera_msgs/msg/detail/feature_flags__struct.h"

/// Struct defined in msg/FeatureInfo in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__msg__FeatureInfo
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String category;
  rosidl_runtime_c__String display_name;
  rosidl_runtime_c__String sfnc_namespace;
  rosidl_runtime_c__String unit;
  uint32_t data_type;
  vimbax_camera_msgs__msg__FeatureFlags flags;
  uint32_t polling_time;
} vimbax_camera_msgs__msg__FeatureInfo;

// Struct for a sequence of vimbax_camera_msgs__msg__FeatureInfo.
typedef struct vimbax_camera_msgs__msg__FeatureInfo__Sequence
{
  vimbax_camera_msgs__msg__FeatureInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__msg__FeatureInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__STRUCT_H_

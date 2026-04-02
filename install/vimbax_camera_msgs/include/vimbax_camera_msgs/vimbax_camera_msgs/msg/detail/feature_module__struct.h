// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:msg/FeatureModule.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MODULE_REMOTE_DEVICE'.
enum
{
  vimbax_camera_msgs__msg__FeatureModule__MODULE_REMOTE_DEVICE = 0
};

/// Constant 'MODULE_SYSTEM'.
enum
{
  vimbax_camera_msgs__msg__FeatureModule__MODULE_SYSTEM = 1
};

/// Constant 'MODULE_INTERFACE'.
enum
{
  vimbax_camera_msgs__msg__FeatureModule__MODULE_INTERFACE = 2
};

/// Constant 'MODULE_LOCAL_DEVICE'.
enum
{
  vimbax_camera_msgs__msg__FeatureModule__MODULE_LOCAL_DEVICE = 3
};

/// Constant 'MODULE_STREAM'.
enum
{
  vimbax_camera_msgs__msg__FeatureModule__MODULE_STREAM = 4
};

/// Struct defined in msg/FeatureModule in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__msg__FeatureModule
{
  uint8_t id;
} vimbax_camera_msgs__msg__FeatureModule;

// Struct for a sequence of vimbax_camera_msgs__msg__FeatureModule.
typedef struct vimbax_camera_msgs__msg__FeatureModule__Sequence
{
  vimbax_camera_msgs__msg__FeatureModule * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__msg__FeatureModule__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:srv/FeatureEnumGet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ENUM_GET__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ENUM_GET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'feature_name'
#include "rosidl_runtime_c/string.h"
// Member 'feature_module'
#include "vimbax_camera_msgs/msg/detail/feature_module__struct.h"

/// Struct defined in srv/FeatureEnumGet in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__FeatureEnumGet_Request
{
  rosidl_runtime_c__String feature_name;
  vimbax_camera_msgs__msg__FeatureModule feature_module;
} vimbax_camera_msgs__srv__FeatureEnumGet_Request;

// Struct for a sequence of vimbax_camera_msgs__srv__FeatureEnumGet_Request.
typedef struct vimbax_camera_msgs__srv__FeatureEnumGet_Request__Sequence
{
  vimbax_camera_msgs__srv__FeatureEnumGet_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__FeatureEnumGet_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'value'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__struct.h"

/// Struct defined in srv/FeatureEnumGet in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__FeatureEnumGet_Response
{
  rosidl_runtime_c__String value;
  vimbax_camera_msgs__msg__Error error;
} vimbax_camera_msgs__srv__FeatureEnumGet_Response;

// Struct for a sequence of vimbax_camera_msgs__srv__FeatureEnumGet_Response.
typedef struct vimbax_camera_msgs__srv__FeatureEnumGet_Response__Sequence
{
  vimbax_camera_msgs__srv__FeatureEnumGet_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__FeatureEnumGet_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ENUM_GET__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:srv/Status.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Status in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__Status_Request
{
  uint8_t structure_needs_at_least_one_member;
} vimbax_camera_msgs__srv__Status_Request;

// Struct for a sequence of vimbax_camera_msgs__srv__Status_Request.
typedef struct vimbax_camera_msgs__srv__Status_Request__Sequence
{
  vimbax_camera_msgs__srv__Status_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__Status_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__struct.h"
// Member 'display_name'
// Member 'model_name'
// Member 'device_firmware_version'
// Member 'device_id'
// Member 'device_user_id'
// Member 'device_serial_number'
// Member 'interface_id'
// Member 'transport_layer_id'
// Member 'pixel_format'
// Member 'ip_address'
// Member 'mac_address'
#include "rosidl_runtime_c/string.h"
// Member 'trigger_info'
#include "vimbax_camera_msgs/msg/detail/trigger_info__struct.h"

/// Struct defined in srv/Status in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__Status_Response
{
  vimbax_camera_msgs__msg__Error error;
  rosidl_runtime_c__String display_name;
  rosidl_runtime_c__String model_name;
  rosidl_runtime_c__String device_firmware_version;
  rosidl_runtime_c__String device_id;
  rosidl_runtime_c__String device_user_id;
  rosidl_runtime_c__String device_serial_number;
  rosidl_runtime_c__String interface_id;
  rosidl_runtime_c__String transport_layer_id;
  bool streaming;
  uint32_t width;
  uint32_t height;
  double frame_rate;
  rosidl_runtime_c__String pixel_format;
  vimbax_camera_msgs__msg__TriggerInfo__Sequence trigger_info;
  rosidl_runtime_c__String ip_address;
  rosidl_runtime_c__String mac_address;
} vimbax_camera_msgs__srv__Status_Response;

// Struct for a sequence of vimbax_camera_msgs__srv__Status_Response.
typedef struct vimbax_camera_msgs__srv__Status_Response__Sequence
{
  vimbax_camera_msgs__srv__Status_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__Status_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__STRUCT_H_

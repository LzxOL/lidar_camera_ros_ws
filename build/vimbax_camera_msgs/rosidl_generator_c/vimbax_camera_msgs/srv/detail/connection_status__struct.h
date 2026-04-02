// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vimbax_camera_msgs:srv/ConnectionStatus.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__STRUCT_H_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ConnectionStatus in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__ConnectionStatus_Request
{
  uint8_t structure_needs_at_least_one_member;
} vimbax_camera_msgs__srv__ConnectionStatus_Request;

// Struct for a sequence of vimbax_camera_msgs__srv__ConnectionStatus_Request.
typedef struct vimbax_camera_msgs__srv__ConnectionStatus_Request__Sequence
{
  vimbax_camera_msgs__srv__ConnectionStatus_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__ConnectionStatus_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ConnectionStatus in the package vimbax_camera_msgs.
typedef struct vimbax_camera_msgs__srv__ConnectionStatus_Response
{
  bool connected;
} vimbax_camera_msgs__srv__ConnectionStatus_Response;

// Struct for a sequence of vimbax_camera_msgs__srv__ConnectionStatus_Response.
typedef struct vimbax_camera_msgs__srv__ConnectionStatus_Response__Sequence
{
  vimbax_camera_msgs__srv__ConnectionStatus_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vimbax_camera_msgs__srv__ConnectionStatus_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__STRUCT_H_

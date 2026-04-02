// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vimbax_camera_msgs:msg/EventDataEntry.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__FUNCTIONS_H_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vimbax_camera_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "vimbax_camera_msgs/msg/detail/event_data_entry__struct.h"

/// Initialize msg/EventDataEntry message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vimbax_camera_msgs__msg__EventDataEntry
 * )) before or use
 * vimbax_camera_msgs__msg__EventDataEntry__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
bool
vimbax_camera_msgs__msg__EventDataEntry__init(vimbax_camera_msgs__msg__EventDataEntry * msg);

/// Finalize msg/EventDataEntry message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
void
vimbax_camera_msgs__msg__EventDataEntry__fini(vimbax_camera_msgs__msg__EventDataEntry * msg);

/// Create msg/EventDataEntry message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vimbax_camera_msgs__msg__EventDataEntry__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
vimbax_camera_msgs__msg__EventDataEntry *
vimbax_camera_msgs__msg__EventDataEntry__create();

/// Destroy msg/EventDataEntry message.
/**
 * It calls
 * vimbax_camera_msgs__msg__EventDataEntry__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
void
vimbax_camera_msgs__msg__EventDataEntry__destroy(vimbax_camera_msgs__msg__EventDataEntry * msg);

/// Check for msg/EventDataEntry message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
bool
vimbax_camera_msgs__msg__EventDataEntry__are_equal(const vimbax_camera_msgs__msg__EventDataEntry * lhs, const vimbax_camera_msgs__msg__EventDataEntry * rhs);

/// Copy a msg/EventDataEntry message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
bool
vimbax_camera_msgs__msg__EventDataEntry__copy(
  const vimbax_camera_msgs__msg__EventDataEntry * input,
  vimbax_camera_msgs__msg__EventDataEntry * output);

/// Initialize array of msg/EventDataEntry messages.
/**
 * It allocates the memory for the number of elements and calls
 * vimbax_camera_msgs__msg__EventDataEntry__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
bool
vimbax_camera_msgs__msg__EventDataEntry__Sequence__init(vimbax_camera_msgs__msg__EventDataEntry__Sequence * array, size_t size);

/// Finalize array of msg/EventDataEntry messages.
/**
 * It calls
 * vimbax_camera_msgs__msg__EventDataEntry__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
void
vimbax_camera_msgs__msg__EventDataEntry__Sequence__fini(vimbax_camera_msgs__msg__EventDataEntry__Sequence * array);

/// Create array of msg/EventDataEntry messages.
/**
 * It allocates the memory for the array and calls
 * vimbax_camera_msgs__msg__EventDataEntry__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
vimbax_camera_msgs__msg__EventDataEntry__Sequence *
vimbax_camera_msgs__msg__EventDataEntry__Sequence__create(size_t size);

/// Destroy array of msg/EventDataEntry messages.
/**
 * It calls
 * vimbax_camera_msgs__msg__EventDataEntry__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
void
vimbax_camera_msgs__msg__EventDataEntry__Sequence__destroy(vimbax_camera_msgs__msg__EventDataEntry__Sequence * array);

/// Check for msg/EventDataEntry message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
bool
vimbax_camera_msgs__msg__EventDataEntry__Sequence__are_equal(const vimbax_camera_msgs__msg__EventDataEntry__Sequence * lhs, const vimbax_camera_msgs__msg__EventDataEntry__Sequence * rhs);

/// Copy an array of msg/EventDataEntry messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vimbax_camera_msgs
bool
vimbax_camera_msgs__msg__EventDataEntry__Sequence__copy(
  const vimbax_camera_msgs__msg__EventDataEntry__Sequence * input,
  vimbax_camera_msgs__msg__EventDataEntry__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__EVENT_DATA_ENTRY__FUNCTIONS_H_

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vimbax_camera_msgs:srv/Status.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/srv/detail/status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
vimbax_camera_msgs__srv__Status_Request__init(vimbax_camera_msgs__srv__Status_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
vimbax_camera_msgs__srv__Status_Request__fini(vimbax_camera_msgs__srv__Status_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
vimbax_camera_msgs__srv__Status_Request__are_equal(const vimbax_camera_msgs__srv__Status_Request * lhs, const vimbax_camera_msgs__srv__Status_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
vimbax_camera_msgs__srv__Status_Request__copy(
  const vimbax_camera_msgs__srv__Status_Request * input,
  vimbax_camera_msgs__srv__Status_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

vimbax_camera_msgs__srv__Status_Request *
vimbax_camera_msgs__srv__Status_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__Status_Request * msg = (vimbax_camera_msgs__srv__Status_Request *)allocator.allocate(sizeof(vimbax_camera_msgs__srv__Status_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vimbax_camera_msgs__srv__Status_Request));
  bool success = vimbax_camera_msgs__srv__Status_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vimbax_camera_msgs__srv__Status_Request__destroy(vimbax_camera_msgs__srv__Status_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vimbax_camera_msgs__srv__Status_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vimbax_camera_msgs__srv__Status_Request__Sequence__init(vimbax_camera_msgs__srv__Status_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__Status_Request * data = NULL;

  if (size) {
    data = (vimbax_camera_msgs__srv__Status_Request *)allocator.zero_allocate(size, sizeof(vimbax_camera_msgs__srv__Status_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vimbax_camera_msgs__srv__Status_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vimbax_camera_msgs__srv__Status_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vimbax_camera_msgs__srv__Status_Request__Sequence__fini(vimbax_camera_msgs__srv__Status_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vimbax_camera_msgs__srv__Status_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vimbax_camera_msgs__srv__Status_Request__Sequence *
vimbax_camera_msgs__srv__Status_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__Status_Request__Sequence * array = (vimbax_camera_msgs__srv__Status_Request__Sequence *)allocator.allocate(sizeof(vimbax_camera_msgs__srv__Status_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vimbax_camera_msgs__srv__Status_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vimbax_camera_msgs__srv__Status_Request__Sequence__destroy(vimbax_camera_msgs__srv__Status_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vimbax_camera_msgs__srv__Status_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vimbax_camera_msgs__srv__Status_Request__Sequence__are_equal(const vimbax_camera_msgs__srv__Status_Request__Sequence * lhs, const vimbax_camera_msgs__srv__Status_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vimbax_camera_msgs__srv__Status_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vimbax_camera_msgs__srv__Status_Request__Sequence__copy(
  const vimbax_camera_msgs__srv__Status_Request__Sequence * input,
  vimbax_camera_msgs__srv__Status_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vimbax_camera_msgs__srv__Status_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vimbax_camera_msgs__srv__Status_Request * data =
      (vimbax_camera_msgs__srv__Status_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vimbax_camera_msgs__srv__Status_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vimbax_camera_msgs__srv__Status_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vimbax_camera_msgs__srv__Status_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error`
#include "vimbax_camera_msgs/msg/detail/error__functions.h"
// Member `display_name`
// Member `model_name`
// Member `device_firmware_version`
// Member `device_id`
// Member `device_user_id`
// Member `device_serial_number`
// Member `interface_id`
// Member `transport_layer_id`
// Member `pixel_format`
// Member `ip_address`
// Member `mac_address`
#include "rosidl_runtime_c/string_functions.h"
// Member `trigger_info`
#include "vimbax_camera_msgs/msg/detail/trigger_info__functions.h"

bool
vimbax_camera_msgs__srv__Status_Response__init(vimbax_camera_msgs__srv__Status_Response * msg)
{
  if (!msg) {
    return false;
  }
  // error
  if (!vimbax_camera_msgs__msg__Error__init(&msg->error)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // display_name
  if (!rosidl_runtime_c__String__init(&msg->display_name)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // model_name
  if (!rosidl_runtime_c__String__init(&msg->model_name)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // device_firmware_version
  if (!rosidl_runtime_c__String__init(&msg->device_firmware_version)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__init(&msg->device_id)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // device_user_id
  if (!rosidl_runtime_c__String__init(&msg->device_user_id)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // device_serial_number
  if (!rosidl_runtime_c__String__init(&msg->device_serial_number)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // interface_id
  if (!rosidl_runtime_c__String__init(&msg->interface_id)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // transport_layer_id
  if (!rosidl_runtime_c__String__init(&msg->transport_layer_id)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // streaming
  // width
  // height
  // frame_rate
  // pixel_format
  if (!rosidl_runtime_c__String__init(&msg->pixel_format)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // trigger_info
  if (!vimbax_camera_msgs__msg__TriggerInfo__Sequence__init(&msg->trigger_info, 0)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // ip_address
  if (!rosidl_runtime_c__String__init(&msg->ip_address)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  // mac_address
  if (!rosidl_runtime_c__String__init(&msg->mac_address)) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
    return false;
  }
  return true;
}

void
vimbax_camera_msgs__srv__Status_Response__fini(vimbax_camera_msgs__srv__Status_Response * msg)
{
  if (!msg) {
    return;
  }
  // error
  vimbax_camera_msgs__msg__Error__fini(&msg->error);
  // display_name
  rosidl_runtime_c__String__fini(&msg->display_name);
  // model_name
  rosidl_runtime_c__String__fini(&msg->model_name);
  // device_firmware_version
  rosidl_runtime_c__String__fini(&msg->device_firmware_version);
  // device_id
  rosidl_runtime_c__String__fini(&msg->device_id);
  // device_user_id
  rosidl_runtime_c__String__fini(&msg->device_user_id);
  // device_serial_number
  rosidl_runtime_c__String__fini(&msg->device_serial_number);
  // interface_id
  rosidl_runtime_c__String__fini(&msg->interface_id);
  // transport_layer_id
  rosidl_runtime_c__String__fini(&msg->transport_layer_id);
  // streaming
  // width
  // height
  // frame_rate
  // pixel_format
  rosidl_runtime_c__String__fini(&msg->pixel_format);
  // trigger_info
  vimbax_camera_msgs__msg__TriggerInfo__Sequence__fini(&msg->trigger_info);
  // ip_address
  rosidl_runtime_c__String__fini(&msg->ip_address);
  // mac_address
  rosidl_runtime_c__String__fini(&msg->mac_address);
}

bool
vimbax_camera_msgs__srv__Status_Response__are_equal(const vimbax_camera_msgs__srv__Status_Response * lhs, const vimbax_camera_msgs__srv__Status_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // error
  if (!vimbax_camera_msgs__msg__Error__are_equal(
      &(lhs->error), &(rhs->error)))
  {
    return false;
  }
  // display_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->display_name), &(rhs->display_name)))
  {
    return false;
  }
  // model_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->model_name), &(rhs->model_name)))
  {
    return false;
  }
  // device_firmware_version
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_firmware_version), &(rhs->device_firmware_version)))
  {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_id), &(rhs->device_id)))
  {
    return false;
  }
  // device_user_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_user_id), &(rhs->device_user_id)))
  {
    return false;
  }
  // device_serial_number
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_serial_number), &(rhs->device_serial_number)))
  {
    return false;
  }
  // interface_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->interface_id), &(rhs->interface_id)))
  {
    return false;
  }
  // transport_layer_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->transport_layer_id), &(rhs->transport_layer_id)))
  {
    return false;
  }
  // streaming
  if (lhs->streaming != rhs->streaming) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // frame_rate
  if (lhs->frame_rate != rhs->frame_rate) {
    return false;
  }
  // pixel_format
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->pixel_format), &(rhs->pixel_format)))
  {
    return false;
  }
  // trigger_info
  if (!vimbax_camera_msgs__msg__TriggerInfo__Sequence__are_equal(
      &(lhs->trigger_info), &(rhs->trigger_info)))
  {
    return false;
  }
  // ip_address
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->ip_address), &(rhs->ip_address)))
  {
    return false;
  }
  // mac_address
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mac_address), &(rhs->mac_address)))
  {
    return false;
  }
  return true;
}

bool
vimbax_camera_msgs__srv__Status_Response__copy(
  const vimbax_camera_msgs__srv__Status_Response * input,
  vimbax_camera_msgs__srv__Status_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // error
  if (!vimbax_camera_msgs__msg__Error__copy(
      &(input->error), &(output->error)))
  {
    return false;
  }
  // display_name
  if (!rosidl_runtime_c__String__copy(
      &(input->display_name), &(output->display_name)))
  {
    return false;
  }
  // model_name
  if (!rosidl_runtime_c__String__copy(
      &(input->model_name), &(output->model_name)))
  {
    return false;
  }
  // device_firmware_version
  if (!rosidl_runtime_c__String__copy(
      &(input->device_firmware_version), &(output->device_firmware_version)))
  {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__copy(
      &(input->device_id), &(output->device_id)))
  {
    return false;
  }
  // device_user_id
  if (!rosidl_runtime_c__String__copy(
      &(input->device_user_id), &(output->device_user_id)))
  {
    return false;
  }
  // device_serial_number
  if (!rosidl_runtime_c__String__copy(
      &(input->device_serial_number), &(output->device_serial_number)))
  {
    return false;
  }
  // interface_id
  if (!rosidl_runtime_c__String__copy(
      &(input->interface_id), &(output->interface_id)))
  {
    return false;
  }
  // transport_layer_id
  if (!rosidl_runtime_c__String__copy(
      &(input->transport_layer_id), &(output->transport_layer_id)))
  {
    return false;
  }
  // streaming
  output->streaming = input->streaming;
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  // frame_rate
  output->frame_rate = input->frame_rate;
  // pixel_format
  if (!rosidl_runtime_c__String__copy(
      &(input->pixel_format), &(output->pixel_format)))
  {
    return false;
  }
  // trigger_info
  if (!vimbax_camera_msgs__msg__TriggerInfo__Sequence__copy(
      &(input->trigger_info), &(output->trigger_info)))
  {
    return false;
  }
  // ip_address
  if (!rosidl_runtime_c__String__copy(
      &(input->ip_address), &(output->ip_address)))
  {
    return false;
  }
  // mac_address
  if (!rosidl_runtime_c__String__copy(
      &(input->mac_address), &(output->mac_address)))
  {
    return false;
  }
  return true;
}

vimbax_camera_msgs__srv__Status_Response *
vimbax_camera_msgs__srv__Status_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__Status_Response * msg = (vimbax_camera_msgs__srv__Status_Response *)allocator.allocate(sizeof(vimbax_camera_msgs__srv__Status_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vimbax_camera_msgs__srv__Status_Response));
  bool success = vimbax_camera_msgs__srv__Status_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vimbax_camera_msgs__srv__Status_Response__destroy(vimbax_camera_msgs__srv__Status_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vimbax_camera_msgs__srv__Status_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vimbax_camera_msgs__srv__Status_Response__Sequence__init(vimbax_camera_msgs__srv__Status_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__Status_Response * data = NULL;

  if (size) {
    data = (vimbax_camera_msgs__srv__Status_Response *)allocator.zero_allocate(size, sizeof(vimbax_camera_msgs__srv__Status_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vimbax_camera_msgs__srv__Status_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vimbax_camera_msgs__srv__Status_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vimbax_camera_msgs__srv__Status_Response__Sequence__fini(vimbax_camera_msgs__srv__Status_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vimbax_camera_msgs__srv__Status_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vimbax_camera_msgs__srv__Status_Response__Sequence *
vimbax_camera_msgs__srv__Status_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__Status_Response__Sequence * array = (vimbax_camera_msgs__srv__Status_Response__Sequence *)allocator.allocate(sizeof(vimbax_camera_msgs__srv__Status_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vimbax_camera_msgs__srv__Status_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vimbax_camera_msgs__srv__Status_Response__Sequence__destroy(vimbax_camera_msgs__srv__Status_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vimbax_camera_msgs__srv__Status_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vimbax_camera_msgs__srv__Status_Response__Sequence__are_equal(const vimbax_camera_msgs__srv__Status_Response__Sequence * lhs, const vimbax_camera_msgs__srv__Status_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vimbax_camera_msgs__srv__Status_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vimbax_camera_msgs__srv__Status_Response__Sequence__copy(
  const vimbax_camera_msgs__srv__Status_Response__Sequence * input,
  vimbax_camera_msgs__srv__Status_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vimbax_camera_msgs__srv__Status_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vimbax_camera_msgs__srv__Status_Response * data =
      (vimbax_camera_msgs__srv__Status_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vimbax_camera_msgs__srv__Status_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vimbax_camera_msgs__srv__Status_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vimbax_camera_msgs__srv__Status_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

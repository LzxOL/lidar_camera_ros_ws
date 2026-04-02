// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vimbax_camera_msgs:srv/StreamStartStop.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/srv/detail/stream_start_stop__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
vimbax_camera_msgs__srv__StreamStartStop_Request__init(vimbax_camera_msgs__srv__StreamStartStop_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
vimbax_camera_msgs__srv__StreamStartStop_Request__fini(vimbax_camera_msgs__srv__StreamStartStop_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
vimbax_camera_msgs__srv__StreamStartStop_Request__are_equal(const vimbax_camera_msgs__srv__StreamStartStop_Request * lhs, const vimbax_camera_msgs__srv__StreamStartStop_Request * rhs)
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
vimbax_camera_msgs__srv__StreamStartStop_Request__copy(
  const vimbax_camera_msgs__srv__StreamStartStop_Request * input,
  vimbax_camera_msgs__srv__StreamStartStop_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

vimbax_camera_msgs__srv__StreamStartStop_Request *
vimbax_camera_msgs__srv__StreamStartStop_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__StreamStartStop_Request * msg = (vimbax_camera_msgs__srv__StreamStartStop_Request *)allocator.allocate(sizeof(vimbax_camera_msgs__srv__StreamStartStop_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vimbax_camera_msgs__srv__StreamStartStop_Request));
  bool success = vimbax_camera_msgs__srv__StreamStartStop_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vimbax_camera_msgs__srv__StreamStartStop_Request__destroy(vimbax_camera_msgs__srv__StreamStartStop_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vimbax_camera_msgs__srv__StreamStartStop_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence__init(vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__StreamStartStop_Request * data = NULL;

  if (size) {
    data = (vimbax_camera_msgs__srv__StreamStartStop_Request *)allocator.zero_allocate(size, sizeof(vimbax_camera_msgs__srv__StreamStartStop_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vimbax_camera_msgs__srv__StreamStartStop_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vimbax_camera_msgs__srv__StreamStartStop_Request__fini(&data[i - 1]);
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
vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence__fini(vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence * array)
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
      vimbax_camera_msgs__srv__StreamStartStop_Request__fini(&array->data[i]);
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

vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence *
vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence * array = (vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence *)allocator.allocate(sizeof(vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence__destroy(vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence__are_equal(const vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence * lhs, const vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vimbax_camera_msgs__srv__StreamStartStop_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence__copy(
  const vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence * input,
  vimbax_camera_msgs__srv__StreamStartStop_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vimbax_camera_msgs__srv__StreamStartStop_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vimbax_camera_msgs__srv__StreamStartStop_Request * data =
      (vimbax_camera_msgs__srv__StreamStartStop_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vimbax_camera_msgs__srv__StreamStartStop_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vimbax_camera_msgs__srv__StreamStartStop_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vimbax_camera_msgs__srv__StreamStartStop_Request__copy(
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

bool
vimbax_camera_msgs__srv__StreamStartStop_Response__init(vimbax_camera_msgs__srv__StreamStartStop_Response * msg)
{
  if (!msg) {
    return false;
  }
  // error
  if (!vimbax_camera_msgs__msg__Error__init(&msg->error)) {
    vimbax_camera_msgs__srv__StreamStartStop_Response__fini(msg);
    return false;
  }
  return true;
}

void
vimbax_camera_msgs__srv__StreamStartStop_Response__fini(vimbax_camera_msgs__srv__StreamStartStop_Response * msg)
{
  if (!msg) {
    return;
  }
  // error
  vimbax_camera_msgs__msg__Error__fini(&msg->error);
}

bool
vimbax_camera_msgs__srv__StreamStartStop_Response__are_equal(const vimbax_camera_msgs__srv__StreamStartStop_Response * lhs, const vimbax_camera_msgs__srv__StreamStartStop_Response * rhs)
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
  return true;
}

bool
vimbax_camera_msgs__srv__StreamStartStop_Response__copy(
  const vimbax_camera_msgs__srv__StreamStartStop_Response * input,
  vimbax_camera_msgs__srv__StreamStartStop_Response * output)
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
  return true;
}

vimbax_camera_msgs__srv__StreamStartStop_Response *
vimbax_camera_msgs__srv__StreamStartStop_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__StreamStartStop_Response * msg = (vimbax_camera_msgs__srv__StreamStartStop_Response *)allocator.allocate(sizeof(vimbax_camera_msgs__srv__StreamStartStop_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vimbax_camera_msgs__srv__StreamStartStop_Response));
  bool success = vimbax_camera_msgs__srv__StreamStartStop_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vimbax_camera_msgs__srv__StreamStartStop_Response__destroy(vimbax_camera_msgs__srv__StreamStartStop_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vimbax_camera_msgs__srv__StreamStartStop_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence__init(vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__StreamStartStop_Response * data = NULL;

  if (size) {
    data = (vimbax_camera_msgs__srv__StreamStartStop_Response *)allocator.zero_allocate(size, sizeof(vimbax_camera_msgs__srv__StreamStartStop_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vimbax_camera_msgs__srv__StreamStartStop_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vimbax_camera_msgs__srv__StreamStartStop_Response__fini(&data[i - 1]);
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
vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence__fini(vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence * array)
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
      vimbax_camera_msgs__srv__StreamStartStop_Response__fini(&array->data[i]);
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

vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence *
vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence * array = (vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence *)allocator.allocate(sizeof(vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence__destroy(vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence__are_equal(const vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence * lhs, const vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vimbax_camera_msgs__srv__StreamStartStop_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence__copy(
  const vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence * input,
  vimbax_camera_msgs__srv__StreamStartStop_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vimbax_camera_msgs__srv__StreamStartStop_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vimbax_camera_msgs__srv__StreamStartStop_Response * data =
      (vimbax_camera_msgs__srv__StreamStartStop_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vimbax_camera_msgs__srv__StreamStartStop_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vimbax_camera_msgs__srv__StreamStartStop_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vimbax_camera_msgs__srv__StreamStartStop_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

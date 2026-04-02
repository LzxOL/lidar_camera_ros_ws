// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vimbax_camera_msgs:msg/TriggerInfo.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/msg/detail/trigger_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `selector`
// Member `mode`
// Member `source`
#include "rosidl_runtime_c/string_functions.h"

bool
vimbax_camera_msgs__msg__TriggerInfo__init(vimbax_camera_msgs__msg__TriggerInfo * msg)
{
  if (!msg) {
    return false;
  }
  // selector
  if (!rosidl_runtime_c__String__init(&msg->selector)) {
    vimbax_camera_msgs__msg__TriggerInfo__fini(msg);
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    vimbax_camera_msgs__msg__TriggerInfo__fini(msg);
    return false;
  }
  // source
  if (!rosidl_runtime_c__String__init(&msg->source)) {
    vimbax_camera_msgs__msg__TriggerInfo__fini(msg);
    return false;
  }
  return true;
}

void
vimbax_camera_msgs__msg__TriggerInfo__fini(vimbax_camera_msgs__msg__TriggerInfo * msg)
{
  if (!msg) {
    return;
  }
  // selector
  rosidl_runtime_c__String__fini(&msg->selector);
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // source
  rosidl_runtime_c__String__fini(&msg->source);
}

bool
vimbax_camera_msgs__msg__TriggerInfo__are_equal(const vimbax_camera_msgs__msg__TriggerInfo * lhs, const vimbax_camera_msgs__msg__TriggerInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // selector
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->selector), &(rhs->selector)))
  {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  // source
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->source), &(rhs->source)))
  {
    return false;
  }
  return true;
}

bool
vimbax_camera_msgs__msg__TriggerInfo__copy(
  const vimbax_camera_msgs__msg__TriggerInfo * input,
  vimbax_camera_msgs__msg__TriggerInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // selector
  if (!rosidl_runtime_c__String__copy(
      &(input->selector), &(output->selector)))
  {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  // source
  if (!rosidl_runtime_c__String__copy(
      &(input->source), &(output->source)))
  {
    return false;
  }
  return true;
}

vimbax_camera_msgs__msg__TriggerInfo *
vimbax_camera_msgs__msg__TriggerInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__TriggerInfo * msg = (vimbax_camera_msgs__msg__TriggerInfo *)allocator.allocate(sizeof(vimbax_camera_msgs__msg__TriggerInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vimbax_camera_msgs__msg__TriggerInfo));
  bool success = vimbax_camera_msgs__msg__TriggerInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vimbax_camera_msgs__msg__TriggerInfo__destroy(vimbax_camera_msgs__msg__TriggerInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vimbax_camera_msgs__msg__TriggerInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vimbax_camera_msgs__msg__TriggerInfo__Sequence__init(vimbax_camera_msgs__msg__TriggerInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__TriggerInfo * data = NULL;

  if (size) {
    data = (vimbax_camera_msgs__msg__TriggerInfo *)allocator.zero_allocate(size, sizeof(vimbax_camera_msgs__msg__TriggerInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vimbax_camera_msgs__msg__TriggerInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vimbax_camera_msgs__msg__TriggerInfo__fini(&data[i - 1]);
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
vimbax_camera_msgs__msg__TriggerInfo__Sequence__fini(vimbax_camera_msgs__msg__TriggerInfo__Sequence * array)
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
      vimbax_camera_msgs__msg__TriggerInfo__fini(&array->data[i]);
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

vimbax_camera_msgs__msg__TriggerInfo__Sequence *
vimbax_camera_msgs__msg__TriggerInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__TriggerInfo__Sequence * array = (vimbax_camera_msgs__msg__TriggerInfo__Sequence *)allocator.allocate(sizeof(vimbax_camera_msgs__msg__TriggerInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vimbax_camera_msgs__msg__TriggerInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vimbax_camera_msgs__msg__TriggerInfo__Sequence__destroy(vimbax_camera_msgs__msg__TriggerInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vimbax_camera_msgs__msg__TriggerInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vimbax_camera_msgs__msg__TriggerInfo__Sequence__are_equal(const vimbax_camera_msgs__msg__TriggerInfo__Sequence * lhs, const vimbax_camera_msgs__msg__TriggerInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vimbax_camera_msgs__msg__TriggerInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vimbax_camera_msgs__msg__TriggerInfo__Sequence__copy(
  const vimbax_camera_msgs__msg__TriggerInfo__Sequence * input,
  vimbax_camera_msgs__msg__TriggerInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vimbax_camera_msgs__msg__TriggerInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vimbax_camera_msgs__msg__TriggerInfo * data =
      (vimbax_camera_msgs__msg__TriggerInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vimbax_camera_msgs__msg__TriggerInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vimbax_camera_msgs__msg__TriggerInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vimbax_camera_msgs__msg__TriggerInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vimbax_camera_msgs:msg/EventDataEntry.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/msg/detail/event_data_entry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `value`
#include "rosidl_runtime_c/string_functions.h"

bool
vimbax_camera_msgs__msg__EventDataEntry__init(vimbax_camera_msgs__msg__EventDataEntry * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    vimbax_camera_msgs__msg__EventDataEntry__fini(msg);
    return false;
  }
  // value
  if (!rosidl_runtime_c__String__init(&msg->value)) {
    vimbax_camera_msgs__msg__EventDataEntry__fini(msg);
    return false;
  }
  return true;
}

void
vimbax_camera_msgs__msg__EventDataEntry__fini(vimbax_camera_msgs__msg__EventDataEntry * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // value
  rosidl_runtime_c__String__fini(&msg->value);
}

bool
vimbax_camera_msgs__msg__EventDataEntry__are_equal(const vimbax_camera_msgs__msg__EventDataEntry * lhs, const vimbax_camera_msgs__msg__EventDataEntry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // value
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->value), &(rhs->value)))
  {
    return false;
  }
  return true;
}

bool
vimbax_camera_msgs__msg__EventDataEntry__copy(
  const vimbax_camera_msgs__msg__EventDataEntry * input,
  vimbax_camera_msgs__msg__EventDataEntry * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // value
  if (!rosidl_runtime_c__String__copy(
      &(input->value), &(output->value)))
  {
    return false;
  }
  return true;
}

vimbax_camera_msgs__msg__EventDataEntry *
vimbax_camera_msgs__msg__EventDataEntry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__EventDataEntry * msg = (vimbax_camera_msgs__msg__EventDataEntry *)allocator.allocate(sizeof(vimbax_camera_msgs__msg__EventDataEntry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vimbax_camera_msgs__msg__EventDataEntry));
  bool success = vimbax_camera_msgs__msg__EventDataEntry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vimbax_camera_msgs__msg__EventDataEntry__destroy(vimbax_camera_msgs__msg__EventDataEntry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vimbax_camera_msgs__msg__EventDataEntry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vimbax_camera_msgs__msg__EventDataEntry__Sequence__init(vimbax_camera_msgs__msg__EventDataEntry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__EventDataEntry * data = NULL;

  if (size) {
    data = (vimbax_camera_msgs__msg__EventDataEntry *)allocator.zero_allocate(size, sizeof(vimbax_camera_msgs__msg__EventDataEntry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vimbax_camera_msgs__msg__EventDataEntry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vimbax_camera_msgs__msg__EventDataEntry__fini(&data[i - 1]);
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
vimbax_camera_msgs__msg__EventDataEntry__Sequence__fini(vimbax_camera_msgs__msg__EventDataEntry__Sequence * array)
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
      vimbax_camera_msgs__msg__EventDataEntry__fini(&array->data[i]);
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

vimbax_camera_msgs__msg__EventDataEntry__Sequence *
vimbax_camera_msgs__msg__EventDataEntry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__EventDataEntry__Sequence * array = (vimbax_camera_msgs__msg__EventDataEntry__Sequence *)allocator.allocate(sizeof(vimbax_camera_msgs__msg__EventDataEntry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vimbax_camera_msgs__msg__EventDataEntry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vimbax_camera_msgs__msg__EventDataEntry__Sequence__destroy(vimbax_camera_msgs__msg__EventDataEntry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vimbax_camera_msgs__msg__EventDataEntry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vimbax_camera_msgs__msg__EventDataEntry__Sequence__are_equal(const vimbax_camera_msgs__msg__EventDataEntry__Sequence * lhs, const vimbax_camera_msgs__msg__EventDataEntry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vimbax_camera_msgs__msg__EventDataEntry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vimbax_camera_msgs__msg__EventDataEntry__Sequence__copy(
  const vimbax_camera_msgs__msg__EventDataEntry__Sequence * input,
  vimbax_camera_msgs__msg__EventDataEntry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vimbax_camera_msgs__msg__EventDataEntry);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vimbax_camera_msgs__msg__EventDataEntry * data =
      (vimbax_camera_msgs__msg__EventDataEntry *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vimbax_camera_msgs__msg__EventDataEntry__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vimbax_camera_msgs__msg__EventDataEntry__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vimbax_camera_msgs__msg__EventDataEntry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

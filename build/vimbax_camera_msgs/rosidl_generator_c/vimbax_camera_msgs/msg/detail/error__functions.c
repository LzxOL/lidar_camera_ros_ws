// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vimbax_camera_msgs:msg/Error.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/msg/detail/error__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `text`
#include "rosidl_runtime_c/string_functions.h"

bool
vimbax_camera_msgs__msg__Error__init(vimbax_camera_msgs__msg__Error * msg)
{
  if (!msg) {
    return false;
  }
  // code
  // text
  if (!rosidl_runtime_c__String__init(&msg->text)) {
    vimbax_camera_msgs__msg__Error__fini(msg);
    return false;
  }
  return true;
}

void
vimbax_camera_msgs__msg__Error__fini(vimbax_camera_msgs__msg__Error * msg)
{
  if (!msg) {
    return;
  }
  // code
  // text
  rosidl_runtime_c__String__fini(&msg->text);
}

bool
vimbax_camera_msgs__msg__Error__are_equal(const vimbax_camera_msgs__msg__Error * lhs, const vimbax_camera_msgs__msg__Error * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // code
  if (lhs->code != rhs->code) {
    return false;
  }
  // text
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->text), &(rhs->text)))
  {
    return false;
  }
  return true;
}

bool
vimbax_camera_msgs__msg__Error__copy(
  const vimbax_camera_msgs__msg__Error * input,
  vimbax_camera_msgs__msg__Error * output)
{
  if (!input || !output) {
    return false;
  }
  // code
  output->code = input->code;
  // text
  if (!rosidl_runtime_c__String__copy(
      &(input->text), &(output->text)))
  {
    return false;
  }
  return true;
}

vimbax_camera_msgs__msg__Error *
vimbax_camera_msgs__msg__Error__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__Error * msg = (vimbax_camera_msgs__msg__Error *)allocator.allocate(sizeof(vimbax_camera_msgs__msg__Error), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vimbax_camera_msgs__msg__Error));
  bool success = vimbax_camera_msgs__msg__Error__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vimbax_camera_msgs__msg__Error__destroy(vimbax_camera_msgs__msg__Error * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vimbax_camera_msgs__msg__Error__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vimbax_camera_msgs__msg__Error__Sequence__init(vimbax_camera_msgs__msg__Error__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__Error * data = NULL;

  if (size) {
    data = (vimbax_camera_msgs__msg__Error *)allocator.zero_allocate(size, sizeof(vimbax_camera_msgs__msg__Error), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vimbax_camera_msgs__msg__Error__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vimbax_camera_msgs__msg__Error__fini(&data[i - 1]);
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
vimbax_camera_msgs__msg__Error__Sequence__fini(vimbax_camera_msgs__msg__Error__Sequence * array)
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
      vimbax_camera_msgs__msg__Error__fini(&array->data[i]);
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

vimbax_camera_msgs__msg__Error__Sequence *
vimbax_camera_msgs__msg__Error__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__Error__Sequence * array = (vimbax_camera_msgs__msg__Error__Sequence *)allocator.allocate(sizeof(vimbax_camera_msgs__msg__Error__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vimbax_camera_msgs__msg__Error__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vimbax_camera_msgs__msg__Error__Sequence__destroy(vimbax_camera_msgs__msg__Error__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vimbax_camera_msgs__msg__Error__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vimbax_camera_msgs__msg__Error__Sequence__are_equal(const vimbax_camera_msgs__msg__Error__Sequence * lhs, const vimbax_camera_msgs__msg__Error__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vimbax_camera_msgs__msg__Error__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vimbax_camera_msgs__msg__Error__Sequence__copy(
  const vimbax_camera_msgs__msg__Error__Sequence * input,
  vimbax_camera_msgs__msg__Error__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vimbax_camera_msgs__msg__Error);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vimbax_camera_msgs__msg__Error * data =
      (vimbax_camera_msgs__msg__Error *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vimbax_camera_msgs__msg__Error__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vimbax_camera_msgs__msg__Error__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vimbax_camera_msgs__msg__Error__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vimbax_camera_msgs:msg/FeatureInfo.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/msg/detail/feature_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `category`
// Member `display_name`
// Member `sfnc_namespace`
// Member `unit`
#include "rosidl_runtime_c/string_functions.h"
// Member `flags`
#include "vimbax_camera_msgs/msg/detail/feature_flags__functions.h"

bool
vimbax_camera_msgs__msg__FeatureInfo__init(vimbax_camera_msgs__msg__FeatureInfo * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    vimbax_camera_msgs__msg__FeatureInfo__fini(msg);
    return false;
  }
  // category
  if (!rosidl_runtime_c__String__init(&msg->category)) {
    vimbax_camera_msgs__msg__FeatureInfo__fini(msg);
    return false;
  }
  // display_name
  if (!rosidl_runtime_c__String__init(&msg->display_name)) {
    vimbax_camera_msgs__msg__FeatureInfo__fini(msg);
    return false;
  }
  // sfnc_namespace
  if (!rosidl_runtime_c__String__init(&msg->sfnc_namespace)) {
    vimbax_camera_msgs__msg__FeatureInfo__fini(msg);
    return false;
  }
  // unit
  if (!rosidl_runtime_c__String__init(&msg->unit)) {
    vimbax_camera_msgs__msg__FeatureInfo__fini(msg);
    return false;
  }
  // data_type
  // flags
  if (!vimbax_camera_msgs__msg__FeatureFlags__init(&msg->flags)) {
    vimbax_camera_msgs__msg__FeatureInfo__fini(msg);
    return false;
  }
  // polling_time
  return true;
}

void
vimbax_camera_msgs__msg__FeatureInfo__fini(vimbax_camera_msgs__msg__FeatureInfo * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // category
  rosidl_runtime_c__String__fini(&msg->category);
  // display_name
  rosidl_runtime_c__String__fini(&msg->display_name);
  // sfnc_namespace
  rosidl_runtime_c__String__fini(&msg->sfnc_namespace);
  // unit
  rosidl_runtime_c__String__fini(&msg->unit);
  // data_type
  // flags
  vimbax_camera_msgs__msg__FeatureFlags__fini(&msg->flags);
  // polling_time
}

bool
vimbax_camera_msgs__msg__FeatureInfo__are_equal(const vimbax_camera_msgs__msg__FeatureInfo * lhs, const vimbax_camera_msgs__msg__FeatureInfo * rhs)
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
  // category
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->category), &(rhs->category)))
  {
    return false;
  }
  // display_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->display_name), &(rhs->display_name)))
  {
    return false;
  }
  // sfnc_namespace
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sfnc_namespace), &(rhs->sfnc_namespace)))
  {
    return false;
  }
  // unit
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->unit), &(rhs->unit)))
  {
    return false;
  }
  // data_type
  if (lhs->data_type != rhs->data_type) {
    return false;
  }
  // flags
  if (!vimbax_camera_msgs__msg__FeatureFlags__are_equal(
      &(lhs->flags), &(rhs->flags)))
  {
    return false;
  }
  // polling_time
  if (lhs->polling_time != rhs->polling_time) {
    return false;
  }
  return true;
}

bool
vimbax_camera_msgs__msg__FeatureInfo__copy(
  const vimbax_camera_msgs__msg__FeatureInfo * input,
  vimbax_camera_msgs__msg__FeatureInfo * output)
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
  // category
  if (!rosidl_runtime_c__String__copy(
      &(input->category), &(output->category)))
  {
    return false;
  }
  // display_name
  if (!rosidl_runtime_c__String__copy(
      &(input->display_name), &(output->display_name)))
  {
    return false;
  }
  // sfnc_namespace
  if (!rosidl_runtime_c__String__copy(
      &(input->sfnc_namespace), &(output->sfnc_namespace)))
  {
    return false;
  }
  // unit
  if (!rosidl_runtime_c__String__copy(
      &(input->unit), &(output->unit)))
  {
    return false;
  }
  // data_type
  output->data_type = input->data_type;
  // flags
  if (!vimbax_camera_msgs__msg__FeatureFlags__copy(
      &(input->flags), &(output->flags)))
  {
    return false;
  }
  // polling_time
  output->polling_time = input->polling_time;
  return true;
}

vimbax_camera_msgs__msg__FeatureInfo *
vimbax_camera_msgs__msg__FeatureInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__FeatureInfo * msg = (vimbax_camera_msgs__msg__FeatureInfo *)allocator.allocate(sizeof(vimbax_camera_msgs__msg__FeatureInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vimbax_camera_msgs__msg__FeatureInfo));
  bool success = vimbax_camera_msgs__msg__FeatureInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vimbax_camera_msgs__msg__FeatureInfo__destroy(vimbax_camera_msgs__msg__FeatureInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vimbax_camera_msgs__msg__FeatureInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vimbax_camera_msgs__msg__FeatureInfo__Sequence__init(vimbax_camera_msgs__msg__FeatureInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__FeatureInfo * data = NULL;

  if (size) {
    data = (vimbax_camera_msgs__msg__FeatureInfo *)allocator.zero_allocate(size, sizeof(vimbax_camera_msgs__msg__FeatureInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vimbax_camera_msgs__msg__FeatureInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vimbax_camera_msgs__msg__FeatureInfo__fini(&data[i - 1]);
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
vimbax_camera_msgs__msg__FeatureInfo__Sequence__fini(vimbax_camera_msgs__msg__FeatureInfo__Sequence * array)
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
      vimbax_camera_msgs__msg__FeatureInfo__fini(&array->data[i]);
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

vimbax_camera_msgs__msg__FeatureInfo__Sequence *
vimbax_camera_msgs__msg__FeatureInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vimbax_camera_msgs__msg__FeatureInfo__Sequence * array = (vimbax_camera_msgs__msg__FeatureInfo__Sequence *)allocator.allocate(sizeof(vimbax_camera_msgs__msg__FeatureInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vimbax_camera_msgs__msg__FeatureInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vimbax_camera_msgs__msg__FeatureInfo__Sequence__destroy(vimbax_camera_msgs__msg__FeatureInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vimbax_camera_msgs__msg__FeatureInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vimbax_camera_msgs__msg__FeatureInfo__Sequence__are_equal(const vimbax_camera_msgs__msg__FeatureInfo__Sequence * lhs, const vimbax_camera_msgs__msg__FeatureInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vimbax_camera_msgs__msg__FeatureInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vimbax_camera_msgs__msg__FeatureInfo__Sequence__copy(
  const vimbax_camera_msgs__msg__FeatureInfo__Sequence * input,
  vimbax_camera_msgs__msg__FeatureInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vimbax_camera_msgs__msg__FeatureInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vimbax_camera_msgs__msg__FeatureInfo * data =
      (vimbax_camera_msgs__msg__FeatureInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vimbax_camera_msgs__msg__FeatureInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vimbax_camera_msgs__msg__FeatureInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vimbax_camera_msgs__msg__FeatureInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

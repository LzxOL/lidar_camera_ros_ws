// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vimbax_camera_msgs:msg/EventData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vimbax_camera_msgs/msg/detail/event_data__rosidl_typesupport_introspection_c.h"
#include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vimbax_camera_msgs/msg/detail/event_data__functions.h"
#include "vimbax_camera_msgs/msg/detail/event_data__struct.h"


// Include directives for member types
// Member `entries`
#include "vimbax_camera_msgs/msg/event_data_entry.h"
// Member `entries`
#include "vimbax_camera_msgs/msg/detail/event_data_entry__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__msg__EventData__init(message_memory);
}

void vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_fini_function(void * message_memory)
{
  vimbax_camera_msgs__msg__EventData__fini(message_memory);
}

size_t vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__size_function__EventData__entries(
  const void * untyped_member)
{
  const vimbax_camera_msgs__msg__EventDataEntry__Sequence * member =
    (const vimbax_camera_msgs__msg__EventDataEntry__Sequence *)(untyped_member);
  return member->size;
}

const void * vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__get_const_function__EventData__entries(
  const void * untyped_member, size_t index)
{
  const vimbax_camera_msgs__msg__EventDataEntry__Sequence * member =
    (const vimbax_camera_msgs__msg__EventDataEntry__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__get_function__EventData__entries(
  void * untyped_member, size_t index)
{
  vimbax_camera_msgs__msg__EventDataEntry__Sequence * member =
    (vimbax_camera_msgs__msg__EventDataEntry__Sequence *)(untyped_member);
  return &member->data[index];
}

void vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__fetch_function__EventData__entries(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vimbax_camera_msgs__msg__EventDataEntry * item =
    ((const vimbax_camera_msgs__msg__EventDataEntry *)
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__get_const_function__EventData__entries(untyped_member, index));
  vimbax_camera_msgs__msg__EventDataEntry * value =
    (vimbax_camera_msgs__msg__EventDataEntry *)(untyped_value);
  *value = *item;
}

void vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__assign_function__EventData__entries(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vimbax_camera_msgs__msg__EventDataEntry * item =
    ((vimbax_camera_msgs__msg__EventDataEntry *)
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__get_function__EventData__entries(untyped_member, index));
  const vimbax_camera_msgs__msg__EventDataEntry * value =
    (const vimbax_camera_msgs__msg__EventDataEntry *)(untyped_value);
  *item = *value;
}

bool vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__resize_function__EventData__entries(
  void * untyped_member, size_t size)
{
  vimbax_camera_msgs__msg__EventDataEntry__Sequence * member =
    (vimbax_camera_msgs__msg__EventDataEntry__Sequence *)(untyped_member);
  vimbax_camera_msgs__msg__EventDataEntry__Sequence__fini(member);
  return vimbax_camera_msgs__msg__EventDataEntry__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_member_array[1] = {
  {
    "entries",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__msg__EventData, entries),  // bytes offset in struct
    NULL,  // default value
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__size_function__EventData__entries,  // size() function pointer
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__get_const_function__EventData__entries,  // get_const(index) function pointer
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__get_function__EventData__entries,  // get(index) function pointer
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__fetch_function__EventData__entries,  // fetch(index, &value) function pointer
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__assign_function__EventData__entries,  // assign(index, value) function pointer
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__resize_function__EventData__entries  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_members = {
  "vimbax_camera_msgs__msg",  // message namespace
  "EventData",  // message name
  1,  // number of fields
  sizeof(vimbax_camera_msgs__msg__EventData),
  vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_member_array,  // message members
  vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, EventData)() {
  vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, EventDataEntry)();
  if (!vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__msg__EventData__rosidl_typesupport_introspection_c__EventData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

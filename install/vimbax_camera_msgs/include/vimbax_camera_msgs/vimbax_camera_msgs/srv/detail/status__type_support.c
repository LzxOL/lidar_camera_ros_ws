// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vimbax_camera_msgs:srv/Status.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vimbax_camera_msgs/srv/detail/status__rosidl_typesupport_introspection_c.h"
#include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vimbax_camera_msgs/srv/detail/status__functions.h"
#include "vimbax_camera_msgs/srv/detail/status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__srv__Status_Request__init(message_memory);
}

void vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_fini_function(void * message_memory)
{
  vimbax_camera_msgs__srv__Status_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_message_members = {
  "vimbax_camera_msgs__srv",  // message namespace
  "Status_Request",  // message name
  1,  // number of fields
  sizeof(vimbax_camera_msgs__srv__Status_Request),
  vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_message_member_array,  // message members
  vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, Status_Request)() {
  if (!vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__srv__Status_Request__rosidl_typesupport_introspection_c__Status_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vimbax_camera_msgs/srv/detail/status__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/status__functions.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/status__struct.h"


// Include directives for member types
// Member `error`
#include "vimbax_camera_msgs/msg/error.h"
// Member `error`
#include "vimbax_camera_msgs/msg/detail/error__rosidl_typesupport_introspection_c.h"
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
#include "vimbax_camera_msgs/msg/trigger_info.h"
// Member `trigger_info`
#include "vimbax_camera_msgs/msg/detail/trigger_info__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__srv__Status_Response__init(message_memory);
}

void vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_fini_function(void * message_memory)
{
  vimbax_camera_msgs__srv__Status_Response__fini(message_memory);
}

size_t vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__size_function__Status_Response__trigger_info(
  const void * untyped_member)
{
  const vimbax_camera_msgs__msg__TriggerInfo__Sequence * member =
    (const vimbax_camera_msgs__msg__TriggerInfo__Sequence *)(untyped_member);
  return member->size;
}

const void * vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__get_const_function__Status_Response__trigger_info(
  const void * untyped_member, size_t index)
{
  const vimbax_camera_msgs__msg__TriggerInfo__Sequence * member =
    (const vimbax_camera_msgs__msg__TriggerInfo__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__get_function__Status_Response__trigger_info(
  void * untyped_member, size_t index)
{
  vimbax_camera_msgs__msg__TriggerInfo__Sequence * member =
    (vimbax_camera_msgs__msg__TriggerInfo__Sequence *)(untyped_member);
  return &member->data[index];
}

void vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__fetch_function__Status_Response__trigger_info(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vimbax_camera_msgs__msg__TriggerInfo * item =
    ((const vimbax_camera_msgs__msg__TriggerInfo *)
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__get_const_function__Status_Response__trigger_info(untyped_member, index));
  vimbax_camera_msgs__msg__TriggerInfo * value =
    (vimbax_camera_msgs__msg__TriggerInfo *)(untyped_value);
  *value = *item;
}

void vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__assign_function__Status_Response__trigger_info(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vimbax_camera_msgs__msg__TriggerInfo * item =
    ((vimbax_camera_msgs__msg__TriggerInfo *)
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__get_function__Status_Response__trigger_info(untyped_member, index));
  const vimbax_camera_msgs__msg__TriggerInfo * value =
    (const vimbax_camera_msgs__msg__TriggerInfo *)(untyped_value);
  *item = *value;
}

bool vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__resize_function__Status_Response__trigger_info(
  void * untyped_member, size_t size)
{
  vimbax_camera_msgs__msg__TriggerInfo__Sequence * member =
    (vimbax_camera_msgs__msg__TriggerInfo__Sequence *)(untyped_member);
  vimbax_camera_msgs__msg__TriggerInfo__Sequence__fini(member);
  return vimbax_camera_msgs__msg__TriggerInfo__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_member_array[17] = {
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "display_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, display_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "model_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, model_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_firmware_version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, device_firmware_version),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, device_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_user_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, device_user_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "device_serial_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, device_serial_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "interface_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, interface_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "transport_layer_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, transport_layer_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "streaming",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, streaming),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_rate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, frame_rate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pixel_format",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, pixel_format),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trigger_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, trigger_info),  // bytes offset in struct
    NULL,  // default value
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__size_function__Status_Response__trigger_info,  // size() function pointer
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__get_const_function__Status_Response__trigger_info,  // get_const(index) function pointer
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__get_function__Status_Response__trigger_info,  // get(index) function pointer
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__fetch_function__Status_Response__trigger_info,  // fetch(index, &value) function pointer
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__assign_function__Status_Response__trigger_info,  // assign(index, value) function pointer
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__resize_function__Status_Response__trigger_info  // resize(index) function pointer
  },
  {
    "ip_address",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, ip_address),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mac_address",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__Status_Response, mac_address),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_members = {
  "vimbax_camera_msgs__srv",  // message namespace
  "Status_Response",  // message name
  17,  // number of fields
  sizeof(vimbax_camera_msgs__srv__Status_Response),
  vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_member_array,  // message members
  vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, Status_Response)() {
  vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, Error)();
  vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_member_array[14].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, TriggerInfo)();
  if (!vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__srv__Status_Response__rosidl_typesupport_introspection_c__Status_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/status__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_service_members = {
  "vimbax_camera_msgs__srv",  // service namespace
  "Status",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_Request_message_type_support_handle,
  NULL  // response message
  // vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_Response_message_type_support_handle
};

static rosidl_service_type_support_t vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_service_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, Status_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, Status_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, Status)() {
  if (!vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_service_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, Status_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, Status_Response)()->data;
  }

  return &vimbax_camera_msgs__srv__detail__status__rosidl_typesupport_introspection_c__Status_service_type_support_handle;
}

// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vimbax_camera_msgs:srv/ConnectionStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vimbax_camera_msgs/srv/detail/connection_status__rosidl_typesupport_introspection_c.h"
#include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vimbax_camera_msgs/srv/detail/connection_status__functions.h"
#include "vimbax_camera_msgs/srv/detail/connection_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__srv__ConnectionStatus_Request__init(message_memory);
}

void vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_fini_function(void * message_memory)
{
  vimbax_camera_msgs__srv__ConnectionStatus_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__ConnectionStatus_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_members = {
  "vimbax_camera_msgs__srv",  // message namespace
  "ConnectionStatus_Request",  // message name
  1,  // number of fields
  sizeof(vimbax_camera_msgs__srv__ConnectionStatus_Request),
  vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_member_array,  // message members
  vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, ConnectionStatus_Request)() {
  if (!vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__srv__ConnectionStatus_Request__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vimbax_camera_msgs/srv/detail/connection_status__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/connection_status__functions.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/connection_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__srv__ConnectionStatus_Response__init(message_memory);
}

void vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_fini_function(void * message_memory)
{
  vimbax_camera_msgs__srv__ConnectionStatus_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_member_array[1] = {
  {
    "connected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__ConnectionStatus_Response, connected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_members = {
  "vimbax_camera_msgs__srv",  // message namespace
  "ConnectionStatus_Response",  // message name
  1,  // number of fields
  sizeof(vimbax_camera_msgs__srv__ConnectionStatus_Response),
  vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_member_array,  // message members
  vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, ConnectionStatus_Response)() {
  if (!vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__srv__ConnectionStatus_Response__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/connection_status__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_service_members = {
  "vimbax_camera_msgs__srv",  // service namespace
  "ConnectionStatus",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_Request_message_type_support_handle,
  NULL  // response message
  // vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_Response_message_type_support_handle
};

static rosidl_service_type_support_t vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_service_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, ConnectionStatus_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, ConnectionStatus_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, ConnectionStatus)() {
  if (!vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_service_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, ConnectionStatus_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, ConnectionStatus_Response)()->data;
  }

  return &vimbax_camera_msgs__srv__detail__connection_status__rosidl_typesupport_introspection_c__ConnectionStatus_service_type_support_handle;
}

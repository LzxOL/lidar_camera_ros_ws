// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vimbax_camera_msgs:srv/FeatureRawInfoGet.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__rosidl_typesupport_introspection_c.h"
#include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__functions.h"
#include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__struct.h"


// Include directives for member types
// Member `feature_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `feature_module`
#include "vimbax_camera_msgs/msg/feature_module.h"
// Member `feature_module`
#include "vimbax_camera_msgs/msg/detail/feature_module__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__init(message_memory);
}

void vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_fini_function(void * message_memory)
{
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_member_array[2] = {
  {
    "feature_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__FeatureRawInfoGet_Request, feature_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feature_module",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__FeatureRawInfoGet_Request, feature_module),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_members = {
  "vimbax_camera_msgs__srv",  // message namespace
  "FeatureRawInfoGet_Request",  // message name
  2,  // number of fields
  sizeof(vimbax_camera_msgs__srv__FeatureRawInfoGet_Request),
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_member_array,  // message members
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeatureRawInfoGet_Request)() {
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, FeatureModule)();
  if (!vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__srv__FeatureRawInfoGet_Request__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__functions.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__struct.h"


// Include directives for member types
// Member `error`
#include "vimbax_camera_msgs/msg/error.h"
// Member `error`
#include "vimbax_camera_msgs/msg/detail/error__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__init(message_memory);
}

void vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_fini_function(void * message_memory)
{
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_member_array[2] = {
  {
    "max_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__FeatureRawInfoGet_Response, max_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__FeatureRawInfoGet_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_members = {
  "vimbax_camera_msgs__srv",  // message namespace
  "FeatureRawInfoGet_Response",  // message name
  2,  // number of fields
  sizeof(vimbax_camera_msgs__srv__FeatureRawInfoGet_Response),
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_member_array,  // message members
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeatureRawInfoGet_Response)() {
  vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, Error)();
  if (!vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__srv__FeatureRawInfoGet_Response__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_service_members = {
  "vimbax_camera_msgs__srv",  // service namespace
  "FeatureRawInfoGet",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Request_message_type_support_handle,
  NULL  // response message
  // vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_Response_message_type_support_handle
};

static rosidl_service_type_support_t vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_service_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeatureRawInfoGet_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeatureRawInfoGet_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeatureRawInfoGet)() {
  if (!vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_service_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeatureRawInfoGet_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeatureRawInfoGet_Response)()->data;
  }

  return &vimbax_camera_msgs__srv__detail__feature_raw_info_get__rosidl_typesupport_introspection_c__FeatureRawInfoGet_service_type_support_handle;
}

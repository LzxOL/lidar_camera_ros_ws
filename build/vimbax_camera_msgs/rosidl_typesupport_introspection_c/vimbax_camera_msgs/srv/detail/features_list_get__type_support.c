// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vimbax_camera_msgs:srv/FeaturesListGet.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vimbax_camera_msgs/srv/detail/features_list_get__rosidl_typesupport_introspection_c.h"
#include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vimbax_camera_msgs/srv/detail/features_list_get__functions.h"
#include "vimbax_camera_msgs/srv/detail/features_list_get__struct.h"


// Include directives for member types
// Member `feature_module`
#include "vimbax_camera_msgs/msg/feature_module.h"
// Member `feature_module`
#include "vimbax_camera_msgs/msg/detail/feature_module__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__srv__FeaturesListGet_Request__init(message_memory);
}

void vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_fini_function(void * message_memory)
{
  vimbax_camera_msgs__srv__FeaturesListGet_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_member_array[1] = {
  {
    "feature_module",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__FeaturesListGet_Request, feature_module),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_members = {
  "vimbax_camera_msgs__srv",  // message namespace
  "FeaturesListGet_Request",  // message name
  1,  // number of fields
  sizeof(vimbax_camera_msgs__srv__FeaturesListGet_Request),
  vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_member_array,  // message members
  vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeaturesListGet_Request)() {
  vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, FeatureModule)();
  if (!vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__srv__FeaturesListGet_Request__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vimbax_camera_msgs/srv/detail/features_list_get__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/features_list_get__functions.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/features_list_get__struct.h"


// Include directives for member types
// Member `feature_list`
#include "rosidl_runtime_c/string_functions.h"
// Member `error`
#include "vimbax_camera_msgs/msg/error.h"
// Member `error`
#include "vimbax_camera_msgs/msg/detail/error__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vimbax_camera_msgs__srv__FeaturesListGet_Response__init(message_memory);
}

void vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_fini_function(void * message_memory)
{
  vimbax_camera_msgs__srv__FeaturesListGet_Response__fini(message_memory);
}

size_t vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__size_function__FeaturesListGet_Response__feature_list(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__get_const_function__FeaturesListGet_Response__feature_list(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__get_function__FeaturesListGet_Response__feature_list(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__fetch_function__FeaturesListGet_Response__feature_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__get_const_function__FeaturesListGet_Response__feature_list(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__assign_function__FeaturesListGet_Response__feature_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__get_function__FeaturesListGet_Response__feature_list(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__resize_function__FeaturesListGet_Response__feature_list(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_member_array[2] = {
  {
    "feature_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__FeaturesListGet_Response, feature_list),  // bytes offset in struct
    NULL,  // default value
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__size_function__FeaturesListGet_Response__feature_list,  // size() function pointer
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__get_const_function__FeaturesListGet_Response__feature_list,  // get_const(index) function pointer
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__get_function__FeaturesListGet_Response__feature_list,  // get(index) function pointer
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__fetch_function__FeaturesListGet_Response__feature_list,  // fetch(index, &value) function pointer
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__assign_function__FeaturesListGet_Response__feature_list,  // assign(index, value) function pointer
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__resize_function__FeaturesListGet_Response__feature_list  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs__srv__FeaturesListGet_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_members = {
  "vimbax_camera_msgs__srv",  // message namespace
  "FeaturesListGet_Response",  // message name
  2,  // number of fields
  sizeof(vimbax_camera_msgs__srv__FeaturesListGet_Response),
  vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_member_array,  // message members
  vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeaturesListGet_Response)() {
  vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, msg, Error)();
  if (!vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vimbax_camera_msgs__srv__FeaturesListGet_Response__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/features_list_get__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_service_members = {
  "vimbax_camera_msgs__srv",  // service namespace
  "FeaturesListGet",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_Request_message_type_support_handle,
  NULL  // response message
  // vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_Response_message_type_support_handle
};

static rosidl_service_type_support_t vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_service_type_support_handle = {
  0,
  &vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeaturesListGet_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeaturesListGet_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vimbax_camera_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeaturesListGet)() {
  if (!vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_service_type_support_handle.typesupport_identifier) {
    vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeaturesListGet_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vimbax_camera_msgs, srv, FeaturesListGet_Response)()->data;
  }

  return &vimbax_camera_msgs__srv__detail__features_list_get__rosidl_typesupport_introspection_c__FeaturesListGet_service_type_support_handle;
}

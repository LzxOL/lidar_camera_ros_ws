// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vimbax_camera_msgs:srv/FeatureRawInfoGet.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vimbax_camera_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void FeatureRawInfoGet_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vimbax_camera_msgs::srv::FeatureRawInfoGet_Request(_init);
}

void FeatureRawInfoGet_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vimbax_camera_msgs::srv::FeatureRawInfoGet_Request *>(message_memory);
  typed_message->~FeatureRawInfoGet_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FeatureRawInfoGet_Request_message_member_array[2] = {
  {
    "feature_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs::srv::FeatureRawInfoGet_Request, feature_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "feature_module",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vimbax_camera_msgs::msg::FeatureModule>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs::srv::FeatureRawInfoGet_Request, feature_module),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FeatureRawInfoGet_Request_message_members = {
  "vimbax_camera_msgs::srv",  // message namespace
  "FeatureRawInfoGet_Request",  // message name
  2,  // number of fields
  sizeof(vimbax_camera_msgs::srv::FeatureRawInfoGet_Request),
  FeatureRawInfoGet_Request_message_member_array,  // message members
  FeatureRawInfoGet_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  FeatureRawInfoGet_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FeatureRawInfoGet_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FeatureRawInfoGet_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace vimbax_camera_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vimbax_camera_msgs::srv::FeatureRawInfoGet_Request>()
{
  return &::vimbax_camera_msgs::srv::rosidl_typesupport_introspection_cpp::FeatureRawInfoGet_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vimbax_camera_msgs, srv, FeatureRawInfoGet_Request)() {
  return &::vimbax_camera_msgs::srv::rosidl_typesupport_introspection_cpp::FeatureRawInfoGet_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vimbax_camera_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void FeatureRawInfoGet_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vimbax_camera_msgs::srv::FeatureRawInfoGet_Response(_init);
}

void FeatureRawInfoGet_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vimbax_camera_msgs::srv::FeatureRawInfoGet_Response *>(message_memory);
  typed_message->~FeatureRawInfoGet_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FeatureRawInfoGet_Response_message_member_array[2] = {
  {
    "max_length",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs::srv::FeatureRawInfoGet_Response, max_length),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "error",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vimbax_camera_msgs::msg::Error>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs::srv::FeatureRawInfoGet_Response, error),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FeatureRawInfoGet_Response_message_members = {
  "vimbax_camera_msgs::srv",  // message namespace
  "FeatureRawInfoGet_Response",  // message name
  2,  // number of fields
  sizeof(vimbax_camera_msgs::srv::FeatureRawInfoGet_Response),
  FeatureRawInfoGet_Response_message_member_array,  // message members
  FeatureRawInfoGet_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  FeatureRawInfoGet_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FeatureRawInfoGet_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FeatureRawInfoGet_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace vimbax_camera_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vimbax_camera_msgs::srv::FeatureRawInfoGet_Response>()
{
  return &::vimbax_camera_msgs::srv::rosidl_typesupport_introspection_cpp::FeatureRawInfoGet_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vimbax_camera_msgs, srv, FeatureRawInfoGet_Response)() {
  return &::vimbax_camera_msgs::srv::rosidl_typesupport_introspection_cpp::FeatureRawInfoGet_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_raw_info_get__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace vimbax_camera_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers FeatureRawInfoGet_service_members = {
  "vimbax_camera_msgs::srv",  // service namespace
  "FeatureRawInfoGet",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<vimbax_camera_msgs::srv::FeatureRawInfoGet>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t FeatureRawInfoGet_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FeatureRawInfoGet_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace vimbax_camera_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<vimbax_camera_msgs::srv::FeatureRawInfoGet>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::vimbax_camera_msgs::srv::rosidl_typesupport_introspection_cpp::FeatureRawInfoGet_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::vimbax_camera_msgs::srv::FeatureRawInfoGet_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::vimbax_camera_msgs::srv::FeatureRawInfoGet_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vimbax_camera_msgs, srv, FeatureRawInfoGet)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<vimbax_camera_msgs::srv::FeatureRawInfoGet>();
}

#ifdef __cplusplus
}
#endif

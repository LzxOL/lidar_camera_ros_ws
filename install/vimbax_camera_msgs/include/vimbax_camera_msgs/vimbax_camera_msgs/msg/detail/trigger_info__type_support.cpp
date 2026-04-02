// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vimbax_camera_msgs:msg/TriggerInfo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vimbax_camera_msgs/msg/detail/trigger_info__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vimbax_camera_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TriggerInfo_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vimbax_camera_msgs::msg::TriggerInfo(_init);
}

void TriggerInfo_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vimbax_camera_msgs::msg::TriggerInfo *>(message_memory);
  typed_message->~TriggerInfo();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TriggerInfo_message_member_array[3] = {
  {
    "selector",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs::msg::TriggerInfo, selector),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs::msg::TriggerInfo, mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "source",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vimbax_camera_msgs::msg::TriggerInfo, source),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TriggerInfo_message_members = {
  "vimbax_camera_msgs::msg",  // message namespace
  "TriggerInfo",  // message name
  3,  // number of fields
  sizeof(vimbax_camera_msgs::msg::TriggerInfo),
  TriggerInfo_message_member_array,  // message members
  TriggerInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  TriggerInfo_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TriggerInfo_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TriggerInfo_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vimbax_camera_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vimbax_camera_msgs::msg::TriggerInfo>()
{
  return &::vimbax_camera_msgs::msg::rosidl_typesupport_introspection_cpp::TriggerInfo_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vimbax_camera_msgs, msg, TriggerInfo)() {
  return &::vimbax_camera_msgs::msg::rosidl_typesupport_introspection_cpp::TriggerInfo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

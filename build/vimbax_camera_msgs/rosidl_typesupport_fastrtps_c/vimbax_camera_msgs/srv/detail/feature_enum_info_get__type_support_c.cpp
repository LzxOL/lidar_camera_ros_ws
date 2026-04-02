// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vimbax_camera_msgs:srv/FeatureEnumInfoGet.idl
// generated code does not contain a copyright notice
#include "vimbax_camera_msgs/srv/detail/feature_enum_info_get__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vimbax_camera_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vimbax_camera_msgs/srv/detail/feature_enum_info_get__struct.h"
#include "vimbax_camera_msgs/srv/detail/feature_enum_info_get__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // feature_name
#include "rosidl_runtime_c/string_functions.h"  // feature_name
#include "vimbax_camera_msgs/msg/detail/feature_module__functions.h"  // feature_module

// forward declare type support functions
size_t get_serialized_size_vimbax_camera_msgs__msg__FeatureModule(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_vimbax_camera_msgs__msg__FeatureModule(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, msg, FeatureModule)();


using _FeatureEnumInfoGet_Request__ros_msg_type = vimbax_camera_msgs__srv__FeatureEnumInfoGet_Request;

static bool _FeatureEnumInfoGet_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FeatureEnumInfoGet_Request__ros_msg_type * ros_message = static_cast<const _FeatureEnumInfoGet_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: feature_name
  {
    const rosidl_runtime_c__String * str = &ros_message->feature_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: feature_module
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, msg, FeatureModule
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->feature_module, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _FeatureEnumInfoGet_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FeatureEnumInfoGet_Request__ros_msg_type * ros_message = static_cast<_FeatureEnumInfoGet_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: feature_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->feature_name.data) {
      rosidl_runtime_c__String__init(&ros_message->feature_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->feature_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'feature_name'\n");
      return false;
    }
  }

  // Field name: feature_module
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, msg, FeatureModule
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->feature_module))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vimbax_camera_msgs
size_t get_serialized_size_vimbax_camera_msgs__srv__FeatureEnumInfoGet_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FeatureEnumInfoGet_Request__ros_msg_type * ros_message = static_cast<const _FeatureEnumInfoGet_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name feature_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->feature_name.size + 1);
  // field.name feature_module

  current_alignment += get_serialized_size_vimbax_camera_msgs__msg__FeatureModule(
    &(ros_message->feature_module), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _FeatureEnumInfoGet_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vimbax_camera_msgs__srv__FeatureEnumInfoGet_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vimbax_camera_msgs
size_t max_serialized_size_vimbax_camera_msgs__srv__FeatureEnumInfoGet_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: feature_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: feature_module
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_vimbax_camera_msgs__msg__FeatureModule(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vimbax_camera_msgs__srv__FeatureEnumInfoGet_Request;
    is_plain =
      (
      offsetof(DataType, feature_module) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FeatureEnumInfoGet_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vimbax_camera_msgs__srv__FeatureEnumInfoGet_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FeatureEnumInfoGet_Request = {
  "vimbax_camera_msgs::srv",
  "FeatureEnumInfoGet_Request",
  _FeatureEnumInfoGet_Request__cdr_serialize,
  _FeatureEnumInfoGet_Request__cdr_deserialize,
  _FeatureEnumInfoGet_Request__get_serialized_size,
  _FeatureEnumInfoGet_Request__max_serialized_size
};

static rosidl_message_type_support_t _FeatureEnumInfoGet_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FeatureEnumInfoGet_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, srv, FeatureEnumInfoGet_Request)() {
  return &_FeatureEnumInfoGet_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_enum_info_get__struct.h"
// already included above
// #include "vimbax_camera_msgs/srv/detail/feature_enum_info_get__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // available_values, possible_values
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // available_values, possible_values
#include "vimbax_camera_msgs/msg/detail/error__functions.h"  // error

// forward declare type support functions
size_t get_serialized_size_vimbax_camera_msgs__msg__Error(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_vimbax_camera_msgs__msg__Error(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, msg, Error)();


using _FeatureEnumInfoGet_Response__ros_msg_type = vimbax_camera_msgs__srv__FeatureEnumInfoGet_Response;

static bool _FeatureEnumInfoGet_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FeatureEnumInfoGet_Response__ros_msg_type * ros_message = static_cast<const _FeatureEnumInfoGet_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: possible_values
  {
    size_t size = ros_message->possible_values.size;
    auto array_ptr = ros_message->possible_values.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: available_values
  {
    size_t size = ros_message->available_values.size;
    auto array_ptr = ros_message->available_values.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: error
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, msg, Error
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->error, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _FeatureEnumInfoGet_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FeatureEnumInfoGet_Response__ros_msg_type * ros_message = static_cast<_FeatureEnumInfoGet_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: possible_values
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->possible_values.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->possible_values);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->possible_values, size)) {
      fprintf(stderr, "failed to create array for field 'possible_values'");
      return false;
    }
    auto array_ptr = ros_message->possible_values.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'possible_values'\n");
        return false;
      }
    }
  }

  // Field name: available_values
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->available_values.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->available_values);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->available_values, size)) {
      fprintf(stderr, "failed to create array for field 'available_values'");
      return false;
    }
    auto array_ptr = ros_message->available_values.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'available_values'\n");
        return false;
      }
    }
  }

  // Field name: error
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, msg, Error
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->error))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vimbax_camera_msgs
size_t get_serialized_size_vimbax_camera_msgs__srv__FeatureEnumInfoGet_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FeatureEnumInfoGet_Response__ros_msg_type * ros_message = static_cast<const _FeatureEnumInfoGet_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name possible_values
  {
    size_t array_size = ros_message->possible_values.size;
    auto array_ptr = ros_message->possible_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name available_values
  {
    size_t array_size = ros_message->available_values.size;
    auto array_ptr = ros_message->available_values.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name error

  current_alignment += get_serialized_size_vimbax_camera_msgs__msg__Error(
    &(ros_message->error), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _FeatureEnumInfoGet_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vimbax_camera_msgs__srv__FeatureEnumInfoGet_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vimbax_camera_msgs
size_t max_serialized_size_vimbax_camera_msgs__srv__FeatureEnumInfoGet_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: possible_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: available_values
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: error
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_vimbax_camera_msgs__msg__Error(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vimbax_camera_msgs__srv__FeatureEnumInfoGet_Response;
    is_plain =
      (
      offsetof(DataType, error) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FeatureEnumInfoGet_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vimbax_camera_msgs__srv__FeatureEnumInfoGet_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FeatureEnumInfoGet_Response = {
  "vimbax_camera_msgs::srv",
  "FeatureEnumInfoGet_Response",
  _FeatureEnumInfoGet_Response__cdr_serialize,
  _FeatureEnumInfoGet_Response__cdr_deserialize,
  _FeatureEnumInfoGet_Response__get_serialized_size,
  _FeatureEnumInfoGet_Response__max_serialized_size
};

static rosidl_message_type_support_t _FeatureEnumInfoGet_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FeatureEnumInfoGet_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, srv, FeatureEnumInfoGet_Response)() {
  return &_FeatureEnumInfoGet_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "vimbax_camera_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vimbax_camera_msgs/srv/feature_enum_info_get.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t FeatureEnumInfoGet__callbacks = {
  "vimbax_camera_msgs::srv",
  "FeatureEnumInfoGet",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, srv, FeatureEnumInfoGet_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, srv, FeatureEnumInfoGet_Response)(),
};

static rosidl_service_type_support_t FeatureEnumInfoGet__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &FeatureEnumInfoGet__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vimbax_camera_msgs, srv, FeatureEnumInfoGet)() {
  return &FeatureEnumInfoGet__handle;
}

#if defined(__cplusplus)
}
#endif

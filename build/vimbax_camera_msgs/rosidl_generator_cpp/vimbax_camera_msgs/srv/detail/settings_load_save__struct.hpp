// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:srv/SettingsLoadSave.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__SETTINGS_LOAD_SAVE__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__SETTINGS_LOAD_SAVE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__srv__SettingsLoadSave_Request __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__SettingsLoadSave_Request __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SettingsLoadSave_Request_
{
  using Type = SettingsLoadSave_Request_<ContainerAllocator>;

  explicit SettingsLoadSave_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
    }
  }

  explicit SettingsLoadSave_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : filename(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
    }
  }

  // field types and members
  using _filename_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _filename_type filename;

  // setters for named parameter idiom
  Type & set__filename(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->filename = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__SettingsLoadSave_Request
    std::shared_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__SettingsLoadSave_Request
    std::shared_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SettingsLoadSave_Request_ & other) const
  {
    if (this->filename != other.filename) {
      return false;
    }
    return true;
  }
  bool operator!=(const SettingsLoadSave_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SettingsLoadSave_Request_

// alias to use template instance with default allocator
using SettingsLoadSave_Request =
  vimbax_camera_msgs::srv::SettingsLoadSave_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs


// Include directives for member types
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__srv__SettingsLoadSave_Response __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__SettingsLoadSave_Response __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SettingsLoadSave_Response_
{
  using Type = SettingsLoadSave_Response_<ContainerAllocator>;

  explicit SettingsLoadSave_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_init)
  {
    (void)_init;
  }

  explicit SettingsLoadSave_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _error_type =
    vimbax_camera_msgs::msg::Error_<ContainerAllocator>;
  _error_type error;

  // setters for named parameter idiom
  Type & set__error(
    const vimbax_camera_msgs::msg::Error_<ContainerAllocator> & _arg)
  {
    this->error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__SettingsLoadSave_Response
    std::shared_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__SettingsLoadSave_Response
    std::shared_ptr<vimbax_camera_msgs::srv::SettingsLoadSave_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SettingsLoadSave_Response_ & other) const
  {
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const SettingsLoadSave_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SettingsLoadSave_Response_

// alias to use template instance with default allocator
using SettingsLoadSave_Response =
  vimbax_camera_msgs::srv::SettingsLoadSave_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace vimbax_camera_msgs
{

namespace srv
{

struct SettingsLoadSave
{
  using Request = vimbax_camera_msgs::srv::SettingsLoadSave_Request;
  using Response = vimbax_camera_msgs::srv::SettingsLoadSave_Response;
};

}  // namespace srv

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__SETTINGS_LOAD_SAVE__STRUCT_HPP_

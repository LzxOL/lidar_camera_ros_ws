// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:msg/TriggerInfo.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__msg__TriggerInfo __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__msg__TriggerInfo __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TriggerInfo_
{
  using Type = TriggerInfo_<ContainerAllocator>;

  explicit TriggerInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->selector = "";
      this->mode = "";
      this->source = "";
    }
  }

  explicit TriggerInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : selector(_alloc),
    mode(_alloc),
    source(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->selector = "";
      this->mode = "";
      this->source = "";
    }
  }

  // field types and members
  using _selector_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _selector_type selector;
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _source_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _source_type source;

  // setters for named parameter idiom
  Type & set__selector(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->selector = _arg;
    return *this;
  }
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__source(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->source = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__msg__TriggerInfo
    std::shared_ptr<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__msg__TriggerInfo
    std::shared_ptr<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggerInfo_ & other) const
  {
    if (this->selector != other.selector) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->source != other.source) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggerInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggerInfo_

// alias to use template instance with default allocator
using TriggerInfo =
  vimbax_camera_msgs::msg::TriggerInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__TRIGGER_INFO__STRUCT_HPP_

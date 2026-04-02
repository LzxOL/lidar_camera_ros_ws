// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureFlags.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__msg__FeatureFlags __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__msg__FeatureFlags __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FeatureFlags_
{
  using Type = FeatureFlags_<ContainerAllocator>;

  explicit FeatureFlags_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag_none = false;
      this->flag_read = false;
      this->flag_write = false;
      this->flag_volatile = false;
      this->flag_modify_write = false;
    }
  }

  explicit FeatureFlags_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag_none = false;
      this->flag_read = false;
      this->flag_write = false;
      this->flag_volatile = false;
      this->flag_modify_write = false;
    }
  }

  // field types and members
  using _flag_none_type =
    bool;
  _flag_none_type flag_none;
  using _flag_read_type =
    bool;
  _flag_read_type flag_read;
  using _flag_write_type =
    bool;
  _flag_write_type flag_write;
  using _flag_volatile_type =
    bool;
  _flag_volatile_type flag_volatile;
  using _flag_modify_write_type =
    bool;
  _flag_modify_write_type flag_modify_write;

  // setters for named parameter idiom
  Type & set__flag_none(
    const bool & _arg)
  {
    this->flag_none = _arg;
    return *this;
  }
  Type & set__flag_read(
    const bool & _arg)
  {
    this->flag_read = _arg;
    return *this;
  }
  Type & set__flag_write(
    const bool & _arg)
  {
    this->flag_write = _arg;
    return *this;
  }
  Type & set__flag_volatile(
    const bool & _arg)
  {
    this->flag_volatile = _arg;
    return *this;
  }
  Type & set__flag_modify_write(
    const bool & _arg)
  {
    this->flag_modify_write = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__msg__FeatureFlags
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__msg__FeatureFlags
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureFlags_ & other) const
  {
    if (this->flag_none != other.flag_none) {
      return false;
    }
    if (this->flag_read != other.flag_read) {
      return false;
    }
    if (this->flag_write != other.flag_write) {
      return false;
    }
    if (this->flag_volatile != other.flag_volatile) {
      return false;
    }
    if (this->flag_modify_write != other.flag_modify_write) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureFlags_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureFlags_

// alias to use template instance with default allocator
using FeatureFlags =
  vimbax_camera_msgs::msg::FeatureFlags_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_FLAGS__STRUCT_HPP_

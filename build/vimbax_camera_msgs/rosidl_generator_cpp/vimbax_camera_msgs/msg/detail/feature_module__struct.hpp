// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureModule.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__msg__FeatureModule __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__msg__FeatureModule __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FeatureModule_
{
  using Type = FeatureModule_<ContainerAllocator>;

  explicit FeatureModule_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
    }
  }

  explicit FeatureModule_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
    }
  }

  // field types and members
  using _id_type =
    uint8_t;
  _id_type id;

  // setters for named parameter idiom
  Type & set__id(
    const uint8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MODULE_REMOTE_DEVICE =
    0u;
  static constexpr uint8_t MODULE_SYSTEM =
    1u;
  static constexpr uint8_t MODULE_INTERFACE =
    2u;
  static constexpr uint8_t MODULE_LOCAL_DEVICE =
    3u;
  static constexpr uint8_t MODULE_STREAM =
    4u;

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__msg__FeatureModule
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__msg__FeatureModule
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureModule_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureModule_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureModule_

// alias to use template instance with default allocator
using FeatureModule =
  vimbax_camera_msgs::msg::FeatureModule_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FeatureModule_<ContainerAllocator>::MODULE_REMOTE_DEVICE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FeatureModule_<ContainerAllocator>::MODULE_SYSTEM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FeatureModule_<ContainerAllocator>::MODULE_INTERFACE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FeatureModule_<ContainerAllocator>::MODULE_LOCAL_DEVICE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FeatureModule_<ContainerAllocator>::MODULE_STREAM;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_MODULE__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:msg/FeatureInfo.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'flags'
#include "vimbax_camera_msgs/msg/detail/feature_flags__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__msg__FeatureInfo __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__msg__FeatureInfo __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FeatureInfo_
{
  using Type = FeatureInfo_<ContainerAllocator>;

  explicit FeatureInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : flags(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->category = "";
      this->display_name = "";
      this->sfnc_namespace = "";
      this->unit = "";
      this->data_type = 0ul;
      this->polling_time = 0ul;
    }
  }

  explicit FeatureInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    category(_alloc),
    display_name(_alloc),
    sfnc_namespace(_alloc),
    unit(_alloc),
    flags(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->category = "";
      this->display_name = "";
      this->sfnc_namespace = "";
      this->unit = "";
      this->data_type = 0ul;
      this->polling_time = 0ul;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _category_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _category_type category;
  using _display_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _display_name_type display_name;
  using _sfnc_namespace_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sfnc_namespace_type sfnc_namespace;
  using _unit_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _unit_type unit;
  using _data_type_type =
    uint32_t;
  _data_type_type data_type;
  using _flags_type =
    vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator>;
  _flags_type flags;
  using _polling_time_type =
    uint32_t;
  _polling_time_type polling_time;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__category(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->category = _arg;
    return *this;
  }
  Type & set__display_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->display_name = _arg;
    return *this;
  }
  Type & set__sfnc_namespace(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sfnc_namespace = _arg;
    return *this;
  }
  Type & set__unit(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->unit = _arg;
    return *this;
  }
  Type & set__data_type(
    const uint32_t & _arg)
  {
    this->data_type = _arg;
    return *this;
  }
  Type & set__flags(
    const vimbax_camera_msgs::msg::FeatureFlags_<ContainerAllocator> & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__polling_time(
    const uint32_t & _arg)
  {
    this->polling_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__msg__FeatureInfo
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__msg__FeatureInfo
    std::shared_ptr<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureInfo_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->category != other.category) {
      return false;
    }
    if (this->display_name != other.display_name) {
      return false;
    }
    if (this->sfnc_namespace != other.sfnc_namespace) {
      return false;
    }
    if (this->unit != other.unit) {
      return false;
    }
    if (this->data_type != other.data_type) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->polling_time != other.polling_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureInfo_

// alias to use template instance with default allocator
using FeatureInfo =
  vimbax_camera_msgs::msg::FeatureInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__MSG__DETAIL__FEATURE_INFO__STRUCT_HPP_

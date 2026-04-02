// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureFloatInfoGet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_INFO_GET__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_INFO_GET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'feature_module'
#include "vimbax_camera_msgs/msg/detail/feature_module__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureFloatInfoGet_Request __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureFloatInfoGet_Request __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FeatureFloatInfoGet_Request_
{
  using Type = FeatureFloatInfoGet_Request_<ContainerAllocator>;

  explicit FeatureFloatInfoGet_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feature_module(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feature_name = "";
    }
  }

  explicit FeatureFloatInfoGet_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feature_name(_alloc),
    feature_module(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feature_name = "";
    }
  }

  // field types and members
  using _feature_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _feature_name_type feature_name;
  using _feature_module_type =
    vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator>;
  _feature_module_type feature_module;

  // setters for named parameter idiom
  Type & set__feature_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->feature_name = _arg;
    return *this;
  }
  Type & set__feature_module(
    const vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator> & _arg)
  {
    this->feature_module = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureFloatInfoGet_Request
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureFloatInfoGet_Request
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureFloatInfoGet_Request_ & other) const
  {
    if (this->feature_name != other.feature_name) {
      return false;
    }
    if (this->feature_module != other.feature_module) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureFloatInfoGet_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureFloatInfoGet_Request_

// alias to use template instance with default allocator
using FeatureFloatInfoGet_Request =
  vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs


// Include directives for member types
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureFloatInfoGet_Response __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureFloatInfoGet_Response __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FeatureFloatInfoGet_Response_
{
  using Type = FeatureFloatInfoGet_Response_<ContainerAllocator>;

  explicit FeatureFloatInfoGet_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min = 0.0;
      this->max = 0.0;
      this->inc = 0.0;
      this->inc_available = false;
    }
  }

  explicit FeatureFloatInfoGet_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min = 0.0;
      this->max = 0.0;
      this->inc = 0.0;
      this->inc_available = false;
    }
  }

  // field types and members
  using _min_type =
    double;
  _min_type min;
  using _max_type =
    double;
  _max_type max;
  using _inc_type =
    double;
  _inc_type inc;
  using _inc_available_type =
    bool;
  _inc_available_type inc_available;
  using _error_type =
    vimbax_camera_msgs::msg::Error_<ContainerAllocator>;
  _error_type error;

  // setters for named parameter idiom
  Type & set__min(
    const double & _arg)
  {
    this->min = _arg;
    return *this;
  }
  Type & set__max(
    const double & _arg)
  {
    this->max = _arg;
    return *this;
  }
  Type & set__inc(
    const double & _arg)
  {
    this->inc = _arg;
    return *this;
  }
  Type & set__inc_available(
    const bool & _arg)
  {
    this->inc_available = _arg;
    return *this;
  }
  Type & set__error(
    const vimbax_camera_msgs::msg::Error_<ContainerAllocator> & _arg)
  {
    this->error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureFloatInfoGet_Response
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureFloatInfoGet_Response
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureFloatInfoGet_Response_ & other) const
  {
    if (this->min != other.min) {
      return false;
    }
    if (this->max != other.max) {
      return false;
    }
    if (this->inc != other.inc) {
      return false;
    }
    if (this->inc_available != other.inc_available) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureFloatInfoGet_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureFloatInfoGet_Response_

// alias to use template instance with default allocator
using FeatureFloatInfoGet_Response =
  vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace vimbax_camera_msgs
{

namespace srv
{

struct FeatureFloatInfoGet
{
  using Request = vimbax_camera_msgs::srv::FeatureFloatInfoGet_Request;
  using Response = vimbax_camera_msgs::srv::FeatureFloatInfoGet_Response;
};

}  // namespace srv

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_FLOAT_INFO_GET__STRUCT_HPP_

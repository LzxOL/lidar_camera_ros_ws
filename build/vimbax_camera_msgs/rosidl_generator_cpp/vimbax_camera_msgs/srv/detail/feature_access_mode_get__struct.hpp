// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureAccessModeGet.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ACCESS_MODE_GET__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ACCESS_MODE_GET__STRUCT_HPP_

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
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureAccessModeGet_Request __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureAccessModeGet_Request __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FeatureAccessModeGet_Request_
{
  using Type = FeatureAccessModeGet_Request_<ContainerAllocator>;

  explicit FeatureAccessModeGet_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feature_module(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feature_name = "";
    }
  }

  explicit FeatureAccessModeGet_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureAccessModeGet_Request
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureAccessModeGet_Request
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureAccessModeGet_Request_ & other) const
  {
    if (this->feature_name != other.feature_name) {
      return false;
    }
    if (this->feature_module != other.feature_module) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureAccessModeGet_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureAccessModeGet_Request_

// alias to use template instance with default allocator
using FeatureAccessModeGet_Request =
  vimbax_camera_msgs::srv::FeatureAccessModeGet_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs


// Include directives for member types
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureAccessModeGet_Response __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureAccessModeGet_Response __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FeatureAccessModeGet_Response_
{
  using Type = FeatureAccessModeGet_Response_<ContainerAllocator>;

  explicit FeatureAccessModeGet_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_readable = false;
      this->is_writeable = false;
    }
  }

  explicit FeatureAccessModeGet_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_readable = false;
      this->is_writeable = false;
    }
  }

  // field types and members
  using _is_readable_type =
    bool;
  _is_readable_type is_readable;
  using _is_writeable_type =
    bool;
  _is_writeable_type is_writeable;
  using _error_type =
    vimbax_camera_msgs::msg::Error_<ContainerAllocator>;
  _error_type error;

  // setters for named parameter idiom
  Type & set__is_readable(
    const bool & _arg)
  {
    this->is_readable = _arg;
    return *this;
  }
  Type & set__is_writeable(
    const bool & _arg)
  {
    this->is_writeable = _arg;
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
    vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureAccessModeGet_Response
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureAccessModeGet_Response
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureAccessModeGet_Response_ & other) const
  {
    if (this->is_readable != other.is_readable) {
      return false;
    }
    if (this->is_writeable != other.is_writeable) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureAccessModeGet_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureAccessModeGet_Response_

// alias to use template instance with default allocator
using FeatureAccessModeGet_Response =
  vimbax_camera_msgs::srv::FeatureAccessModeGet_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace vimbax_camera_msgs
{

namespace srv
{

struct FeatureAccessModeGet
{
  using Request = vimbax_camera_msgs::srv::FeatureAccessModeGet_Request;
  using Response = vimbax_camera_msgs::srv::FeatureAccessModeGet_Response;
};

}  // namespace srv

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_ACCESS_MODE_GET__STRUCT_HPP_

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:srv/FeatureInfoQuery.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__STRUCT_HPP_

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
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureInfoQuery_Request __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureInfoQuery_Request __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FeatureInfoQuery_Request_
{
  using Type = FeatureInfoQuery_Request_<ContainerAllocator>;

  explicit FeatureInfoQuery_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feature_module(_init)
  {
    (void)_init;
  }

  explicit FeatureInfoQuery_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feature_module(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _feature_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _feature_names_type feature_names;
  using _feature_module_type =
    vimbax_camera_msgs::msg::FeatureModule_<ContainerAllocator>;
  _feature_module_type feature_module;

  // setters for named parameter idiom
  Type & set__feature_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->feature_names = _arg;
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
    vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureInfoQuery_Request
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureInfoQuery_Request
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureInfoQuery_Request_ & other) const
  {
    if (this->feature_names != other.feature_names) {
      return false;
    }
    if (this->feature_module != other.feature_module) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureInfoQuery_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureInfoQuery_Request_

// alias to use template instance with default allocator
using FeatureInfoQuery_Request =
  vimbax_camera_msgs::srv::FeatureInfoQuery_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs


// Include directives for member types
// Member 'feature_info'
#include "vimbax_camera_msgs/msg/detail/feature_info__struct.hpp"
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureInfoQuery_Response __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__FeatureInfoQuery_Response __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FeatureInfoQuery_Response_
{
  using Type = FeatureInfoQuery_Response_<ContainerAllocator>;

  explicit FeatureInfoQuery_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_init)
  {
    (void)_init;
  }

  explicit FeatureInfoQuery_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _feature_info_type =
    std::vector<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>>>;
  _feature_info_type feature_info;
  using _error_type =
    vimbax_camera_msgs::msg::Error_<ContainerAllocator>;
  _error_type error;

  // setters for named parameter idiom
  Type & set__feature_info(
    const std::vector<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vimbax_camera_msgs::msg::FeatureInfo_<ContainerAllocator>>> & _arg)
  {
    this->feature_info = _arg;
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
    vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureInfoQuery_Response
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__FeatureInfoQuery_Response
    std::shared_ptr<vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureInfoQuery_Response_ & other) const
  {
    if (this->feature_info != other.feature_info) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureInfoQuery_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureInfoQuery_Response_

// alias to use template instance with default allocator
using FeatureInfoQuery_Response =
  vimbax_camera_msgs::srv::FeatureInfoQuery_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace vimbax_camera_msgs
{

namespace srv
{

struct FeatureInfoQuery
{
  using Request = vimbax_camera_msgs::srv::FeatureInfoQuery_Request;
  using Response = vimbax_camera_msgs::srv::FeatureInfoQuery_Response;
};

}  // namespace srv

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__FEATURE_INFO_QUERY__STRUCT_HPP_

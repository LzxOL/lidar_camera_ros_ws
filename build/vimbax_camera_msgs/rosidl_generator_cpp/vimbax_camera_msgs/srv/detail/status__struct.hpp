// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vimbax_camera_msgs:srv/Status.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__STRUCT_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__srv__Status_Request __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__Status_Request __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Status_Request_
{
  using Type = Status_Request_<ContainerAllocator>;

  explicit Status_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Status_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__Status_Request
    std::shared_ptr<vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__Status_Request
    std::shared_ptr<vimbax_camera_msgs::srv::Status_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_Request_

// alias to use template instance with default allocator
using Status_Request =
  vimbax_camera_msgs::srv::Status_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs


// Include directives for member types
// Member 'error'
#include "vimbax_camera_msgs/msg/detail/error__struct.hpp"
// Member 'trigger_info'
#include "vimbax_camera_msgs/msg/detail/trigger_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vimbax_camera_msgs__srv__Status_Response __attribute__((deprecated))
#else
# define DEPRECATED__vimbax_camera_msgs__srv__Status_Response __declspec(deprecated)
#endif

namespace vimbax_camera_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Status_Response_
{
  using Type = Status_Response_<ContainerAllocator>;

  explicit Status_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->display_name = "";
      this->model_name = "";
      this->device_firmware_version = "";
      this->device_id = "";
      this->device_user_id = "";
      this->device_serial_number = "";
      this->interface_id = "";
      this->transport_layer_id = "";
      this->streaming = false;
      this->width = 0ul;
      this->height = 0ul;
      this->frame_rate = 0.0;
      this->pixel_format = "";
      this->ip_address = "";
      this->mac_address = "";
    }
  }

  explicit Status_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc, _init),
    display_name(_alloc),
    model_name(_alloc),
    device_firmware_version(_alloc),
    device_id(_alloc),
    device_user_id(_alloc),
    device_serial_number(_alloc),
    interface_id(_alloc),
    transport_layer_id(_alloc),
    pixel_format(_alloc),
    ip_address(_alloc),
    mac_address(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->display_name = "";
      this->model_name = "";
      this->device_firmware_version = "";
      this->device_id = "";
      this->device_user_id = "";
      this->device_serial_number = "";
      this->interface_id = "";
      this->transport_layer_id = "";
      this->streaming = false;
      this->width = 0ul;
      this->height = 0ul;
      this->frame_rate = 0.0;
      this->pixel_format = "";
      this->ip_address = "";
      this->mac_address = "";
    }
  }

  // field types and members
  using _error_type =
    vimbax_camera_msgs::msg::Error_<ContainerAllocator>;
  _error_type error;
  using _display_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _display_name_type display_name;
  using _model_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _model_name_type model_name;
  using _device_firmware_version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_firmware_version_type device_firmware_version;
  using _device_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_id_type device_id;
  using _device_user_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_user_id_type device_user_id;
  using _device_serial_number_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_serial_number_type device_serial_number;
  using _interface_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _interface_id_type interface_id;
  using _transport_layer_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _transport_layer_id_type transport_layer_id;
  using _streaming_type =
    bool;
  _streaming_type streaming;
  using _width_type =
    uint32_t;
  _width_type width;
  using _height_type =
    uint32_t;
  _height_type height;
  using _frame_rate_type =
    double;
  _frame_rate_type frame_rate;
  using _pixel_format_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _pixel_format_type pixel_format;
  using _trigger_info_type =
    std::vector<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>>>;
  _trigger_info_type trigger_info;
  using _ip_address_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ip_address_type ip_address;
  using _mac_address_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mac_address_type mac_address;

  // setters for named parameter idiom
  Type & set__error(
    const vimbax_camera_msgs::msg::Error_<ContainerAllocator> & _arg)
  {
    this->error = _arg;
    return *this;
  }
  Type & set__display_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->display_name = _arg;
    return *this;
  }
  Type & set__model_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->model_name = _arg;
    return *this;
  }
  Type & set__device_firmware_version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_firmware_version = _arg;
    return *this;
  }
  Type & set__device_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_id = _arg;
    return *this;
  }
  Type & set__device_user_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_user_id = _arg;
    return *this;
  }
  Type & set__device_serial_number(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_serial_number = _arg;
    return *this;
  }
  Type & set__interface_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->interface_id = _arg;
    return *this;
  }
  Type & set__transport_layer_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->transport_layer_id = _arg;
    return *this;
  }
  Type & set__streaming(
    const bool & _arg)
  {
    this->streaming = _arg;
    return *this;
  }
  Type & set__width(
    const uint32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const uint32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__frame_rate(
    const double & _arg)
  {
    this->frame_rate = _arg;
    return *this;
  }
  Type & set__pixel_format(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->pixel_format = _arg;
    return *this;
  }
  Type & set__trigger_info(
    const std::vector<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<vimbax_camera_msgs::msg::TriggerInfo_<ContainerAllocator>>> & _arg)
  {
    this->trigger_info = _arg;
    return *this;
  }
  Type & set__ip_address(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ip_address = _arg;
    return *this;
  }
  Type & set__mac_address(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mac_address = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vimbax_camera_msgs__srv__Status_Response
    std::shared_ptr<vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vimbax_camera_msgs__srv__Status_Response
    std::shared_ptr<vimbax_camera_msgs::srv::Status_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_Response_ & other) const
  {
    if (this->error != other.error) {
      return false;
    }
    if (this->display_name != other.display_name) {
      return false;
    }
    if (this->model_name != other.model_name) {
      return false;
    }
    if (this->device_firmware_version != other.device_firmware_version) {
      return false;
    }
    if (this->device_id != other.device_id) {
      return false;
    }
    if (this->device_user_id != other.device_user_id) {
      return false;
    }
    if (this->device_serial_number != other.device_serial_number) {
      return false;
    }
    if (this->interface_id != other.interface_id) {
      return false;
    }
    if (this->transport_layer_id != other.transport_layer_id) {
      return false;
    }
    if (this->streaming != other.streaming) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->frame_rate != other.frame_rate) {
      return false;
    }
    if (this->pixel_format != other.pixel_format) {
      return false;
    }
    if (this->trigger_info != other.trigger_info) {
      return false;
    }
    if (this->ip_address != other.ip_address) {
      return false;
    }
    if (this->mac_address != other.mac_address) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_Response_

// alias to use template instance with default allocator
using Status_Response =
  vimbax_camera_msgs::srv::Status_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vimbax_camera_msgs

namespace vimbax_camera_msgs
{

namespace srv
{

struct Status
{
  using Request = vimbax_camera_msgs::srv::Status_Request;
  using Response = vimbax_camera_msgs::srv::Status_Response;
};

}  // namespace srv

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__STATUS__STRUCT_HPP_

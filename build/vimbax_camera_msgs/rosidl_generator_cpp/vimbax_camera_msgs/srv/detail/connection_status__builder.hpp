// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/ConnectionStatus.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/connection_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::ConnectionStatus_Request>()
{
  return ::vimbax_camera_msgs::srv::ConnectionStatus_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_ConnectionStatus_Response_connected
{
public:
  Init_ConnectionStatus_Response_connected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vimbax_camera_msgs::srv::ConnectionStatus_Response connected(::vimbax_camera_msgs::srv::ConnectionStatus_Response::_connected_type arg)
  {
    msg_.connected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::ConnectionStatus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::ConnectionStatus_Response>()
{
  return vimbax_camera_msgs::srv::builder::Init_ConnectionStatus_Response_connected();
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__CONNECTION_STATUS__BUILDER_HPP_

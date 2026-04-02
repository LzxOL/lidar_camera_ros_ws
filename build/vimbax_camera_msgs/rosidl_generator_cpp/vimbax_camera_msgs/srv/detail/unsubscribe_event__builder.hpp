// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vimbax_camera_msgs:srv/UnsubscribeEvent.idl
// generated code does not contain a copyright notice

#ifndef VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__BUILDER_HPP_
#define VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vimbax_camera_msgs/srv/detail/unsubscribe_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vimbax_camera_msgs
{

namespace srv
{

namespace builder
{

class Init_UnsubscribeEvent_Request_name
{
public:
  Init_UnsubscribeEvent_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vimbax_camera_msgs::srv::UnsubscribeEvent_Request name(::vimbax_camera_msgs::srv::UnsubscribeEvent_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vimbax_camera_msgs::srv::UnsubscribeEvent_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::UnsubscribeEvent_Request>()
{
  return vimbax_camera_msgs::srv::builder::Init_UnsubscribeEvent_Request_name();
}

}  // namespace vimbax_camera_msgs


namespace vimbax_camera_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vimbax_camera_msgs::srv::UnsubscribeEvent_Response>()
{
  return ::vimbax_camera_msgs::srv::UnsubscribeEvent_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace vimbax_camera_msgs

#endif  // VIMBAX_CAMERA_MSGS__SRV__DETAIL__UNSUBSCRIBE_EVENT__BUILDER_HPP_

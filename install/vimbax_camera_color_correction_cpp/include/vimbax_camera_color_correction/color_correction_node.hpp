// Copyright (c) 2024 Color Correction C++ Optimization
// ROS2 node for high-performance 3D LUT color correction

#ifndef VIMBAX_CAMERA_COLOR_CORRECTION_COLOR_CORRECTION_NODE_HPP_
#define VIMBAX_CAMERA_COLOR_CORRECTION_COLOR_CORRECTION_NODE_HPP_

#include <memory>
#include <string>
#include <mutex>
#include <atomic>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>

#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <std_msgs/msg/string.hpp>

#include <image_transport/image_transport.hpp>
#include <camera_info_manager/camera_info_manager.hpp>
#include <cv_bridge/cv_bridge.h>

#include <opencv2/opencv.hpp>

#include "vimbax_camera_color_correction/color_lut.hpp"

namespace vimbax_camera_color_correction
{

/**
 * @brief ROS2 node for high-performance 3D LUT color correction
 *
 * This node subscribes to camera images, applies 3D LUT color correction
 * using optimized C++ code with OpenMP parallelization, and publishes
 * the corrected images.
 *
 * Features:
 * - High-performance LUT processing (< 5ms for 1920x1080)
 * - Automatic LUT loading from binary files
 * - Support for RGB and BGR input/output
 * - Thread-safe LUT updates
 * - Performance monitoring
 */
class ColorCorrectionNode : public rclcpp::Node
{
public:
  /**
   * @brief Construct a new Color Correction Node
   * @param options ROS2 node options
   */
  explicit ColorCorrectionNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions{});

  /**
   * @brief Destructor
   */
  ~ColorCorrectionNode();

private:
  // ==========================================================================
  // Constants
  // ==========================================================================
  static constexpr const char * NODE_NAME = "lut_color_correction_cpp_node";

  // ==========================================================================
  // Parameters
  // ==========================================================================
  std::string input_topic_;
  std::string output_topic_;
  std::string camera_info_topic_;
  std::string output_camera_info_topic_;
  std::string input_encoding_;
  std::string output_encoding_;
  std::string lut_file_;
  int lut_size_;
  int num_threads_;
  bool enable_color_correction_;
  bool publish_ccm_;
  bool verbose_;

  // ==========================================================================
  // Runtime state
  // ==========================================================================
  std::unique_ptr<ColorLUT> color_lut_;
  std::atomic_bool lut_enabled_;
  std::atomic_bool is_processing_;

  cv_bridge::CvImagePtr latest_cv_image_;
  std::mutex image_mutex_;

  // Performance metrics
  std::atomic<uint64_t> frame_count_;
  std::atomic<uint64_t> total_processing_time_us_;
  rclcpp::Time last_perf_log_time_;

  // ==========================================================================
  // Publishers and Subscribers
  // ==========================================================================
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
  rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_sub_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub_;
  rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_pub_;

  // Status publishers
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr status_pub_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr detection_status_pub_;
  rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr ccm_pub_;

  std::shared_ptr<camera_info_manager::CameraInfoManager> camera_info_manager_;

  // ==========================================================================
  // Methods
  // ==========================================================================

  /**
   * @brief Initialize parameters from ROS2 parameter server
   */
  void initParameters();

  /**
   * @brief Initialize publishers and subscribers
   */
  void initPublishersSubscribers();

  /**
   * @brief Load LUT from file
   * @return true if LUT loaded successfully
   */
  bool loadLUT();

  /**
   * @brief Load LUT from binary file format
   * @param filename Path to binary LUT file
   * @return true if loaded successfully
   */
  bool loadLUTFromBinary(const std::string & filename);

  /**
   * @brief Load LUT from numpy .npy file
   * @param filename Path to .npy file
   * @return true if loaded successfully
   */
  bool loadLUTFromNpy(const std::string & filename);

  /**
   * @brief Image callback - processes incoming images
   * @param msg Shared pointer to input image message
   */
  void imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr msg);

  /**
   * @brief Camera info callback
   * @param msg Shared pointer to camera info message
   */
  void cameraInfoCallback(const sensor_msgs::msg::CameraInfo::SharedPtr msg);

  /**
   * @brief Apply LUT to image and return result
   * @param input Input OpenCV image
   * @return Corrected OpenCV image
   */
  cv::Mat applyLUT(const cv::Mat & input);

  /**
   * @brief Convert between RGB and BGR if needed
   * @param input Input image
   * @param to_bgr True to convert to BGR, false for RGB
   * @return Converted image
   */
  cv::Mat convertColor(const cv::Mat & input, bool to_bgr);

  /**
   * @brief Publish status messages
   */
  void publishStatus();

  /**
   * @brief Log performance metrics
   */
  void logPerformance();

  /**
   * @brief Helper to convert OpenCV type to string
   */
  std::string openCVTypeToString(int type);
};

}  // namespace vimbax_camera_color_correction

#endif  // VIMBAX_CAMERA_COLOR_CORRECTION_COLOR_CORRECTION_NODE_HPP_

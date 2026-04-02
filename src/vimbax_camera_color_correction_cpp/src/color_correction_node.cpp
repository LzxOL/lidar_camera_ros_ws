// Copyright (c) 2024 Color Correction C++ Optimization
// ROS2 node for high-performance 3D LUT color correction

#include "vimbax_camera_color_correction/color_correction_node.hpp"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <cstring>
#include <cstdlib>

#ifdef _OPENMP
#include <omp.h>
#endif

namespace vimbax_camera_color_correction
{

// ============================================================================
// Node Implementation
// ============================================================================

ColorCorrectionNode::ColorCorrectionNode(const rclcpp::NodeOptions & options)
  : Node(NODE_NAME, options),
    lut_enabled_(false),
    is_processing_(false),
    frame_count_(0),
    total_processing_time_us_(0),
    last_perf_log_time_(this->now())
{
  RCLCPP_INFO(this->get_logger(), "==============================================");
  RCLCPP_INFO(this->get_logger(), "Color Correction C++ Node (High Performance)");
  RCLCPP_INFO(this->get_logger(), "==============================================");

  // Create ColorLUT instance
  color_lut_ = createColorLUT();

  // Initialize parameters
  initParameters();

  // Load LUT if file specified
  if (!lut_file_.empty()) {
    if (loadLUT()) {
      RCLCPP_INFO(this->get_logger(), "LUT loaded successfully: %s", lut_file_.c_str());
      RCLCPP_INFO(this->get_logger(), "LUT size: %d", color_lut_->getLutSize());
    } else {
      RCLCPP_WARN(this->get_logger(), "Failed to load LUT from: %s", lut_file_.c_str());
      RCLCPP_WARN(this->get_logger(), "Color correction will be disabled");
    }
  }

  // Initialize publishers and subscribers
  initPublishersSubscribers();

  // Print configuration
  RCLCPP_INFO(this->get_logger(), "Configuration:");
  RCLCPP_INFO(this->get_logger(), "  Input topic: %s", input_topic_.c_str());
  RCLCPP_INFO(this->get_logger(), "  Output topic: %s", output_topic_.c_str());
  RCLCPP_INFO(this->get_logger(), "  Input encoding: %s", input_encoding_.c_str());
  RCLCPP_INFO(this->get_logger(), "  Output encoding: %s", output_encoding_.c_str());
  RCLCPP_INFO(this->get_logger(), "  LUT file: %s", lut_file_.empty() ? "(not set)" : lut_file_.c_str());
  RCLCPP_INFO(this->get_logger(), "  Number of threads: %d", num_threads_);
  RCLCPP_INFO(this->get_logger(), "  Color correction enabled: %s", enable_color_correction_ ? "true" : "false");

#if defined(_OPENMP)
  RCLCPP_INFO(this->get_logger(), "  OpenMP enabled: true (max threads: %d)", omp_get_max_threads());
#else
  RCLCPP_INFO(this->get_logger(), "  OpenMP enabled: false");
#endif

  RCLCPP_INFO(this->get_logger(), "==============================================");
}

ColorCorrectionNode::~ColorCorrectionNode()
{
  logPerformance();
}

// ============================================================================
// Parameter Initialization
// ============================================================================

void ColorCorrectionNode::initParameters()
{
  // Declare and get parameters
  this->declare_parameter<std::string>("input_topic", "/vimbax_camera/image_raw");
  this->declare_parameter<std::string>("output_topic", "/color_corrected/image_raw");
  this->declare_parameter<std::string>("camera_info_topic", "/vimbax_camera/camera_info");
  this->declare_parameter<std::string>("output_camera_info_topic", "/color_corrected/camera_info");

  this->declare_parameter<std::string>("input_encoding", "rgb8");
  this->declare_parameter<std::string>("output_encoding", "rgb8");

  this->declare_parameter<std::string>(
    "lut_file", "/home/root1/lzx_ws/project/vimbax_ros_camera/config/color_correction_lut.bin");
  this->declare_parameter<int>("lut_size", 33);
  this->declare_parameter<int>("num_threads", 0);
  this->declare_parameter<bool>("enable_color_correction", true);
  this->declare_parameter<bool>("publish_ccm", false);
  this->declare_parameter<bool>("verbose", false);

  this->get_parameter("input_topic", input_topic_);
  this->get_parameter("output_topic", output_topic_);
  this->get_parameter("camera_info_topic", camera_info_topic_);
  this->get_parameter("output_camera_info_topic", output_camera_info_topic_);

  this->get_parameter("input_encoding", input_encoding_);
  this->get_parameter("output_encoding", output_encoding_);

  this->get_parameter("lut_file", lut_file_);
  this->get_parameter("lut_size", lut_size_);
  this->get_parameter("num_threads", num_threads_);
  this->get_parameter("enable_color_correction", enable_color_correction_);
  this->get_parameter("publish_ccm", publish_ccm_);
  this->get_parameter("verbose", verbose_);

  // Validate encoding
  if (input_encoding_ != "rgb8" && input_encoding_ != "bgr8") {
    RCLCPP_WARN(this->get_logger(), "Unsupported input encoding: %s, using rgb8", input_encoding_.c_str());
    input_encoding_ = "rgb8";
  }

  if (output_encoding_ != "rgb8" && output_encoding_ != "bgr8") {
    RCLCPP_WARN(this->get_logger(), "Unsupported output encoding: %s, using rgb8", output_encoding_.c_str());
    output_encoding_ = "rgb8";
  }

  // Configure parallel processing
  if (num_threads_ > 0) {
    color_lut_->setParallelEnabled(true);
#ifdef _OPENMP
    omp_set_num_threads(num_threads_);
#endif
  }
}

// ============================================================================
// Publishers and Subscribers
// ============================================================================

void ColorCorrectionNode::initPublishersSubscribers()
{
  image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
    input_topic_,
    rclcpp::SensorDataQoS(),
    std::bind(&ColorCorrectionNode::imageCallback, this, std::placeholders::_1));

  camera_info_sub_ = this->create_subscription<sensor_msgs::msg::CameraInfo>(
    camera_info_topic_,
    10,
    std::bind(&ColorCorrectionNode::cameraInfoCallback, this, std::placeholders::_1));

  // Publishers
  image_pub_ = this->create_publisher<sensor_msgs::msg::Image>(output_topic_, 10);
  camera_info_pub_ = this->create_publisher<sensor_msgs::msg::CameraInfo>(
      output_camera_info_topic_, 10);

  // Status publishers
  status_pub_ = this->create_publisher<std_msgs::msg::Bool>("~/lut_loaded", 10);
  detection_status_pub_ = this->create_publisher<std_msgs::msg::String>("~/status", 10);
  ccm_pub_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("~/ccm_matrix", 10);

  // Camera info manager
  camera_info_manager_ = std::make_shared<camera_info_manager::CameraInfoManager>(
      this, "color_correction_camera");

  // Initial status
  publishStatus();
}

// ============================================================================
// LUT Loading
// ============================================================================

bool ColorCorrectionNode::loadLUT()
{
  if (lut_file_.empty()) {
    return false;
  }

  namespace fs = std::filesystem;
  fs::path lut_path(lut_file_);

  if (!fs::exists(lut_path)) {
    RCLCPP_ERROR(this->get_logger(), "LUT file does not exist: %s", lut_file_.c_str());
    return false;
  }

  // Try binary format first
  if (lut_path.extension() == ".bin") {
    return loadLUTFromBinary(lut_file_);
  }

  // Try numpy format
  if (lut_path.extension() == ".npy") {
    return loadLUTFromNpy(lut_file_);
  }

  // Auto-detect based on file magic
  return loadLUTFromBinary(lut_file_);
}

bool ColorCorrectionNode::loadLUTFromBinary(const std::string & filename)
{
  if (color_lut_->loadFromBinary(filename)) {
    lut_enabled_ = enable_color_correction_;
    return true;
  }
  return false;
}

bool ColorCorrectionNode::loadLUTFromNpy(const std::string & filename)
{
  // Simple NPY loader - reads shape and data
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    RCLCPP_ERROR(this->get_logger(), "Failed to open NPY file: %s", filename.c_str());
    return false;
  }

  // Read magic bytes
  unsigned char magic[6];
  file.read(reinterpret_cast<char *>(magic), 6);
  if (magic[0] != 0x93 || magic[1] != 'N' || magic[2] != 'U' ||
      magic[3] != 'M' || magic[4] != 'P' || magic[5] != 'Y') {
    RCLCPP_ERROR(this->get_logger(), "Not a valid NPY file: %s", filename.c_str());
    return false;
  }

  // Read version
  uint8_t major_version, minor_version;
  file.read(reinterpret_cast<char *>(&major_version), 1);
  file.read(reinterpret_cast<char *>(&minor_version), 1);

  // Read header length
  uint16_t header_len;
  if (major_version == 1) {
    file.read(reinterpret_cast<char *>(&header_len), 2);
  } else {
    file.read(reinterpret_cast<char *>(&header_len), 4);
  }

  // Read header
  std::string header(header_len, '\0');
  file.read(header.data(), header_len);

  // Find shape in header
  size_t shape_start = header.find("'(");
  size_t shape_end = header.find(")'");
  if (shape_start == std::string::npos || shape_end == std::string::npos) {
    RCLCPP_ERROR(this->get_logger(), "Could not parse NPY shape");
    return false;
  }

  std::string shape_str = header.substr(shape_start + 2, shape_end - shape_start - 2);
  int dims[4] = {0, 0, 0, 0};
  int ndims = 0;

  char *token = strtok(const_cast<char *>(shape_str.c_str()), ",");
  while (token != nullptr && ndims < 4) {
    dims[ndims++] = atoi(token);
    token = strtok(nullptr, ",");
  }

  // Validate shape: should be (size, size, size, 3)
  if (ndims != 4 || dims[0] != dims[1] || dims[1] != dims[2] || dims[3] != 3) {
    RCLCPP_ERROR(this->get_logger(), "Invalid NPY shape: expected (N,N,N,3), got (%d,%d,%d,%d)",
                 dims[0], dims[1], dims[2], dims[3]);
    return false;
  }

  // Allocate and read data
  int lut_size = dims[0];
  int64_t total_elements = static_cast<int64_t>(lut_size) * lut_size * lut_size * 3;
  std::vector<float> lut_data(total_elements);
  file.read(reinterpret_cast<char *>(lut_data.data()), total_elements * sizeof(float));

  if (!file.good()) {
    RCLCPP_ERROR(this->get_logger(), "Failed to read NPY data");
    return false;
  }

  color_lut_->setLUTData(lut_data.data(), lut_size);
  lut_enabled_ = enable_color_correction_;

  RCLCPP_INFO(this->get_logger(), "Loaded NPY LUT: size=%d, elements=%ld", lut_size, total_elements);

  return true;
}

// ============================================================================
// Image Processing
// ============================================================================

void ColorCorrectionNode::imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr msg)
{
  // Skip if already processing
  if (is_processing_.exchange(true)) {
    return;
  }

  auto start_time = std::chrono::high_resolution_clock::now();

  try {
    // Convert ROS image to OpenCV
    cv_bridge::CvImagePtr cv_image = cv_bridge::toCvCopy(msg, input_encoding_);
    if (!cv_image || cv_image->image.empty()) {
      RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
                          "Failed to convert image");
      is_processing_ = false;
      return;
    }

    // Apply LUT if enabled
    cv::Mat output_image;
    if (lut_enabled_ && enable_color_correction_) {
      output_image = applyLUT(cv_image->image);
    } else {
      output_image = cv_image->image;
    }

    // Convert output encoding
    std::string output_encoding = output_encoding_;
    if (output_encoding == "rgb8" && cv_image->encoding == "bgr8") {
      cv::cvtColor(output_image, output_image, cv::COLOR_BGR2RGB);
      output_encoding = "rgb8";
    } else if (output_encoding == "bgr8" && cv_image->encoding == "rgb8") {
      cv::cvtColor(output_image, output_image, cv::COLOR_RGB2BGR);
      output_encoding = "bgr8";
    }

    // Create output message
    sensor_msgs::msg::Image output_msg;
    output_msg.header = msg->header;
    output_msg.height = output_image.rows;
    output_msg.width = output_image.cols;
    output_msg.encoding = output_encoding;
    output_msg.is_bigendian = msg->is_bigendian;
    output_msg.step = static_cast<uint32_t>(output_image.step);

    // Copy data
    size_t data_size = output_image.rows * output_image.step;
    output_msg.data.resize(data_size);
    memcpy(output_msg.data.data(), output_image.data, data_size);

    // Publish
    image_pub_->publish(output_msg);

  } catch (const cv_bridge::Exception & e) {
    RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
  } catch (const std::exception & e) {
    RCLCPP_ERROR(this->get_logger(), "Exception in image callback: %s", e.what());
  }

  // Update performance metrics
  auto end_time = std::chrono::high_resolution_clock::now();
  auto processing_time = std::chrono::duration_cast<std::chrono::microseconds>(
      end_time - start_time).count();

  frame_count_++;
  total_processing_time_us_ += processing_time;

  // Log performance every second
  auto current_time = this->now();
  if ((current_time - last_perf_log_time_).seconds() >= 1.0) {
    logPerformance();
    last_perf_log_time_ = current_time;
  }

  is_processing_ = false;
}

void ColorCorrectionNode::cameraInfoCallback(const sensor_msgs::msg::CameraInfo::SharedPtr msg)
{
  camera_info_manager_->setCameraInfo(*msg);
  camera_info_pub_->publish(*msg);
}

cv::Mat ColorCorrectionNode::applyLUT(const cv::Mat & input)
{
  if (!color_lut_ || !color_lut_->isLoaded()) {
    return input;
  }

  // Ensure input is continuous and in correct format
  cv::Mat rgb_input;
  if (input.channels() != 3) {
    RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
                        "Input image must have 3 channels");
    return input;
  }

  // Convert BGR to RGB if needed for processing
  if (input.channels() == 3 && input.type() == CV_8UC3) {
    // Check if it's BGR format (most common from cameras)
    if (input_encoding_ == "bgr8" || input_encoding_ == "BGR8") {
      cv::cvtColor(input, rgb_input, cv::COLOR_BGR2RGB);
    } else {
      rgb_input = input;
    }
  } else {
    rgb_input = input;
  }

  // Create output buffer
  cv::Mat output(rgb_input.rows, rgb_input.cols, CV_8UC3);

  // Apply LUT
  color_lut_->applyImage(rgb_input.data, output.data,
                         rgb_input.cols, rgb_input.rows,
                         num_threads_);

  // Convert back to BGR if input was BGR
  cv::Mat final_output;
  if (input_encoding_ == "bgr8" || input_encoding_ == "BGR8") {
    cv::cvtColor(output, final_output, cv::COLOR_RGB2BGR);
  } else {
    final_output = output;
  }

  return final_output;
}

cv::Mat ColorCorrectionNode::convertColor(const cv::Mat & input, bool to_bgr)
{
  if (input.channels() != 3) {
    return input;
  }

  cv::Mat output;
  if (to_bgr) {
    if (input.type() == CV_8UC3) {
      cv::cvtColor(input, output, cv::COLOR_RGB2BGR);
    } else {
      output = input;
    }
  } else {
    if (input.type() == CV_8UC3) {
      cv::cvtColor(input, output, cv::COLOR_BGR2RGB);
    } else {
      output = input;
    }
  }

  return output;
}

// ============================================================================
// Status Publishing
// ============================================================================

void ColorCorrectionNode::publishStatus()
{
  auto status_msg = std_msgs::msg::Bool();
  status_msg.data = lut_enabled_;
  status_pub_->publish(status_msg);

  auto detection_msg = std_msgs::msg::String();
  if (lut_enabled_) {
    detection_msg.data = "LUT loaded and active";
  } else if (!lut_file_.empty()) {
    detection_msg.data = "LUT file specified but not loaded";
  } else {
    detection_msg.data = "No LUT file specified";
  }
  detection_status_pub_->publish(detection_msg);
}

void ColorCorrectionNode::logPerformance()
{
  uint64_t frames = frame_count_.load();
  uint64_t total_us = total_processing_time_us_.load();

  if (frames == 0) {
    return;
  }

  double avg_time_ms = static_cast<double>(total_us) / frames / 1000.0;
  double fps = frames / std::max(1.0, (this->now() - last_perf_log_time_).seconds());

  if (verbose_) {
    RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                        "Performance: %.2f ms/frame, %.1f FPS (frames: %lu)",
                        avg_time_ms, fps, frames);
  }

  // Reset counters
  frame_count_ = 0;
  total_processing_time_us_ = 0;
}

std::string ColorCorrectionNode::openCVTypeToString(int type)
{
  std::string r;
  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch (depth) {
    case CV_8U: r = "8U"; break;
    case CV_8S: r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default: r = "User"; break;
  }

  r += "C" + std::to_string(chans);
  return r;
}

}  // namespace vimbax_camera_color_correction

// Register the node as a ROS2 component
RCLCPP_COMPONENTS_REGISTER_NODE(vimbax_camera_color_correction::ColorCorrectionNode)

// Copyright (c) 2024 Color Correction C++ Optimization
// High-performance 3D LUT color correction implementation
// Optimized with SIMD and multi-threading for real-time processing

#ifndef VIMBAX_CAMERA_COLOR_CORRECTION_COLOR_LUT_HPP_
#define VIMBAX_CAMERA_COLOR_CORRECTION_COLOR_LUT_HPP_

#include <cstdint>
#include <vector>
#include <string>
#include <memory>
#include <array>
#include <mutex>

namespace vimbax_camera_color_correction
{

/**
 * @brief High-performance 3D LUT color correction class
 *
 * This class implements fast trilinear interpolation for applying 3D LUT
 * color corrections to RGB images. It uses:
 * - OpenMP for parallel processing
 * - Pre-computed LUT tables for fast lookup
 * - SIMD-friendly memory access patterns
 * - Optimized interpolation with minimal branching
 *
 * Performance target: < 5ms for 1920x1080 image with 33x33x33 LUT
 */
class ColorLUT
{
public:
  /**
   * @brief Construct a new Color LUT object
   */
  ColorLUT();

  /**
   * @brief Destructor
   */
  ~ColorLUT();

  // Disable copy (LUT data is large, use move instead)
  ColorLUT(const ColorLUT &) = delete;
  ColorLUT & operator=(const ColorLUT &) = delete;

  // Enable move semantics
  ColorLUT(ColorLUT && other) noexcept;
  ColorLUT & operator=(ColorLUT && other) noexcept;

  /**
   * @brief Load LUT from binary file
   *
   * File format:
   * [4 bytes] lut_size (int32, little-endian)
   * [lut_size^3 * 3 * 4 bytes] float32 RGB data (little-endian)
   *
   * @param filename Path to binary LUT file
   * @return true if loaded successfully
   */
  bool loadFromBinary(const std::string & filename);

  /**
   * @brief Load LUT from numpy .npy file (optional fallback)
   *
   * @param filename Path to .npy file
   * @return true if loaded successfully
   */
  bool loadFromNpy(const std::string & filename);

  /**
   * @brief Set LUT data directly from flat array
   *
   * @param lut_data Pointer to LUT data (size = lut_size^3 * 3)
   * @param lut_size Size of each dimension (typically 33)
   */
  void setLUTData(const float * lut_data, int32_t lut_size);

  /**
   * @brief Apply LUT to a single RGB pixel (for testing/verification)
   *
   * @param r Input R channel [0, 255]
   * @param g Input G channel [0, 255]
   * @param b Input B channel [0, 255]
   * @param out_r Output R channel
   * @param out_g Output G channel
   * @param out_b Output B channel
   */
  void applyPixel(uint8_t r, uint8_t g, uint8_t b,
                  uint8_t & out_r, uint8_t & out_g, uint8_t & out_b) const;

  /**
   * @brief Apply LUT to RGB image (main processing function)
   *
   * This is the main performance-critical function. It processes the entire
   * image using trilinear interpolation with parallel processing.
   *
   * @param input Input RGB image (size = width * height * 3), RGB format
   * @param output Output RGB image (same size as input)
   * @param width Image width
   * @param height Image height
   * @param num_threads Number of threads for parallel processing (0 = auto)
   */
  void applyImage(const uint8_t * input, uint8_t * output,
                  int32_t width, int32_t height,
                  int32_t num_threads = 0);

  /**
   * @brief Apply LUT to BGR image (OpenCV format)
   *
   * Converts BGR to RGB internally, applies LUT, converts back to BGR.
   *
   * @param input Input BGR image (OpenCV format)
   * @param output Output BGR image
   * @param width Image width
   * @param height Image height
   * @param num_threads Number of threads
   */
  void applyImageBGR(const uint8_t * input, uint8_t * output,
                     int32_t width, int32_t height,
                     int32_t num_threads = 0);

  /**
   * @brief Check if LUT is loaded and ready
   * @return true if LUT is available
   */
  bool isLoaded() const { return is_loaded_; }

  /**
   * @brief Get LUT size
   * @return LUT dimension size
   */
  int32_t getLutSize() const { return lut_size_; }

  /**
   * @brief Get LUT data pointer (for debugging)
   * @return Pointer to LUT data
   */
  const float * getLutData() const { return lut_data_.data(); }

  /**
   * @brief Enable/disable OpenMP parallel processing
   * @param enable True to enable parallel processing
   */
  void setParallelEnabled(bool enable) { parallel_enabled_ = enable; }

  /**
   * @brief Check if parallel processing is enabled
   * @return true if parallel processing is enabled
   */
  bool isParallelEnabled() const { return parallel_enabled_; }

private:
  /**
   * @brief Fast inline trilinear interpolation lookup
   *
   * Optimized version with minimal branching and cache-friendly access.
   */
  inline void trilinearInterpolate(float r_norm, float g_norm, float b_norm,
                                    float & out_r, float & out_g, float & out_b) const;

  /**
   * @brief Convert normalized float to LUT index
   */
  inline int32_t normalizeToIndex(float value) const;

  /**
   * @brief Clamp value to [0, max]
   */
  inline float clamp(float value, float min_val, float max_val) const;

  /**
   * @brief Parallel processing worker for image rows
   */
  void processRowsParallel(const uint8_t * input, uint8_t * output,
                           int32_t width, int32_t height,
                           int32_t num_threads);

  // LUT data
  std::vector<float> lut_data_;
  int32_t lut_size_{0};
  int32_t lut_size_minus_one_{0};
  float lut_size_minus_one_inv_{0.0f};

  // State
  bool is_loaded_{false};
  bool parallel_enabled_{true};

  // LUT lookup tables for faster interpolation
  std::vector<int32_t> r0_table_;
  std::vector<int32_t> r1_table_;
  std::vector<float> dr_table_;
  std::vector<int32_t> g0_table_;
  std::vector<int32_t> g1_table_;
  std::vector<float> dg_table_;
  std::vector<int32_t> b0_table_;
  std::vector<int32_t> b1_table_;
  std::vector<float> db_table_;

  // Thread safety
  mutable std::mutex lut_mutex_;
};

/**
 * @brief Factory function to create ColorLUT with OpenMP support
 */
std::unique_ptr<ColorLUT> createColorLUT();

/**
 * @brief Generate 3D LUT from CCM matrix
 *
 * This function generates a 3D LUT from a 3x3 Color Correction Matrix.
 *
 * @param ccm 3x3 CCM matrix (row-major)
 * @param lut_size Size of LUT dimension (default 33)
 * @return Generated LUT data (size = lut_size^3 * 3)
 */
std::vector<float> generateLUTFromCCM(const float ccm[9], int32_t lut_size = 33);

/**
 * @brief Save LUT to binary file
 *
 * @param lut_data LUT data
 * @param lut_size LUT dimension size
 * @param filename Output filename
 * @return true if saved successfully
 */
bool saveLUTToBinary(const float * lut_data, int32_t lut_size, const std::string & filename);

}  // namespace vimbax_camera_color_correction

#endif  // VIMBAX_CAMERA_COLOR_CORRECTION_COLOR_LUT_HPP_

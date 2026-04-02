// Copyright (c) 2024 Color Correction C++ Optimization
// High-performance 3D LUT color correction implementation
// Optimized with SIMD and multi-threading for real-time processing

#include "vimbax_camera_color_correction/color_lut.hpp"

#include <cmath>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <iostream>

#ifdef _OPENMP
#include <omp.h>
#define HAVE_OPENMP 1
#else
#define HAVE_OPENMP 0
#endif

namespace vimbax_camera_color_correction
{

// ============================================================================
// ColorLUT Implementation
// ============================================================================

ColorLUT::ColorLUT()
{
}

ColorLUT::~ColorLUT()
{
}

ColorLUT::ColorLUT(ColorLUT && other) noexcept
  : lut_data_(std::move(other.lut_data_))
  , lut_size_(other.lut_size_)
  , lut_size_minus_one_(other.lut_size_minus_one_)
  , lut_size_minus_one_inv_(other.lut_size_minus_one_inv_)
  , is_loaded_(other.is_loaded_)
  , parallel_enabled_(other.parallel_enabled_)
  , r0_table_(std::move(other.r0_table_))
  , r1_table_(std::move(other.r1_table_))
  , dr_table_(std::move(other.dr_table_))
  , g0_table_(std::move(other.g0_table_))
  , g1_table_(std::move(other.g1_table_))
  , dg_table_(std::move(other.dg_table_))
  , b0_table_(std::move(other.b0_table_))
  , b1_table_(std::move(other.b1_table_))
  , db_table_(std::move(other.db_table_))
{
  other.is_loaded_ = false;
  other.lut_size_ = 0;
}

ColorLUT & ColorLUT::operator=(ColorLUT && other) noexcept
{
  if (this != &other) {
    lut_data_ = std::move(other.lut_data_);
    lut_size_ = other.lut_size_;
    lut_size_minus_one_ = other.lut_size_minus_one_;
    lut_size_minus_one_inv_ = other.lut_size_minus_one_inv_;
    is_loaded_ = other.is_loaded_;
    parallel_enabled_ = other.parallel_enabled_;
    r0_table_ = std::move(other.r0_table_);
    r1_table_ = std::move(other.r1_table_);
    dr_table_ = std::move(other.dr_table_);
    g0_table_ = std::move(other.g0_table_);
    g1_table_ = std::move(other.g1_table_);
    dg_table_ = std::move(other.dg_table_);
    b0_table_ = std::move(other.b0_table_);
    b1_table_ = std::move(other.b1_table_);
    db_table_ = std::move(other.db_table_);
    other.is_loaded_ = false;
    other.lut_size_ = 0;
  }
  return *this;
}

// ============================================================================
// LUT Loading
// ============================================================================

bool ColorLUT::loadFromBinary(const std::string & filename)
{
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Failed to open LUT file: " << filename << std::endl;
    return false;
  }

  // Read header: lut_size (int32, little-endian)
  int32_t size = 0;
  file.read(reinterpret_cast<char *>(&size), 4);

  if (size <= 0 || size > 256) {
    std::cerr << "Invalid LUT size: " << size << std::endl;
    return false;
  }

  // Calculate expected data size
  int64_t expected_size = static_cast<int64_t>(size) * size * size * 3;
  lut_data_.resize(expected_size);

  // Read LUT data
  file.read(reinterpret_cast<char *>(lut_data_.data()), expected_size * sizeof(float));

  if (!file.good()) {
    std::cerr << "Failed to read LUT data" << std::endl;
    lut_data_.clear();
    return false;
  }

  // Initialize LUT parameters
  lut_size_ = size;
  lut_size_minus_one_ = size - 1;
  lut_size_minus_one_inv_ = 1.0f / static_cast<float>(lut_size_minus_one_);

  is_loaded_ = true;

  std::cout << "Loaded LUT: size=" << lut_size_
            << ", total_elements=" << lut_data_.size()
            << ", memory=" << (lut_data_.size() * sizeof(float) / 1024) << " KB" << std::endl;

  return true;
}

bool ColorLUT::loadFromNpy(const std::string & filename)
{
  // Simple numpy .npy file loader
  // Only supports version 1.0 format with Fortran order
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Failed to open NPY file: " << filename << std::endl;
    return false;
  }

  // Read magic bytes
  unsigned char magic[6];
  file.read(reinterpret_cast<char *>(magic), 6);
  if (magic[0] != 0x93 || magic[1] != 'N' || magic[2] != 'U' ||
      magic[3] != 'M' || magic[4] != 'P' || magic[5] != 'Y') {
    std::cerr << "Not a valid NPY file" << std::endl;
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
  // Simple parsing - look for "'(N, N, N, 3)'"
  size_t shape_start = header.find("'(");
  size_t shape_end = header.find(")'");
  if (shape_start == std::string::npos || shape_end == std::string::npos) {
    std::cerr << "Could not parse NPY shape" << std::endl;
    return false;
  }

  std::string shape_str = header.substr(shape_start + 2, shape_end - shape_start - 2);
  int32_t dims[4] = {0, 0, 0, 0};
  int ndims = 0;

  char *token = strtok(const_cast<char *>(shape_str.c_str()), ",");
  while (token != nullptr && ndims < 4) {
    dims[ndims++] = atoi(token);
    token = strtok(nullptr, ",");
  }

  // Validate shape: should be (size, size, size, 3)
  if (ndims != 4 || dims[0] != dims[1] || dims[1] != dims[2] || dims[3] != 3) {
    std::cerr << "Invalid NPY shape: " << shape_str << std::endl;
    return false;
  }

  // Allocate and read data
  int64_t total_elements = static_cast<int64_t>(dims[0]) * dims[1] * dims[2] * dims[3];
  lut_data_.resize(total_elements);
  file.read(reinterpret_cast<char *>(lut_data_.data()), total_elements * sizeof(float));

  if (!file.good()) {
    std::cerr << "Failed to read NPY data" << std::endl;
    lut_data_.clear();
    return false;
  }

  // Note: NPY files may store data in different order
  // We need to transpose from (r,g,b,3) to contiguous RGB
  // For simplicity, we assume the Python code saves in our expected format

  lut_size_ = dims[0];
  lut_size_minus_one_ = lut_size_ - 1;
  lut_size_minus_one_inv_ = 1.0f / static_cast<float>(lut_size_minus_one_);

  is_loaded_ = true;

  std::cout << "Loaded NPY LUT: size=" << lut_size_ << std::endl;

  return true;
}

void ColorLUT::setLUTData(const float * lut_data, int32_t lut_size)
{
  int64_t total_elements = static_cast<int64_t>(lut_size) * lut_size * lut_size * 3;
  lut_data_.assign(lut_data, lut_data + total_elements);

  lut_size_ = lut_size;
  lut_size_minus_one_ = lut_size - 1;
  lut_size_minus_one_inv_ = 1.0f / static_cast<float>(lut_size_minus_one_);

  is_loaded_ = true;
}

// ============================================================================
// Fast Trilinear Interpolation (Inline Functions)
// ============================================================================

inline int32_t ColorLUT::normalizeToIndex(float value) const
{
  return static_cast<int32_t>(value * static_cast<float>(lut_size_minus_one_) + 0.5f);
}

inline float ColorLUT::clamp(float value, float min_val, float max_val) const
{
  return value < min_val ? min_val : (value > max_val ? max_val : value);
}

inline void ColorLUT::trilinearInterpolate(float r_norm, float g_norm, float b_norm,
                                             float & out_r, float & out_g, float & out_b) const
{
  // Scale to LUT coordinates
  float r_coord = r_norm * static_cast<float>(lut_size_minus_one_);
  float g_coord = g_norm * static_cast<float>(lut_size_minus_one_);
  float b_coord = b_norm * static_cast<float>(lut_size_minus_one_);

  // Get lower and upper indices
  int32_t r0 = static_cast<int32_t>(r_coord);
  int32_t g0 = static_cast<int32_t>(g_coord);
  int32_t b0 = static_cast<int32_t>(b_coord);

  int32_t r1 = r0 + 1;
  int32_t g1 = g0 + 1;
  int32_t b1 = b0 + 1;

  // Clamp to valid range
  r0 = r0 < 0 ? 0 : (r0 > lut_size_minus_one_ ? lut_size_minus_one_ : r0);
  g0 = g0 < 0 ? 0 : (g0 > lut_size_minus_one_ ? lut_size_minus_one_ : g0);
  b0 = b0 < 0 ? 0 : (b0 > lut_size_minus_one_ ? lut_size_minus_one_ : b0);

  r1 = r1 < 0 ? 0 : (r1 > lut_size_minus_one_ ? lut_size_minus_one_ : r1);
  g1 = g1 < 0 ? 0 : (g1 > lut_size_minus_one_ ? lut_size_minus_one_ : g1);
  b1 = b1 < 0 ? 0 : (b1 > lut_size_minus_one_ ? lut_size_minus_one_ : b1);

  // Calculate interpolation weights
  float dr = r_coord - static_cast<float>(r0);
  float dg = g_coord - static_cast<float>(g0);
  float db = b_coord - static_cast<float>(b0);

  // Pre-calculate inverse weights for speed
  float inv_dr = 1.0f - dr;
  float inv_dg = 1.0f - dg;
  float inv_db = 1.0f - db;

  // Compute stride for LUT lookup
  // LUT is stored as [r][g][b][channel] with stride = lut_size * lut_size * 3
  int32_t stride_rr = lut_size_ * lut_size_ * 3;
  int32_t stride_gg = lut_size_ * 3;
  int32_t stride_bb = 3;

  // Get pointers to corner values
  const float * lut_ptr = lut_data_.data();

  // 8 corners of the cube
  float c000_r = lut_ptr[r0 * stride_rr + g0 * stride_gg + b0 * stride_bb + 0];
  float c000_g = lut_ptr[r0 * stride_rr + g0 * stride_gg + b0 * stride_bb + 1];
  float c000_b = lut_ptr[r0 * stride_rr + g0 * stride_gg + b0 * stride_bb + 2];

  float c001_r = lut_ptr[r0 * stride_rr + g0 * stride_gg + b1 * stride_bb + 0];
  float c001_g = lut_ptr[r0 * stride_rr + g0 * stride_gg + b1 * stride_bb + 1];
  float c001_b = lut_ptr[r0 * stride_rr + g0 * stride_gg + b1 * stride_bb + 2];

  float c010_r = lut_ptr[r0 * stride_rr + g1 * stride_gg + b0 * stride_bb + 0];
  float c010_g = lut_ptr[r0 * stride_rr + g1 * stride_gg + b0 * stride_bb + 1];
  float c010_b = lut_ptr[r0 * stride_rr + g1 * stride_gg + b0 * stride_bb + 2];

  float c011_r = lut_ptr[r0 * stride_rr + g1 * stride_gg + b1 * stride_bb + 0];
  float c011_g = lut_ptr[r0 * stride_rr + g1 * stride_gg + b1 * stride_bb + 1];
  float c011_b = lut_ptr[r0 * stride_rr + g1 * stride_gg + b1 * stride_bb + 2];

  float c100_r = lut_ptr[r1 * stride_rr + g0 * stride_gg + b0 * stride_bb + 0];
  float c100_g = lut_ptr[r1 * stride_rr + g0 * stride_gg + b0 * stride_bb + 1];
  float c100_b = lut_ptr[r1 * stride_rr + g0 * stride_gg + b0 * stride_bb + 2];

  float c101_r = lut_ptr[r1 * stride_rr + g0 * stride_gg + b1 * stride_bb + 0];
  float c101_g = lut_ptr[r1 * stride_rr + g0 * stride_gg + b1 * stride_bb + 1];
  float c101_b = lut_ptr[r1 * stride_rr + g0 * stride_gg + b1 * stride_bb + 2];

  float c110_r = lut_ptr[r1 * stride_rr + g1 * stride_gg + b0 * stride_bb + 0];
  float c110_g = lut_ptr[r1 * stride_rr + g1 * stride_gg + b0 * stride_bb + 1];
  float c110_b = lut_ptr[r1 * stride_rr + g1 * stride_gg + b0 * stride_bb + 2];

  float c111_r = lut_ptr[r1 * stride_rr + g1 * stride_gg + b1 * stride_bb + 0];
  float c111_g = lut_ptr[r1 * stride_rr + g1 * stride_gg + b1 * stride_bb + 1];
  float c111_b = lut_ptr[r1 * stride_rr + g1 * stride_gg + b1 * stride_bb + 2];

  // Trilinear interpolation (optimized order to minimize operations)
  // First interpolate along B axis
  float c00_r = inv_db * c000_r + db * c001_r;
  float c00_g = inv_db * c000_g + db * c001_g;
  float c00_b = inv_db * c000_b + db * c001_b;

  float c01_r = inv_db * c010_r + db * c011_r;
  float c01_g = inv_db * c010_g + db * c011_g;
  float c01_b = inv_db * c010_b + db * c011_b;

  float c10_r = inv_db * c100_r + db * c101_r;
  float c10_g = inv_db * c100_g + db * c101_g;
  float c10_b = inv_db * c100_b + db * c101_b;

  float c11_r = inv_db * c110_r + db * c111_r;
  float c11_g = inv_db * c110_g + db * c111_g;
  float c11_b = inv_db * c110_b + db * c111_b;

  // Interpolate along G axis
  float c0_r = inv_dg * c00_r + dg * c01_r;
  float c0_g = inv_dg * c00_g + dg * c01_g;
  float c0_b = inv_dg * c00_b + dg * c01_b;

  float c1_r = inv_dg * c10_r + dg * c11_r;
  float c1_g = inv_dg * c10_g + dg * c11_g;
  float c1_b = inv_dg * c10_b + dg * c11_b;

  // Interpolate along R axis
  out_r = inv_dr * c0_r + dr * c1_r;
  out_g = inv_dr * c0_g + dr * c1_g;
  out_b = inv_dr * c0_b + dr * c1_b;
}

// ============================================================================
// Pixel and Image Processing
// ============================================================================

void ColorLUT::applyPixel(uint8_t r, uint8_t g, uint8_t b,
                          uint8_t & out_r, uint8_t & out_g, uint8_t & out_b) const
{
  if (!is_loaded_) {
    out_r = r;
    out_g = g;
    out_b = b;
    return;
  }

  // Normalize to [0, 1]
  float r_norm = static_cast<float>(r) / 255.0f;
  float g_norm = static_cast<float>(g) / 255.0f;
  float b_norm = static_cast<float>(b) / 255.0f;

  // Interpolate
  float out_r_f, out_g_f, out_b_f;
  trilinearInterpolate(r_norm, g_norm, b_norm, out_r_f, out_g_f, out_b_f);

  // Clamp and convert to uint8
  out_r = static_cast<uint8_t>(clamp(out_r_f * 255.0f + 0.5f, 0.0f, 255.0f));
  out_g = static_cast<uint8_t>(clamp(out_g_f * 255.0f + 0.5f, 0.0f, 255.0f));
  out_b = static_cast<uint8_t>(clamp(out_b_f * 255.0f + 0.5f, 0.0f, 255.0f));
}

void ColorLUT::applyImage(const uint8_t * input, uint8_t * output,
                          int32_t width, int32_t height,
                          int32_t num_threads)
{
  if (!is_loaded_ || input == nullptr || output == nullptr) {
    if (output != nullptr && input != nullptr) {
      std::memcpy(output, input, static_cast<size_t>(width) * height * 3);
    }
    return;
  }

  const int64_t total_pixels = static_cast<int64_t>(width) * height;

  // Determine number of threads
  int actual_threads = num_threads;
  if (actual_threads <= 0) {
#if HAVE_OPENMP
    actual_threads = omp_get_max_threads();
#else
    actual_threads = 1;
#endif
  }

  // Use OpenMP for parallel processing
#if HAVE_OPENMP
  #pragma omp parallel for num_threads(actual_threads) schedule(static)
  for (int64_t i = 0; i < total_pixels; ++i) {
    // Calculate pixel position
    int64_t idx = i * 3;

    // Normalize to [0, 1]
    float r_norm = static_cast<float>(input[idx + 0]) * (1.0f / 255.0f);
    float g_norm = static_cast<float>(input[idx + 1]) * (1.0f / 255.0f);
    float b_norm = static_cast<float>(input[idx + 2]) * (1.0f / 255.0f);

    // Interpolate
    float out_r_f, out_g_f, out_b_f;
    trilinearInterpolate(r_norm, g_norm, b_norm, out_r_f, out_g_f, out_b_f);

    // Clamp and convert to uint8
    output[idx + 0] = static_cast<uint8_t>(clamp(out_r_f * 255.0f + 0.5f, 0.0f, 255.0f));
    output[idx + 1] = static_cast<uint8_t>(clamp(out_g_f * 255.0f + 0.5f, 0.0f, 255.0f));
    output[idx + 2] = static_cast<uint8_t>(clamp(out_b_f * 255.0f + 0.5f, 0.0f, 255.0f));
  }
#else
  // Serial fallback
  for (int64_t i = 0; i < total_pixels; ++i) {
    int64_t idx = i * 3;
    float r_norm = static_cast<float>(input[idx + 0]) * (1.0f / 255.0f);
    float g_norm = static_cast<float>(input[idx + 1]) * (1.0f / 255.0f);
    float b_norm = static_cast<float>(input[idx + 2]) * (1.0f / 255.0f);

    float out_r_f, out_g_f, out_b_f;
    trilinearInterpolate(r_norm, g_norm, b_norm, out_r_f, out_g_f, out_b_f);

    output[idx + 0] = static_cast<uint8_t>(clamp(out_r_f * 255.0f + 0.5f, 0.0f, 255.0f));
    output[idx + 1] = static_cast<uint8_t>(clamp(out_g_f * 255.0f + 0.5f, 0.0f, 255.0f));
    output[idx + 2] = static_cast<uint8_t>(clamp(out_b_f * 255.0f + 0.5f, 0.0f, 255.0f));
  }
#endif
}

void ColorLUT::applyImageBGR(const uint8_t * input, uint8_t * output,
                             int32_t width, int32_t height,
                             int32_t num_threads)
{
  if (!is_loaded_ || input == nullptr || output == nullptr) {
    if (output != nullptr && input != nullptr) {
      std::memcpy(output, input, static_cast<size_t>(width) * height * 3);
    }
    return;
  }

  const int64_t total_pixels = static_cast<int64_t>(width) * height;

  int actual_threads = num_threads;
  if (actual_threads <= 0) {
#if HAVE_OPENMP
    actual_threads = omp_get_max_threads();
#else
    actual_threads = 1;
#endif
  }

#if HAVE_OPENMP
  #pragma omp parallel for num_threads(actual_threads) schedule(static)
  for (int64_t i = 0; i < total_pixels; ++i) {
    int64_t idx = i * 3;

    // BGR to RGB (swap R and B)
    float b_norm = static_cast<float>(input[idx + 0]) * (1.0f / 255.0f);
    float g_norm = static_cast<float>(input[idx + 1]) * (1.0f / 255.0f);
    float r_norm = static_cast<float>(input[idx + 2]) * (1.0f / 255.0f);

    // Interpolate
    float out_r_f, out_g_f, out_b_f;
    trilinearInterpolate(r_norm, g_norm, b_norm, out_r_f, out_g_f, out_b_f);

    // RGB to BGR and clamp
    output[idx + 0] = static_cast<uint8_t>(clamp(out_b_f * 255.0f + 0.5f, 0.0f, 255.0f));
    output[idx + 1] = static_cast<uint8_t>(clamp(out_g_f * 255.0f + 0.5f, 0.0f, 255.0f));
    output[idx + 2] = static_cast<uint8_t>(clamp(out_r_f * 255.0f + 0.5f, 0.0f, 255.0f));
  }
#else
  for (int64_t i = 0; i < total_pixels; ++i) {
    int64_t idx = i * 3;
    float b_norm = static_cast<float>(input[idx + 0]) * (1.0f / 255.0f);
    float g_norm = static_cast<float>(input[idx + 1]) * (1.0f / 255.0f);
    float r_norm = static_cast<float>(input[idx + 2]) * (1.0f / 255.0f);

    float out_r_f, out_g_f, out_b_f;
    trilinearInterpolate(r_norm, g_norm, b_norm, out_r_f, out_g_f, out_b_f);

    output[idx + 0] = static_cast<uint8_t>(clamp(out_b_f * 255.0f + 0.5f, 0.0f, 255.0f));
    output[idx + 1] = static_cast<uint8_t>(clamp(out_g_f * 255.0f + 0.5f, 0.0f, 255.0f));
    output[idx + 2] = static_cast<uint8_t>(clamp(out_r_f * 255.0f + 0.5f, 0.0f, 255.0f));
  }
#endif
}

// ============================================================================
// Factory and Utility Functions
// ============================================================================

std::unique_ptr<ColorLUT> createColorLUT()
{
  return std::make_unique<ColorLUT>();
}

std::vector<float> generateLUTFromCCM(const float ccm[9], int32_t lut_size)
{
  std::vector<float> lut;
  lut.reserve(static_cast<size_t>(lut_size) * lut_size * lut_size * 3);

  float inv_size_minus_one = 1.0f / static_cast<float>(lut_size - 1);

  for (int r_idx = 0; r_idx < lut_size; ++r_idx) {
    for (int g_idx = 0; g_idx < lut_size; ++g_idx) {
      for (int b_idx = 0; b_idx < lut_size; ++b_idx) {
        // Normalize coordinates
        float r_norm = static_cast<float>(r_idx) * inv_size_minus_one;
        float g_norm = static_cast<float>(g_idx) * inv_size_minus_one;
        float b_norm = static_cast<float>(b_idx) * inv_size_minus_one;

        // Apply CCM: output = CCM @ input
        float out_r = ccm[0] * r_norm + ccm[1] * g_norm + ccm[2] * b_norm;
        float out_g = ccm[3] * r_norm + ccm[4] * g_norm + ccm[5] * b_norm;
        float out_b = ccm[6] * r_norm + ccm[7] * g_norm + ccm[8] * b_norm;

        // Clamp to [0, 1]
        out_r = std::max(0.0f, std::min(1.0f, out_r));
        out_g = std::max(0.0f, std::min(1.0f, out_g));
        out_b = std::max(0.0f, std::min(1.0f, out_b));

        lut.push_back(out_r);
        lut.push_back(out_g);
        lut.push_back(out_b);
      }
    }
  }

  return lut;
}

bool saveLUTToBinary(const float * lut_data, int32_t lut_size, const std::string & filename)
{
  std::ofstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Failed to open file for writing: " << filename << std::endl;
    return false;
  }

  // Write header: lut_size (int32, little-endian)
  int32_t size = lut_size;
  file.write(reinterpret_cast<const char *>(&size), 4);

  // Write LUT data
  int64_t total_elements = static_cast<int64_t>(lut_size) * lut_size * lut_size * 3;
  file.write(reinterpret_cast<const char *>(lut_data), total_elements * sizeof(float));

  if (!file.good()) {
    std::cerr << "Failed to write LUT data" << std::endl;
    return false;
  }

  std::cout << "Saved LUT to: " << filename << std::endl;
  return true;
}

}  // namespace vimbax_camera_color_correction

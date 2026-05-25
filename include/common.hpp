#ifndef COMMON_HPP
#define COMMON_HPP

// std headers
#include <fstream>
#include <filesystem>
#include <vector>

// external headers
#include "include/core/SkCanvas.h"
#include "include/core/SkData.h"
#include "include/core/SkImage.h"
#include "include/core/SkPaint.h"
#include "include/core/SkRect.h"
#include "include/core/SkSamplingOptions.h"

auto LoadFileAsStream(std::filesystem::path path) -> std::vector<uint32_t>;
auto LoadImage(std::filesystem::path path) -> sk_sp<SkImage>;

#endif // COMMON_HPP
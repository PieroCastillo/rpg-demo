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

struct InputEvent
{
    uint32_t x,y;
    bool isMousePressed;
    uint32_t mouseButton;
    bool anyKeyPressed;
    uint32_t key;
};

class View
{
    virtual void OnInput(const InputEvent& input) = 0;
    virtual void OnRender(SkCanvas* canvas) = 0;
};

#endif // COMMON_HPP
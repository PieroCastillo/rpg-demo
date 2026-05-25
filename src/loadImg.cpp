#include <fstream>
#include <filesystem>

#include "include/core/SkCanvas.h"
#include "include/core/SkData.h"
#include "include/core/SkImage.h"
#include "include/core/SkPaint.h"
#include "include/core/SkRect.h"
#include "include/core/SkSamplingOptions.h"

#include "common.hpp"

auto LoadFileAsStream(std::filesystem::path path) -> std::vector<uint32_t>
{
    auto file = std::ifstream(path, std::ios::ate | std::ios::binary);
    if (!file) throw std::runtime_error(path.string() + " does not exist");

    auto fileSize = (uint32_t)file.tellg();
    std::vector<uint32_t> buffer;
    buffer.resize(fileSize / sizeof(uint32_t));

    file.seekg(0);
    file.read((char*)buffer.data(), fileSize);

    return buffer;
}

auto LoadImage(std::filesystem::path path) -> sk_sp<SkImage>
{
    auto data = SkData::MakeFromFileName(path.string().c_str());
    
    if (!data) 
        return nullptr; 
    
    auto sprite = SkImages::DeferredFromEncodedData(data);
    if (!sprite)
        return nullptr;
    
    return sprite;
}
#pragma once

#include "bin/Vector2.hpp"
#include <cstdint>
#include <stdint.h>
#include <string>

class IWindow {
  public:
    // virtual IWindow();
    virtual uint32_t LoadTexture(const std::string& texture) = 0;
    virtual void DrawTexture(neoskye::Vector2<uintptr_t> pos, int32_t index) = 0;
    virtual ~IWindow() = default;
};
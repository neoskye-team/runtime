#pragma once

#include "bin/IWindow.hpp"

class SdlGLWindow : public IWindow {
  public:
    SdlGLWindow();
    uint32_t LoadTexture(const std::string& texture) override;
    void DrawTexture(neoskye::Vector2<uintptr_t> pos, int32_t index) override;
    ~SdlGLWindow();
};
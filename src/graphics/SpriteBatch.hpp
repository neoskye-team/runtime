#pragma once

#include "Vector2.hpp"
#include "content/Sprite.hpp"
#include "util/Types.hpp"
#include <memory>

namespace neoskye::graphics {

struct DrawData {
    DrawData();
    content::Sprite::Pointer spr;
    Vector2<usize> pos;
};

class SpriteBatch {
  public:
    SpriteBatch();
    void Submit(content::Sprite::Pointer spr, Vector2<usize> pos);
    const std::vector<DrawData>& GetDrawData() const;
    void Flush();

  private:
    std::vector<DrawData> queue;
};

typedef std::shared_ptr<SpriteBatch> SpriteBatchPtr;

SpriteBatchPtr GetSpriteBatch();

} // namespace neoskye::graphics
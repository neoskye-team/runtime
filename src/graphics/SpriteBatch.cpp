#include "graphics/SpriteBatch.hpp"
#include "Vector2.hpp"
#include "content/Sprite.hpp"
#include <iostream>
#include <vector>

namespace neoskye::graphics {

DrawData::DrawData() : pos(0, 0) {}

SpriteBatch::SpriteBatch() {}

void SpriteBatch::Submit(content::Sprite::Pointer spr, Vector2<usize> pos) {
    DrawData dd;
    dd.pos = pos;
    dd.spr = spr;
    this->queue.push_back(dd);
}

const std::vector<DrawData>& SpriteBatch::GetDrawData() const { return this->queue; }

void SpriteBatch::Flush() { this->queue.clear(); }

SpriteBatchPtr GetSpriteBatch() {
    SpriteBatchPtr retVal(new SpriteBatch());
    return retVal;
}

} // namespace neoskye::graphics
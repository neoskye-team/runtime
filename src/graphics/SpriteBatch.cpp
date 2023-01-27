#include "graphics/SpriteBatch.hpp"
#include "Vector2.hpp"
#include "content/Sprite.hpp"
#include <iostream>
#include <vector>

namespace neoskye {
namespace graphics {

DrawData::DrawData(content::Sprite& spr, Vector2<usize> pos) : spr(spr), pos(pos) {}

SpriteBatch::SpriteBatch() {}

void SpriteBatch::Submit(content::Sprite& spr, Vector2<usize> pos) {
    DrawData dd(spr, pos);
    this->queue.push_back(dd);
}

std::vector<DrawData>& SpriteBatch::GetDrawData() { return this->queue; }

void SpriteBatch::Flush() { this->queue.clear(); }

} // namespace graphics
} // namespace neoskye
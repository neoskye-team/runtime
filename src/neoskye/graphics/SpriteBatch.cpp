#include "neoskye/graphics/SpriteBatch.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Shape.hpp"
#include "SFML/System/Vector2.hpp"
#include "neoskye/Vector2.hpp"
#include "neoskye/content/Sprite.hpp"
#include <iostream>
#include <vector>

namespace neoskye {
namespace graphics {

SpriteDrawData::SpriteDrawData(content::Sprite::Pointer& spr, Vector2<usize> pos) : spr(spr), pos(pos) {}

SpriteBatch::SpriteBatch() {}

void SpriteBatch::Submit(content::Sprite::Pointer& spr, Vector2<usize> pos) {
    SpriteDrawData dd(spr, pos);
    this->spriteQueue.push_back(dd);
}

std::vector<SpriteDrawData>& SpriteBatch::GetDrawData() { return this->spriteQueue; }

void SpriteBatch::Flush() {
    this->spriteQueue.clear();
    this->shapeQueue.clear();
}

void SpriteBatch::SubmitRect(Vector2<isize> pos, Vector2<usize> size) { sf::Vector2f(pos.x, pos.y); }

} // namespace graphics
} // namespace neoskye
#pragma once

#include "SFML/Graphics/Shape.hpp"

#include "neoskye/Vector2.hpp"
#include "neoskye/content/Sprite.hpp"

#include "util/Types.hpp"
#include <memory>

namespace neoskye {
namespace graphics {

struct SpriteDrawData {
    SpriteDrawData(content::Sprite::Pointer& spr, Vector2<usize> pos);
    content::Sprite::Pointer& spr;
    Vector2<usize> pos;
};

struct ShapeDrawData {
    ShapeDrawData(sf::Shape& s);
    sf::Shape& s;
};

/// <summary>
/// Allows you to draw sprites in one big batch
/// </summary>
class SpriteBatch {
  public:
    /// <summary>
    /// Creates a <see cref="neoskye::graphics::SpriteBatch">SpriteBatch</see>
    /// </summary>
    SpriteBatch();

    /// <summary>
    /// Submits a sprite for drawing
    /// </summary>
    /// <param name="spr">A pointer to the sprite you want to draw</param>
    void Submit(content::Sprite::Pointer& spr, Vector2<usize> pos);

    /// <summary>
    /// Submits a rectangle for drawing
    /// </summary>
    /// <param name="pos">The position of the rectangle</param>
    /// <param name="size">The size of the rectangle</param>
    void SubmitRect(Vector2<isize> pos, Vector2<usize> size);

    /// <summary>
    /// Gets the draw data, is only used internally
    /// </summary>
    /// <returns>A reference to the vector of spritedrawdata</returns>
    std::vector<SpriteDrawData>& GetDrawData();

    /// <summary>
    /// Removes all the draw data
    /// </summary>
    void Flush();

  private:
    std::vector<SpriteDrawData> spriteQueue;
    std::vector<ShapeDrawData> shapeQueue;
};

} // namespace graphics
} // namespace neoskye
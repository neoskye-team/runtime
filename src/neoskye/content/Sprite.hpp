#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace neoskye {
namespace content {

/// <summary>
/// Describes a drawable sprite
/// </summary>
class Sprite {
  public:
    /// <summary>
    /// Loads from a file, you can call this, but it's preferred to use `neoskye::content::ContentLoader::LoadFromFile`
    /// </summary>
    Sprite(const std::string& rootContentFolder, const std::string& path);
    /// <summary>
    /// Loads from memory, you can call this, but it's preferred to use
    /// `neoskye::content::ContentLoader::LoadFromMemory`
    /// </summary>
    Sprite(const void* data, std::size_t size);

    /// <summary>
    /// Creates an empty instance, use `neoskye::content::ContentLoader::LoadFromFile` instead
    /// </summary>
    Sprite();

    /// <summary>
    /// Gives you a const reference to the inner sf::Sprite, use `neoskye::graphics::SpriteBatch::Submit` instead
    /// </summary>
    sf::Sprite& GetData();

  private:
    sf::Texture texture;
    sf::Sprite spr;
};

} // namespace content
} // namespace neoskye

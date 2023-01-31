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
    typedef std::shared_ptr<Sprite> Pointer;

    /// <summary>
    /// Loads from a file, you can call this, but it's preferred to use `neoskye::content::ContentLoader::LoadFromFile`
    /// </summary>
    /// <param name="rootContentFolder">The content folder relative to the folder of the executable</param>
    /// <param name="path">The path to the content, without the <c>.png</c></param>
    /// <returns>A pointer to the content</returns>
    Sprite(const std::string& rootContentFolder, const std::string& path);

    /// <summary>
    /// Loads from memory, you can call this, but it's preferred to use
    /// `neoskye::content::ContentLoader::LoadFromMemory`
    /// </summary>
    /// <param name="data">A void* to the data you want to load</param>
    /// <param name="size">The size of the data you want to load</param>
    /// <returns>A pointer to the content</returns>
    Sprite(const void* data, std::size_t size);

    /// <summary>
    /// Creates an empty instance of a sprite
    /// </summary>
    Sprite();

    /// <summary>
    /// Gives you a reference to the inner sf::Sprite
    /// </summary>
    sf::Sprite& GetData();

  private:
    sf::Texture texture;
    sf::Sprite spr;
};

} // namespace content
} // namespace neoskye

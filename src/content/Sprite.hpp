#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace neoskye::content {

class Sprite {
  public:
    typedef std::shared_ptr<Sprite> Pointer;

    static Pointer LoadFromFile(const std::string& rootContentFolder, const std::string& path);
    static Pointer LoadFromMemory(const void* data, std::size_t size);

    Sprite();

    sf::Sprite& GetData();

  private:
    sf::Texture texture;
    sf::Sprite spr;
};

} // namespace neoskye::content

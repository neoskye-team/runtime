#pragma once

#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace neoskye::content {

class Sprite {
  public:
    static std::shared_ptr<Sprite> LoadFromFile(const std::string& rootContentFolder, const std::string& path);
    static std::shared_ptr<Sprite> LoadFromMemory(const void* data, std::size_t size);
    Sprite();

    void Draw();

  private:
    sf::Texture texture;
};

} // namespace neoskye::content

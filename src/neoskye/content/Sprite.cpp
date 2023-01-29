#include "neoskye/content/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "neoskye/content/Sprite.hpp"
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

namespace fs = std::filesystem;

namespace neoskye {
namespace content {

Sprite::Sprite(const std::string& rootContentFolder, const std::string& path) {
    std::string fullPath = fs::current_path();
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(rootContentFolder);
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(path);
    fullPath = fullPath.append(".png");
    std::cout << "Loading Sprite from " << fullPath << ": ";
    if (!this->texture.loadFromFile(fullPath)) {
        std::cout << "Failed!" << std::endl;
    } else {
        std::cout << "Success!" << std::endl;
    }
    this->spr.setTexture(this->texture);
}

Sprite::Sprite(const void* data, std::size_t size) {
    std::cout << "Loading Sprite from memory: ";
    if (!this->texture.loadFromMemory(data, size)) {
        std::cout << "Failed!" << std::endl;
    } else {
        std::cout << "Success!" << std::endl;
    }
    this->spr.setTexture(this->texture);
}

Sprite::Sprite() {}

sf::Sprite& Sprite::GetData() { return this->spr; }

} // namespace content
} // namespace neoskye
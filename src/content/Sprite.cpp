#include "content/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "Sprite.hpp"
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <memory>

namespace fs = std::filesystem;

namespace neoskye::content {

Sprite::Pointer Sprite::LoadFromFile(const std::string& rootContentFolder, const std::string& path) {
    std::shared_ptr<Sprite> spr(new Sprite());
    std::string fullPath = fs::current_path();
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(rootContentFolder);
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(path);
    fullPath = fullPath.append(".png");
    std::cout << "Loading Sprite from " << fullPath << ": ";
    if (!spr->texture.loadFromFile(fullPath)) {
        std::cout << "Failed!" << std::endl;
        return spr; // this is the user's problem now
    } else {
        std::cout << "Success!" << std::endl;
    }
    spr->spr.setTexture(spr->texture);
    return spr;
}

Sprite::Pointer Sprite::LoadFromMemory(const void* data, std::size_t size) {
    std::shared_ptr<Sprite> spr(new Sprite());
    std::cout << "Loading Sprite from memory: ";
    if (!spr->texture.loadFromMemory(data, size)) {
        std::cout << "Failed!" << std::endl;
        return spr; // this is the user's problem now
    } else {
        std::cout << "Success!" << std::endl;
    }
    spr->spr.setTexture(spr->texture);
    return spr;
}

Sprite::Sprite() {}

sf::Sprite& Sprite::GetData() { return this->spr; }

} // namespace neoskye::content
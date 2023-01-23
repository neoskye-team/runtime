#include "content/Sprite.hpp"
#include "Sprite.hpp"
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <memory>

namespace fs = std::filesystem;

namespace neoskye::content {

std::shared_ptr<Sprite> Sprite::LoadFromFile(const std::string& rootContentFolder, const std::string& path) {
    std::shared_ptr<Sprite> spr(new Sprite());
    std::string fullPath = fs::current_path();
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(rootContentFolder);
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(path);
    fullPath = fullPath.append(".png");
    std::cout << "Loading Sprite from " << fullPath << ": " << std::endl;
    if (!spr->texture.loadFromFile(fullPath)) {
        std::cout << "Failed!" << std::endl;
        return spr; // this is the user's problem now
    } else {
        std::cout << "Success!" << std::endl;
    }
    return spr;
}
std::shared_ptr<Sprite> Sprite::LoadFromMemory(const void* data, std::size_t size) {
    std::shared_ptr<Sprite> spr(new Sprite());
    std::cout << "Loading Sprite from memory: " << std::endl;
    if (!spr->texture.loadFromMemory(data, size)) {
        std::cout << "Failed!" << std::endl;
        return spr; // this is the user's problem now
    } else {
        std::cout << "Success!" << std::endl;
    }
    return spr;
}
} // namespace neoskye::content
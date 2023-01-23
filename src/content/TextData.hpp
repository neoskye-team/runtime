#pragma once

#include <memory>
#include <string>

namespace neoskye::content {

class TextData {
  public:
    TextData();
    static std::shared_ptr<TextData> LoadFromFile(const std::string& rootContentFolder, const std::string& path);
    static std::shared_ptr<TextData> LoadFromMemory(const void* data, std::size_t size);
    const std::string& ToString() const;

  private:
    std::string data;
};

} // namespace neoskye::content
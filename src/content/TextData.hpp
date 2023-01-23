#pragma once

#include <memory>
#include <string>

namespace neoskye::content {

class TextData {
  public:
    typedef std::shared_ptr<TextData> Pointer;

    TextData();
    static Pointer LoadFromFile(const std::string& rootContentFolder, const std::string& path);
    static Pointer LoadFromMemory(const void* data, std::size_t size);
    const std::string& ToString() const;

  private:
    std::string data;
};

} // namespace neoskye::content
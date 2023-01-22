#pragma once

#include <string>

namespace neoskye::content {

class TextData {
  public:
    TextData();
    static TextData LoadFromFile(const std::string& rootContentFolder, const std::string& path);
    static TextData LoadFromMemory(std::string data);
    const std::string& ToString() const;

  private:
    std::string data;
};

} // namespace neoskye::content
#pragma once

#include <memory>
#include <string>

namespace neoskye::content {

// TODO: compression so this isnt just a comptime wrapper for something useless
class ContentLoader {
  public:
    ContentLoader(const std::string& contentRoot);

    template <typename C>
    C LoadFromFile(const std::string& path) {
        return C::LoadFromFile(this->contentRoot, path);
    }

    template <typename C>
    C LoadFromMemory(const void* data, std::size_t size) {
        return C::LoadFromMemory(data, size);
    }

  private:
    std::string contentRoot;
};

typedef std::shared_ptr<ContentLoader> ContentLoaderPtr;

ContentLoaderPtr GetContentLoader(const std::string& contentRoot);

} // namespace neoskye::content
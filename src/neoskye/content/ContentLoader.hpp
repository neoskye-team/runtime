#pragma once

#include <memory>
#include <string>

namespace neoskye {
namespace content {

// TODO: compression so this isnt just a comptime wrapper for something useless
/// <summary>
/// Contentloader, it loads content
/// </summary>
class ContentLoader {
  public:
    /// <summary>
    /// Creates a new contentloader, use `neoskye::content::GetContentLoader` instead
    /// </summary>
    ContentLoader(const std::string& contentRoot);

    /// <summary>
    /// Loads from a file, template the content you want to load
    /// </summary>
    template <typename C>
    typename C::Pointer LoadFromFile(const std::string& path) {
        typename C::Pointer retPtr(new C(this->contentRoot, path));
        return retPtr;
    }

    /// <summary>
    /// Loads from memory, template the content you want to load
    /// </summary>
    template <typename C>
    typename C::Pointer LoadFromMemory(const void* data, std::size_t size) {
        typename C::Pointer retPtr(new C(data, size));
        return retPtr;
    }

  private:
    std::string contentRoot;
};

typedef std::shared_ptr<ContentLoader> ContentLoaderPtr;

/// <summary>
/// Creates a new contentloader
/// </summary>
ContentLoaderPtr GetContentLoader(const std::string& contentRoot);

} // namespace content
} // namespace neoskye
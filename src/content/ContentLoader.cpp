#include "content/CotentLoader.hpp"

namespace neoskye::content {

ContentLoader::ContentLoader(const std::string& rootPath) { this->contentRoot = rootPath; }

ContentLoaderPtr GetContentLoader(const std::string& path) {
    ContentLoaderPtr cl(new ContentLoader(path));
    return cl;
}

} // namespace neoskye::content
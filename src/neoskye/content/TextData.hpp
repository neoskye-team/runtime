#pragma once

#include <memory>
#include <string>

namespace neoskye {
namespace content {

/// <summary>
/// Loads a `.txt` file from the content folder
/// </summary>
class TextData {
  public:
    typedef std::shared_ptr<TextData> Pointer;

    /// <summary>
    /// Creates an empty instance, use `neoskye::content::ContentLoader::LoadFromFile` instead
    /// </summary>
    TextData();
    /// <summary>
    /// Loads from a file, you can call this, but it's preferred to use `neoskye::content::ContentLoader::LoadFromFile`
    /// </summary>
    static Pointer LoadFromFile(const std::string& rootContentFolder, const std::string& path);
    /// <summary>
    /// Loads from memory, you can call this, but it's preferred to use
    /// `neoskye::content::ContentLoader::LoadFromMemory`
    /// </summary>
    static Pointer LoadFromMemory(const void* data, std::size_t size);
    /// <summary>
    /// Gives you a const reference to the inner string data
    /// </summary>
    const std::string& ToString() const;

  private:
    std::string data;
};

} // namespace content
} // namespace neoskye
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
    /// Loads from a file, you can call this, but it's preferred to use
    /// <see cref="neoskye::content::ContentLoader::LoadFromFile">the contentloader</see>
    /// </summary>
    /// <param name="rootContentFolder">The content folder relative to the folder of the executable</param>
    /// <param name="path">The path to the content, without the <c>.txt</c></param>
    /// <returns>A pointer to the content</returns>
    static Pointer LoadFromFile(const std::string& rootContentFolder, const std::string& path);

    /// <summary>
    /// Loads from memory, you can call this, but it's preferred to use
    /// <see cref="neoskye::content::ContentLoader::LoadFromMemory">the contentloader</see>
    /// </summary>
    /// <param name="data">A void* to the data you want to load</param>
    /// <param name="size">The size of the data you want to load</param>
    /// <returns>A pointer to the content</returns>
    static Pointer LoadFromMemory(const void* data, std::size_t size);

    /// <summary>
    /// Gets the inner string data
    /// </summary>
    /// <returns>A const& to the inner string data</returns>
    const std::string& ToString() const;

  private:
    std::string data;
};

} // namespace content
} // namespace neoskye
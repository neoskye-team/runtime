#include "content/TextData.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>

namespace fs = std::filesystem;

namespace neoskye::content {

TextData::TextData() { this->data = ""; }

std::shared_ptr<TextData> TextData::LoadFromFile(const std::string& rootContentFolder, const std::string& path) {
    std::shared_ptr<TextData> td(new TextData());

    std::string fullPath = fs::current_path();
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(rootContentFolder);
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(path);
    fullPath = fullPath.append(".txt");
    std::cout << "Loading TextData from " << fullPath << ": ";
    std::ifstream fs;
    std::stringstream ss;
    fs.open(fullPath);
    if (fs.fail()) {
        std::cout << "Failed!" << std::endl;
        return td; // empty obj
    } else {
        std::cout << "Success!" << std::endl;
    }
    ss << fs.rdbuf();
    fs.close();
    td->data = ss.str();
    return td;
}

std::shared_ptr<TextData> TextData::LoadFromMemory(const void* data, std::size_t size) {
    std::shared_ptr<TextData> td;
    // we interpret the void* as a char*
    const char* charData = (const char*)data;
    std::string intoString(charData, size);
    td->data = intoString;
    return td;
}

const std::string& TextData::ToString() const { return this->data; }

} // namespace neoskye::content
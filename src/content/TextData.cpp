#include "content/TextData.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

namespace neoskye::content {

TextData::TextData() { this->data = ""; }

TextData TextData::LoadFromFile(const std::string& rootContentFolder, const std::string& path) {
    TextData td;
    std::string fullPath = fs::current_path();
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(rootContentFolder);
    fullPath = fullPath.append("/");
    fullPath = fullPath.append(path);
    fullPath = fullPath.append(".txt");
    std::cout << "Loading TextData from " << fullPath << std::endl;
    std::ifstream fs;
    std::stringstream ss;
    fs.open(fullPath);
    ss << fs.rdbuf();
    td.data = ss.str();
    return td;
}

TextData TextData::LoadFromMemory(std::string data) {
    TextData td;
    td.data = data;
    return td;
}

const std::string& TextData::ToString() const { return this->data; }

} // namespace neoskye::content
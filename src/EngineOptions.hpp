#pragma once

#include "util/Types.hpp"

#include <map>
#include <optional>
#include <string>

namespace neoskye {
class EngineOptions {
  public:
    EngineOptions();
    static EngineOptions GenerateOptionsFromArgv(const int argc, const char** argv);
    std::optional<usize> GetUnsignedFlag(const std::string key);
    std::optional<isize> GetSignedFlag(const std::string key);
    std::optional<std::string> GetStringFlag(const std::string key);
    void InsertFlag(const std::string name, const std::string value);

  private:
    // prefix with -[NAME] for user-configurable flag, use [NAME] for code-internal flag
    inline static const char* switchOpts[] = { "-fullscreen" };
    inline static const char* flagOpts[] = { "-width", "-height" };
    std::map<std::string, bool> switches;
    std::map<std::string, std::string> flags;
};
} // namespace neoskye
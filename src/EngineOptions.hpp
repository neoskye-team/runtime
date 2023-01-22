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

    // flag related functions
    std::optional<usize> GetUnsignedFlag(const std::string& key) const;
    std::optional<isize> GetSignedFlag(const std::string& key) const;
    std::optional<std::string> GetStringFlag(const std::string& key) const;
    void InsertFlag(const std::string& name, const std::string& value);
    void InsertFlagIfItDoesntExist(const std::string& name, const std::string& value);

    // switch related functions
    void EnableSwitch(const std::string& name);
    void DisableSwitch(const std::string& name);

  private:
    // prefix with -[NAME] for user-configurable flag
    inline static const char* switchOpts[] = { "-fullscreen" };
    inline static const char* flagOpts[] = { "-width", "-height" };
    std::map<std::string, bool> switches;
    std::map<std::string, std::string> flags;
};

} // namespace neoskye
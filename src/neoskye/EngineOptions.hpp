#pragma once

#include "neoskye/util/Types.hpp"

#include <map>
#include <optional>
#include <string>

namespace neoskye {

/// <summary>
/// Describes a configuration to run the engine on
/// </summary>
class EngineOptions {
  public:
    /// <summary>
    ///  Creates a default config
    /// </summary>
    EngineOptions();
    /// <summary>
    ///  Creates a default config from your `argc` and `argv`
    /// </summary>
    static EngineOptions GenerateOptionsFromArgv(const int argc, const char** argv);

    /// <summary>
    /// Gets a flag, and parses it into a `usize`
    /// </summary>
    std::optional<usize> GetUnsignedFlag(const std::string& key) const;
    /// <summary>
    /// Gets a flag, and parses it into a `isize`
    /// </summary>
    std::optional<isize> GetSignedFlag(const std::string& key) const;
    /// <summary>
    /// Gets a flag
    /// </summary>
    std::optional<std::string> GetStringFlag(const std::string& key) const;
    /// <summary>
    /// Insert a flag, can be used for internal flags (e.g. `title`)
    /// </summary>
    void InsertFlag(const std::string& name, const std::string& value);
    /// <summary>
    /// Insert a flag, if it doesn't exist yet (e.g. `-width`)
    /// </summary>
    void InsertFlagIfItDoesntExist(const std::string& name, const std::string& value);

    // switch related functions
    /// <summary>
    /// Enables a switch, (e.g. `fullscreen`)
    /// </summary>
    void EnableSwitch(const std::string& name);
    /// <summary>
    /// Disables a switch, (e.g. `fullscreen`)
    /// </summary>
    void DisableSwitch(const std::string& name);

  private:
    // prefix with -[NAME] for user-configurable flag
    inline static const char* switchOpts[] = { "-fullscreen" };
    inline static const char* flagOpts[] = { "-width", "-height" };
    std::map<std::string, bool> switches;
    std::map<std::string, std::string> flags;
};

} // namespace neoskye
#pragma once

#include "util/Types.hpp"
#include <map>
#include <optional>
#include <string>

namespace neoskye {

/// <summary>
/// Describes a configuration for the engine to use
/// </summary>
class EngineOptions {
  public:
    /// <summary>
    /// Loads the default config
    /// </summary>
    EngineOptions();

    /// <summary>
    /// Creates a default config from your `argc` and `argv`
    /// </summary>
    /// <param name="argc">The argc you got from your <c>int main</c></param>
    /// <param name="argv">The argv you got from your <c>int main</c></param>
    EngineOptions(const int argc, const char** argv);

    /// <summary>
    /// Gets a flag, and parses it into a `usize`
    /// </summary>
    /// <param name="key">The key of the parameter, e.g. <c>-width</c></param>
    /// <returns>A <c>std::optional</c> containing the usize, if the key was set.</returns>
    std::optional<usize> GetUnsignedFlag(const std::string& key) const;

    /// <summary>
    /// Gets a flag, and parses it into a `isize`
    /// </summary>
    /// <param name="key">The key of the parameter, e.g. <c>-width</c></param>
    /// <returns>A <c>std::optional</c> containing the isize, if the key was set.</returns>
    std::optional<isize> GetSignedFlag(const std::string& key) const;

    /// <summary>
    /// Gets a flag
    /// </summary>
    /// <param name="key">The key of the parameter, e.g. <c>-width</c></param>
    /// <returns>A <c>std::optional</c> containing the value of the key</returns>
    std::optional<std::string> GetStringFlag(const std::string& key) const;

    /// <summary>
    /// Insert a flag, can be used for internal flags (e.g. `title`)
    /// </summary>
    /// <param name="name">The name of the key</param>
    /// <param name="value">The value of the key</param>
    void InsertFlag(const std::string& name, const std::string& value);

    /// <summary>
    /// Insert a flag, if it doesn't exist yet (e.g. `-width`)
    /// </summary>
    /// <param name="name">The name of the key</param>
    /// <param name="value">The value of the key</param>
    void InsertFlagIfItDoesntExist(const std::string& name, const std::string& value);

    /// <summary>
    /// Enables a switch, (e.g. `-fullscreen`)
    /// </summary>
    /// <param name="name">The name of the switch</param>
    void EnableSwitch(const std::string& name);

    /// <summary>
    /// Disables a switch, (e.g. `-fullscreen`)
    /// </summary>
    /// <param name="name">The name of the switch</param>
    void DisableSwitch(const std::string& name);

    /// <summary>
    /// Gets if a switch was toggled
    /// </summary>
    /// <param name="name">The name of the switch</param>
    /// <returns>If the switch was toggled</returns>
    bool GetSwitch(const std::string& name);

    /// <summary>
    /// The title of the window
    /// </summary>
    std::string title;

    /// <summary>
    /// If the engine should run in VSync
    /// </summary>
    bool useVSync;

  private:
    // backing
    inline static const char* switchOpts[] = { "-fullscreen" };
    inline static const char* flagOpts[] = { "-width", "-height" };
    std::map<std::string, bool> switches;
    std::map<std::string, std::string> flags;
};

} // namespace neoskye
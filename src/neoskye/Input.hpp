#pragma once

#include "SFML/Window/Keyboard.hpp"
#include <map>
#include <string>
#include <vector>

// TODO: mouse input, more support for stuff
namespace neoskye {
class Input {
  public:
    /// <summary>
    /// Maps a key to a name, so you can eazily use multiple inputs
    /// </summary>
    /// <param name="str">The name you want to map to</param>
    /// <param name="key">The key you want the name to map to</param>
    static void Map(std::string str, sf::Keyboard::Key key);

    /// <summary>
    /// Returns if a key is down
    /// </summary>
    /// <param name="keyName">The name of your key you set in <see cref="neoskye::Input::Map">here</see></param>
    /// <returns>A bool, true if the key was pressed</returns>
    static bool IsDown(const std::string& keyName);

  private:
    static std::map<std::string, std::vector<sf::Keyboard::Key>> inputMap; // TODO: use custom enum
};
} // namespace neoskye

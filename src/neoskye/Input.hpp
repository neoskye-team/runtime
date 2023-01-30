#pragma once

#include "SFML/Window/Keyboard.hpp"
#include <map>
#include <string>
#include <vector>

// TODO: mouse input, more support for stuff
namespace neoskye {
class Input {
  public:
    static void Map(std::string str, sf::Keyboard::Key key);
    static bool IsDown(const std::string& keyName);

  private:
    static std::map<std::string, std::vector<sf::Keyboard::Key>> inputMap; // TODO: use custom enum
};
} // namespace neoskye

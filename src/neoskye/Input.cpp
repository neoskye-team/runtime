#include "neoskye/Input.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <iostream>

namespace neoskye {

void Input::Map(std::string str, sf::Keyboard::Key key) {
    Input::inputMap[str].push_back(key);
    std::cout << str << " -> " << key << std::endl;
}

bool Input::IsDown(const std::string& keyName) {
    bool pressed = false;
    for (const auto& key : Input::inputMap[keyName]) {
        if (sf::Keyboard::isKeyPressed(key)) {
            pressed = true;
            break;
        }
    }
    return pressed;
}

std::map<std::string, std::vector<sf::Keyboard::Key>> Input::inputMap;

} // namespace neoskye
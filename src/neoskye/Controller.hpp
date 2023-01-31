#pragma once

#include "SFML/System/Lock.hpp"
#include "SFML/Window/Joystick.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <map>
#include <string>
#include <vector>

namespace neoskye {
class Controller {
  public:
    Controller(int controllerNumber)
      :controllerNumber(controllerNumber){};
    static bool connected(int controllerNumber);
    static void NameAxis(std::string axisName, sf::Joystick::Axis axis);
    static void MapButton(std::string buttonName, int button);
    bool buttonPressed(std::string buttonName);
    float axisPosition(std::string axisName);
    std::string getControllerName();

  private:
    int controllerNumber;
    static std::map<std::string, sf::Joystick::Axis> axisMap; // TODO: use custom enum
    static std::map<std::string, std::vector<int>> buttonMap;

};
} // namespace neoskye

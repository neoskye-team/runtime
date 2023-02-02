#pragma once

#include "SFML/System/Lock.hpp"
#include "SFML/Window/Joystick.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <map>
#include <string>
#include <vector>

namespace neoskye {
/// <summary>
/// Describes a controller
/// </summary>
class Controller {
  public:
    /// <summary>
    /// Checks if a controller is connected
    /// </summary>
    /// <param name="controllerNumber">The index of the controller</param>
    static bool Connected(int controllerNumber);

    /// <summary>
    /// Give an analog axis a name
    /// </summary>
    /// <param name="axisName">The name you want to give the axis</param>
    /// <param name="axis">The axis you want to name</param>
    static void NameAxis(std::string axisName, sf::Joystick::Axis axis);

    /// <summary>
    /// Give a button axis a name
    /// </summary>
    /// <param name="axisName">The name you want to give the button</param>
    /// <param name="axis">The button you want to name</param>
    static void MapButton(std::string buttonName, int button);

    /// <summary>
    /// Creates a <see cref="neoskye::Controller">controller</see>
    /// </summary>
    /// <param name="controllerNumber">The index of the controller</param>
    Controller(int controllerNumber) : controllerNumber(controllerNumber){};

    /// <summary>
    /// Checks if a button is pressed
    /// </summary>
    /// <param name="buttonName">The name of the button</param>
    /// <returns>If the button was pressed</returns>
    bool ButtonPressed(std::string buttonName);

    /// <summary>
    /// Gets the tilt of the axis
    /// </summary>
    /// <param name="buttonName">The name of the axis</param>
    /// <returns>How much the axis is tilted</returns>
    float AxisPosition(std::string axisName);

    /// <summary>
    /// Gets the name of the controller
    /// </summary>
    /// <returns>The name of the controller</returns>
    std::string GetControllerName();

  private:
    int controllerNumber;
    static std::map<std::string, sf::Joystick::Axis> axisMap; // TODO: use custom enum
    static std::map<std::string, std::vector<int>> buttonMap;
};
} // namespace neoskye

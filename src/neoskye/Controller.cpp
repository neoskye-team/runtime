#include "neoskye/Controller.hpp"
#include "SFML/Window/Joystick.hpp"
#include <iostream>

namespace neoskye {

bool Controller::connected(int controllerNumber) {
    return sf::Joystick::isConnected(controllerNumber);
}

void Controller::NameAxis(std::string axisName, sf::Joystick::Axis axis){
    Controller::axisMap[axisName] = axis;
};

void Controller::MapButton(std::string buttonName, int button){
    Controller::buttonMap[buttonName].push_back(button);
}

bool Controller::buttonPressed(std::string buttonName){
    bool pressed = false;
    for (const auto& key : Controller::buttonMap[buttonName]) {
        if (sf::Joystick::isButtonPressed(Controller::controllerNumber, key)) {
            pressed = true;
            break;
        }
    }
    return pressed;
}

float Controller::axisPosition(std::string axisName){
    return sf::Joystick::getAxisPosition(Controller::controllerNumber, Controller::axisMap[axisName]);
}

std::string Controller::getControllerName(){
    return sf::Joystick::getIdentification(Controller::controllerNumber).name;
}

std::map<std::string, sf::Joystick::Axis> Controller::axisMap;
std::map<std::string, std::vector<int>> Controller::buttonMap;

} // namespace neoskye
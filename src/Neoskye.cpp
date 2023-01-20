#include "Neoskye.hpp"
#include "SFML/Window/Event.hpp"
#include "util/Types.hpp"
#include <SFML/Window.hpp>

namespace neoskye {
Neoskye::Neoskye() { this->win.create(sf::VideoMode(1280, 720), ""); }

u16 Neoskye::Run() {
    while (this->win.isOpen()) {
        sf::Event event;
        while (this->win.pollEvent(event)) {
            if (this->HandleEvent(event))
                this->win.close();
        }
    }

    return 0;
}

// return true if the window should close
bool Neoskye::HandleEvent(sf::Event& ev) {
    switch (ev.type) {
    case sf::Event::Closed:
        return true;
    default:
        return false;
    }
}

} // namespace neoskye
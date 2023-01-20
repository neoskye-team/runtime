#pragma once

#include "SFML/Window/Event.hpp"
#include "util/Types.hpp"
#include <SFML/Window.hpp>

namespace neoskye {

class Neoskye {
  public:
    Neoskye();
    u16 Run();
    bool HandleEvent(sf::Event& ev);

  private:
    sf::Window win;
};

} // namespace neoskye
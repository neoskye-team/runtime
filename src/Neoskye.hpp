#pragma once

#include "EngineOptions.hpp"
#include "util/Types.hpp"
#include <SFML/Window.hpp>

namespace neoskye {

class Neoskye {
  public:
    Neoskye(EngineOptions& opts);
    u16 Run();
    bool HandleEvent(sf::Event& ev);

  private:
    sf::Window win;
};

} // namespace neoskye
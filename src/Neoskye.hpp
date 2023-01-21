#pragma once

#include "EngineOptions.hpp"
#include "View.hpp"
#include "util/Types.hpp"
#include <SFML/Window.hpp>
#include <memory>

namespace neoskye {

class Neoskye {
  public:
    explicit Neoskye(EngineOptions& opts);
    u16 Run();
    bool HandleEvent(sf::Event& ev);

    // implement here so template specialization works
    template <typename V> void SwitchView() {
        std::shared_ptr<V> view(new V());
        this->view = view;
    }

  private:
    sf::Window win;
    std::shared_ptr<neoskye::View> view;
};

} // namespace neoskye
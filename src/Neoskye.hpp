#pragma once

#include "EngineOptions.hpp"
#include "View.hpp"
#include "graphics/SpriteBatch.hpp"
#include "util/Types.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

namespace neoskye {

/// <summary>
/// The engine, this trickles down to `View`'s
/// </summary>
class Neoskye {
  public:
    /// <summary>
    /// Creates an engine from EngineOptions
    /// </summary>
    explicit Neoskye(const EngineOptions& opts, graphics::SpriteBatch& sprBtch);
    /// <sumarry>
    /// Runs the engine, and returns the engine's exist code
    /// </summary>
    u16 Run();

    // implement here so template specialization works
    /// <summary>
    /// Switches to a new view. syntax: `SwitchView<YourView>()`
    /// </summary>
    template <typename V>
    void SwitchView() {
        std::shared_ptr<View> view(new V());
        this->view = view;
    }

  private:
    bool HandleEvent(const sf::Event& ev);
    sf::RenderWindow win;
    std::shared_ptr<View> view;
    graphics::SpriteBatch& spriteBatch;
};

} // namespace neoskye
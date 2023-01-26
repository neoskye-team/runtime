#pragma once

#include "EngineOptions.hpp"
#include "View.hpp"
#include "graphics/SpriteBatch.hpp"
#include "util/Types.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <memory>
#include <optional>

namespace neoskye {

/// <summary>
/// The engine, this trickles down to `View`'s
/// </summary>
class Neoskye {
  public:
    /// <summary>
    /// Creates an engine from EngineOptions
    /// </summary>
    explicit Neoskye(const EngineOptions& opts);
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
        V view;
        this->view = view;
    }

    void RegisterSpriteBatch(neoskye::graphics::SpriteBatch& sb);

  private:
    bool HandleEvent(const sf::Event& ev);
    sf::RenderWindow win;
    std::optional<View> view;
    std::optional<std::reference_wrapper<graphics::SpriteBatch>> spriteBatch;
};

} // namespace neoskye
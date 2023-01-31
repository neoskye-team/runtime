#pragma once

#include "neoskye/EngineOptions.hpp"
#include "neoskye/View.hpp"
#include "neoskye/graphics/SpriteBatch.hpp"
#include "neoskye/util/Types.hpp"
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
    /// Creates an engine with the specified <see cref="neoskye::EngineOptions">EngineOptions</see>
    /// </summary>
    /// <param name="opts">The <see cref="neoskye::EngineOptions">options for the engine</see></param>
    explicit Neoskye(const EngineOptions& opts);

    /// <summary>
    /// Runs the engine, and returns the engine's exit code
    /// </summary>
    /// <returns>The exit code</returns>
    u16 Run();

    /// <summary>
    /// Switches to a new view. syntax: <c>SwitchView<YourView>()</c>
    /// </summary>
    template <typename V>
    void SwitchView() {
        V view;
        this->view = view;
    }

    /// <summary>
    /// Registers a mutuable reference to your <see cref="neoskye::SpriteBatch">spritebatch</see>
    /// </summary>
    void RegisterSpriteBatch(neoskye::graphics::SpriteBatch& sb);

  private:
    bool HandleEvent(const sf::Event& ev);
    sf::RenderWindow win;
    std::optional<View> view;
    std::optional<std::reference_wrapper<graphics::SpriteBatch>> spriteBatch;
};

} // namespace neoskye
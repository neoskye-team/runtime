#include "Neoskye.hpp"
#include "EngineOptions.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "graphics/SpriteBatch.hpp"
#include "util/Types.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <optional>

// i have lost my c++ template virginity
template <typename T>
inline T UnwrapOptional(const std::optional<T>& optional) {
    if (optional.has_value())
        return optional.value();
    throw "Failed to unwrap optional!"; // todo: add an std::basic_stacktrace to this (c++23 feature)
}

namespace neoskye {

Neoskye::Neoskye(const EngineOptions& opts) {
    auto width = UnwrapOptional(opts.GetUnsignedFlag("-width"));
    auto height = UnwrapOptional(opts.GetUnsignedFlag("-height"));
    auto title = UnwrapOptional(opts.GetStringFlag("title"));
    this->win.create(sf::VideoMode(width, height), title);
}

void Neoskye::RegisterSpriteBatch(neoskye::graphics::SpriteBatch& sb) { this->spriteBatch = sb; }

// TODO: this is kinda messy and i dont like that
u16 Neoskye::Run() {
    while (this->win.isOpen()) {
        sf::Event event;
        while (this->win.pollEvent(event)) {
            if (this->HandleEvent(event))
                this->win.close();
        }
        if (this->view.has_value()) {
            this->view->Update();
            this->view->Draw();
        } else {
            std::cerr << "view is null!" << std::endl;
        }
        if (this->spriteBatch.has_value()) {
            auto& spriteBatch = this->spriteBatch.value().get();
            auto& drawData = spriteBatch.GetDrawData();
            this->win.clear();
            // kinda funny code
            for (auto& draw : drawData) {
                auto& sprite = draw.spr.GetData();
                sprite.setPosition(draw.pos.x, draw.pos.y);
                this->win.draw(sprite);
            }
            spriteBatch.Flush();
            this->win.display();
        } else {
            std::cerr << "view is null!" << std::endl;
        }
    }

    return 0;
}

// return true if the window should close
bool Neoskye::HandleEvent(const sf::Event& ev) {
    switch (ev.type) {
    case sf::Event::Closed:
        return true;
    default:
        return false;
    }
}
} // namespace neoskye
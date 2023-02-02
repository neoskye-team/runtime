#include "neoskye/Neoskye.hpp"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window.hpp"

#include "neoskye/EngineOptions.hpp"
#include "neoskye/content/ContentLoader.hpp"
#include "neoskye/graphics/SpriteBatch.hpp"

#include "util/Types.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <optional>

namespace neoskye {

Neoskye::Neoskye(const EngineOptions& opts) {
    auto width = opts.GetUnsignedFlag("-width").value();
    auto height = opts.GetUnsignedFlag("-height").value();
    auto& title = opts.title;

    this->win.create(sf::VideoMode(width, height), title);
    this->win.setVerticalSyncEnabled(opts.useVSync);
}

void Neoskye::RegisterSpriteBatch(neoskye::graphics::SpriteBatch& sb) { this->spriteBatch = sb; }

void Neoskye::RegisterContentLoader(neoskye::content::ContentLoader& cl) { this->contentLoader = cl; }

std::optional<std::reference_wrapper<graphics::SpriteBatch>> Neoskye::spriteBatch;
std::optional<std::reference_wrapper<content::ContentLoader>> Neoskye::contentLoader;

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
                auto& sprite = draw.spr->GetData();
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

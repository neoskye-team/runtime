#include "neoskye/components/spriterenderer.hpp"

#include "neoskye/Component.hpp"
#include "neoskye/Neoskye.hpp"
#include "neoskye/Vector2.hpp"
#include "neoskye/components/spatial.hpp"
#include "neoskye/content/Sprite.hpp"

#include <iostream>

using neoskye::Neoskye;

namespace neoskye::components {

CSpriteRenderer::CSpriteRenderer() : neoskye::Component() { std::cout << "Mounted CRenderer" << std::endl; }

void CSpriteRenderer::Update(neoskye::Entity& ent) { Component::Update(ent); }

void CSpriteRenderer::Draw(neoskye::Entity& ent) {
    neoskye::Vector2<usize> pos(0, 0);
    // TODO: should probably use references for this
    auto posCmp = ent.GetComponent<CSpatial>();
    if (posCmp.has_value()) {
        auto& posCmpVec = posCmp->get()->GetPos();
        pos.x = posCmpVec.x;
        pos.y = posCmpVec.y;
        Neoskye::spriteBatch->get().Submit(this->spr, pos);
    }
    Component::Draw(ent);
}

void CSpriteRenderer::SetTexture(const std::string& texturePath) {
    this->spr = Neoskye::contentLoader->get().LoadFromFile<neoskye::content::Sprite>(texturePath);
}

} // namespace neoskye::components
#include "neoskye/components/rectrenderer.hpp"

#include "neoskye/Component.hpp"
#include "neoskye/Neoskye.hpp"
#include "neoskye/components/spatial.hpp"

namespace neoskye::components {

CRectRenderer::CRectRenderer() : size(0, 0), pos(0, 0) {}

void CRectRenderer::Update(neoskye::Entity& ent) {
    auto spatialEntOption = ent.GetComponent<CSpatial>();
    if (!spatialEntOption.has_value())
        return;
    auto spatialEnt = spatialEntOption->get();
    this->pos = spatialEnt->GetPos();
    this->size = spatialEnt->GetSize();
    neoskye::Component::Update(ent);
}

void CRectRenderer::Draw(neoskye::Entity& ent) {
    Neoskye::spriteBatch->get().SubmitRect(this->pos, this->size);
    this->neoskye::Component::Draw(ent);
}

} // namespace neoskye::components
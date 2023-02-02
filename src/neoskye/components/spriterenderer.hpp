#pragma once

#include "neoskye/Component.hpp"
#include "neoskye/Entity.hpp" // to satisfy the forward decl in neoskye/Component
#include "neoskye/content/Sprite.hpp"

#include <string>

namespace neoskye::components {

class CSpriteRenderer : public neoskye::Component {
  public:
    CSpriteRenderer();
    void Update(neoskye::Entity& ent);
    void Draw(neoskye::Entity& ent);

    void SetTexture(const std::string& texturePath);

  private:
    neoskye::content::Sprite::Pointer spr;
};

} // namespace neoskye::components
#pragma once

#include "neoskye/Component.hpp"
#include "neoskye/Entity.hpp" // to satisfy the forward decl in neoskye/Component
#include "neoskye/Vector2.hpp"
#include "neoskye/content/Sprite.hpp"

#include "util/Types.hpp"
#include <string>

namespace neoskye::components {

class CRectRenderer : public neoskye::Component {
  public:
    CRectRenderer();
    void Update(neoskye::Entity& ent);
    void Draw(neoskye::Entity& ent);

  private:
    neoskye::Vector2<isize> pos;
    neoskye::Vector2<usize> size;
};

} // namespace neoskye::components
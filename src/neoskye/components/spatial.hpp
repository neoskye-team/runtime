#pragma once

#include "neoskye/Component.hpp"
#include "neoskye/Vector2.hpp"

#include "util/Types.hpp"

namespace neoskye::components {

class CSpatial : public neoskye::Component {
  public:
    CSpatial();
    void Update(neoskye::Entity& ent);
    void Draw(neoskye::Entity& ent);
    neoskye::Vector2<isize>& GetPos();
    neoskye::Vector2<usize>& GetSize();

  private:
    neoskye::Vector2<isize> pos;
    neoskye::Vector2<usize> size;
};

} // namespace neoskye::components
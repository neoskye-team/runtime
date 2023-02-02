#pragma once

#include "nsphysics/PhysicsObject.hpp"

#include <functional>
#include <vector>

namespace nsphysics {

class World {
  public:
    World();
    void Add(PhysicsObject& obj);
    void Tick();

  private:
    std::vector<std::reference_wrapper<PhysicsObject>> objects;
    float gravity;          // how fast something falls in units/tick
    float terminalVelocity; // maximum speed
};
} // namespace nsphysics
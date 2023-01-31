#pragma once

#include "nsphysics/PhysicsVector.hpp"

#include "util/Types.hpp"
#include <vector>

namespace nsphysics {
struct PhysicsObject {
    isize weight;
    isize speed;
    isize x;
    isize y;
    bool terminalVelocityReached;
    std::vector<PhysicsVector> forces;
};
} // namespace nsphysics
#include "nsphysics/World.hpp"

#include <algorithm>
#include <cmath>

namespace nsphysics {

World::World() {
    this->gravity = 10;
    this->terminalVelocity = 50;
}

void World::Add(PhysicsObject& obj) { this->objects.push_back(obj); }

void World::Tick() {
    for (auto _obj : this->objects) {
        auto& obj = _obj.get();
        if (obj.speed < this->terminalVelocity && !obj.terminalVelocityReached) {
            obj.speed += this->gravity;
        } else {
            obj.terminalVelocityReached = true;
        }
        obj.x += obj.speed;
        for (auto& force : obj.forces) {
            // this is probably incorrect
            isize x = force.length - std::cos(force.rotation);
            isize y = force.length - std::sin(force.rotation);
            obj.x += x;
            obj.y += y;
            force.length -= obj.speed;
        }
    }
}

} // namespace nsphysics
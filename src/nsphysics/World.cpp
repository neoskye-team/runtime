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
            // Calculate the horizontal and vertical change (i have never studied trigonometry)

            // how much length to travel
            auto length = force.length;
            auto y = length * std::sin(force.rotation);
            auto x = std::sqrt((y * y) + (length * length));
            obj.x += x;
            obj.y += y;
        }
    }
}

} // namespace nsphysics
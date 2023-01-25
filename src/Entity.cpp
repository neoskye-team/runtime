#include "Entity.hpp"
#include <iostream>

namespace neoskye {

Entity::Entity() {}

void Entity::Update() {
    for (auto& component : this->components)
        component.second.Update();
}
void Entity::Draw() {
    for (auto& component : this->components)
        component.second.Update();
}

} // namespace neoskye
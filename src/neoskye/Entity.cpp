#include "neoskye/Entity.hpp"
#include <iostream>

namespace neoskye {

Entity::Entity() {}

void Entity::Update() {
    for (auto& component : this->components)
        component.second->Update(*this);
}
void Entity::Draw() {
    for (auto& component : this->components)
        component.second->Draw(*this);
}

} // namespace neoskye
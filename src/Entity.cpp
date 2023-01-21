#include "Entity.hpp"
#include <iostream>

namespace neoskye {

Entity::Entity() { std::cout << "neoskye::Entity ctor"; }

void Entity::Update() {}
void Entity::Draw() {}

} // namespace neoskye
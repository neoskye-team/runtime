#include "neoskye/components/spatial.hpp"

#include "neoskye/Component.hpp"
#include "neoskye/Vector2.hpp"

#include <iostream>

namespace neoskye::components {

CSpatial::CSpatial() : neoskye::Component(), pos(0, 0), size(0, 0) { std::cout << "Mounted CPosition" << std::endl; }

void CSpatial::Update(neoskye::Entity& ent) { Component::Update(ent); }
void CSpatial::Draw(neoskye::Entity& ent) { Component::Draw(ent); }

neoskye::Vector2<isize>& CSpatial::GetPos() { return this->pos; }
neoskye::Vector2<usize>& CSpatial::GetSize() { return this->size; }

} // namespace neoskye::components
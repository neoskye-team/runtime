#include "View.hpp"
#include "Entity.hpp"
#include <iostream>
#include <memory>
#include <tuple>
#include <typeinfo>

namespace neoskye {

View::View() {}

template <class E>
void View::RemoveEntity(const std::string& name) {}

template <class E>
E View::GetEntity(const std::string& name) {}

void View::Update() {
    for (const auto& entity : this->entities)
        entity.second->Update();
}

void View::Draw() {
    for (const auto& entity : this->entities)
        entity.second->Draw();
}

} // namespace neoskye
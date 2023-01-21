#include "View.hpp"
#include "Entity.hpp"
#include <iostream>
#include <memory>
#include <tuple>
#include <typeinfo>

namespace neoskye {

View::View() { std::cout << "View ctor" << std::endl; }

template <class E> void View::AddEntity(const std::string& name) {
    const auto typeName = typeid(E).name();
    // E* here will be casted to Entity* so we can dynamically store them in our map
    const std::shared_ptr<Entity> ent = new E();
    this->entities[std::make_tuple(typeName, name)] = ent;
}
template <class E> void View::RemoveEntity(const std::string& name) {}
template <class E> E View::GetEntity(const std::string& name) {}

void View::Update() {
    for (const auto& entity : this->entities)
        entity.second->Update();
}

void View::Draw() {
    for (const auto& entity : this->entities)
        entity.second->Draw();
}

} // namespace neoskye
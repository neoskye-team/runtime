#pragma once

#include "Entity.hpp"
#include <map>
#include <memory>
#include <string>
#include <tuple>

namespace neoskye {
class View {
  public:
    View();

    template <class E> void AddEntity(const std::string& name) {
        const auto typeName = typeid(E).name();
        // E* here will be casted to Entity* so we can dynamically store them in our map
        const std::shared_ptr<Entity> ent(new E());
        this->entities[std::make_tuple(typeName, name)] = ent;
    }

    template <class E> void RemoveEntity(const std::string& name);
    template <class E> E GetEntity(const std::string& name);

    virtual void Update();
    virtual void Draw();

  private:
    std::map<std::tuple<std::string, std::string>, std::shared_ptr<Entity>> entities;
};
} // namespace neoskye
#pragma once

#include "neoskye/Entity.hpp"
#include <map>
#include <memory>
#include <string>
#include <tuple>

namespace neoskye {

/// <summary>
/// A scene, this trickles down to `Entities`'s
/// </summary>
class View {
  public:
    /// <summary>
    /// Base view constructor, you should never call this in game
    /// </summary>
    View();

    /// <summary>
    /// Add an entity with a name, syntax: `AddEntity<YourEntity>("player")`
    /// </summary>
    template <class E>
    void AddEntity(const std::string& name) {
        const auto typeName = typeid(E).name();
        // E* here will be casted to Entity* so we can dynamically store them in our map
        const std::shared_ptr<Entity> ent(new E());
        this->entities[std::make_tuple(typeName, name)] = ent;
    }

    /// <summary>
    /// Add an entity with a name, syntax: `RemoveEntity<YourEntity>("player")`
    /// </summary>
    template <class E>
    void RemoveEntity(const std::string& name);

    /// <summary>
    /// Add an entity with a name, syntax: `GetEntity<YourEntity>("player")`
    /// </summary>
    template <class E>
    E GetEntity(const std::string& name);

    /// <summary>
    /// Updates all entitites
    /// </summary>
    virtual void Update();
    /// <summary>
    /// Draw all entitites
    /// </summary>
    virtual void Draw();

    virtual ~View();

  private:
    std::map<std::tuple<std::string, std::string>, std::shared_ptr<Entity>> entities;
};
} // namespace neoskye
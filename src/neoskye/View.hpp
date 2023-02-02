#pragma once

#include "neoskye/Entity.hpp"
#include <map>
#include <memory>
#include <string>
#include <tuple>

namespace neoskye {

/// <summary>
/// A scene with global data (for this view), contains <see cref="neoskye::Entity">Entity</see>s
/// </summary>
class View {
  public:
    /// <summary>
    /// Base view constructor
    /// </summary>
    /// <remarks>
    /// This function should be overridden by your view
    /// </remarks>
    View();

    /// <summary>
    /// Add an entity with a name, syntax: `AddEntity<YourEntity>("player")`
    /// </summary>
    /// <remarks>
    /// Entities are keyed using their type and name, so you can have 2 diffrent entities with the same name, aslong
    /// they have diffrent types
    /// </remarks>
    /// <param name="name">The name of your entity</param>
    template <class E>
    void AddEntity(const std::string& name) {
        const auto typeName = typeid(E).name();
        // E* here will be casted to Entity* so we can dynamically store them in our map
        const std::shared_ptr<Entity> ent(new E());
        this->entities[std::make_tuple(typeName, name)] = ent;
    }
    /// <summary>
    ///  Add an entity with a name, syntax: <s>GetEntity<YourEntity>("player")</c>
    /// </summary>
    /// <remarks>
    /// Entities are keyed using their type and name, so you can have 2 diffrent entities with the same name, aslong
    /// they have diffrent types
    /// </remarks>
    /// <param name="name">The name of your entity</param>

    template <class E>
    void RemoveEntity(const std::string& name);

    /// <summary>
    /// Add an entity with a name, syntax: <s>GetEntity<YourEntity>("player")</c>
    /// </summary>
    /// <remarks>
    /// Entities are keyed using their type and name, so you can have 2 diffrent entities with the same name, aslong
    /// they have diffrent types
    /// </remarks>
    /// <param name="name">The name of your entity</param>
    /// <returns>A <c>std::shared_ptr</c> to your entity</returns>
    template <class E>
    E GetEntity(const std::string& name);

    /// <summary>
    /// Updates all entitites in this view
    /// </summary>
    /// <remarks>
    /// This function should be overridden by your view
    /// </remarks>
    virtual void Update();
    /// <summary>
    /// Draw all entitites in this view
    /// </summary>
    /// <remarks>
    /// This function should be overridden by your view
    /// </remarks>
    virtual void Draw();

    virtual ~View();

  private:
    std::map<std::tuple<std::string, std::string>, std::shared_ptr<Entity>> entities;
};
} // namespace neoskye
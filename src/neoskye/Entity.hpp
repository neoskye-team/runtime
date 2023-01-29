#pragma once

#include "neoskye/Component.hpp"
#include <map>
#include <memory>
#include <string>
#include <tuple>
#include <typeinfo>

namespace neoskye {
/// <summary>
/// An entity, this trickles down to `Components`
/// </summary>
class Entity {
  public:
    /// <summary>
    /// Base enemy constructor, makes sure all the base items are properly initialized
    /// </summary>
    Entity();
    /// <summary>
    /// Updates this `Entity`s components
    /// </summary>
    virtual void Update();
    /// <summary>
    /// Updates this `Entity`s components
    /// </summary>
    virtual void Draw();

    /// <summary>
    /// Adds a component to this entity
    /// </summary>
    template <typename C>
    void MountComponent() {
        C component{};
        this->components.insert({ typeid(C).name(), component });
    }

    template <typename C>
    void RemoveComponent() {
        this->components.erase(typeid(C).name());
    }

    template <typename C>
    C& GetComponent() {
        return dynamic_cast<C&>(this->components[typeid(C).name()]);
    }

  private:
    std::map<std::string, Component> components;
};
} // namespace neoskye

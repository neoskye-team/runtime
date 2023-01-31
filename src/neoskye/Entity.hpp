#pragma once

#include "neoskye/Component.hpp"
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <typeinfo>

namespace neoskye {
/// <summary>
/// An entity, this trickles down to <see cref="neoskye::Component">Components</see>
/// </summary>
class Entity {
  public:
    /// <summary>
    /// Base enemy constructor, makes sure all the base items are properly initialized
    /// </summary>
    Entity();
    /// <summary>
    /// Updates this <see cref="neoskye::Entity">entity</see>'s components
    /// </summary>
    virtual void Update();
    /// <summary>
    /// Updates this <see cref="neoskye::Entity">entity</see>'s components
    /// </summary>
    virtual void Draw();

    /// <summary>
    /// Adds a component to this entity
    /// Syntax: <c>this->MountComponent<demogame::CMovement>();</c>
    /// </summary>
    /// <remarks>
    /// Template parameter C - the component
    /// </remarks>
    template <typename C>
    void MountComponent() {
        if (this->components.count(typeid(C).name())) {
            std::cerr << "Tried to mount a component that was already mounted!" << std::endl;
        }
        std::shared_ptr<C> ptr(new C());
        this->components.insert({ typeid(C).name(), ptr });
    }

    /// <summary>
    /// Removes a component from this <see cref="neoskye::Entity">entity</see>
    /// Syntax: <c>this->RemoveComponent<demogame::CMovement>();</c>
    /// </summary>
    /// <remarks>
    /// Template parameter C - the component
    /// </remarks>
    template <typename C>
    void RemoveComponent() {
        this->components.erase(typeid(C).name());
    }

    /// <summary>
    /// Removes a component from this <see cref="neoskye::Entity">entity</see>
    /// Syntax: <c>this->GetComponent<demogame::CMovement>();</c>
    /// </summary>
    /// <remarks>
    /// Template parameter C - the component
    /// </remarks>
    /// <returns>A std::shared_ptr wrapped in a std::optional, the optional is empty if the component doesn't
    /// exist</returns>
    template <typename C>
    std::optional<std::shared_ptr<C>> GetComponent() {
        std::optional<std::shared_ptr<C>> retVal;
        if (this->components.count(typeid(C).name()) == 0) {
            return retVal;
        }
        auto balls = std::dynamic_pointer_cast<C>(this->components[typeid(C).name()]);
        retVal = std::optional<std::shared_ptr<C>>(balls);
        return retVal;
    }

  private:
    std::map<std::string, std::shared_ptr<Component>> components;
};
} // namespace neoskye

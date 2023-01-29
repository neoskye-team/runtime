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
        if (this->components.count(typeid(C).name())) {
            std::cerr << "Tried to mount a component that was already mounted!" << std::endl;
        }
        std::shared_ptr<C> ptr(new C());
        this->components.insert({ typeid(C).name(), ptr });
    }

    template <typename C>
    void RemoveComponent() {
        this->components.erase(typeid(C).name());
    }

    // this is kinda shit rn
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

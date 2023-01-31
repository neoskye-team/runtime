#pragma once

namespace neoskye {

class Entity; // neoskye/Entity.hpp

/// <summary>
/// Describes a component, contains most of the logic that makes the entity do stuff
/// </summary>
class Component {
  public:
    /// <summary>
    /// The base constructor of the component
    /// </summary>
    Component() {}

    /// <summary>
    /// Overridable function for the update logic in a component
    /// </summary>
    virtual void Update(neoskye::Entity& ent) {}

    /// <summary>
    /// Overridable function for the graphics logic in a component
    /// </summary>
    virtual void Draw(neoskye::Entity& ent) {}

  private:
    // ...
};

} // namespace neoskye
#pragma once

namespace neoskye {

class Entity; // neoskye/Entity.hpp

// this needs some extra functionality added
/// <summary>
/// Describes a component, contains most of the logic that makes the engine run
/// </summary>
class Component {
  public:
    Component() {}

    // TODO: pass the entity the component is mounted on here
    virtual void Update(neoskye::Entity& ent) {}
    virtual void Draw(neoskye::Entity& ent) {}

  private:
    // ...
};

} // namespace neoskye
#pragma once

namespace neoskye {

/// <summary>
/// Describes a component, contains most of the logic that makes the engine run
/// </summary>
class Component {
  public:
    Component();

    // TODO: pass the entity the component is mounted on here
    virtual void Update();
    virtual void Draw();

  private:
    // ...
};

} // namespace neoskye
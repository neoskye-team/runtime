#pragma once

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
    /// unimplemented virtual function, should never be called
    /// </summary>
    virtual void Update();
    /// <summary>
    /// unimplemented virtual function, should never be called
    /// </summary>
    virtual void Draw();

  private:
    // std::map<std::string, Component> components;
};
} // namespace neoskye

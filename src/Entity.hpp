#pragma once

namespace neoskye {
class Entity {
  public:
    Entity();
    virtual void Update();
    virtual void Draw();

  private:
    // std::map<std::string, Component> components;
};
} // namespace neoskye

#pragma once

namespace neoskye {

class Vector2 {
  public:
    Vector2(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double x;
    double y;
  
    Vector2 operator+(Vector2 const& other);
    Vector2 operator-(Vector2 const& other);
    Vector2 operator*(Vector2 const& other);
    Vector2 operator/(Vector2 const& other);
    double mag();
    void normalize();
};

} // namespace neoskye

#include "Vector2.hpp"
#include <cmath>

namespace neoskye {

Vector2 Vector2::operator+(Vector2 const& other) {
  return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(Vector2 const& other) {
  return Vector2(this->x - other.x, this->y - other.y);
}
  
Vector2 Vector2::operator*(Vector2 const& other) {
  return Vector2(this->x * other.x, this->y * other.y);
}
  
Vector2 Vector2::operator/(Vector2 const& other) { // if we're dividing by zero blame the user 😎
  return Vector2(this->x / other.x, this->y / other.y);
}
  
T Vector2::mag() {
  return sqrt(this->x*this->x + this->y*this->y);
}
  
void Vector2::normalize() {
  T magnitude = this->mag();
  
  this->x = this->x / magnitude;
  this->y = this->y / magnitude;
}
  
} // namespace neoskye

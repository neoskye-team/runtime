#include "neoskye/Vector2.hpp"
#include <cmath>

namespace neoskye {

// TODO move all these to the header or a `.tcc` file

template <typename T>
Vector2<T> Vector2<T>::operator+(Vector2 const& other) {
    return Vector2(this->x + other.x, this->y + other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(Vector2 const& other) {
    return Vector2(this->x - other.x, this->y - other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(Vector2 const& other) {
    return Vector2(this->x * other.x, this->y * other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator/(Vector2 const& other) {
    return Vector2(this->x / other.x, this->y / other.y); // if we're dividing by zero blame the user 😎
}

template <typename T>
T Vector2<T>::Mag() {
    return sqrt(this->x * this->x + this->y * this->y);
}

template <typename T>
void Vector2<T>::Normalize() {
    T magnitude = this->mag();

    this->x = this->x / magnitude;
    this->y = this->y / magnitude;
}

} // namespace neoskye

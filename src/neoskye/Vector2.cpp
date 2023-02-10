#include "neoskye/Vector2.hpp"
#include "../util/Functions.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

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
    
template <typename T>
Vector2<T> Vector2<T>::Abs() {
    return Vector2(abs(this->x), abs(this->y));
}
    
template <typename T>
float Vector2<T>::Angle() { // in radians
    return atan2(this->y, this->x);
}
    
template <typename T>    
float Vector2<T>::Cross(const Vector2 b) {
    return this->x * b.y - y * b.x;
}
   
    
template <typename T>
float Vector2<T>::Dot(const Vector2 with) {
    return this->x * with.x + this->y * with.y;
}
    
template <typename T>
float Vector2<T>::AngleTo(const Vector2 to) { // in radians
    return atan2(this->Cross(to), this->Dot(to));
}
    
template <typename T>
float Vector2<T>::AngleToPoint(const Vector2 to) {
    return atan2(this->y - to.y, this->x - to.x);
}
    
template <typename T>
float Vector2<T>::Aspect() {
    return this->x / this->y;
}
    
template <typename T>
Vector2<T> Vector2<T>::Inverse() {
    return Vector2(1 / this->x, 1 / this->y);
}
    
template <typename T>
Vector2<T> Vector2<T>::Perpendicular() {
    return Vector2(this->y, this->x);
}

template <typename T>
float Vector2<T>::Length() {
    return sqrt(this->x * this->x + this->y * this->y);
}
    
template <typename T>
float Vector2<T>::LengthSquared() {
    float l = this->Length();
    return l * l;
}

template <typename T>
Vector2<T> Vector2<T>::LinearInterpolate(const Vector2 to, float weight) {
    float lerpedX = util::lerp(this->x, to.x, weight);
    float lerpedY = util::lerp(this->y, to.y, weight);
    return Vector2(lerpedX, lerpedY);
}
    
template <typename T>
Vector2<T> Vector2<T>::Random(float mv) {
    srand((unsigned int)time(NULL));
    float x = (float(rand())/float((RAND_MAX)) * mv);
    float y = (float(rand())/float((RAND_MAX)) * mv);
    return Vector2(x, y);
}
    
} // namespace neoskye

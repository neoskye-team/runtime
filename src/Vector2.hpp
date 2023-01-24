#pragma once

namespace neoskye {

/// <summary>
/// A Vector2, this wraps a `T[2]`
/// </summary>
template <typename T>
class Vector2 {
  public:
    /// <summary>
    /// Creates a Vector2, no default constructor will be implemented
    /// </summary>
    Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }

    /// <summary>
    /// The x component of the vector
    /// </summary>
    T x;
    /// <summary>
    /// The Y component of the vector
    /// </summary>
    T y;

    /// <summary>
    /// Adds another vector to this vector
    /// </summary>
    Vector2 operator+(Vector2 const& other);
    /// <summary>
    /// Subtract another vector from this vector
    /// </summary>
    Vector2 operator-(Vector2 const& other);
    /// <summary>
    /// Multiply another vector with this vector
    /// </summary>
    Vector2 operator*(Vector2 const& other);
    /// <summary>
    /// Divide another vector with this vector
    /// </summary>
    Vector2 operator/(Vector2 const& other);
    /// <summary>
    /// Runs the pythagoras theorem on this vector
    /// </summary>
    T Mag();

    /// <summary>
    /// Normalize this vector
    /// </summary>
    void Normalize();
};

} // namespace neoskye

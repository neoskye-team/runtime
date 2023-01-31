#pragma once

namespace neoskye {

/// <summary>
/// A Vector2, contains 2 values of type <c>T</c>
/// </summary>
template <typename T>
class Vector2 {
  public:
    /// <summary>
    /// Creates a Vector2 from 2 values
    /// </summary>
    /// <returns>The created Vector2</returns>
    /// <param name="x">The X component of the vector</param>
    /// <param name="y">The Y component of the vector</param>
    Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }

    /// <summary>
    /// The X component of the vector
    /// </summary>
    T x;

    /// <summary>
    /// The Y component of the vector
    /// </summary>
    T y;

    /// <summary>
    /// Adds another vector to this vector
    /// </summary>
    /// <param name="other">The right hand size of the operation</param>
    Vector2 operator+(Vector2 const& other);

    /// <summary>
    /// Subtract another vector from this vector
    /// </summary>
    /// <param name="other">The right hand size of the operation</param>
    Vector2 operator-(Vector2 const& other);
    /// <summary>
    /// Multiply another vector with this vector
    /// </summary>
    /// <param name="other">The right hand size of the operation</param>
    Vector2 operator*(Vector2 const& other);

    /// <summary>
    /// Divide another vector with this vector
    /// </summary>
    /// <param name="other">The right hand size of the operation</param>
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

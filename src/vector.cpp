#include "vector.hpp"

#include <cmath>

// class functions implementation

double Vector::length() const { return sqrt(_x * _x + _y * _y + _z * _z); }

Vector Vector::normalize()
{
    const double vector_length = length();
    return Vector(_x / vector_length, _y / vector_length, _z / vector_length);
}

// friend functions implementation

Vector operator+(const Vector &u, const Vector &v) { return Vector(u._x + v._x, u._y + v._y, u._z + v._z); }
Vector operator-(const Vector &u, const Vector &v) { return Vector(u._x - v._x, u._y - v._y, u._z - v._z); }
Vector operator*(double scalar, const Vector &v) { return Vector(scalar * v._x, scalar * v._y, scalar * v._z); }
Vector operator/(const Vector &v, double scalar) { return Vector(v._x / scalar, v._y / scalar, v._z / scalar); }

// static class functions implementation

double Vector::dot(const Vector &v1, const Vector &v2) { return v1._x * v2._x + v1._y * v2._y + v1._z * v2._z; }

Vector Vector::cross(const Vector &u, const Vector &v)
{
    return Vector(
        u._y * v._z - u._z * v._y,
        u._z * v._x - u._x * v._z,
        u._x * v._y - u._y * v._x);
}
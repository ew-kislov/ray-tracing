#include "vector.hpp"

// friend functions

Vector operator+(const Vector &u, const Vector &v) { return Vector(u.x + v.x, u.y + v.y, u.z + v.z); }
Vector operator-(const Vector &u, const Vector &v) { return Vector(u.x - v.x, u.y - v.y, u.z - v.z); }
Vector operator*(double scalar, const Vector &v) { return Vector(scalar * v.x, scalar * v.y, scalar * v.z); }
Vector operator/(const Vector &v, double scalar) { return Vector(v.x / scalar, v.y / scalar, v.z / scalar); }

// static class function implementations

double Vector::dot(const Vector &v1, const Vector &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
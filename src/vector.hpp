#pragma once

class Vector
{
public:
    Vector(double x, double y, double z) : _x(x), _y(y), _z(z) {}
    Vector() : _x(0.0), _y(0.0), _z(0.0) {}

    double x() { return _x; }
    double y() { return _y; }
    double z() { return _z; }

    double length() const;
    Vector normalize();

    friend Vector operator/(const Vector &v, double scalar);
    friend Vector operator+(const Vector &u, const Vector &v);
    friend Vector operator-(const Vector &u, const Vector &v);
    friend Vector operator*(double scalar, const Vector &v);

    static double dot(const Vector &v1, const Vector &v2);
    static Vector cross(const Vector &v1, const Vector &v2);

private:
    double _x;
    double _y;
    double _z;
};

#pragma once

class Vector
{
public:
    Vector(double m_x, double m_y, double m_z) : x(m_x), y(m_y), z(m_z) {}

    friend Vector operator/(const Vector &v, double scalar);
    friend Vector operator+(const Vector &u, const Vector &v);
    friend Vector operator-(const Vector &u, const Vector &v);
    friend Vector operator*(double scalar, const Vector &v);

    static double dot(const Vector &v1, const Vector &v2);

private:
    double x;
    double y;
    double z;
};

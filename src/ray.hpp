#pragma once

#include "vector.hpp"

class Ray
{
private:
    Vector _origin;
    Vector _direction;

public:
    Ray(Vector origin, Vector direction) : _origin(origin), _direction(direction){};

    const Vector &origin() const { return _origin; }
    const Vector &direction() const { return _direction; }
};

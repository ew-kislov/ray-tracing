#pragma once

#include "vector.hpp"

class Material
{
public:
    Material(Vector color) : _color(color) {}

    const Vector &color() const { return _color; }

private:
    Vector _color;
};

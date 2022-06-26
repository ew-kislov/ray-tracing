#pragma once

#include "vector.hpp"
#include "hittable.hpp"

class Sphere : public Hittable
{
private:
    Vector _center;
    double _radius;

public:
    Sphere(Vector center, double radius) : _center(center), _radius(radius){};

    virtual bool hits(const Ray &ray) const;
};

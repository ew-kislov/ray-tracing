#pragma once

#include "vector.hpp"
#include "i_world_object.hpp"
#include "material.hpp"

class Sphere : public IWorldObject
{
public:
    Sphere(Vector center, double radius, const Material &material)
        : _center(center), _radius(radius), IWorldObject(material){};

    virtual bool hits(const Ray &ray) const;

private:
    Vector _center;
    double _radius;
};

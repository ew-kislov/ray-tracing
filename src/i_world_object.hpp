#pragma once

#include "ray.hpp"
#include "material.hpp"

class IWorldObject
{
public:
    IWorldObject(const Material &material) : _material(material){};

    const Material &get_material() const { return _material; }

    virtual bool hits(const Ray &ray) const = 0;

private:
    Material _material;
};

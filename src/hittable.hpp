#pragma once

#include "ray.hpp"

class Hittable
{
public:
    virtual bool hits(const Ray &ray) const = 0;
};

#pragma once

#include "vector.hpp"
#include "ray.hpp"

class Camera
{
public:
    Camera(
        const Vector &look_from,
        const Vector &look_at,
        const Vector &vup, // stub up(z axis) vector
        double vfov,       // vertical field-of-view in degrees
        double aspect_ratio);

    Ray get_ray(double s, double t) const;

private:
    Vector _origin;
    Vector _lower_left_corner;
    Vector _x_axis;
    Vector _y_axis;
};
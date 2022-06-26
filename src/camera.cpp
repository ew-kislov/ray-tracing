#include "camera.hpp"

#include "math.hpp"

Camera::Camera(
    const Vector &look_from,
    const Vector &look_at,
    const Vector &vup,
    double vfov,
    double aspect_ratio)
{
    auto theta = Math::degrees_to_radians(vfov);
    auto h = Math::tan(theta / 2);
    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect_ratio * viewport_height;

    auto w = (look_from - look_at).normalize();
    auto u = (Vector::cross(vup, w)).normalize();
    auto v = Vector::cross(w, u); // no need to normalize as cross product of 2 unit vectors gives unit vector

    _origin = look_from;
    _x_axis = viewport_width * u;
    _y_axis = viewport_height * v;
    _lower_left_corner = _origin - _x_axis / 2 - _y_axis / 2 - w;
}

Ray Camera::get_ray(double s, double t) const
{
    return Ray(_origin, _lower_left_corner + s * _x_axis + t * _y_axis - _origin);
}
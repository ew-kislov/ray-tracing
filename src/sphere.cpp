#include "sphere.hpp"

bool Sphere::hits(const Ray &ray) const
{
    Vector oc = ray.origin() - _center;
    double a = Vector::dot(ray.direction(), ray.direction());
    auto b = 2.0 * Vector::dot(oc, ray.direction());
    auto c = Vector::dot(oc, oc) - _radius * _radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

#include <stdio.h>
#include <iostream>
#include <cmath>

#include "vector.hpp"

bool hit_sphere(const Vector &origin, const Vector &direction, const Vector &center, double radius)
{
    Vector oc = origin - center;
    auto a = Vector::dot(direction, direction);
    auto b = 2.0 * Vector::dot(oc, direction);
    auto c = Vector::dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

int main()
{
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    Vector origin = Vector(0, 0, 0);
    Vector horizontal = Vector(viewport_width, 0, 0);
    Vector vertical = Vector(0, viewport_height, 0);
    Vector lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vector(0, 0, focal_length);

    //

    FILE *f = fopen("image.ppm", "w");
    fprintf(f, "P3\n%d %d\n%d\n", image_width, image_height, 255);

    //

    const Vector sphere_pos = Vector(0.0, 0.0, -1.0);
    const float sphere_radius = 0.5;

    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; i++)
        {
            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);
            Vector direction = Vector(lower_left_corner + u * horizontal + v * vertical - origin);

            if (hit_sphere(origin, direction, sphere_pos, sphere_radius))
            {
                fprintf(f, "%d %d %d ", 255, 255, 255);
            }
            else
            {
                fprintf(f, "%d %d %d ", 0, 0, 0);
            }
        }
        fprintf(f, "\n");
    }
}
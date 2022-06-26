#include <stdio.h>
#include <vector>
#include <cmath>

#include "vector.hpp"
#include "ray.hpp"
#include "i_world_object.hpp"
#include "sphere.hpp"
#include "camera.hpp"

Vector get_color_at(const Ray &ray, const std::vector<IWorldObject *> &world)
{
    Vector base_color(0.0, 0.0, 0.0);

    for (const auto object : world)
    {
        if (object->hits(ray))
        {
            return object->get_material().color();
        }
    }

    return base_color;
}

int main()
{
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    Camera camera(Vector(0, 0, 2), Vector(0, 0, -1), Vector(0, 1, 0), 30, aspect_ratio);

    //

    FILE *f = fopen("image.ppm", "w");
    fprintf(f, "P3\n%d %d\n%d\n", image_width, image_height, 255);

    //

    std::vector<IWorldObject *> world;

    world.push_back(new Sphere(Vector(0.0f, 0.0f, -1.0f), 0.5f, Material(Vector(255.0, 0.0, 0.0))));
    world.push_back(new Sphere(Vector(-1.0f, 0.0f, -1.0f), 0.3f, Material(Vector(0.0, 255.0, 0.0))));
    world.push_back(new Sphere(Vector(1.0f, 0.0f, -1.0f), 0.3f, Material(Vector(0.0, 0.0, 255.0))));

    //

    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; i++)
        {
            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);

            Vector color = get_color_at(camera.get_ray(u, v), world);

            fprintf(f, "%d %d %d ", int(color.x()), int(color.y()), int(color.z()));
        }
        fprintf(f, "\n");
    }
}
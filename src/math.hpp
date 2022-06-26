#pragma once

#include <cmath>

#define K_PI 3.14159265358979323846

namespace Math {
    double degrees_to_radians(double degrees) {
        return K_PI * degrees / 180;
    }

    double tan(double angle) {
        return ::tan(angle);
    }
}

#include "stdafx.h"
namespace {
    float Degree2Radians(float a)
    {
        return a * DEGREE2RADIANS;
    }

    float Radians2Degree(float a)
    {
        return a * RADIANS2DEGREE;
    }

    float clampf(float value, float min_inclusive, float max_inclusive)
    {
        if (min_inclusive > max_inclusive)
        {
            std::swap(min_inclusive, max_inclusive);
        }
        return value < min_inclusive ? min_inclusive : value < max_inclusive ? value : max_inclusive;
    }

    /**
    A more effect random number getter function, get from ejoy2d.
    */
    static float RANDOM_M11(unsigned int* seed)
    {
        *seed = *seed * 134775813 + 1;
        union
        {
            uint32_t d;
            float f;
        } u;
        u.d = (((uint32_t)(*seed) & 0x7fff) << 8) | 0x40000000;
        return u.f - 3.0f;
    }
}
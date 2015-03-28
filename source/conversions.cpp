#include "conversions.hpp"

float toDeg(const float radians)
{
    return radians * 57.2957795131f;
}

float toRad(const float degrees)
{
    return degrees * 0.01745329251f;
}

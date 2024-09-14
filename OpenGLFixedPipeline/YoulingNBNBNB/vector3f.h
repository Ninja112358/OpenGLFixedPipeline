#pragma once

#include <cmath>


class Vector3f
{
public:
    float x;
    float y;
    float z;
    Vector3f(float x, float y, float z);
    Vector3f operator+(Vector3f& vector3f);
    Vector3f operator-(Vector3f& vector3f);
    Vector3f operator*(float k);
    float    operator*(Vector3f& vector3f);
    Vector3f operator/(float& k);
    Vector3f operator^(Vector3f& vector3f);
    float    getLength();
    Vector3f Normalize();
};

const Vector3f UP(0, 1, 0);
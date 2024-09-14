#include "Vector3f.h"

Vector3f::Vector3f(float x = 0, float y = 0, float z = 0){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3f Vector3f::operator+(Vector3f& vector3f){
    Vector3f result;
    result.x = this->x + vector3f.x;
    result.y = this->y + vector3f.y;
    result.z = this->z + vector3f.z;
    return result;
}

Vector3f Vector3f::operator-(Vector3f& vector3f){
    Vector3f result;
    result.x = this->x - vector3f.x;
    result.y = this->y - vector3f.y;
    result.z = this->z - vector3f.z;
    return result;
}

Vector3f Vector3f::operator*(float k){
    Vector3f result;
    result.x = this->x * k;
    result.y = this->y * k;
    result.z = this->z * k;
    return result;
}

float Vector3f::operator*(Vector3f& vector3f){
    return this->x * vector3f.x + this->y * vector3f.y + this->z * vector3f.z;
}

Vector3f Vector3f::operator/(float& k){
    Vector3f result;
    result.x = this->x / k;
    result.y = this->y / k;
    result.z = this->z / k;
    return result;
}

Vector3f Vector3f::operator^(Vector3f& vector3f){
    Vector3f result;
    result.x = this->y * vector3f.z - this->z * vector3f.y;
    result.y = this->z * vector3f.x - this->x * vector3f.z;
    result.z = this->x * vector3f.y - this->y * vector3f.x;
    return result;
}

float Vector3f::getLength(){
    return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}
Vector3f Vector3f::Normalize(){
    float length = this->getLength();
    Vector3f result;
    result.x = this->x / length;
    result.y = this->y / length;
    result.z = this->z / length;
    return result;
}
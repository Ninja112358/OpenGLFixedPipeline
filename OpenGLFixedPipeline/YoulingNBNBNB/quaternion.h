#pragma once

#include "vector3f.h"
#include "matrix3x3.h"

class Quaternion {
public:
	float x, y, z, w;
	Quaternion(float x,float y,float z,float w);
	inline friend Quaternion operator * (const Quaternion& lhs, const Quaternion& rhs) {
		return Quaternion(	lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
							lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z, 
							lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x, 
							lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z);
	}

};

Quaternion EulerToQuaternion(const Vector3f& Euler);			//欧拉角转四元数
void QuaternionToMatrix(const Quaternion& q, Matrix3x3& m);		//四元数转矩阵
#pragma once
#include "vector3f.h"
#include "ggl.h"
class Camera {
public:
	float moveSpeed = MOVE_SPEED;
	Camera();
	//mPos:摄像机坐标
	//mViewCenter:摄像机的视口中心的位置
	//mUp:摄像机的头顶的方向向量
	Vector3f mPos, mViewCenter, mUp;
	bool mbMoveLeft, mbMoveRight, mbMoveForward, mbMoveBack, mbMoveUp, mbMoveDown;
	void Update(float deltaTime);		//实时更新
	void Pitch(float angle);			//横向转动
	void Yaw(float angle);				//纵向转动
	void RotateView(float angle, float x, float y, float z);	//旋转视口

};
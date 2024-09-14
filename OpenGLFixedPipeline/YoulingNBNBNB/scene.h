#pragma once
#include "ggl.h"

void Init(float windowWidth, float windowHeight);	//初始化函数
void Draw();		//绘制函数
void DrawModel();	//绘制模型
void InitLight();	//初始化灯光，这里是固定管线的灯光（贼丑
void OnKeyDown(char code);							//按下键盘的事件
void OnKeyUp(char code);							//抬起键盘的事件
void OnMouseMove(float deltaX, float deltaY);		//移动鼠标的事件
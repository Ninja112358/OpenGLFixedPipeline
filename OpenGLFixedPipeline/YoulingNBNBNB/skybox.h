#pragma once
#include "ggl.h"

#define SKYBOX_SIZE 0.5f	//天空盒的大小

class SkyBox {
	GLuint mTextures[6];				//天空盒的纹理
	GLuint mFastDrawCall;				//显示列表
public:
	void Init(const char* imageDir);	//初始化天空盒
	void DrawCommand();					//把指令装入显示列表中
	void Draw(float x,float y,float z);	//对天空盒进行绘制
};
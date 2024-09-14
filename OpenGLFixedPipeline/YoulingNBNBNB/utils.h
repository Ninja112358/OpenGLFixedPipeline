#pragma once
#include "ggl.h"

unsigned char* LoadFileContent(const char* path,int& fileSize);						//读取文件的内容
unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int& height);		//解码bmp
GLuint CreateTexture2D(unsigned char* pixelData,int width,int height,GLenum type);	//生成一个Texture对象
GLuint CreateTexture2DFromBMP(const char* bmpPath);									//封装一下创建Texture的方法
GLuint CreateDisplayList(std::function<void()>foo);									//显示列表的封装
float GetFrameTime();																//获取一帧的时间(单位:秒
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "scene.h"
#include "utils.h"
#include "skybox.h"
#include "model.h"
#include "ground.h"
#include "camera.h"

Model model;
GLuint texture;
SkyBox skybox;
Ground ground;
Camera camera;

void Init(float windowWidth,float windowHeight) {
	//初始化灯光
	InitLight();
	//初始化矩阵(projection和modelview)
	glMatrixMode(GL_PROJECTION);
	gluPerspective(GL_FOVY, windowWidth / windowHeight, GL_NEAR, GL_FAR);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	skybox.Init("res/skybox/");

	model.Init("res/model/niutou.obj");
	model.mTexture = CreateTexture2DFromBMP("res/bmp/niutou.bmp");
	texture = CreateTexture2DFromBMP("res/bmp/test.bmp");
	ground.mTexture = CreateTexture2DFromBMP("res/bmp/earth.bmp");
}
void Draw() {
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float frameTime = GetFrameTime();
	camera.Update(frameTime);

	//天空盒必须在任何物体绘制之前进行绘制
	skybox.Draw(camera.mPos.x, camera.mPos.y,camera.mPos.z);

	ground.Draw();
	model.Draw();
	//开始绘制
	//DrawModel();
}

int size = 10.0f;
void DrawModel() {
	glPushMatrix();
	//开启深度测试
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);



	//static float rotation = 0.0f;
	//rotation += 0.05f;
	//glTranslatef(0.0f, -1.0f, -5.0f);
	//glRotatef(rotation, 0.0f, 1.0f,0.0f);


	glBegin(GL_QUADS);
	glColor4ub(255, 0, 0, 255);
	glVertex3f(-size, -size, -size);
	glVertex3f(+size, -size, -size);
	glVertex3f(+size, +size, -size);
	glVertex3f(-size, +size, -size);

	glColor4ub(0, 255, 0, 255);
	glVertex3f(-size, -size, -size);
	glVertex3f(+size, -size, -size);
	glVertex3f(+size, -size, +size);
	glVertex3f(-size, -size, +size);

	glColor4ub(0, 0, 255, 255);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, +size, -size);
	glVertex3f(-size, +size, +size);
	glVertex3f(-size, -size, +size);

	glColor4ub(255, 255, 0, 255);
	glVertex3f(+size, +size, +size);
	glVertex3f(-size, +size, +size);
	glVertex3f(-size, -size, +size);
	glVertex3f(+size, -size, +size);

	glColor4ub(255, 0, 255, 255);
	glVertex3f(+size, +size, +size);
	glVertex3f(-size, +size, +size);
	glVertex3f(-size, +size, -size);
	glVertex3f(+size, +size, -size);

	glColor4ub(0, 255, 255, 255);
	glVertex3f(+size, +size, +size);
	glVertex3f(+size, -size, +size);
	glVertex3f(+size, -size, -size);
	glVertex3f(+size, +size, -size);
	glEnd();
	glPopMatrix();
}



void InitLight() {
	
	//glEnable(GL_CULL_FACE);

	//float lightPos[] = { 0.0f,1.0f,0.0f,0.0f };
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//float whiteColor[] = { 1.0f,1.0f,1.0f,1.0f };
	//float ambientMat[] = { 1.0f,1.0f,1.0f,1.0f };
	//float diffuseMat[] = { 0.4f,0.4f,0.4f,1.0f };
	//float specularMat[] = { 0.9f,0.9f,0.9f,1.0f };

	//glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteColor);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor);

	//glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMat);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMat);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specularMat);

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
}

void OnKeyDown(char code) {
	switch (code)
	{
	case VK_W:
		camera.mbMoveForward = true;
		break;
	case VK_S:
		camera.mbMoveBack = true;
		break;
	case VK_A:
		camera.mbMoveLeft = true;
		break;
	case VK_D:
		camera.mbMoveRight = true;
		break;
	case VK_Q:
		camera.mbMoveUp = true;
		break;
	case VK_E:
		camera.mbMoveDown = true;
		break;
	case VK_ESCAPE:
		PostQuitMessage(0);
		break;
	}
}
void OnKeyUp(char code) {
	switch (code)
	{
	case VK_W:
		camera.mbMoveForward = false;
		break;
	case VK_S:
		camera.mbMoveBack = false;
		break;
	case VK_A:
		camera.mbMoveLeft = false;
		break;
	case VK_D:
		camera.mbMoveRight = false;
		break;
	case VK_Q:
		camera.mbMoveUp = false;
		break;
	case VK_E:
		camera.mbMoveDown = false;
		break;
	}
}
void OnMouseMove(float deltaX, float deltaY) {
	float angleRotateByUp = deltaX / 1000.0f;
	float angleRotateByRight = deltaY / 1000.0f;
	camera.Yaw(-angleRotateByUp);
	camera.Pitch(-angleRotateByRight);
}
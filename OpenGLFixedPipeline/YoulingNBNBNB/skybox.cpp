#define _CRT_SECURE_NO_WARNINGS
#include "skybox.h"
#include "utils.h"

GLuint CreateTexture2DFromDirName(const char* imageDir, const char* imageName){
	char temp[256];
	strcpy(temp, imageDir);
	strcat(temp, imageName);
	return CreateTexture2DFromBMP(temp);
}
const char* imageName[] ={
	"front.bmp",
	"back.bmp",
	"left.bmp",
	"right.bmp",
	"top.bmp",
	"bottom.bmp",
};
void SkyBox::Init(const char* imageDir) {
	for (int i = 0; i < sizeof(mTextures) / sizeof(*mTextures); ++i)
		mTextures[i] = CreateTexture2DFromDirName(imageDir, imageName[i]);
	mFastDrawCall = CreateDisplayList([this]()->void { DrawCommand(); });
}

const float SkyBoxSize[][12] = {
	{-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
	SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
	SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
	-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE},

	{SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
	-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
	-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
	SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE},

	{-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
	-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
	-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
	-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE},

	{SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
	SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
	SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
	SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE},

	{-SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
	SKYBOX_SIZE, SKYBOX_SIZE, -SKYBOX_SIZE,
	SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE,
	-SKYBOX_SIZE, SKYBOX_SIZE, SKYBOX_SIZE},

	{-SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
	SKYBOX_SIZE, -SKYBOX_SIZE, SKYBOX_SIZE,
	SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE,
	-SKYBOX_SIZE, -SKYBOX_SIZE, -SKYBOX_SIZE}
};


void SkyBox::DrawCommand() {
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	//ªÊ÷∆Œ∆¿ÌÃ˘Õº
	for (int i = 0; i < sizeof(mTextures) / sizeof(*mTextures); ++i){
		glBindTexture(GL_TEXTURE_2D, mTextures[i]);
		glBegin(GL_QUADS);
		glColor4ub(255, 255, 255, 255);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(SkyBoxSize[i][0], SkyBoxSize[i][1], SkyBoxSize[i][2]);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(SkyBoxSize[i][3], SkyBoxSize[i][4], SkyBoxSize[i][5]);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(SkyBoxSize[i][6], SkyBoxSize[i][7], SkyBoxSize[i][8]);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(SkyBoxSize[i][9], SkyBoxSize[i][10], SkyBoxSize[i][11]);

		glEnd();
	}
}
void SkyBox::Draw(float x,float y, float z) {
	glPushMatrix();
	glTranslatef(x,y,z);
	glCallList(mFastDrawCall);
	glPopMatrix();
}
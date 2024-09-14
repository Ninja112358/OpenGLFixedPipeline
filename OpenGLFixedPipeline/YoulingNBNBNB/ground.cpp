#include "ground.h"

void Ground::Draw() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTexture);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_REPEAT);
	glPushMatrix();


	glBegin(GL_QUADS);
	glColor4ub(255, 255, 255, 255);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-this->groundSize, -1.0f, this->groundSize);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(this->groundSize, -1.0f, this->groundSize);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(this->groundSize, -1.0f, -this->groundSize);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-this->groundSize, -1.0f, -this->groundSize);

	glEnd();
	glPopMatrix();
}
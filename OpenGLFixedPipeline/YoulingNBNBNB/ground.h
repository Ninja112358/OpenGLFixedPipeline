#pragma once
#include "ggl.h"

class Ground {
public:
	GLuint mTexture;
	float groundSize = 4000.0f;
	void Draw();
};
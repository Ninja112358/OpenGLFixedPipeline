#pragma once
#include "ggl.h"

struct VertexData {
	float position[3];
	float normal[3];
	float texcoord[2];
};

class Model {
	VertexData* mVertexes;
	unsigned short* mIndexes;
	int mIndexCount;
	
public:
	GLuint mTexture;
	Model();
	void Init(const char* modelPath);
	void Draw();
};
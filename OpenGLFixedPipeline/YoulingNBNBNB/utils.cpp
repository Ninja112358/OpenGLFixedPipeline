#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"



unsigned char* LoadFileContent(const char* path, int& fileSize) {
	unsigned char* fileContent = nullptr;
	fileSize = 0;
	FILE* pFile = fopen(path, "rb");
	if (pFile) {
		fseek(pFile,0,SEEK_END);
		int nLen = ftell(pFile);
		if (nLen > 0) {
			rewind(pFile);
			fileContent = new unsigned char[nLen + 1];
			fread(fileContent,sizeof(unsigned char),nLen,pFile);
			fileContent[nLen] = '\0';
			fileSize = nLen;
		}
		fclose(pFile);
	}
	return fileContent;
	
}
unsigned char* DecodeBMP(unsigned char* bmpFileData,int& width,int& height) {
	if (0x4D42  == *((unsigned short*)bmpFileData)) {
		int pixelDataOffset = *((int*)(bmpFileData + 10));
		width = *((int*)(bmpFileData + 18));
		height = *((int*)(bmpFileData + 22));
		unsigned char* pixelData = bmpFileData + pixelDataOffset;
		for (int i = 0; i < width * height * 3; i += 3) {
			unsigned char temp = pixelData[i];
			pixelData[i] = pixelData[i + 2];
			pixelData[i + 2] = temp;
		}
		return pixelData;
	}
}
GLuint CreateTexture2D(unsigned char* pixelData, int width, int height, GLenum type) {
	GLuint texture;
	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D,texture);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D,0,type,width,height,0,type,GL_UNSIGNED_BYTE,pixelData);
	glBindTexture(GL_TEXTURE_2D, 0);
	return texture;

}
GLuint CreateTexture2DFromBMP(const char* bmpPath) {
	int nFileSize = 0;
	unsigned char* bmpFileContent = LoadFileContent(bmpPath, nFileSize);
	if (bmpFileContent == nullptr) {
		return 0;
	}
	int bmpWidth = 0, bmpHeight = 0;
	unsigned char* pixelData = DecodeBMP(bmpFileContent, bmpWidth, bmpHeight);
	if (bmpWidth == 0) {
		delete bmpFileContent;
		return 0;
	}

	GLuint texture = CreateTexture2D(pixelData, bmpWidth, bmpHeight, GL_RGB);
	delete bmpFileContent;
	return texture;
	
}
GLuint CreateDisplayList(std::function<void()>foo) {
	GLuint displayList = glGenLists(1);
	glNewList(displayList,GL_COMPILE);
	foo();
	glEndList();
	return displayList;
}
float GetFrameTime() {
	static unsigned long startTime = 0;
	static unsigned long lastTime = 0;
	startTime = timeGetTime();
	unsigned long frameTime = lastTime == 0 ? 0 : startTime - lastTime;
	lastTime = startTime;
	return (float)frameTime / 1000.0f;
}
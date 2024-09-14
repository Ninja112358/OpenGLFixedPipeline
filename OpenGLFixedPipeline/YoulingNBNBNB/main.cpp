#define _CRT_SECURE_NO_WARNINGS
#include "ggl.h"
#include "scene.h"
#include "debug.h"

#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"winmm.lib")

//鼠标的坐标
POINT originalPos;
//旋转用的
bool rotateView = false;

//窗口过程
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) {
#ifdef _DEBUG
	InitConsole();
#endif
	wchar_t szAppName[] = L"OpenGL";

	WNDCLASSEX wndclass;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255,0,0));
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	ATOM atom = RegisterClassEx(&wndclass);
	if(!atom){
		MessageBox(NULL,L"register class fail",L"warning",MB_ICONERROR);
		return 0;
	}
	int realWidth = WIDTH;
	int realHeight = HEIGHT;
	RECT rect;
	rect.left = 0;
	rect.right = realWidth;
	rect.top = 0;
	rect.bottom = realHeight;
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW,NULL);
	int windowWidth = rect.right - rect.left;
	int windowHeight = rect.bottom - rect.top;
	
	HWND hWnd = CreateWindowEx(	NULL,szAppName,szAppName,WS_OVERLAPPEDWINDOW,
								WINDOW_X,WINDOW_Y,windowWidth,windowHeight,NULL,NULL,hInstance,NULL);
	//搭建OpenGL的绘制框架
	HDC dc = GetDC(hWnd);
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nVersion = 1;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 8;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	int pixelFormat = ChoosePixelFormat(dc,&pfd);
	SetPixelFormat(dc, pixelFormat, &pfd);
	HGLRC rc = wglCreateContext(dc);
	wglMakeCurrent(dc, rc);
	//初始化操作
	Init((float)realWidth,(float)realHeight);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	//在消息循环中执行Draw函数并且交换缓冲区
	//OpenGL中的绘制操作都去scene.cpp里去实现
	while (1) {
		//clock_t startTime = clock();

		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Draw();
		SwapBuffers(dc);

		//clock_t endTime = clock();
		//printf("一次循环的时间:%dms\n", endTime - startTime);
	}

	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	switch (uMessage) {
	case WM_RBUTTONDOWN:
		GetCursorPos(&originalPos);
		ShowCursor(false);
		rotateView = true;
		return 0;
	case WM_RBUTTONUP:
		SetCursorPos(originalPos.x, originalPos.y);
		ShowCursor(true);
		rotateView = false;
		return 0;
	case WM_MOUSEMOVE:
		if (rotateView) {
			POINT currentPos;
			GetCursorPos(&currentPos);
			int deltaX = currentPos.x - originalPos.x;
			int deltaY = currentPos.y - originalPos.y;
			OnMouseMove(deltaX, deltaY);
			SetCursorPos(originalPos.x, originalPos.y);
		}
		return 0;
	case WM_KEYDOWN:
		OnKeyDown(wParam);
		return 0;
	case WM_KEYUP:
		OnKeyUp(wParam);
		return 0;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, uMessage, wParam, lParam);
}

#pragma once
#include <windows.h>

class Widget{
public:
	WNDCLASS wndclass;
	wchar_t szAppName[20] = L"Ninja";
	Widget();
	~Widget();
};


#pragma once

/************************
 *      常用头文件      *
 ************************/
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <functional>
#include <math.h>
#include <iostream>

/*******************
 *     常用宏      *
 *******************/
#define WIDTH 1800		//窗口的宽度
#define HEIGHT 900		//窗口的高度

#define WINDOW_X 0		//窗口的x位置
#define WINDOW_Y 0		//窗口的y位置

#define GL_NEAR	0.1f	//摄像机最近看到的距离
#define GL_FAR 2000.0f	//摄像机最远看到的距离
#define GL_FOVY 50.0f	//摄像机上下睁开的幅度

#define GL_CLAMP_TO_EDGE 0x812F		//解决天空盒的缝隙的问题

#define MOVE_SPEED 50.0f		//移动速度
#define ROTATION_SPEED 2.0f		//旋转速度

/**********************
 *     键盘的键值     *
 **********************/
#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
#define VK_6 0x36
#define VK_7 0x37
#define VK_8 0x38
#define VK_9 0x39

#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A
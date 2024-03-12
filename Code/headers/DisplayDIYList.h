/*
 * FILE: DisplayDIYList.h
 * BRIEF: This file displays the "My DIY Maps" GUI
 */ 
 
#ifndef __DIYLIST_H__
#define __DIYLIST_H__

/* Global Header */
#include "main.h"

/* Functions */
void DisplayDIYListDefault();						      		// 选取DIY地图界面绘制，包括六个按钮，地图的显示 
void myMouseEventDIYList (int x, int y, int button, int event);	// 用于选取地图的鼠标事件，可以选择地图1-4并显示.
																// play进入当前选定的地图进行游玩 
void DisplayDIYList();											// 注册鼠标事件，显示选取DIY地图页面 
extern drawBlock();

#endif

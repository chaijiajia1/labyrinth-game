/*
 * FILE: DisplayGUI.h
 * BRIEF: This file displays the level choosing GUI for default maps.
 */

#ifndef __GUI_H__
#define __GUI_H__

/* Global header */
#include "main.h"

/* Global and extern variables */
Pixel mini;
extern int isGUI;

/* Functions for display GUI */
void DisplayGUIDefault();  									// 绘制选择level界面的图形
void myMouseEventGUI (int x, int y, int button, int event); // 点击左键在level按钮位置内升起可选定level并进入游玩界面
void DisplayGUI();											// 注册一个鼠标事件的回调函数，用于level界面的选择

#endif

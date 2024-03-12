/*
 * FILE: DisplayHelp.h
 * BRIEF: This file displays the instruction GUI for the entire project. 
 *        It lies in the "?" in the main GUI.
 */
 
#ifndef __MAINGUI_H__
#define __MAINGUI_H__

/* Global header */
#include "main.h"

/* Global variable */ 
Pixel mini1;

/* Functions */
void DisplayMainGUIDefault();									// 绘制选择主界面的图形
void myMouseEventMainGUI (int x, int y, int button, int event); // 用于主界面的鼠标事件 
void DisplayMainGUI();											// 注册鼠标事件，绘制主界面图形

#endif

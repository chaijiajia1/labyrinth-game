/*
 * FILE: DisplayScoreList.h
 * BRIEF: Show the score list display GUI
 */

#ifndef __SCORELIST_H__
#define __SCORELIST_H__

/* Global header */
#include "main.h"

/* Extern value */
extern Pixel mini1;

/* Functions */
void myMouseEventScoreList(int x, int y, int button, int event);	// 注册鼠标事件，用以退出分数榜显示 
void DisplayScoreListDefault();										// 绘制分数榜界面，从文件中读取分数与姓名 
void DisplayScoreList();											// 注册鼠标事件，显示分数榜界面 

#endif

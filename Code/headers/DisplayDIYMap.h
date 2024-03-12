/*
 * FILE: DisplayDIYList.h
 * BRIEF: This file displays the "My DIY Maps" GUI
 */ 
 
#ifndef __DIYMAP_H__
#define __DIYMAP_H__

/* Global header */
#include "main.h"

/* Extern variables and flag */
extern Map map;
int currentDraw = TREE;	// currentDraw指当前选中的方块类型，点击地图中的格子即可将之变为相应的类型，初始化为墙壁 
extern int HIGHLIGHT;	// 决定是否高亮显示最短路径 
extern int OnlyNext;	// 只高亮显示下一步
extern int PRESSED;		// 标志着是否按下show shortest path 

/* Functions */
void DisplayDIYMapDefault();// 注册鼠标事件，显示DIY地图界面 
void myMouseEventDIYMap(int x, int y, int button, int event);	// 判定鼠标是否点击按钮或地图中的格子，若有，修改当前地图信息 
void DisplayDIYMap();		// 绘制按钮，显示地图与提示信息 
int CheckUniqueness ();		// 检查自定义生成地图的连通性，若不连通无法显示最短路径，亦无法游玩 

#endif 

/*
 * FILE: MapUtils.h
 * BRIEF: Consists of 4 map generation methods, map I/O functions and block print function
 */

#ifndef __MAPUTILS_H__
#define __MAPUTILS_H__

/* Global header */
#include "main.h"

/* Extern and global variables */
Map map;
Coordinate door;						// 门的坐标 
Coordinate key; 						// 钥匙的坐标 
extern int OnlyNext;					// 只高亮显示下一步

/* Functions */
void DrawBlock(Pixel start, int type);	// 绘制方块，包括空，起点，终点，墙壁，钥匙，门等类型 
int NextTo(Coordinate me, Coordinate other); // 获取下一步的位置 
void HighlightPath(Pixel start, int type);   // 高亮显示求解得到的一条最短路径路径 
void SaveMap(int num);					// 保存地图 
void ReadMap(int num, int isDIY);		// 读取地图 
void GenerateMapStatic();				// 显示静态存储的地图 
void GenerateMapRandom();				// 随机生成地图，直到生成连通性判断成功的地图 
void GenerateMapStaticDIY(int map_num);	// 显示生成的地图 
void GenerateMapEmpty();				// 做一个空地图 

#endif

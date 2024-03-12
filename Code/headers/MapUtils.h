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
Coordinate door;						// �ŵ����� 
Coordinate key; 						// Կ�׵����� 
extern int OnlyNext;					// ֻ������ʾ��һ��

/* Functions */
void DrawBlock(Pixel start, int type);	// ���Ʒ��飬�����գ���㣬�յ㣬ǽ�ڣ�Կ�ף��ŵ����� 
int NextTo(Coordinate me, Coordinate other); // ��ȡ��һ����λ�� 
void HighlightPath(Pixel start, int type);   // ������ʾ���õ���һ�����·��·�� 
void SaveMap(int num);					// �����ͼ 
void ReadMap(int num, int isDIY);		// ��ȡ��ͼ 
void GenerateMapStatic();				// ��ʾ��̬�洢�ĵ�ͼ 
void GenerateMapRandom();				// ������ɵ�ͼ��ֱ��������ͨ���жϳɹ��ĵ�ͼ 
void GenerateMapStaticDIY(int map_num);	// ��ʾ���ɵĵ�ͼ 
void GenerateMapEmpty();				// ��һ���յ�ͼ 

#endif

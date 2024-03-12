/*
 * FILE: MyDraw.h
 * BRIEF: Draw character, key, door, destination elements.
 */

#ifndef __MYDRAW_H__
#define __MYDRAW_H__

/* global header */
#include "main.h"

/* Color for draw character, destination, key, door */
static double color = 0.999;		// color to display the painted elements

/* Functions */
void DrawCharacter(double x, double y);//绘制小人，输入的是绘画起点的像素坐标 
void DrawDestination(double x, double y);//绘制终点，输入的是绘画起点的像素坐标 
void DrawDoor(double x, double y);//绘制门，输入的是绘画起点的像素坐标 
void DrawKey(double x, double y);//绘制钥匙，输入的是绘画起点的像素坐标 

#endif

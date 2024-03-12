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
void DrawCharacter(double x, double y);//����С�ˣ�������ǻ滭������������ 
void DrawDestination(double x, double y);//�����յ㣬������ǻ滭������������ 
void DrawDoor(double x, double y);//�����ţ�������ǻ滭������������ 
void DrawKey(double x, double y);//����Կ�ף�������ǻ滭������������ 

#endif

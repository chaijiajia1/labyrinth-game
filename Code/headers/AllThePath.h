/*
 * FILE: AllThePath.h
 * BRIEF: This file supposts the 'Find all paths', 'Solve the maze step by step' and 'Automatically solve the maze' features.
 */

#ifndef __AllThePath_H__
#define __AllThePath_H__

#include "main.h"

/* Extern and Global variables */
extern Coordinate direction[4];
struct StackRecord;
int dist[MAP_MAX][MAP_MAX];
int procession;
Coordinate Visualized[50000];

/* Functions for finding all the paths */
void findastep(int sx,int sy,int fx,int fy,Stack S);
int findAllPath(Coordinate from, Coordinate to);
void printpath(Stack S);
int bfs(Coordinate from,Coordinate to);


/* Stack Operations for finding all the paths */
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X,int y,Stack S);
Coordinate Top(Stack S);
void Pop(Stack S);
Coordinate TopAndPop(Stack S);

#endif



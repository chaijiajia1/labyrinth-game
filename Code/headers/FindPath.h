/*
 * FILE: FindPath.h
 * BRIEF: Basic find path function 
 */

#ifndef __FINDPATH_H__
#define __FINDPATH_H__

/* Global headers */
#include "main.h"

/* Global and extern variables */
int minStep;					// the minimum steps required to reach the destination
int path[MAP_MAX][MAP_MAX];   	// save the shortest path
extern int dist[MAP_MAX][MAP_MAX];
Coordinate direction[4] = {
	{1,0}, {0,1}, {-1,0}, {0,-1}// 4 directions
};

/* Functions */
int bfs(Coordinate from, Coordinate to);// breadth first search function
int findPath(Coordinate from, Coordinate to);// return reachable flag and modify the **path matrix
#endif

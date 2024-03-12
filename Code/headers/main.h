/*
 * FILE: main.h
 * BRIEF: The global header. All other headers should include this header.
 */

#ifndef __HEAD__
#define __HEAD__

#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


/* Constants */
#define TRUE 1
#define FALSE 0
#define INX_MAX 1e9
#define MAP_MAX 60
#define EmptyToS -1
#define MinStackSize 5
enum MAPELEMENTS{
	EMPTY,			// 0
	TREE,			// 1
	PATH,			// 2
	KEY,			// 3
	DOOR, 			// 4
	ME,				// 5
	PLACEHOLDER6,	// 6
	PLACEHOLDER7, 	// 7
	PLACEHOLDER8,	// 8
	DESTINATION		// 9
};

/* Structs */
/* Coordinate for display */ 
typedef struct Pixel{
	double x, y;
}Pixel; 
/* Coordinate for map */
typedef struct Coordinate{
	int x, y;
}Coordinate;
/* Map information */
typedef struct Map{          
	int level;               // map level: 1 ~ 5. Related to the map size
	int size;                // map size: number of blocks per row/column
	int **arrangement;       // map arrangement: the content of each block.
	int time;                // left life: a remaning time value related to the map size.
}Map;
/* User score information */
typedef struct ScoreList
{
    char name[20];           // player name
    int score;               // player score
    struct ScoreList* next;
}ScoreList;

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    Coordinate *PNode;
};
extern Coordinate direction[4];
typedef struct StackRecord *Stack;


/* Flags */
extern int level;
extern int isGUI;
extern int isWin;
extern int isConinue;
extern int PRESSED;

/* Map Info */
extern Map map;
extern double blockSize;
extern Pixel window_size;
extern time_t startTime, currentTime;
extern Pixel mini1;
extern int OnlyNext ;

/* Path Info */
extern Coordinate me;
extern Coordinate destination;
extern Coordinate key;
extern Coordinate door;
extern int minStep;						// minimum # steps to the destination
extern int dist[MAP_MAX][MAP_MAX];		// store distance
extern int path[MAP_MAX][MAP_MAX];   	// path to be visualized 

/* Display Functions */
extern void DisplayGUI();
extern void DisplayMap();
extern void DisplayExit();

/* Functional Functions */
extern int findPath(Coordinate from, Coordinate to);
/* All the path */
extern int findAllPath(Coordinate from, Coordinate to); 
extern void findastep(int sx,int sy,int fx,int fy,Stack S);
extern void printpath(Stack S);
extern Coordinate **route;
extern int routelines;
extern int procession;
extern Coordinate Visualized[50000];

/* Map Utils */
extern void GenerateMapStatic();
extern void GenerateMapRandom();
extern void SaveMap(int num);
extern void ReadMap(int num, int isDIY);
extern void DrawBlock(Pixel start, int type);
extern int NextTo(Coordinate me, Coordinate other);
extern void HighlightPath(Pixel start, int type);

/* Timer for Left Life */
typedef enum {
	count_down,
	auto_timer,
} MyTimer;

#endif

/*
 * FILE: DisplayExit.h
 * BRIEF: This file displays the GUI when finishing the game.
 *        It supports entering the user name, saving the scores, showing all the possible paths and automatically solving the maze.
 */ 

#ifndef __EXIT_H__
#define __EXIT_H__

#include "main.h"

/* Global and extern variables */
extern int isWin;
extern Pixel mini1;
extern Pixel O;
extern Coordinate me;
extern Coordinate destination;
extern Coordinate Key;
extern Coordinate Door;
static char Name[80] = "player";
extern int dist[MAP_MAX][MAP_MAX];
extern int path[MAP_MAX][MAP_MAX]; 
int routelines;
Coordinate **route;
int maphaskey;
int tokeylines;
int keytolines;
Coordinate **tokeyroute;
Coordinate **keytoroute;
int choice;
int displayshorestpath;
extern int procession;
int processionnum;
int processionflag;
extern Coordinate Visualized[50000];
int Visualizedblock[MAP_MAX][MAP_MAX];
int processionnumrepeat;

/* Functions */
void DisplayExitDefault();					  // default display function
void KeyboardEventProcess(int key, int event);// read keyboard event
void MouseEventProcess(int x, int y, int button, int event); // read mouse event
void CharEventProcess(char ch);				  // read keyboard input
void myMouseEventExit (int x, int y, int button, int event); // register mouse event
void DisplayExit();							  // main display function
void timer1(int timerID);


#endif

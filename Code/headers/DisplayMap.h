/*
 * FILE: DisplayMap.h
 * BRIEF: This file displays the instruction GUI for the entire project. 
 *        It lies in the "?" in the main GUI.
 */

#ifndef __MAP_H__ 
#define __MAP_H__

/* Global header */
#include "main.h"

/* Extern and global variables */
extern Map map;
extern isWithKey;
int HIGHLIGHT=FALSE;		// whether the path is highlighted. bound with the button
int OnlyNext=TRUE;
extern isContinue;
Pixel O;
int cnt = 0;

/* Functions */ 
void timer(int timerID);
void myMouseEventGame(int x, int y, int button, int event);	// mouse event for display map
void myKeyboardEventGame(int key, int event);				// keyboard event for display map
void DisplayMap();			// Recurrent display map function
void DisplayMapDefault(); 	// Default display map function
#endif



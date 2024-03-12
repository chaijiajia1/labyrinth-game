#include "headers\\main.h"

/* Global variables */ 
int level;					// game level	
int isGUI = TRUE;			// to display GUI: 1. else: 0
int isContinue = TRUE;		// to stop the game: 0. else: 1
int isWin = FALSE;			// win/reach the destination: 1. else: 0
int PRESSED = FALSE;		// for buttons
int isWithKey = FALSE;      // to determine whether the character can pass the door
double blockSize = 0.35;	// height/width of map block in display
Pixel window_size;			// display window size
Coordinate me;				// player's place in map
Coordinate destination;		// destination's place in map
Coordinate key;				// key's place in map
Coordinate door;			// door's place in map
time_t startTime, currentTime;	// start system time, current system time


/* Set windows information to initialize */
void InitWindow(){
	
	window_size.x = 20;
	window_size.y = 10;
	SetWindowTitle("Labyrinth √‘π¨”Œœ∑");
	SetWindowSize(window_size.x, window_size.y);
	InitGraphics();
}
/* Set my colors */
/* To modify colors, only to change here */
void InitMyColor(){
	
	DefineColor("Background", 230.0/256, 256.0/256, 160.0/256);		// light green
	DefineColor("Headline1", 63.0/256, 92.0/256, 0.0/256);			// dark green
	DefineColor("Headline2", 138.0/256, 49.0/256, 0.0/256);			// brown
	DefineColor("Button", 7.0/256, 241.0/256, 250.0/256);			// blue
	DefineColor("Buttontext", 145.0/256, 20.0/256, 250.0/256);		// purple
	DefineColor("Text", 69.0/256, 138.0/256, 0.0/256);			// another dark green
	
	DefineColor("Key", 250.0/256, 128.0/256, 50.0/256);
	DefineColor("Door", 145.0/256, 20.0/256, 250.0/256);
	
	
}

void Main(){
	
	/* Set window basic information */
	InitWindow();
	
	/* Set Colors */
	InitMyColor();
	
	/* Display GUI */
	Map map;
	DisplayMainGUI();

}



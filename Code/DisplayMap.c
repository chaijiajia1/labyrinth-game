#include "headers\\DisplayMap.h"
	
/* default map display function */
void DisplayMapDefault(){
	
	DisplayClear();
	
	/* Background */
	SetPenColor("Background");
	drawBox(0, 0, window_size.x, window_size.y, 1, "", 's', "Background");
	
	/* prompt */
	SetPointSize(15);
	SetPenColor("Headline2");
	MovePen(14.5, 8.5);
	DrawTextString("您的生命值会随时间流失，请尽快找到出口。");
	MovePen(14.5, 8);
	DrawTextString("按W: 向上走. 按A: 向左走. 按S: 向下走. 按D: 向右走.");
	MovePen(14.5, 7.5);
	DrawTextString("按Q: 退出本地图.");
	MovePen(14.5, 7);
	DrawTextString("按一下按钮提示下一步，再按一下隐藏。");
	
	
	/* Buttons */
	button(GenUIID(0), 14.5, 5.5, 2, 1, PRESSED? "隐藏提示": "显示提示");
	button(GenUIID(0), 14.5, 4, 2, 1, "退出当前地图");
	
	
	/*  */ 
	int i, j;
	
	for (i = 0; i < map.size; i++)
		for (j = 0; j < map.size; j++)
		{
			Pixel start;
			start.x = O.x+i*blockSize;
			start.y = O.y-j*blockSize;
			if (HIGHLIGHT == TRUE){
				OnlyNext=TRUE;
				HighlightPath(start, path[i][j]);
			}
			DrawBlock(start, map.arrangement[i][j]);
		}

	/* timer */
	SetPenColor("Black");
	SetPointSize(30);
	char s[12] ;
	sprintf(s, "Life Left: %d ", map.time/1000);
	MovePen(GetWindowWidth() - 5.5,GetWindowHeight() - 1);
	DrawTextString(s);
}


/* todo: for buttons */
void myMouseEventGame(int x, int y, int button, int event){
	
	// Get My Mouse Pixel
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	uiGetMouse(x, y, button, event); // needed for using simpleGUI
	
	switch (event){
		case BUTTON_UP:{
			if (button == LEFT_BUTTON){
				if (mx >= 14.5 && my >= 5.5 && mx <= 16.5 && my <= 6.5){
					/* Show Shortest Path */
					findPath(me, destination);
					HIGHLIGHT = TRUE;
				}
				else if (mx >= 14.5 && my >= 4 && mx <= 16.5 && my <= 5){
					/* Quit */
					cancelMouseEvent(myMouseEventGame);
					cancelKeyboardEvent(myKeyboardEventGame);
					cancelTimerEvent(count_down);
					DisplayExit();
				}
			break;
			}

		}
		case MOUSEMOVE:
		default:
			DisplayMapDefault();
	} 
	
}

/* calc currnet time */
void timer(int timerID){
	switch (timerID)
	{
		case count_down:{
			if(HIGHLIGHT == TRUE)
				cnt++;
			if(cnt>=3){
				cnt = 0;
				HIGHLIGHT = FALSE;
			}
			printf("%d\n", cnt);
			if (map.time > 0)
			{
				DisplayMapDefault();
				map.time -= 500;
			}
			else
			{
				isWin = FALSE;
				cancelTimerEvent(count_down);
				cancelMouseEvent(myMouseEventGame);
				cancelKeyboardEvent(myKeyboardEventGame);
				DisplayExit();
			}
		}
	}
}

/* WASD to move */
void myKeyboardEventGame(int key, int event){
	
	switch (event){
		case KEY_UP:
			if (key == 'Q'){
				/* Quit */
				cancelMouseEvent(myMouseEventGame);
				cancelKeyboardEvent(myKeyboardEventGame);
				cancelTimerEvent(count_down);
				DisplayExit();
			}
			if (key == 'W')
			{
				if(me.y-1 >= 0&&map.arrangement[me.x][me.y-1]!=TREE&&((map.arrangement[me.x][me.y-1]!=DOOR)||(map.arrangement[me.x][me.y-1]==DOOR&&isWithKey==TRUE))){
					map.arrangement[me.x][me.y] = EMPTY;
					me.y -= 1;
					if(map.arrangement[me.x][me.y]==KEY){
						isWithKey = TRUE;
					}
					map.arrangement[me.x][me.y] = ME;
					DisplayMapDefault();	
				}
				if(me.x == destination.x && me.y == destination.y){
					isWin = TRUE;
					time(&currentTime);
					cancelTimerEvent(count_down);
					cancelMouseEvent(myMouseEventGame);
					cancelKeyboardEvent(myKeyboardEventGame);
					cancelTimerEvent(count_down);
					DisplayExit();
				}
			}
			
			if (key == 'A')
			{
				if(me.x-1 >= 0 && map.arrangement[me.x-1][me.y] != TREE&&((map.arrangement[me.x-1][me.y]!=DOOR)||(map.arrangement[me.x-1][me.y]==DOOR&&isWithKey==TRUE))){
					map.arrangement[me.x][me.y] = EMPTY;
					me.x -= 1;
					if(map.arrangement[me.x][me.y]==KEY){
						isWithKey = TRUE;
					}
					map.arrangement[me.x][me.y] = ME;
					DisplayMapDefault();	
				}

				if(me.x == destination.x && me.y == destination.y){
					isWin = TRUE;
					time(&currentTime);
					cancelTimerEvent(count_down);
					cancelMouseEvent(myMouseEventGame);
					cancelKeyboardEvent(myKeyboardEventGame);
					DisplayExit();
				}
			}
			
			if (key == 'S')
			{
				if(me.y+1 <= map.size-1 && map.arrangement[me.x][me.y+1] != TREE&&((map.arrangement[me.x][me.y+1]!=DOOR)||(map.arrangement[me.x][me.y+1]==DOOR&&isWithKey==TRUE))){
					map.arrangement[me.x][me.y] = EMPTY;
					me.y += 1;
					if(map.arrangement[me.x][me.y]==KEY){
						isWithKey = TRUE;
					}
					map.arrangement[me.x][me.y] = ME;
					DisplayMapDefault();	
				}

				if(me.x == destination.x && me.y == destination.y){
					isWin = TRUE;
					time(&currentTime);
					cancelMouseEvent(myMouseEventGame);
					cancelKeyboardEvent(myKeyboardEventGame);
					cancelTimerEvent(count_down);
					DisplayExit();
				}

			}
			
			if (key == 'D')
			{
				if(me.x+1 <= map.size-1 && map.arrangement[me.x+1][me.y] != TREE&&((map.arrangement[me.x+1][me.y]!=DOOR)||(map.arrangement[me.x+1][me.y]==DOOR&&isWithKey==TRUE))){
					map.arrangement[me.x][me.y] = EMPTY;
					me.x += 1;
					if(map.arrangement[me.x][me.y]==KEY){
						isWithKey = TRUE;
					}
					map.arrangement[me.x][me.y] = ME;
					DisplayMapDefault();	
				}

				if(me.x == destination.x && me.y == destination.y){
					isWin = TRUE;
					time(&currentTime);
					cancelMouseEvent(myMouseEventGame);
					cancelKeyboardEvent(myKeyboardEventGame);
					cancelTimerEvent(count_down);
					DisplayExit();
				}
			}
	}	
}


void DisplayMap(){
	
	/* initialize path matrix */
	int i, j;
	for (i = 0; i < map.size; i++)
		for (j = 0; j < map.size; j++)
			path[i][j] = 0;	
	
	
	/* find the shortest path for display */
	findPath(me, key);
	findPath(key, door);
	findPath(door, destination);

	/* Determine whether there are key/door in the map */
	isWithKey = TRUE; 
	for (i = 0; i < map.size; i++)
		for (j = 0; j > map.size; j++){
			if (map.arrangement[i][j] == KEY)
				isWithKey = FALSE;
		}
	
	
	O.x = 5;
	O.y = window_size.y - 0.5;
	
	/* register callback function */
	registerMouseEvent(myMouseEventGame);	
	registerKeyboardEvent(myKeyboardEventGame); 
	registerTimerEvent(timer);
	startTimer(count_down, 1000);
	
	/* display a map*/
	time(&startTime);
	PRESSED=FALSE;
	OnlyNext=TRUE;
	DisplayMapDefault();
}


#include "headers\\DisplayGUI.h"


/// @brief default GUI display, draw 5 buttons
void DisplayGUIDefault()
{
    DisplayClear();
    SetPenColor("Background");
	drawBox(0, 0, window_size.x, window_size.y, 1, "", 's', "Background");
	
	SetPenSize(3);
    double width = GetWindowWidth();
	double height = GetWindowHeight();
	mini.x=width/10.0; mini.y=height/11.0;
	button(GenUIID(0),mini.x*3,mini.y*1,mini.x*4,mini.y*1,PRESSED ? "level 5" : "Choose Level 5. 一个25*25的地图。需要钥匙开门。");
	button(GenUIID(0),mini.x*3,mini.y*3,mini.x*4,mini.y*1,PRESSED ? "level 4" : "Choose Level 4. 一个25*25的地图。较简单。");
    button(GenUIID(0),mini.x*3,mini.y*5,mini.x*4,mini.y*1,PRESSED ? "level 3" : "Choose Level 3. 一个20*20的地图。");
    button(GenUIID(0),mini.x*3,mini.y*7,mini.x*4,mini.y*1,PRESSED ? "level 2" : "Choose Level 2. 一个15*15的地图。");
    button(GenUIID(0),mini.x*3,mini.y*9,mini.x*4,mini.y*1,PRESSED ? "level 1" : "Choose Level 1. 一个10*10的地图。");
    
    /* back button */
    SetPenColor("Headline1");
	button(GenUIID(0), 14.5, 1, 3, 1, "返回主界面");
	
}

/// @brief mouse event for GUI
void myMouseEventGUI (int x, int y, int button, int event)
{
	// Get My Position
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	uiGetMouse(x, y, button, event); // needed for using simpleGUI

	switch (event)
		{
		case BUTTON_UP:{
			if (button == LEFT_BUTTON)
				if( mx>mini.x*3 && mx<mini.x*7 && my>mini.y && my<mini.y*2)
				{
					/* Level 5 */
					DisplayClear();
					level = 5;
						/* new a map */
					GenerateMapStatic(level);
					cancelMouseEvent();
					DisplayMap();
					
					break;
					// here is inverse because the graph is top to bottom but the mx,my is bottom to top
				}
				else if(mx>mini.x*3 && mx<mini.x*7 && my>mini.y*3 && my<mini.y*4)
				{
					/* Level 4 */
					DisplayClear();
					level = 4;
						/* new a map */
					GenerateMapStatic(level);
					cancelMouseEvent();
					DisplayMap();
					
					break;
				}
				else if(mx>mini.x*3 && mx<mini.x*7 && my>mini.y*5 && my<mini.y*6)
				{
					/* Level 3 */
					DisplayClear();
					level = 3;
					/* new a map */
					GenerateMapStatic(level);
					cancelMouseEvent();
					DisplayMap();
					
					break;
				}
				else if(mx>mini.x*3 && mx<mini.x*7 && my>mini.y*7 && my<mini.y*8)
				{
					/* Level 2 */
					DisplayClear();
					level = 2;
					/* new a map */
					GenerateMapStatic(level);
					cancelMouseEvent();
					DisplayMap();
					
					break;
				}
				else if(mx>mini.x*3 && mx<mini.x*7 && my>mini.y*9 && my<mini.y*10)
				{
					/* Level 1 */
					DisplayClear();
					level = 1;
					/* new a map */
					GenerateMapStatic(level);
					cancelMouseEvent();
					DisplayMap();
					
					break;
				}
				else if(mx >= 14.5 && mx <= 17.5 && my >= 1 && my <= 2)
				{
					/* score list */
                    cancelMouseEvent(myMouseEventGUI);
					DisplayMainGUI();
				}
		}
		case MOUSEMOVE:
		default:
			DisplayGUIDefault();
		}
	
}
void DisplayGUI(){
	DisplayGUIDefault();
	registerMouseEvent(myMouseEventGUI);
}

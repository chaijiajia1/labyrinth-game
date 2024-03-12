#include "headers\\DisplayMainGUI.h"

void DisplayMainGUIDefault()
{
	DisplayClear();
	
	SetPenColor("Background");
	drawBox(0, 0, window_size.x, window_size.y, 1, "", 's', "Background");
	
	/* Draw Title */
	SetPointSize(50);
	SetPenColor("Headline1");
	MovePen(window_size.x/2-2.5, window_size.y - 1);
	DrawTextString("Labyrinth Generator");
	
	SetPointSize(25);
	SetPenColor("Headline2");
	MovePen(window_size.x/2-1.75, window_size.y - 1.5);
	DrawTextString("Make your maps and play");
	
	/* Buttons */
	SetPenSize(3);
	
    double width = GetWindowWidth();
	double height = GetWindowHeight();
	mini1.x = width/20.0; 
	mini1.y = height/10.0;
	
	
	
	/* Todo: rearrange the GUI */
	SetPenColor("ButtonText");
	SetPointSize(30);
    button(GenUIID(0),mini1.x*3,mini1.y*4,mini1.x*6,mini1.y*4,"DIY Map");
    button(GenUIID(0),mini1.x*11,mini1.y*4,mini1.x*6,mini1.y*4,"My Maps");
    
	SetPointSize(35);
	button(GenUIID(0),mini1.x*3,mini1.y*1,mini1.x*4,mini1.y*2,"Play with Default");
    button(GenUIID(0),mini1.x*8,mini1.y*1,mini1.x*4,mini1.y*2,"Show Score List");
    button(GenUIID(0),mini1.x*13,mini1.y*1,mini1.x*4,mini1.y*2,"Quit");
    
        
    SetPointSize(20);
    button(GenUIID(0), GetWindowWidth() - 1, GetWindowHeight() - 1, 0.5, 0.5, "?"); 
    
    
}
void myMouseEventMainGUI (int x, int y, int button, int event)
{
	// Get My Mouse Pixel
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	uiGetMouse(x, y, button, event); // needed for using simpleGUI

	switch (event)
		{
		case BUTTON_UP:{
			if (button == LEFT_BUTTON){
				if( mx>mini1.x*3 && mx<mini1.x*7 && my>mini1.y && my<mini1.y*3)
				{
					/* choose level */
                    cancelMouseEvent(myMouseEventMainGUI);
					DisplayGUI();
				}
				else if(mx>mini1.x*9 && mx<mini1.x*13 && my>mini1.y && my<mini1.y*3)
				{
					/* score list */
                    cancelMouseEvent(myMouseEventMainGUI);
					DisplayScoreList();
				}
				else if(mx>mini1.x*13 && mx<mini1.x*17 && my>mini1.y && my<mini1.y*3)
				{
					/* quit */
                    cancelMouseEvent(myMouseEventMainGUI);
					exit(-1);
				}
				else if(mx>mini1.x*3 && mx<mini1.x*9 && my>mini1.y*4 && my<mini1.y*9)
				{
                	/* DIY map */
                    cancelMouseEvent(myMouseEventMainGUI);
                    DisplayDIYMap();
				}
				else if(mx>mini1.x*11 && mx<mini1.x*17 && my>mini1.y*4 && my<mini1.y*8)
                {
                    /* DIY list */
                    cancelMouseEvent(myMouseEventMainGUI);
					DisplayDIYList();
                }
                else if(mx>GetWindowWidth()-1 && mx<GetWindowWidth()-0.5 && my>GetWindowHeight()-1 && GetWindowHeight()-0.5){
                	/* Help */
                	cancelMouseEvent(myMouseEventMainGUI);
                	DisplayHelp();
				}
			break;
		}
		case MOUSEMOVE:
		default:
			DisplayMainGUIDefault();
		}
		}
}
void DisplayMainGUI(){
	registerMouseEvent(myMouseEventMainGUI);
	DisplayMainGUIDefault();
}


#include "headers\\DisplayHelp.h"

void myMouseEventHelp(int x, int y, int button, int event)
{
	// Get My Mouse Pixel
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	uiGetMouse(x, y, button, event); // needed for using simpleGUI

	switch (event)
		{
		case BUTTON_UP:{
			if (button == LEFT_BUTTON){
				if(mx >= 14.5 && mx <= 17.5 && my >= 1 && my <= 2)
				{
					/* Back */
                    cancelMouseEvent(myMouseEventHelp);
					DisplayMainGUI();
				}
			}
			break;
		}
		case MOUSEMOVE:
		default:
		DisplayHelpDefault();
		}
}

void DisplayHelpDefault(){
    
	DisplayClear();

	/* Background */
	SetPenColor("Background");
	drawBox(0, 0, window_size.x, window_size.y, 1, "", 's', "Background");
	
	/* Prompts */
	SetPointSize(40);
	SetPenColor("Headline2");
	MovePen(window_size.x/2-5, window_size.y - 1.5);
	DrawTextString("故事");
	
	SetPointSize(20);
	SetPenColor("Text");
	MovePen(window_size.x/2-5, window_size.y-2.5);
	DrawTextString("你被困在了一片森林中。你的体力不足，只能支撑一定时间。");
	MovePen(window_size.x/2-5, window_size.y-3);
	DrawTextString("避开树木，找到钥匙，打开门，努力找到走出森林的路！");
	

	SetPointSize(40);
	SetPenColor("Headline2");
	MovePen(window_size.x/2-5, window_size.y - 4);
	DrawTextString("游戏帮助");
	
	SetPointSize(20);
	SetPenColor("Text");
	MovePen(window_size.x/2-5, window_size.y-5);
	DrawTextString("DIY Map: 您可以在此页面自定义一份地图，并保存在选定位置。");
	MovePen(window_size.x/2-5, window_size.y-5.5);
	DrawTextString("My DIY Maps: 您可以在此页面加载您之前设计的地图并开始游戏。");
	MovePen(window_size.x/2-5, window_size.y-6);
	DrawTextString("Play with Default: 您可以在此页面加载预设的5份地图并开始游戏。");
	MovePen(window_size.x/2-5, window_size.y-6.5);
	DrawTextString("Show Score List: 您可以在此页面查看游戏分数最高的前5名用户。");
	MovePen(window_size.x/2-5, window_size.y-7);
	DrawTextString("Quit: 点此退出游戏。 ");
    
    /* back button */
    SetPenColor("Headline1");
	button(GenUIID(0), 14.5, 1, 3, 1, "返回主界面");
	
}

void DisplayHelp(){
	registerMouseEvent(myMouseEventHelp);
	DisplayHelpDefault();
}


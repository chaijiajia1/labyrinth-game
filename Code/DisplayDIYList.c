#include "headers\\DisplayDIYList.h"

void DisplayDIYListDefault(){
	
	DisplayClear();
	
	/* Prompts */
	SetPenColor("Background");
	drawBox(0, 0, window_size.x, window_size.y, 1, "", 's', "Background");
	
	SetPointSize(15);
	SetPenColor("Headline1");
	MovePen(window_size.x/2 + 4.5, window_size.y - 1);
	DrawTextString("My DIY Maps");
	MovePen(window_size.x/2 + 4.5, window_size.y - 1.5);
	DrawTextString("������ڱ�������ʱ�´����ĵ�ͼû����ȷ���أ�");
	MovePen(window_size.x/2 + 4.5, window_size.y - 2);
	DrawTextString("�볢�������������ܿ����µ�ͼ��ȷ���ء�");
	
	/* Buttons */
	button(GenUIID(0), 14.5, 6, 1, 1, "�浵1");
	button(GenUIID(0), 16.5, 6, 1, 1, "�浵2");
	button(GenUIID(0), 14.5, 4.5, 1, 1, "�浵3");
	button(GenUIID(0), 16.5, 4.5, 1, 1, "�浵4");
	button(GenUIID(0), 14.5, 3, 3, 1, "�ڵ�ǰ�浵��ʼ��Ϸ");
	
	/* back button */
    SetPenColor("Headline1");
	button(GenUIID(0), 14.5, 1, 3, 1, "����������");
	
	/* Draw Map */
	Pixel O;
	O.x = 5;
	O.y = window_size.y - 0.5;
	
	int i, j;
	
	for (i = 0; i < map.size; i++)
		for (j = 0; j < map.size; j++)
		{
			Pixel start;
			start.x = O.x + i*blockSize;
			start.y = O.y - j*blockSize;

			DrawBlock(start, map.arrangement[i][j]);
		}

}


// todo: map size has to be initialized
void myMouseEventDIYList (int x, int y, int button, int event){
	
	// Get My Position
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	uiGetMouse(x, y, button, event); // needed for using simpleGUI

	switch (event)
		{
		case BUTTON_UP:{
			if (button == LEFT_BUTTON){
				if (mx >= 14.5 && mx <= 15.5 && my >= 6 && my <= 7)	{
					GenerateMapStaticDIY(1);	// isDIY = TRUE
				}	
				else if (mx >= 16.5 && mx <= 17.5 && my >= 6 && my <= 7){
					GenerateMapStaticDIY(2);
				}
				else if (mx >= 14.5 && mx <= 15.5 && my >= 4.5 && my <= 5.5){
					GenerateMapStaticDIY(3);
				}
				else if(mx >= 16.5 && mx <= 17.5 && my >= 4.5 && my <= 5.5){
					GenerateMapStaticDIY(4);
				}			
				else if(mx >= 14.5 && mx <= 17.5 && my >= 3 && my <= 4){
					cancelMouseEvent(myMouseEventDIYList);
					DisplayMap();
				}		
				else if(mx >= 14.5 && mx <= 17.5 && my >= 1 && my <= 2){
					// map.arrangement = NULL;
					cancelMouseEvent(myMouseEventDIYList);
					DisplayMainGUI();
				}		
			}
		}
		case MOUSEMOVE:
		default:
			DisplayDIYListDefault();
		}
}	
	

void DisplayDIYList(){
	GenerateMapEmpty();
	registerMouseEvent(myMouseEventDIYList);
	DisplayDIYListDefault();
	
}

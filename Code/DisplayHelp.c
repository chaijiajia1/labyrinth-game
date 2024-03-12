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
	DrawTextString("����");
	
	SetPointSize(20);
	SetPenColor("Text");
	MovePen(window_size.x/2-5, window_size.y-2.5);
	DrawTextString("�㱻������һƬɭ���С�����������㣬ֻ��֧��һ��ʱ�䡣");
	MovePen(window_size.x/2-5, window_size.y-3);
	DrawTextString("�ܿ���ľ���ҵ�Կ�ף����ţ�Ŭ���ҵ��߳�ɭ�ֵ�·��");
	

	SetPointSize(40);
	SetPenColor("Headline2");
	MovePen(window_size.x/2-5, window_size.y - 4);
	DrawTextString("��Ϸ����");
	
	SetPointSize(20);
	SetPenColor("Text");
	MovePen(window_size.x/2-5, window_size.y-5);
	DrawTextString("DIY Map: �������ڴ�ҳ���Զ���һ�ݵ�ͼ����������ѡ��λ�á�");
	MovePen(window_size.x/2-5, window_size.y-5.5);
	DrawTextString("My DIY Maps: �������ڴ�ҳ�������֮ǰ��Ƶĵ�ͼ����ʼ��Ϸ��");
	MovePen(window_size.x/2-5, window_size.y-6);
	DrawTextString("Play with Default: �������ڴ�ҳ�����Ԥ���5�ݵ�ͼ����ʼ��Ϸ��");
	MovePen(window_size.x/2-5, window_size.y-6.5);
	DrawTextString("Show Score List: �������ڴ�ҳ��鿴��Ϸ������ߵ�ǰ5���û���");
	MovePen(window_size.x/2-5, window_size.y-7);
	DrawTextString("Quit: ����˳���Ϸ�� ");
    
    /* back button */
    SetPenColor("Headline1");
	button(GenUIID(0), 14.5, 1, 3, 1, "����������");
	
}

void DisplayHelp(){
	registerMouseEvent(myMouseEventHelp);
	DisplayHelpDefault();
}


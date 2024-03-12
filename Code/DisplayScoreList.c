#include "headers\\DisplayScoreList.h"

void myMouseEventScoreList(int x, int y, int button, int event)
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
					/* score list */
                    cancelMouseEvent(myMouseEventScoreList);
					DisplayMainGUI();
				}
			}
			break;
		}
		case MOUSEMOVE:
		default:
		DisplayScoreListDefault();
		}
}

void DisplayScoreListDefault(){
    
	DisplayClear();

	/* Background */
	SetPenColor("Background");
	drawBox(0, 0, window_size.x, window_size.y, 1, "", 's', "Background");
	
	/* Texts */
	SetPenColor("Headline1");
	SetPointSize(50);
	MovePen(2, 8); 
	DrawTextString("Score List");

   FILE  *fp=fopen("Data\\score.txt","r");	// open file/create file
    ScoreList *head=NULL;ScoreList *p=NULL;ScoreList *pf=head;
    if(fp!=NULL)	// If file opened
    {
        // get the content of the file
        while (!feof(fp)) {		// if not the file end
            p=(ScoreList*)malloc(sizeof(ScoreList));p->next=NULL;
            fscanf(fp,"%s %d\n",p->name,&p->score);
            if(pf==NULL)head=p;
            else pf->next=p;
            pf=p;
        }
    }
    fclose(fp);
    p=head;
    int draw_x=10;
	int cnt=1;
    SetPenColor("Headline2");
    SetPointSize(20);
	while(p!=NULL&&cnt<=10){
        char s[20] ;
        MovePen(mini1.x*2,mini1.y*(8-cnt));
	    sprintf(s, "%d : %s with %d points", cnt,p->name,p->score);
        DrawTextString(s);
        cnt++;
        p=p->next;
    }
    
    /* back button */
    SetPenColor("Headline1");
	button(GenUIID(0), 14.5, 1, 3, 1, "返回主界面");
	
}

void DisplayScoreList(){
	registerMouseEvent(myMouseEventScoreList);
	DisplayScoreListDefault();
}

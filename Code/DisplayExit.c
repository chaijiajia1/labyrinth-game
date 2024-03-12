#include "headers\\DisplayExit.h"
int Auto=0;
void DisplayExitDefault(){
	
	DisplayClear();
	
	SetPenColor("Background");
	drawBox(0, 0, window_size.x, window_size.y, 1, "", 's', "Background");
	
	/* Prompts-left */
	MovePen(mini1.x*1,mini1.y*9);
	SetPenColor("Headline1");
	SetPointSize(50);	// Font Size
	isWin? DrawTextString("You Win!"):DrawTextString("You Loss!");
	SetPointSize(13);
	
	char s[20];
	sprintf(s, "Your score is: %d ", 100-currentTime+startTime);
	MovePen(mini1.x*1,mini1.y*8);
	DrawTextString(s);

	SetPenColor("Headline2"); 
	drawLabel(mini1.x*1,mini1.y*7,"Please input your name:");
	textbox(GenUIID(0), mini1.x*1,mini1.y*5.5 , mini1.x*2.5, mini1.y, Name, sizeof(Name));
	
	/* Prompts-right */
	SetPenColor("Headline1");	
	MovePen(mini1.x*15,mini1.y*9.4);
	DrawTextString("自动求解该地图：");
	SetPenColor("Headline2");
	MovePen(mini1.x*15,mini1.y*9);
	DrawTextString("正序是求解地图过程，");
	MovePen(mini1.x*15,mini1.y*8.6);
	DrawTextString("到达终点后会回退显示求解最短路过程。");
	MovePen(mini1.x*15,mini1.y*8.2);
	DrawTextString("循环点击显示最短路，将展示所有路径。");
	
	button(GenUIID(0),mini1.x*15,mini1.y*4,mini1.x*3,mini1.y*1,"显示最短路");	//显示下一个格子 
	button(GenUIID(0),mini1.x*15,mini1.y*5.5,mini1.x*3,mini1.y*1,"显示下一格");	//可视化最短路 
	button(GenUIID(0),mini1.x*15,mini1.y*1,mini1.x*3,mini1.y*1,"提交到排行榜");	//提交 
	button(GenUIID(0),mini1.x*15,mini1.y*7,mini1.x*3,mini1.y*1,Auto?"暂停自动求解":"自动求解");	//自动显示下一步格子 

	int i, j;
	for (i = 0; i < map.size; i++)
		for (j = 0; j < map.size; j++)
		{
			Pixel start;
			start.x = O.x+i*blockSize;
			start.y = O.y-j*blockSize;

			DrawBlock(start, map.arrangement[i][j]);
		}
	
	if(displayshorestpath==1&&maphaskey==0){
		if(choice>routelines)choice=choice-routelines;
	for (i=1;i<=(*(*(route+choice))).x;i++){
		    Pixel start;
			start.x = O.x+(*(*(route+choice)+i)).x*blockSize;
			start.y = O.y-(*(*(route+choice)+i)).y*blockSize;
			
		    StartFilledRegion(0.5); 
			
			SetPenColor("Yellow"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			EndFilledRegion(); 
			}

  		}
  		
  			if(displayshorestpath==1&&maphaskey==1){
  		if(choice>tokeylines*keytolines)choice=choice-tokeylines*keytolines;
  		int tokeynum=1,keytonum=0;
  		tokeynum=(choice-1)/keytolines+1;
		keytonum=(choice-1)%keytolines+1;
	for (i=1;i<=(*(*(tokeyroute+tokeynum))).x;i++){
		    Pixel start;
			start.x = O.x+(*(*(tokeyroute+tokeynum)+i)).x*blockSize;
			start.y = O.y-(*(*(tokeyroute+tokeynum)+i)).y*blockSize;
			
		    StartFilledRegion(0.3); 
			
			SetPenColor("Yellow"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			EndFilledRegion(); 
			}
	for (i=1;i<=(*(*(keytoroute+keytonum))).x;i++){
		    Pixel start;
			start.x = O.x+(*(*(keytoroute+keytonum)+i)).x*blockSize;
			start.y = O.y-(*(*(keytoroute+keytonum)+i)).y*blockSize;
			
		    StartFilledRegion(0.3); 
			
			SetPenColor("Green"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			EndFilledRegion(); 
			}
  		}
  		
	if(processionflag==1){
		if(processionnum!=processionnumrepeat&&processionnum<procession){
			if(Visualizedblock[Visualized[processionnum].x][Visualized[processionnum].y]==0)
				Visualizedblock[Visualized[processionnum].x][Visualized[processionnum].y]=1;
			else if (Visualizedblock[Visualized[processionnum].x][Visualized[processionnum].y]==1)
			  	Visualizedblock[Visualized[processionnum].x][Visualized[processionnum].y] =0;
			  	processionnumrepeat=processionnum;
			}
		
	/* all the path */
  	for(i=0;i<map.size;i++){
		for (j=0;j<map.size;j++){
			if(Visualizedblock[i][j]==1){
			    Pixel start;
				start.x = O.x+i*blockSize;
				start.y = O.y-j*blockSize;
				
			    StartFilledRegion(0.5); 
				
				SetPenColor("Yellow"); 
				MovePen(start.x, start.y);
				DrawLine(0,-blockSize);
				DrawLine(blockSize,0);
				DrawLine(0, blockSize);
				DrawLine(-blockSize,0);
				
				EndFilledRegion(); 
				}
			}
		}
	}
}

void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); DisplayExitDefault();
}

void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); DisplayExitDefault();
}



void CharEventProcess(char ch)
{
	uiGetChar(ch); 
	DisplayExitDefault();
}
void myMouseEventExit (int x, int y, int button, int event)
{
	// Get Mouse Position
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	uiGetMouse(x, y, button, event); // needed for using simpleGUI

	switch (event)
		{
		case BUTTON_UP:{
			if (button == LEFT_BUTTON){
				if( mx>mini1.x*15 && mx<mini1.x*18 && my>mini1.y && my<mini1.y*2)
				{
                    cancelMouseEvent(myMouseEventExit);
					cancelCharEvent(CharEventProcess);
					cancelKeyboardEvent(KeyboardEventProcess);
					printf("%d",(int)(currentTime-startTime));
					RenewScoreList(Name,isWin?(100-(int)(currentTime-startTime)/level):0);
					DisplayScoreList();
				}
				else if(mx>mini1.x*15 && mx<mini1.x*18 && my>mini1.y*4 && my<mini1.y*5){
					printf("ALL");
					if(displayshorestpath==1)choice++;
					processionflag=0;
					displayshorestpath=1;
					DisplayExitDefault();
				}
				else if(mx>mini1.x*15 && mx<mini1.x*18 && my>mini1.y*5.5 && my<mini1.y*6.5){
					// printf("one");
					if(processionflag==1)processionnum++;
					displayshorestpath=0;
					processionflag=1;
					 
					DisplayExitDefault();
				}
				else if(mx>mini1.x*15 && mx<mini1.x*18 && my>mini1.y*7 && my<mini1.y*8){
					Auto=!Auto;
					printf("Auto is %d",Auto);
					if(Auto==1){
						registerTimerEvent(timer1);
						startTimer(auto_timer, 1000);
					}
					else cancelTimerEvent(auto_timer);
				}
			break;
		}
		case MOUSEMOVE:
		default:
			DisplayExitDefault();
		}
		}
}
void DisplayExit(){
	
	/* initialize the path display matrix */
	int i,j;
	for(i=0;i<map.size;i++){
		for(j=0;j<map.size;j++){
			Visualizedblock[i][j]=0;
		}
	}
	
	/* variables for find all the paths */
	displayshorestpath=0;
	processionflag=0;
	processionnum=0;
	processionnumrepeat=-1;
	maphaskey=0;
	choice=1;
	procession=0;
	
		for (i = 0; i < map.size; i++){
		for (j = 0; j < map.size; j++){
			if (map.arrangement[i][j] == KEY){
			key.x=i;
			key.y=j;
				maphaskey = 1;
			}
			if(map.arrangement[i][j] == DOOR){
				door.x=i;
				door.y=j;
			}
			if(map.arrangement[i][j] == ME){
				me.x=i;
				me.y=j;
			}
			if(map.arrangement[i][j] == DESTINATION){
				destination.x=i;
				destination.y=j;
			}
		}}
		if(maphaskey==1){
			map.arrangement[door.x][door.y] == TREE;
			findAllPath(me,key);
			tokeyroute=route;
			tokeylines=routelines;
			map.arrangement[door.x][door.y] == PATH;
			findAllPath(key,destination);
			keytoroute=route;
			keytolines=routelines;
		}		
		else{
			findAllPath(me,destination);
		}
	
	registerMouseEvent(myMouseEventExit);	
	registerKeyboardEvent(KeyboardEventProcess); 
	registerCharEvent(CharEventProcess);
	DisplayExitDefault();
		
}

void timer1(int timerID){
	switch (timerID)
	{
		case auto_timer:{
		if(processionflag==1)
			processionnum++;
		processionflag=1;
		DisplayExitDefault();	
		}
	}
}


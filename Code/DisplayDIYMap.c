#include "headers\\DisplayDIYMap.h"

/* Display DIY Map */
void DisplayDIYMapDefault(){

	DisplayClear();
	
	/* Background */
	SetPenColor("Background");
	drawBox(0, 0, window_size.x, window_size.y, 1, "", 's', "Background");
	
	/* Prompts: right */
	SetPointSize(30);
	MovePen(14.5, 8.5);
	SetPenColor("Headline1");
	DrawTextString("DIY地图");
	/* errors */ 
	SetPointSize(13);
	SetPenColor("Headline2");	
	if(CheckUniqueness()==-1) {
		MovePen(14.5, 7);
		DrawTextString("图中至少要有一个起点和终点，请检查。"); 
	}
	if(CheckUniqueness()==-2){
		MovePen(14.5, 6.6);
		DrawTextString("图中至多只能有一个起点和一个终点，请检查。");
	} 
	if(CheckUniqueness()==-3){
		MovePen(14.5, 6.2);
		DrawTextString("大门需要钥匙来打开，请添加一把钥匙。");
	}
	if(CheckUniqueness()==-4){
		MovePen(14.5, 5.8);
		DrawTextString("图中至多只能有一扇紧闭大门和一把钥匙，请检查。");
	} 
	if(CheckUniqueness()==-5){
		MovePen(14.5, 5.4);
		DrawTextString("当前角色位置不可达终点，请检查。");
	} 
	if(CheckUniqueness()==-6){
		MovePen(14.5, 5.0);
		DrawTextString("当前角色位置不可经由钥匙和门达到终点，请检查。");
	} 
	
	/* Prompts: left */
	SetPointSize(13);
	SetPenColor("Headline2");
	MovePen(1.5, 8.2);
	DrawTextString("画一个: ");
	MovePen(1.5, 3.7);
	DrawTextString("将该地图保存到: ");


	/* Buttons */
	button(GenUIID(0), 1.5, 8.5, 3, 1, "随机一个地图！");
	
	button(GenUIID(0), 1.5, 7, 1, 1, "空地");
	button(GenUIID(0), 3.5, 7, 1, 1, "障碍树");
	button(GenUIID(0), 1.5, 5.5, 1, 1, "钥匙");
	button(GenUIID(0), 3.5, 5.5, 1, 1, "紧闭大门");
	button(GenUIID(0), 1.5, 4, 1, 1, "您的位置");
	button(GenUIID(0), 3.5, 4, 1, 1, "森林出口");
	
	button(GenUIID(0), 1.5, 2.5, 1, 1, "存档 1");
	button(GenUIID(0), 3.5, 2.5, 1, 1, "存档 2");
	button(GenUIID(0), 1.5, 1, 1, 1, "存档 3");
	button(GenUIID(0), 3.5, 1, 1, 1, "存档 4");
	
	button(GenUIID(0), 14.5, 3, 2, 1, PRESSED? "隐藏最短路": "显示最短路");
	button(GenUIID(0), 14.5, 1, 2, 1, "返回主界面");
	
	/* Maps */
	Pixel O;
	O.x = 5;
	O.y = window_size.y - 0.5;
	
	int i, j;
	
	for (i = 0; i < map.size; i++)
		for (j = 0; j < map.size; j++)
		{
			Pixel start;
			start.x = O.x+i*blockSize;
			start.y = O.y-j*blockSize;
			if (PRESSED == TRUE){
				OnlyNext=FALSE;
				HighlightPath(start, path[i][j]);
				
			}
			DrawBlock(start, map.arrangement[i][j]);
		}

}

/* Choose Draw Status */
void myMouseEventDIYMap(int x, int y, int button, int event){
	
	// Get My Mouse Pixel
	double mx = ScaleXInches(x);
	double my = ScaleYInches(y);
	uiGetMouse(x, y, button, event); // needed for using simpleGUI
	
	switch (event){
		case BUTTON_UP:{
			if (button == LEFT_BUTTON){
				
				/* Buttons */
				if (mx >= 1.5 && my >= 8.5 && mx <= 4.5 && my <= 9.5){	
					/* Get a random one*/
					GenerateMapRandom(); 
				}
				else if (mx >= 1.4 && my >= 7 && mx <= 2.5 && my <= 8){
					currentDraw = EMPTY;
				}
				else if (mx >= 3.5 && my >= 7 && mx <= 4.5 && my <= 8){
					currentDraw = TREE; 
				}
	
				else if (mx >= 1.5 && my >= 5.5 && mx <= 2.5 && my <= 6.5){
					currentDraw = KEY;
				}
	
				else if (mx >= 3.5 && my >= 5.5 && mx <= 4.5 && my <= 6.5){			
					currentDraw = DOOR;
				}
	
				else if (mx >= 1.5 && my >= 4 && mx <= 2.5 && my <= 5){
					currentDraw = ME; 
				}
	
				else if (mx >= 3.5 && my >= 4 && mx <= 4.5 && my <= 5){
					currentDraw = DESTINATION;	
				}
				
				// TODO: Check single user, single destination, single key, single door, check reachable 
				else if (mx >= 1.5 && my >= 2.5 && mx <= 2.5 && my <= 3.5){
					
					/* Save as map1 */
					if(CheckUniqueness()==TRUE)
					SaveMap(1);
				}
				else if (mx >= 3.5 && my >= 2.5 && mx <= 4.5 && my <= 3.5){
					/* Save as map2 */
					if(CheckUniqueness()==TRUE)
					SaveMap(2);
					
				}
				else if (mx >= 1.5 && my >= 1 && mx <= 2.5 && my <= 2){
					/* Save as map3 */
					if(CheckUniqueness()==TRUE)
					SaveMap(3);
				}
				else if (mx >= 3.5 && my >= 1 && mx <= 4.5 && my <= 2){
					/* Save as map4 */
					if(CheckUniqueness()==TRUE)
					SaveMap(4);
				}
				else if (mx >= 14.5 && my >= 3 && mx <= 17.5 && my <= 4){
					/* highlight path */
					PRESSED = !PRESSED;
				}
				else if (mx >= 14.5 && my >= 1 && mx <= 17.5 && my <= 2){
					/* Back */
					cancelMouseEvent(myMouseEventDIYMap);
					map.arrangement = NULL;
					DisplayMainGUI();
				}

				/* Map Area */
				Pixel O;
				O.x = 5;
				O.y = window_size.y - 0.5;	
				/* Block searching */
				if (mx >= O.x && my <= O.y && mx <= O.x+(map.size)*blockSize && my >= O.y-(map.size)*blockSize){
					Coordinate draw;
					draw.x = (mx-O.x)/blockSize;
					draw.y = (O.y-my)/blockSize;
					map.arrangement[draw.x][draw.y] = currentDraw;	
					}	


/* This code block is commented on purpose.
 * It is the first block searching algorithm we design, with worse time complexity. (O(log^2n))
 * The faster version is right above it. (O(1))
 * A description of this seciton can be found in the time complexity section in our report.
 */
// 				/* Block searching */
//				int i, j;
//				for (i = 0; i < map.size; i++)
//					for (j = 0; j < map.size; j++)
//					{
//						Pixel start;
//						start.x = O.x+i*blockSize;
//						start.y = O.y-j*blockSize;
//						
//						if (mx >= start.x && my >= start.y && mx <= start.x+blockSize && my <= start.y+blockSize)
//						{
//							/* modify map */
//							map.arrangement[i][j-1] = currentDraw;	// -1 is a magic number
//							break;
//						}
//					}
				}
				break;
			}
		case MOUSEMOVE:
		default:
			DisplayDIYMapDefault();
		}
} 

/* Default Display DIY Map */
void DisplayDIYMap(){
	
    GenerateMapEmpty();
	PRESSED = FALSE;
	registerMouseEvent(myMouseEventDIYMap);	
	DisplayDIYMapDefault();
	
} 
/* To check whether there is only on character, destination and door(if exists) in the graph. */
int CheckUniqueness(){
	
	int i, j, nMe=0, nDestination=0, nKey=0, nDoor=0;
		
	// to do: set me, key, door, destination positions
	for (i = 0; i < map.size; i++){
		for (j = 0; j < map.size; j++){
			if(map.arrangement[i][j]==ME) {
				nMe++;
				me.x = i;
				me.y = j;
			}
			if(map.arrangement[i][j]==DESTINATION){
				nDestination++;
				destination.x = i;
				destination.y = j;
			} 
			if(map.arrangement[i][j]==KEY){
				nKey++;
				key.x = i;
				key.y = j;
			} 
			if(map.arrangement[i][j]==DOOR){
				nDoor++;
				door.x = i;
				door.y = j;
			} 
		}
	}
	
	/* Return corresponding errors */
	if (nMe==1&&nDestination==1&&nKey<=1&&nDoor<=1&&nKey+nDoor!=1){
		if (nKey+nDoor==0&&findPath(me, destination) ==TRUE){
			// without key+door, reachable
			return TRUE;	
		}
		else if (nKey+nDoor==2&&findPath(me, key)==TRUE&&findPath(key, door)==TRUE&&findPath(door, destination)==TRUE){
			// with key+door, reachable
			return TRUE;
		}
	}
	else if(nMe==0 || nDestination==0){
		// no me or no destination
		return -1;
	}
	else if(nMe>1 || nDestination>1){
		// more than one me or destination
		return -2;
	} 
	else if(nDoor==1 && nKey==0){
		// with door but without key
		return -3;
	}
	else if(nDoor > 1 || nKey>1){
		// with more than one key or door
		return -4;
	}
	else if(nKey+nDoor<=2&&findPath(me, destination) == FALSE){
		// not reachable
		return -5;
	}
	else if(nKey+nDoor==2&&(findPath(me, key)==FALSE||findPath(key, door)==FALSE||findPath(door, destination)==FALSE)){
		return -6;
	}
	
	
}


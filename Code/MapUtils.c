#include "headers\\MapUtils.h"

/* draw a single block */
void DrawBlock(Pixel start, int type){
	
	switch(type){
		case EMPTY:{
			
			SetPenColor("Black"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			break;
		}
		case TREE:{
			StartFilledRegion(0.5); 
			
			SetPenColor("Black"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			EndFilledRegion(); 
			break;
		}
		case KEY:{
			StartFilledRegion(0.5); 
			
			SetPenColor("Key"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			EndFilledRegion(); 
			
			SetPenColor("Black");
			DrawKey(start.x,start.y); 
			break;
		}		
		case DOOR:{
			StartFilledRegion(0.5); 
			
			SetPenColor("Door"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			EndFilledRegion(); 
			SetPenColor("Black");
			DrawDoor(start.x,start.y); 
			break;
		}		
		case ME:{
			
			StartFilledRegion(0.5);
			
			SetPenColor("Red"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			EndFilledRegion(); 
			
			SetPenColor("Black");
			DrawCharacter(start.x,start.y);
			//DrawCharacter(start.x, start.y);
			break;
		}
		case DESTINATION:{
						
			StartFilledRegion(0.5);
			
			SetPenColor("Green"); 
			MovePen(start.x, start.y);
			DrawLine(0,-blockSize);
			DrawLine(blockSize,0);
			DrawLine(0, blockSize);
			DrawLine(-blockSize,0);
			
			EndFilledRegion(); 
			
			SetPenColor("Black");
			DrawDestination(start.x, start.y);
			//DrawDestination(start.x, start.y);
			break;
		}
	}

}


/* show a nextto block */
int NextTo(Coordinate me, Coordinate other){
	if((me.x==other.x&&abs(me.y-other.y)==1)||(me.y==other.y&&abs(me.x-other.x)==1))
		return TRUE;
	else return FALSE;
}


/* show path */
void HighlightPath(Pixel start, int type){
	int i,j;
	for (i = 0; i < map.size; i++){
			for (j = 0; j < map.size; j++){
				path[i][j]=0;
			}
		}
	if(findPath(me, destination) == TRUE){
	
	switch (type){
		case PATH:{
			Coordinate temp;
			temp.x=round((start.x-5)/blockSize);
			temp.y=round((9.5-start.y)/blockSize);
			if(OnlyNext==FALSE||NextTo(me,temp)==TRUE){
				printf("me.x=%d me.y=%d temp.x=%d temp.y=%d\n",me.x,me.y,temp.x,temp.y);
				StartFilledRegion(0.5);
				
				SetPenColor("Yellow"); 
				MovePen(start.x, start.y);
				DrawLine(0,-blockSize);
				DrawLine(blockSize,0);
				DrawLine(0, blockSize);
				DrawLine(-blockSize,0);
				
				EndFilledRegion(); 
				break;
			}
		}
		default: break;
	}
  }
}


void SaveMap(int num){
	
	int i, j;
	
	/* Create File Name */
	char FileName[20] = "Data\\DIY", FileEnd[7] = ".txt", levelNum[2] = "";
	levelNum[0] = num + '0';
	levelNum[1] = '\0';
	strcat(FileName, levelNum);
	strcat(FileName, FileEnd);
	
	FILE *fp = fopen(FileName, "w");
	for (i = 0; i < map.size; i++){
		for (j = 0; j < map.size; j++)
			fprintf(fp, "%d ", map.arrangement[j][i]);
		fprintf(fp, "\n");
	}
}


void ReadMap(int num, int isDIY){
	
	int i, j;
	
	/* Create File Name */
	// char FileName[35] = "..\\Code\\compiled\\Data\\", DIY[5] = "DIY", level[7] = "level", FileEnd[7] = ".txt", levelNum[2] = "";
	char FileName[35] = "Data\\", DIY[5] = "DIY", level[7] = "level", FileEnd[7] = ".txt", levelNum[2] = "";
	if (isDIY == TRUE) strcat(FileName, DIY); else strcat(FileName, level);
	levelNum[0] = num + '0';
	levelNum[1] = '\0';
	strcat(FileName, levelNum);
	strcat(FileName, FileEnd);
	
	/* Read from File */
	// TODO: record key, door coordinate
	FILE *fp = fopen(FileName, "r");
	if (fp != NULL){
		for (i = 0; i < map.size; i++){
			for (j = 0; j < map.size; j++){
				fscanf(fp, "%d ", &map.arrangement[j][i]);		// i, j here should be inversed
			}
        }
    }
    fclose(fp);
}


/* Read a Map from the DIY File */
void GenerateMapStaticDIY(int map_num){
	
	int i, j;
	
	/* map initialization */
	map.level = 5;
	map.size = 25;
	map.time = 5*60*500;
	me.x = 0;
	me.y = 0;
	key.x = 0;
	key.y = 0;
	door.x = 0;
	door.y = 0;
	destination.x = map.size - 1;
	destination.y = map.size - 1;
	
	map.arrangement = (int**)malloc(sizeof(int*)*map.size);
	for (i = 0; i < map.size; i++)
		map.arrangement[i] = (int*)malloc(sizeof(int)*map.size);
			
	ReadMap(map_num, TRUE);	// isDIY = TRUE
	
	for (i = 0; i < map.size; i++)
		for (j = 0; j < map.size; j++){
			if (map.arrangement[i][j] == KEY) {key.x = i; key.y = j;}
			if (map.arrangement[i][j] == DOOR) {door.x = i; door.y = j;}			
		}
}




/* Read a Map from the File */
void GenerateMapStatic(){
	
	int i, j;
	
	/* map initialization */
	map.level = level;
	map.size = (level+1)*5<25?(level+1)*5:25;
	map.time = level*60*500;
	me.x = 0;
	me.y = 0;
	key.x = 0;
	key.y = 0;
	door.x = 0;
	door.y = 0;
	destination.x = map.size - 1;
	destination.y = map.size - 1;
	
	map.arrangement = (int**)malloc(sizeof(int*)*map.size);
	for (i = 0; i < map.size; i++)
		map.arrangement[i] = (int*)malloc(sizeof(int)*map.size);
			
	ReadMap(level, FALSE);	// isDIY = FALSE
	
	for (i = 0; i < map.size; i++)
		for (j = 0; j < map.size; j++){
			if (map.arrangement[i][j] == KEY) {key.x = i; key.y = j;}
			if (map.arrangement[i][j] == DOOR) {door.x = i; door.y = j;}			
		}
}

/* Randomly Generate a Map */
void GenerateMapRandom(){
	
	int i, j, n = 0;
	
	/* map initialization */
	map.level = level;
	map.size = level*5;
	map.time = level*60*500;
	me.x = 0;
	me.y = 0;
	key.x = 0;
	key.y = 0;
	door.x = 0;
	door.y = 0;
	destination.x = map.size - 1;
	destination.y = map.size - 1;
	
	map.arrangement = (int**)malloc(sizeof(int*)*map.size);
	for (i = 0; i < map.size; i++)
		map.arrangement[i] = (int*)malloc(sizeof(int)*map.size);
	int cnt=0;
	/* generate walls & check connect, or regenerate */
	do {
		for (i = 0; i < map.size; i++)
			for (j = 0; j < map.size; j++)
				map.arrangement[i][j] = EMPTY;
			
		int nWalls = map.size*map.size/3;
		int cWalls = 0;
		srand((unsigned)time(NULL)+n);
		while (cWalls < nWalls){
			int randX = rand()%(map.size);
			int randY = rand()%(map.size); 
			// checkConnect
			map.arrangement[randX][randY] = TREE; 
			cWalls += 1; 
		}
		// cnt++;
		map.arrangement[0][0] = ME;
		map.arrangement[map.size-1][map.size-1] = DESTINATION;
	}while (findPath(me, destination) == FALSE);
//	if (cnt>3)
//	{
//		ReadMap(level, FALSE);
//	}
//	
	map.arrangement[0][0] = ME;
	map.arrangement[map.size-1][map.size-1] = DESTINATION;

}
/* Generate an empty map */
void GenerateMapEmpty(){
	
	level = 5;
	map.level = level;
	map.size = level*5;
	map.time = level*60*500;
	me.x = 0;
	me.y = 0;
	key.x = 0;
	key.y = 0;
	door.x = 0;
	door.y = 0;
	destination.x = map.size - 1;
	destination.y = map.size - 1;
	map.arrangement = (int**)malloc(sizeof(int*)*map.size);
	
	int i, j;
	
	for (i = 0; i < map.size; i++)
		map.arrangement[i] = (int*)malloc(sizeof(int)*map.size);
		
	for (i = 0; i < map.size; i++)
		for (j = 0; j < map.size; j++)
				map.arrangement[i][j] = EMPTY;
}


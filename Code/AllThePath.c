#include "headers\\AllThePath.h"

/* Save all the possible paths into the Visualize struct */
int findAllPath(Coordinate from, Coordinate to){
	
	int i, j;
	int sx=from.x,sy=from.y,fx=to.x,fy=to.y;
    int flag = FALSE;
    Stack S;
	flag = bfs(from, to);

    if (flag == FALSE)
        return flag;
    routelines = 0;
    route=(Coordinate **)malloc(101*sizeof(Coordinate *));
    if(route==NULL) 
		return -1;
    for(i=0;i<101;i++) 
		*(route+i)=(Coordinate *)malloc(sizeof(Coordinate)*map.size*map.size);
	
	S = CreateStack(500); 	// 500 is the maximum possible blocks
	Push(sx,sy,S);
	if(routelines==0){
		Visualized[procession].x=sx;
		Visualized[procession].y=sy;
		procession++;
	}
	findastep(sx,sy,fx,fy,S);
    return flag;
}

/* To be called by findallpath function. It is to find the next block for every step in a path */
void findastep(int sx,int sy,int fx,int fy,Stack S){
    int tx;
    int ty;
    int i;
    for(i=0;i<4;i++){
        tx=sx+direction[i].x;
        ty=sy+direction[i].y;
        if(tx>=0&&tx<map.size&&ty>=0&&ty<map.size&&(dist[tx][ty]==dist[sx][sy]-1)){
            Push(tx,ty,S);
            if(procession<50000){		// maximum #blocks in this map
				Visualized[procession].x=tx;
				Visualized[procession].y=ty;
				procession++;
	}
        if(tx==fx&&ty==fy){
            routelines++;
            printpath(S);
            Pop(S);
	        if(procession<50000){		// maximum #blocks in this map
				Visualized[procession].x=tx;
				Visualized[procession].y=ty;
				procession++;
			}
        }
        else{
        	findastep(tx,ty,fx,fy,S);
        	}
        }
    }
    	Pop(S);
        if(procession<50000){
			Visualized[procession].x=sx;
			Visualized[procession].y=sy;
			procession++;
	    }
}

/* Get the path block by block from the stack */
void printpath(Stack S){
    int i;
    (*(*(route+routelines))).x=S->TopOfStack+1;
    for(i=1;i<=S->TopOfStack+1;i++)
    *(*(route+routelines)+i)=S->PNode[i-1];
}




/* Stack Operations */
Stack CreateStack( int MaxElements ){
    Stack S;
    if(MaxElements < MinStackSize){
        printf( "Stack size is too small!" );
    }
    S = malloc(sizeof( struct StackRecord ));
    if (S == NULL) printf("Out of space!");
    S->PNode = malloc(sizeof( Coordinate )* MaxElements );
    if( S->PNode == NULL) printf("Out of space!");
    S->Capacity = MaxElements;
    MakeEmpty( S );
    return S;
}
void DisposeStack( Stack S ){
    if(S != NULL){
        free(S->PNode);
        free(S);
    }
}
int IsEmpty(Stack S){
    return S->TopOfStack == EmptyToS;
}
int IsFull(Stack S){
    return S->TopOfStack == S->Capacity-1;
}
void MakeEmpty(Stack S){
    S->TopOfStack=EmptyToS;
}
void Push(int x,int y,Stack S){
    if(IsFull(S))printf("Full Stack!");
    else {
        S->PNode[++S->TopOfStack].x = x;
        S->PNode[S->TopOfStack].y = y;
    }
}
Coordinate Top(Stack S){
    if(!IsEmpty(S)) return S->PNode[S->TopOfStack];
}
void Pop(Stack S){
    if(IsEmpty(S)) printf("Empty Stack!");
    else S->TopOfStack--;
}
Coordinate TopAndPop(Stack S){
    if(!IsEmpty(S)) return S->PNode[S->TopOfStack--];
}


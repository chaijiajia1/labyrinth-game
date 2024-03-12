#include "headers\\MyDraw.h"
/// @brief draw a character
/// @var x block x
/// @var y block y
void DrawCharacter(double x, double y)
{
	double cx,cy;
	cx=x+blockSize/2;
	cy=y-blockSize/2-0.1;
	double length=0.02;
    MovePen(cx,cy);
    MovePen(cx+0.1*length,cy); 
    
    StartFilledRegion(color);
	DrawLine(length,0);
	DrawLine(0,5*length);
	DrawLine(0.2*length,0);
	DrawLine(0,-2*length);
	DrawLine(0.9*length,0);
	DrawLine(0,3*length);
	DrawLine(-4.4*length,0);
	DrawLine(0,-3*length);
	DrawLine(0.9*length,0);
	DrawLine(0,2*length);
	DrawLine(0.2*length,0);
	DrawLine(0,-5*length);
	DrawLine(length,0);
	DrawLine(0,3*length);
	DrawLine(0.2*length,0);
	DrawLine(0,-3*length);
	EndFilledRegion();
	
    MovePen(cx,cy+7*length); 
    StartFilledRegion(color);
    DrawArc(length,270,360);
    EndFilledRegion();

}

void DrawDestination(double x, double y)
{
	double cx,cy;
	int i,j;
	double length=0.029;
	cx=x+length;
	cy=y-blockSize+length;
    MovePen(cx,cy);
    StartFilledRegion(color);
	DrawLine(2*length,0);
	DrawLine(0,length);
	DrawLine(-0.5*length,0);
	DrawLine(0,7*length);
	DrawLine(-length,0);
	DrawLine(0,-7*length);
	DrawLine(-0.5*length,0);
	DrawLine(0,-length);
	EndFilledRegion();
	
	MovePen(cx+8*length,cy);
	StartFilledRegion(color);
	DrawLine(2*length,0);
	DrawLine(0,length);
	DrawLine(-0.5*length,0);
	DrawLine(0,7*length);
	DrawLine(-length,0);
	DrawLine(0,-7*length);
	DrawLine(-0.5*length,0);
	DrawLine(0,-length);
	EndFilledRegion();

	MovePen(cx+1.5*length,cy+3.5*length);
	for(i=0;i<3;i++){
		for(j=0;j<7;j++){
		if((i+j)%2==0) StartFilledRegion(color);
	   DrawLine(length,0);
	   DrawLine(0,length);
	   DrawLine(-length,0);
	   DrawLine(0,-length);
	   if((i+j)%2==0) EndFilledRegion();
	   DrawLine(length,0);
    }
	DrawLine(-7*length,0);
	DrawLine(0,length);
}
}

void DrawDoor(double x, double y)
{
	double cx,cy; 
	double length=0.018;
	cx=x+0.05*blockSize;
	cy=y-0.9*blockSize;
	
    MovePen(cx,cy);
    StartFilledRegion(color);
	DrawLine(17.5*length,0);
	DrawLine(0,15.5*length);
	DrawLine(-17.5*length,0);
	DrawLine(0,-15.5*length);
	EndFilledRegion();
    
    SetPenColor("White");
    
    MovePen(cx+length,cy);
    StartFilledRegion(0);
    DrawLine(0.5*length,0);
	DrawLine(0,2*length);
	DrawLine(-0.5*length,0);
	DrawLine(0,-2*length);
    EndFilledRegion();
    
    MovePen(cx+length,cy+3*length);
    StartFilledRegion(0);
    DrawLine(0.5*length,0);
	DrawLine(0,8*length);
	DrawLine(-0.5*length,0);
	DrawLine(0,-8*length);
    EndFilledRegion();
    
    MovePen(cx+16*length,cy);
    StartFilledRegion(0);
    DrawLine(0.5*length,0);
	DrawLine(0,2*length);
	DrawLine(-0.5*length,0);
	DrawLine(0,-2*length);
    EndFilledRegion();
    
    MovePen(cx+16*length,cy+3*length);
    StartFilledRegion(0);
    DrawLine(0.5*length,0);
	DrawLine(0,8*length);
	DrawLine(-0.5*length,0);
	DrawLine(0,-8*length);
    EndFilledRegion();
    
    MovePen(cx+8.5*length,cy);
    StartFilledRegion(0);
    DrawLine(0.5*length,0);
    DrawLine(0,14*length);
    DrawLine(7*length,0);
    DrawLine(0,-2*length);
    DrawLine(0.5*length,0);
    DrawLine(0,2.5*length);
    DrawLine(-15.5*length,0);
    DrawLine(0,-2.5*length);
    DrawLine(0.5*length,0);
    DrawLine(0,2*length);
    DrawLine(7*length,0);
    DrawLine(0,-14*length);
    EndFilledRegion();
    
    MovePen(cx+8*length,cy+6*length);
    StartFilledRegion(0);
    DrawArc(0.5*length,0,360);
    EndFilledRegion();

    MovePen(cx+8*length,cy+8*length);
    StartFilledRegion(0);
    DrawArc(0.5*length,0,360);
    EndFilledRegion();
    
    MovePen(cx+10.5*length,cy+6*length);
    StartFilledRegion(0);
    DrawArc(0.5*length,0,360);
    EndFilledRegion();

    MovePen(cx+10.5*length,cy+8*length);
    StartFilledRegion(0);
    DrawArc(0.5*length,0,360);
    EndFilledRegion();

    MovePen(cx+7.5*length,cy+6*length);
    StartFilledRegion(0);
    DrawLine(0.15*length,0);
	DrawLine(0,2*length);
	DrawLine(-0.3*length,0);
	DrawLine(0,-2*length);
	DrawLine(0.15*length,0);
    EndFilledRegion();

    MovePen(cx+10*length,cy+6*length);
    StartFilledRegion(0);
    DrawLine(0.15*length,0);
	DrawLine(0,2*length);
	DrawLine(-0.3*length,0);
	DrawLine(0,-2*length);
	DrawLine(0.15*length,0);
    EndFilledRegion();


}
/// @brief draw key
/// @var x
/// @var y
void DrawKey(double x, double y)
{
    double cx, cy;
	double length=0.019;
	cx=x+0.25*blockSize;
	cy=y-0.5*blockSize;
	
    MovePen(cx+3*length,cy); 
    StartFilledRegion(color);
    DrawArc(3*length,0,360);
    EndFilledRegion();
    
    MovePen(cx+length,cy); 
    StartFilledRegion(0);
    DrawArc(2*length,0,360);
    EndFilledRegion();
    
    MovePen(cx+3*length,cy); 
    StartFilledRegion(color);
    DrawLine(0,-0.6*length);
    DrawLine(8*length,0);
    DrawLine(0,1.2*length);
    DrawLine(-8*length,0);
    DrawLine(0,-0.6*length);
    EndFilledRegion();
    
    MovePen(cx+7*length,cy-0.6*length); 
    StartFilledRegion(color);
    DrawLine(0,-length);
    DrawLine(length,0);
    DrawLine(0,length);
    DrawLine(-length,0);
    EndFilledRegion();
    
    MovePen(cx+9*length,cy-0.6*length); 
    StartFilledRegion(color);
    DrawLine(0,-2*length);
    DrawLine(length,0);
    DrawLine(0,2*length);
    DrawLine(-length,0);
    EndFilledRegion();
    
    MovePen(cx+11.6*length,cy); 
    StartFilledRegion(color);
    DrawArc(0.6*length,0,360);
    EndFilledRegion();
    


} 


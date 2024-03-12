/*
 * FILE: DisplayDIYList.h
 * BRIEF: This file displays the "My DIY Maps" GUI
 */ 
 
#ifndef __DIYMAP_H__
#define __DIYMAP_H__

/* Global header */
#include "main.h"

/* Extern variables and flag */
extern Map map;
int currentDraw = TREE;	// currentDrawָ��ǰѡ�еķ������ͣ������ͼ�еĸ��Ӽ��ɽ�֮��Ϊ��Ӧ�����ͣ���ʼ��Ϊǽ�� 
extern int HIGHLIGHT;	// �����Ƿ������ʾ���·�� 
extern int OnlyNext;	// ֻ������ʾ��һ��
extern int PRESSED;		// ��־���Ƿ���show shortest path 

/* Functions */
void DisplayDIYMapDefault();// ע������¼�����ʾDIY��ͼ���� 
void myMouseEventDIYMap(int x, int y, int button, int event);	// �ж�����Ƿ�����ť���ͼ�еĸ��ӣ����У��޸ĵ�ǰ��ͼ��Ϣ 
void DisplayDIYMap();		// ���ư�ť����ʾ��ͼ����ʾ��Ϣ 
int CheckUniqueness ();		// ����Զ������ɵ�ͼ����ͨ�ԣ�������ͨ�޷���ʾ���·�������޷����� 

#endif 

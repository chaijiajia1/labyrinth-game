/*
 * FILE: DisplayDIYList.h
 * BRIEF: This file displays the "My DIY Maps" GUI
 */ 
 
#ifndef __DIYLIST_H__
#define __DIYLIST_H__

/* Global Header */
#include "main.h"

/* Functions */
void DisplayDIYListDefault();						      		// ѡȡDIY��ͼ������ƣ�����������ť����ͼ����ʾ 
void myMouseEventDIYList (int x, int y, int button, int event);	// ����ѡȡ��ͼ������¼�������ѡ���ͼ1-4����ʾ.
																// play���뵱ǰѡ���ĵ�ͼ�������� 
void DisplayDIYList();											// ע������¼�����ʾѡȡDIY��ͼҳ�� 
extern drawBlock();

#endif

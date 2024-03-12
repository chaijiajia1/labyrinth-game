/*
 * FILE: DisplayScoreList.h
 * BRIEF: Show the score list display GUI
 */

#ifndef __SCORELIST_H__
#define __SCORELIST_H__

/* Global header */
#include "main.h"

/* Extern value */
extern Pixel mini1;

/* Functions */
void myMouseEventScoreList(int x, int y, int button, int event);	// ע������¼��������˳���������ʾ 
void DisplayScoreListDefault();										// ���Ʒ�������棬���ļ��ж�ȡ���������� 
void DisplayScoreList();											// ע������¼�����ʾ��������� 

#endif

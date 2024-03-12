/*
 * FILE: DisplayGUI.h
 * BRIEF: This file displays the level choosing GUI for default maps.
 */

#ifndef __GUI_H__
#define __GUI_H__

/* Global header */
#include "main.h"

/* Global and extern variables */
Pixel mini;
extern int isGUI;

/* Functions for display GUI */
void DisplayGUIDefault();  									// ����ѡ��level�����ͼ��
void myMouseEventGUI (int x, int y, int button, int event); // ��������level��ťλ���������ѡ��level�������������
void DisplayGUI();											// ע��һ������¼��Ļص�����������level�����ѡ��

#endif

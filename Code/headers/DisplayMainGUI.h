/*
 * FILE: DisplayHelp.h
 * BRIEF: This file displays the instruction GUI for the entire project. 
 *        It lies in the "?" in the main GUI.
 */
 
#ifndef __MAINGUI_H__
#define __MAINGUI_H__

/* Global header */
#include "main.h"

/* Global variable */ 
Pixel mini1;

/* Functions */
void DisplayMainGUIDefault();									// ����ѡ���������ͼ��
void myMouseEventMainGUI (int x, int y, int button, int event); // ���������������¼� 
void DisplayMainGUI();											// ע������¼�������������ͼ��

#endif

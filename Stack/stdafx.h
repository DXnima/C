// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������
#define STACKINCREMENT 10   //�洢�ռ��������

typedef int Status;

/*�꺯��*/
//������ͣһ��ʱ��
#define Wait(x)\
 {\
	double _Loop_Num_;\
	for(_Loop_Num_=0.01; _Loop_Num_<=100000.0*x; _Loop_Num_+=0.01)\
		;\
 }//����һ����ѭ�� 

/* Ԫ�����Ͷ��� */
typedef int SElemType;

// ���Ժ�������ӡԪ��
void PrintElem(SElemType e);

//ջ������
void main_Stack();
//�Թ�����
void main_Maze();
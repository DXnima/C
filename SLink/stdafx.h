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

typedef int Status;

/* ˳���Ԫ�����Ͷ��� */
typedef int ElemType;

// �ж�data>e�Ƿ����
Status CmpGreater(ElemType data, ElemType e);

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e);

//���Ա�������
void main_SList();
//������������
void main_SLink();
//��ѭ������������
void main_SLink_R();
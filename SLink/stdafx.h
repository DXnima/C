// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>


// TODO:  在此处引用程序需要的其他头文件
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

/* 顺序表元素类型定义 */
typedef int ElemType;

// 判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e);

// 测试函数，打印元素
void PrintElem(ElemType e);

//线性表主函数
void main_SList();
//单链表主函数
void main_SLink();
//单循环链表主函数
void main_SLink_R();
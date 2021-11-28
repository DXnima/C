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

#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10   //存储空间分配增量

typedef int Status;

/*宏函数*/
//函数暂停一段时间
#define Wait(x)\
 {\
	double _Loop_Num_;\
	for(_Loop_Num_=0.01; _Loop_Num_<=100000.0*x; _Loop_Num_+=0.01)\
		;\
 }//设立一个空循环 

/* 元素类型定义 */
typedef int SElemType;

// 测试函数，打印元素
void PrintElem(SElemType e);

//栈主函数
void main_Stack();
//迷宫问题
void main_Maze();
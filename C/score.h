#pragma once
#include "stdafx.h"

#define N 20

struct Student
{
	char num[10];    //学号
	char name[20];   //姓名
	int score1;      //分数一
	int score2;      //分数二
	float sumscore;  //总分
	int rank;        //排名   
}student[N];

//读取文件，打印学生信息
void file_print();

//计算平均分
float avg(Student *s);

//计算方差
float var(Student *s);

//排序
float sort(Student *s);

//打印不及格人
void bad(Student *s);
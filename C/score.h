#pragma once
#include "stdafx.h"

#define N 20

struct Student
{
	char num[10];    //ѧ��
	char name[20];   //����
	int score1;      //����һ
	int score2;      //������
	float sumscore;  //�ܷ�
	int rank;        //����   
}student[N];

//��ȡ�ļ�����ӡѧ����Ϣ
void file_print();

//����ƽ����
float avg(Student *s);

//���㷽��
float var(Student *s);

//����
float sort(Student *s);

//��ӡ��������
void bad(Student *s);
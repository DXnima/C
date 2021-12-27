#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK     1
#define ERROR  0
#define MIX    100
typedef int Status;
//结点定义
typedef struct telebook    //通讯录结点数据域  
{
	char num[MIX];         //学号
	char name[MIX];        //姓名
	char sex[MIX];         //性别
	char hostel[MIX];      //宿舍
	char telephone[MIX];   //电话号码    
}telebook;

typedef struct LNode      //链表结点
{
	telebook data; //结点数据域   
	struct LNode *next;  //结点指针域  
}LNode, *LinkList;

//读取文本信息
void readFile(LinkList &L);

//单链表的初始化 
Status  InitList_L(LinkList &L);

void Find_Name(LinkList &L); //按姓名查询

void Find_Num(LinkList &L); //按姓名查询

Status  CreateFromTail(LinkList &L);     //采用尾插法在尾部插入元素

										 //初始条件：线性表L已经存在
										 //在单链线性表L的第i个元素之前插入元素
Status ListInsert_L(LinkList &L);

//在单链线性表L的姓名元素之前插入元素
Status ListInsert_LName(LinkList &L);
Status Fund_LName(LinkList &L);  //寻找该姓名的位置

								 //初始条件：线性表L已经存在
								 //删除第i个元素
Status ListDelete_L(LinkList &L);

Status ListDelete_LName(LinkList &L);   //删除姓名为“XXX”的学生记录

void saveFile(LinkList &L);  //保存通讯录到文件

							 //初始条件：线性表L已经存在
							 //打印出所有元素
void PrintElem(LinkList L);

void List_free(LinkList L);  //销毁链表

int score();
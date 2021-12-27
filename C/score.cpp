#include "stdafx.h"
#include "score.h"

//单链表的初始化
Status  InitList_L(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));   //申请结点空间 
	if (L == NULL)                       //判断是否有足够的内存空间 
		printf("申请内存空间失败\n");
	L->next = NULL;                  //将next设置为NULL,初始长度为0的单链表 
	return OK;
}

void readFile(LinkList &L)          //读取文件信息
{
	LinkList q, p;
	FILE *fp;
	p = L;
	q = (LNode*)malloc(sizeof(LNode));
	char name[20] = "通讯录.txt";
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("error\n");
		exit(0);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (fscanf(fp, "%s%s%s%s%s\n", q->data.num, q->data.name, q->data.sex, q->data.hostel, q->data.telephone) != EOF)
	{
		q->next = NULL;
		p->next = q;
		p = q;
		q = (LNode*)malloc(sizeof(LNode));
	}
	printf("                             文件读取成功！       \n");
	fclose(fp);
}

void Find_Name(LinkList &L) //按姓名查询    
{
	LinkList q, p;
	q = L->next;
	printf("输入要查询的姓名：\n");
	p = (LNode*)malloc(sizeof(LNode));
	scanf("%s", p->data.name);
	while (q != NULL&&strcmp(q->data.name, p->data.name) != 0)
	{
		q = q->next;
	}
	if (q == NULL)
	{
		printf("通讯录中没有这个姓名！\n");
	}
	else
	{
		printf("已经找到此联系人!\n");
		printf("   学号       姓名      性别         宿舍            电话号码 \n");
		printf("%s    %s\t %s\t     %s          %s\n", q->data.num, q->data.name, q->data.sex, q->data.hostel, q->data.telephone);
	}
}

void Find_Num(LinkList &L) //按学号查询    
{
	LinkList q, p;
	q = L->next;
	printf("输入要查询的编号：\n");
	p = (LNode*)malloc(sizeof(LNode));
	scanf("%s", p->data.num);
	while (q != NULL&&strcmp(q->data.num, p->data.num) != 0)
	{
		q = q->next;
	}
	if (q == NULL)
	{
		printf("通讯录中没有这个编号！\n");
	}
	else
	{
		printf("已经找到此联系人!\n");
		printf("   学号       姓名      性别         宿舍            电话号码 \n");
		printf("%s    %s\t %s\t     %s          %s\n", q->data.num, q->data.name, q->data.sex, q->data.hostel, q->data.telephone);
	}
}


Status  CreateFromTail(LinkList &L)     //采用尾插法在尾部插入元素
{
	LinkList r, s;
	r = L;   //r指针始终动态指向链表的当前表尾
	while (r->next)
	{//尾插法，直接把指针移位到尾部  
		r = r->next;
	}
	s = (LinkList)malloc(sizeof(LNode));
	printf("在尾部插入的联系人信息为：\n");
	printf("   学号    姓名   性别  宿舍  电话号码 \n");
	scanf("%s%s%s%s%s", s->data.num, s->data.name, s->data.sex, s->data.hostel, s->data.telephone);
	s->next = NULL;
	r->next = s;
	return OK;
}

//初始条件：线性表L已经存在
//在单链线性表L的第i个元素之前插入元素
Status ListInsert_L(LinkList &L)
{
	LinkList s, p = L;
	int  j = 0, i;
	printf("输入要插入的位置：");
	scanf("%d", &i);
	while (p&&j < i)
	{  // 寻找第i个结点
		p = p->next;
		++j;
	}
	if (!p || j > i) { printf("----无此位置添加失败-----\n"); return ERROR; }      // i小于1或者大于表长
	s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
	printf("插入的联系人信息为：\n");
	printf("   学号    姓名   性别  宿舍  电话号码 \n");
	scanf("%s%s%s%s%s", s->data.num, s->data.name, s->data.sex, s->data.hostel, s->data.telephone);
	s->next = p->next;      // 插入L中
	p->next = s;
	return OK;
} // LinstInsert_L


Status Fund_LName(LinkList &L)  //寻找该姓名的位置
{
	LinkList s, p = L->next;
	int  i = 0;
	s = (LNode*)malloc(sizeof(LNode));
	scanf("%s", s->data.name);
	while (p != NULL&&strcmp(p->data.name, s->data.name) != 0)
	{
		p = p->next;
		++i;
	}
	return i + 1;
}

//在单链线性表L的姓名元素之前插入元素
Status ListInsert_LName(LinkList &L)
{
	LinkList s, s1, q = L, p = L->next;
	printf("输入要在谁的姓名之前添加信息：");
	int j = 0, i = 0;
	s1 = (LNode*)malloc(sizeof(LNode));
	scanf("%s", s1->data.name);
	while (p != NULL&&strcmp(p->data.name, s1->data.name) != 0)
	{
		p = p->next;
		++i;
	}
	if (p == NULL) { printf("----查无此人添加失败-----\n"); return ERROR; }      // 如果没有找到
	while (q&&j < i)
	{  // 寻找第i-1个结点
		q = q->next;
		++j;
	}

	s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
	printf("插入的联系人信息为：\n");
	printf("   学号    姓名   性别  宿舍  电话号码 \n");
	scanf("%s%s%s%s%s", s->data.num, s->data.name, s->data.sex, s->data.hostel, s->data.telephone);
	s->next = q->next;      // 插入L中
	q->next = s;
	return OK;
}

//初始条件：线性表L已经存在
//删除第i个元素
Status ListDelete_L(LinkList &L)
{
	LinkList p = L, q;
	int  j = 0, i;
	printf("输入要删除的位置：");
	scanf("%d", &i);
	while (p->next && j < i)
	{  // 寻找第i个结点，并令p指向其前趋
		p = p->next;    ++j;
	}
	if (!(p->next) || j > i) { printf("----查无此人删除失败-----\n"); return ERROR; }  // 删除位置不合理
	q = p->next;
	p->next = q->next;           // 删除并释放结点  
	free(q);
	printf("----删除成功-----\n");
	return OK;
} // ListDelete_L

Status ListDelete_LName(LinkList &L)   //删除姓名为“XXX”的学生记录
{
	LinkList p = L, q;
	printf("输入要删除的学生的姓名：");
	int  j = 0, i = Fund_LName(L);
	while (p->next && j < i - 1)
	{  // 寻找第i个结点，并令p指向其前趋
		p = p->next;    ++j;
	}
	if (!(p->next) || j > i - 1) { printf("----查无此人删除失败-----\n"); return ERROR; }  // 删除位置不合理
	q = p->next;
	p->next = q->next;           // 删除并释放结点  
	free(q);
	printf("----删除成功-----\n");
	return OK;
}

//初始条件：线性表L已经存在
//打印出所有元素
void PrintElem(LinkList L)
{
	LinkList p = L->next;
	printf("当前的信息为：\n");
	while (p != NULL)
	{
		printf("%s    %s\t %s\t     %s          %s\n", p->data.num, p->data.name, p->data.sex, p->data.hostel, p->data.telephone);
		p = p->next;
	}
	printf("\n");
}

void saveFile(LinkList &L)  //保存通讯录到文件  
{
	FILE*fp;
	LinkList p;
	p = L;
	if ((fp = fopen("通讯录.txt", "wt")) == NULL)   exit(0);   // "wt"方式打开文件时，如果源文件中有内容，追加            
	if (p == NULL || p->next == NULL) //链表为空    
		printf("您的操作有误，请确保您的通讯录不为空！\n");
	else
	{
		p = p->next;
		while (p != NULL)
		{
			fprintf(fp, "%s    %s\t %s\t     %s          %s", p->data.num, p->data.name, p->data.sex, p->data.hostel, p->data.telephone);
			fprintf(fp, "\n");
			p = p->next;
		}
		fclose(fp);
		printf("通讯录已保存！\n");
	}
}

void List_free(LinkList L)  //销毁链表
{
	LinkList p;
	while (L != NULL)
	{
		p = L;
		L = L->next;
		free(p);
	}
}

int score()
{
	int n = 1;
	LinkList L;
	InitList_L(L);
	readFile(L);
	while (n != 0)
	{
		printf("*****************************基于单链表的班级通讯录*****************************\n");
		printf("           1:通过姓名查找联系人        |      2:通过学号查找联系人\n\n");
		printf("           3:在最后添加某学生信息      |      4:将新联系人加在某条记录之前\n\n");
		printf("           5:将新联系人加某个学生之前  |      6:删除第i条记录\n\n");
		printf("           7:按姓名删除                |      8:显示结果\n\n");
		printf("                             0:退出程序并保存              \n\n");
		printf("*********************************************************************************\n");
		printf("请选择操作<1-8>,退出<0>:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:Find_Name(L);
			system("pause");//输入任意键继续    
			system("cls");//清屏
			break;
		case 2:Find_Num(L);
			system("pause");//输入任意键继续    
			system("cls");//清屏
			break;
		case 3:CreateFromTail(L);
			system("pause");//输入任意键继续    
			system("cls");//清屏
			break;
		case 4:ListInsert_L(L);
			system("pause");//输入任意键继续    
			system("cls");//清屏
			break;
		case 5:ListInsert_LName(L);
			system("pause");//输入任意键继续    
			system("cls");//清屏
			break;
		case 6:ListDelete_L(L);
			system("pause");//输入任意键继续    
			system("cls");//清屏
			break;
		case 7:ListDelete_LName(L);
			system("pause");//输入任意键继续    
			system("cls");//清屏
			break;
		case 8:PrintElem(L);
			system("pause");//输入任意键继续    
			system("cls");//清屏
			break;
		case 0:saveFile(L); List_free(L);
			system("cls");//清屏
			break;
		}
	}
	return 0;
}
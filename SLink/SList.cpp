// SList.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "SList.h"


//构建空线性表
Status InitList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

//销毁空线性表
Status DestroyList(SqList *L) {
	// 确保顺序表结构存在
	if (L == NULL || (*L).elem == NULL) {
		return ERROR;
	}
	// 释放顺序表内存
	free((*L).elem);
	// 释放内存后置空指针
	(*L).elem = NULL;
	// 顺序表长度跟容量都归零
	(*L).length = 0;
	(*L).listsize = 0;
	return OK;
}

//判断是否为空表
Status ListEmpty(SqList L) {
	return L.length == 0 ? TRUE : FALSE;
}

//获取元素个数
int ListLength(SqList L) {
	return L.length;
}

//返回第一个与e满足的元素位序
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
	int i;
	ElemType* p;
	// 确保顺序表结构存在
	if (L.elem == NULL) {
		return ERROR;
	}
	/*
	* i的初值为第1个元素的位序
	*/
	i = 1;
	// p的初值为第1个元素的存储位置
	p = L.elem;
	// 遍历顺序表
	while (i <= L.length && !Compare(*p++, e)) {
		++i;
	}
	if (i <= L.length) {
		return i;
	}
	else {
		return 0;
	}
}

//前驱 获取元素cur_e的前驱
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e) {
	int i;
	// 确保顺序表结构存在，且最少包含两个元素
	if (L.elem == NULL || L.length < 2) {
		return ERROR;
	}
	// 这里的i初始化为第1个元素的【索引】
	i = 0;
	// 从第1个元素开始，查找cur_e的位置
	while (i < L.length && L.elem[i] != cur_e) {
		++i;
	}
	// 如果cur_e是首个元素(没有前驱)，或者没找到元素cur_e，返回ERROR
	if (i == 0 || i >= L.length) {
		return ERROR;
	}
	// 存储cur_e的前驱
	*pre_e = L.elem[i - 1];
	return OK;
}

//后继 获取元素cur_e的后继
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e) {
	int i;
	// 确保顺序表结构存在，且最少包含两个元素
	if (L.elem == NULL || L.length < 2) {
		return ERROR;
	}
	// 这里的i初始化为第1个元素的【索引】
	i = 0;
	// 从第1个元素开始，查找cur_e的位置
	while (i < L.length - 1 && L.elem[i] != cur_e) {
		++i;
	}
	// 如果cur_e是最后个元素(没有后驱)，或者没找到元素cur_e，返回ERROR
	if (i >= L.length - 1) {
		return ERROR;
	}
	// 存储cur_e的前驱
	*next_e = L.elem[i + 1];
	return OK;
}

//插入
Status ListInsert(SqList *L, int i, ElemType e) {
	ElemType *newe, *p, *q;
	if (i<1 || i>(*L).length + 1) return ERROR;
	if ((*L).length >= (*L).listsize) {
		//扩容
		newe = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newe) exit(OVERFLOW);
		L->elem = newe;
		L->length += LISTINCREMENT;
	}
	q = &L->elem[i - 1];
	for (p = &(L->elem[L->length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L->length;
	return OK;
}

//删除
Status ListDelete(SqList *L, int i, ElemType *e) {
	ElemType *p, *q;
	if (i<1 || i>(*L).length + 1) return ERROR;
	p = &L->elem[i - 1];
	*e = *p;
	// 表尾元素位置
	q = L->elem + L->length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L->length;
	return OK;
}

//遍历 用visit函数访问顺序表
void ListTraverse(SqList L, void (Visit)(ElemType)) {
	int i;
	for (i = 0; i < L.length; i++) {
		Visit(L.elem[i]);
	}
	printf("\n");
}

//合并
void MergeList(SqList La, SqList Lb, SqList *Lc) {
	ElemType *pa, *pa_last, *pb, *pb_last, *pc;
	pa = La.elem;
	pb = Lb.elem;
	Lc->listsize = Lc->length = La.listsize + Lb.length - 1;
	pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
	if (!pc) exit(OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}

void main_SList()
{
	SqList L, L1, Lc;
	ElemType e;
	//初始化表
	InitList(&L);
	//插入
	for (int i = 1; i<LIST_INIT_SIZE; i++)
		ListInsert(&L, i, i);
	printf("----------------初始L----------------\n");
	printf("----------------个数：%d----------------\n", ListLength(L));
	ListTraverse(L, PrintElem);
	printf("----------------L.elem[0]：%d----------------\n", L.elem[0]);
	printf("\n----------------99位置插入8848----------------\n");
	//99位置插入8848
	ListInsert(&L, 98, 8848);
	ListTraverse(L, PrintElem);
	PriorElem(L, 8848, &e);
	printf("\n----------------8848前驱:%d\n", e);
	NextElem(L, 8848, &e);
	printf("\n----------------8848后驱:%d\n", e);
	//删除99位置元素
	ListDelete(&L, 98, &e);
	printf("\n----------------删除99位置元素----------------\n");
	ListTraverse(L, PrintElem);
	printf("\n----------------L1表----------------\n");
	InitList(&L1);
	for (int i = 1; i <= 5; i++)
		ListInsert(&L1, i, i * 100);
	ListTraverse(L1, PrintElem);
	//InitList(&Lc);
	MergeList(L, L1, &Lc);
	printf("\n----------------L、L1合并为Lc----------------\n");
	ListTraverse(Lc, PrintElem);
	printf("\n----------------Lc中第一个大于 \"200\" 的位置是:%d----------------\n", LocateElem(Lc, 200, CmpGreater));
	printf("\n----------------销毁L、L1、Lc----------------\n");
	DestroyList(&L);
	DestroyList(&L1);
	DestroyList(&Lc);
}
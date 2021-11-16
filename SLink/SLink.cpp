#include "stdafx.h"
#include "SLink.h"

//初始化
Status InitLinkList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL) {
		exit(OVERFLOW);
		return ERROR;
	}
	(*L)->next = NULL;
	return OK;
}

//销毁
Status DestroyLinkList(LinkList *L) {
	LinkList p, q;
	if (L == NULL || *L == NULL) return ERROR;
	p = *L;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L = NULL;
	return OK;
}

//清空
Status ClearLinkList(LinkList *L) {
	LinkList p, q;
	if (L == NULL || (*L)->next == NULL) return ERROR;
	p = (*L)->next;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	(*L)->next = NULL;
	return OK;
}

//判断是否为空
Status EmptyLinkList(LinkList L) {
	if (L != NULL && L->next == NULL) return TRUE;
	else return FALSE;
}

//获取长度
int GetLengthLinkList(LinkList L) {
	int i = 0;
	LinkList p;
	if (L == NULL || L->next == NULL) return 0;
	p = L->next;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return i;
}

//获取指定位置i的e
Status GetElemLinkList(LinkList L, int i, ElemType *e) {
	LinkList p;
	int j = 0;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L->next;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i + 1) return ERROR;
	*e = p->next->data;
	return OK;
}

//获取指定e的位置
Status LocateElemLinkList(LinkList L, ElemType e, Status(*Compare)(ElemType, ElemType)) {
	int i = 1;
	LinkList p;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L->next;
	while (p != NULL && !Compare(e, p->data))
	{
		p = p->next;
		i++;
	}
	if (p == NULL) return 0;
	else return i;
}
//前驱
Status PriorElemLinkList(LinkList L, ElemType e, ElemType *pre) {
	LinkList p, q;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L->next;
	//第一个没有前驱
	if (p->data == e) return ERROR;
	q = p->next;
	while (q != NULL && q->data != e)
	{
		p = q;
		q = q->next;
	}
	if (p == NULL) return NULL;
	*pre = p->data;
	return OK;
}

//后继
Status NextElemLinkList(LinkList L, ElemType e, ElemType *pre) {
	LinkList p;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	//最后一个没有后继
	if (p == NULL || p->next == NULL) return ERROR;
	*pre = p->next->data;
	return OK;
}
//插入
Status InsertLinkList(LinkList L, int i, ElemType e) {
	LinkList p, newp;
	int j = 0;
	if (L == NULL) return ERROR;
	p = L;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;
	newp = (LinkList)malloc(sizeof(LNode));
	newp->data = NULL;
	newp->data = e;
	newp->next = p->next;
	p->next = newp;
	return OK;
}

//删除
Status DeleteLinkList(LinkList L, int i, ElemType *e) {
	LinkList p, q;
	int j = 0;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L;
	while (p != NULL && j<i - 1)
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j>i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

//打印
Status TraverseLinkList(LinkList L, void(*visit)(ElemType)) {
	LinkList p;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L->next;
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

//头插法
Status InsertLinkList_H(LinkList *L, int n) {
	LinkList p;
	*L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) {
		exit(OVERFLOW);
		return ERROR;
	}
	(*L)->next = NULL;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->next = NULL;
		p->data = i + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return OK;
}

//尾插法
Status InsertLinkList_N(LinkList *L, int n) {
	LinkList p, q;
	int i;
	*L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) {
		exit(OVERFLOW);
		return ERROR;
	}
	(*L)->next = NULL;
	q = *L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->next = NULL;
		p->data = i + 1;
		q->next = p;
		q = q->next;
	}
	return OK;
}

//合并
Status MergeLinkList(LinkList La, LinkList Lb, LinkList *Lc, Status(*Compare)(ElemType, ElemType)) {
	LinkList pc, pa, pb;
	if (La == NULL || Lb == NULL) return ERROR;
	*Lc = (LinkList)malloc(sizeof(LNode));
	(*Lc)->next = NULL;
	if (!Lc) { 
		exit(OVERFLOW);
		return ERROR;
	}
	pa = La->next; pb = Lb->next;
	pc = *Lc;
	while (pa && pb)
	{
		if (Compare(pa->data, pb->data)) { 
			pc->next = pa; 
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	//将剩余部分直接接到最后
	pc->next = pa ? pa : pb;
	//释放Lb头节点
	free(Lb);
	return OK;
}

void main_SLink() {
	LinkList L,Lb,Lc;
	ElemType e;
	int i;
	printf("-----------头插法----------------\n");
	InsertLinkList_H(&L, 10);
	TraverseLinkList(L, PrintElem);
	if (DestroyLinkList(&L)) printf("\n-----------链表销毁成功！----------------\n");
	
	printf("\n-----------尾插法----------------\n");
	InsertLinkList_N(&L, 10);
	TraverseLinkList(L, PrintElem);
	if (InitLinkList(&L)) printf("\n-----------链表销毁成功！----------------\n");
	DestroyLinkList(&L);
	
	if (InitLinkList(&L)) printf("\n-----------链表初始化成功！----------------\n");
	for (i = 1; i <= 10; i++)
	{
		InsertLinkList(L, i, i);
	}
	TraverseLinkList(L, PrintElem);
	printf("\n链表创建成功，长度为：%d\n", GetLengthLinkList(L));
	
	PriorElemLinkList(L, 8, &e);
	printf("\n元素8的前序是：%d\n", e);
	
	NextElemLinkList(L, 8, &e);
	printf("\n元素8的后继是：%d\n", e);
	
	printf("\n在第8位置插入8848\n", e);
	InsertLinkList(L, 8, 8848);
	TraverseLinkList(L, PrintElem);
	
	printf("\n删除第8个元素\n", e);
	DeleteLinkList(L, 8, &e);
	TraverseLinkList(L, PrintElem);
	printf("\n删除成功，删除元素为：e = %d\n", e);
	
	printf("\n第一个大于 \"8\" 的位置是:i = %d\n", LocateElemLinkList(L, 8, CmpGreater));
	
	printf("\n-----------初始化Lb----------------\n");
	InitLinkList(&Lb);
	for (i = 1; i <= 5; i++)
	{
		InsertLinkList(Lb, i, i*3);
	}
	TraverseLinkList(Lb, PrintElem);
	printf("\n-----------L和Lb合并为Lc----------------\n");
	MergeLinkList(L, Lb, &Lc, CmpGreater);
	TraverseLinkList(Lc, PrintElem);
	if (DestroyLinkList(&L)) printf("\n-----------链表销毁成功！----------------\n");
}
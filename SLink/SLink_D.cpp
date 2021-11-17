#include "stdafx.h"
#include "SLink_D.h"

//初始化
Status InitLinkList_D(LinkList_D *L) {
	*L = (LinkList_D)malloc(sizeof(LNode_D));
	if (!*L) exit(OVERFLOW);
	(*L)->prior = *L;
	(*L)->next = *L;
	return OK;
}

//销毁
Status DestroyLinkList_D(LinkList_D *L) {
	LinkList_D p;
	if (EmptyLinkList_D(*L)) return ERROR;
	p = *L;
	while (p && (*L)->next != *L)
	{
		p = (*L)->next;
		(*L)->next = p->next;
		free(p);
	}
	free((*L)->next);
	(*L) = NULL;
	return OK;
}

//清空
Status ClearLinkList_D(LinkList_D *L) {
	LinkList_D p;
	if (EmptyLinkList_D(*L)) return ERROR;
	p = *L;
	while (p && (*L)->next != *L)
	{
		p = (*L)->next;
		(*L)->next = p->next;
		free(p);
	}
	(*L)->prior = *L;
	(*L)->next = *L;
	return OK;
}

//判断是否为空
Status EmptyLinkList_D(LinkList_D L) {
	if (L == NULL || (L->prior = L->next) == L) return TRUE;
	return FALSE;
}

//获取长度
int GetLengthLinkList_D(LinkList_D L) {
	LinkList_D p;
	int i = 0;
	if (EmptyLinkList_D(L)) return ERROR;
	p = L->next;
	while (p && p != L)
	{
		p = p->next;
		i++;
	}
	return i;
}

//获取指定位置id的e
Status GetElemLinkList_D(LinkList_D L, int i, ElemType *e) {
	LinkList_D p;
	int j = 0;
	if (EmptyLinkList_D(L)) return ERROR;
	p = L;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return 0;
	*e = p->next->data;
	return OK;
}

//获取指定e的位置
int LocateElemLinkList_D(LinkList_D L, ElemType e, Status(*Compare)(ElemType, ElemType)) {
	LinkList_D p;
	int i = 0;
	if (EmptyLinkList_D(L)) return ERROR;
	p = L->next;
	while (p && !Compare(e, p->data))
	{
		p = p->next;
		i++;
	}
	return i;
}

//前驱
Status PriorElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre);
//后继
Status NextElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre);

//插入
Status InsertLinkList_D(LinkList_D L, int i, ElemType e) {
	LinkList_D p,newp;
	int j = 0;
	if (L == NULL) return ERROR;
	p = L;
	while (p && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;
	newp = (LinkList_D)malloc(sizeof(LNode_D));
	if (!newp) exit(OVERFLOW);
	newp->data = e; 
	newp->next = p->next;
	newp->prior = p;
	p->next->prior = newp;
	p->next = newp;
	return OK;
}

//删除
Status DeleteLinkList_D(LinkList_D L, int i, ElemType *e) {
	LinkList_D p, q;
	int j = 0;
	if (L == NULL) return ERROR;
	p = L;
	while (p && j<i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	q->next->prior = p;
	*e = q->data;
	free(q);
	return OK;
}

//打印
Status TraverseLinkList_D(LinkList_D L, void(*visit)(ElemType)) {
	LinkList_D p;
	if (EmptyLinkList_D(L)) return ERROR;
	p = L->next;
	while (p && p != L)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

//头插法
Status InsertLinkList_D_H(LinkList_D *L, int n);
//尾插法
Status InsertLinkList_D_N(LinkList_D *L, int n);
//合并
Status MergeLinkList_D(LinkList_D La, LinkList_D Lb, LinkList_D *Lc);

void main_SLink_D() {
	LinkList_D L;
	ElemType e;
	int i = 0;
	if(InitLinkList_D(&L)) printf("初始化成功\n");
	else printf("初始化失败\n");
	for (i = 1; i < 5; i++)
	{
		InsertLinkList_D(L, i, i);
	}
	TraverseLinkList_D(L, PrintElem);
	printf("长度：%d\n",GetLengthLinkList_D(L));
	if (DeleteLinkList_D(L, 2, &e)) printf("删除成功，e=%d\n",e);
	else printf("删除失败\n");
	TraverseLinkList_D(L, PrintElem);
	printf("长度：%d\n", GetLengthLinkList_D(L));
	if (GetElemLinkList_D(L, 2, &e)) printf("按位置获取元素：e=%d\n", e);
	else printf("按位置元素获取失败！\n", e);
	printf("元素%d的位置是：%d\n", e, LocateElemLinkList_D(L, e, CmpGreater));
	if (DestroyLinkList_D(&L)) printf("销毁成功\n");
	else printf("销毁失败\n");
}
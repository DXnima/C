#include "stdafx.h"
#include "SLink_R.h"

//初始化
Status InitLinkList_R(LinkList_R *L) {
	*L = (LinkList_R)malloc(sizeof(LNode));
	if (!L) exit(OVERFLOW);
	(*L)->next = *L;
	return OK;
}

//销毁
Status DestroyLinkList_R(LinkList_R *L) {
	LinkList_R p;
	if (L == NULL) return ERROR;
	p = *L;
	while (p)
	{
		p = (*L)->next;
		(*L)->next = p->next;
		free(p);
		if ((*L)->next == *L) break;
	}
	*L = NULL;
	return OK;
}

//清空
Status ClearLinkList_R(LinkList_R *L) {
	LinkList_R p,q;
	if (L == NULL || (*L)->next == NULL) return ERROR;
	p = (*L)->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	(*L)->next = *L;
	return OK;
}

//判断是否为空
Status EmptyLinkList_R(LinkList_R L) {
	if (L != NULL && L->next == L) return TRUE;
	else return FALSE;
}

//获取长度
int GetLengthLinkList_R(LinkList_R L) {
	int i = 0;
	LinkList_R p, frist;
	if (L == NULL || L->next == L) return 0;
	p = L->next;
	while (p)
	{
		if (p == L) break;
		p = p->next;
		i++;
	}
	if (p == NULL) return 0;
	return i;
}

//获取指定位置id的e
Status GetElemLinkList_R(LinkList_R L, int i, ElemType *e);
//获取指定e的位置
Status LocateElemLinkList_R(LinkList_R L, ElemType e, Status(*Compare)(ElemType, ElemType));
//前驱
Status PriorElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre);
//后继
Status NextElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre);
//插入
Status InsertLinkList_R(LinkList_R L, int i, ElemType e) {
	int j = 0;
	LinkList_R p,newp;
	if (L == NULL) return ERROR;
	p = L;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i - 1) return ERROR;
	newp = (LinkList_R)malloc(sizeof(LNode));
	newp->data = e;
	newp->next = NULL;
	newp->next = p->next;
	p->next = newp;
	return OK;
}

//删除
Status DeleteLinkList_R(LinkList_R L, int i, ElemType *e);
//打印
Status TraverseLinkList_R(LinkList_R L, void(*visit)(ElemType)) {
	LinkList_R p;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L->next;
	while (p)
	{
		if (p == L) break;
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
//头插法
Status InsertLinkList_R_H(LinkList_R *L, int n);
//尾插法
Status InsertLinkList_R_N(LinkList_R *L, int n);
//合并
Status MergeLinkList_R(LinkList_R La, LinkList_R Lb, LinkList_R *Lc);

void main_SLink_R() {
	LinkList_R L;
	int i = 0;
	InitLinkList_R(&L);
	for (i = 1; i < 5; i++)
	{
		InsertLinkList_R(L, i, i);
	}
	printf("\n");
	TraverseLinkList_R(L, PrintElem);
	printf("%d\n", GetLengthLinkList_R(L));
	if (DestroyLinkList_R(&L)) printf("销毁成功！");
	else printf("销毁失败！");
}
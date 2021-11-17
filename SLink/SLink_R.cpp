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
	free((*L)->next);
	*L = NULL;
	return OK;
}

//清空
Status ClearLinkList_R(LinkList_R *L) {
	LinkList_R p,q;
	if (L == NULL || (*L)->next == NULL) return ERROR;
	p = (*L)->next;
	while (p && (*L)->next == *L)
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
	LinkList_R p;
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
Status GetElemLinkList_R(LinkList_R L, int i, ElemType *e) {
	LinkList_R p;
	int j = 0;
	if (L == NULL || L->next == L) return ERROR;
	p = L;
	while (p->next && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i - 1) return ERROR;
	*e = p->next->data;
	return OK;
}

//获取指定第一个e的位置
int LocateElemLinkList_R(LinkList_R L, ElemType e, Status(*Compare)(ElemType, ElemType)) {
	LinkList_R p;
	int i = 1;
	if (L == NULL || L->next == L) return ERROR;
	p = L->next;
	while (p && !Compare(e, p->data) && p->next != L)
	{
		p = p->next;
		i++;
	}
	return i;
}

//前驱
Status PriorElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre) {
	LinkList_R p,q;
	if (L == NULL || L->next == L) return ERROR;
	p = L->next;
	if (p->data == e) {
		while (p && p->next !=L)
		{
			p = p->next;
		}
		*pre = p->data;
	}
	q = L->next;
	while (q && q->data != e)
	{
		p = q;
		q = q->next;
	}
	if (p == NULL) return ERROR;
	*pre = p->data;
	return OK;
}

//后继
Status NextElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre) {
	LinkList_R p;
	if (L == NULL || L->next == L) return ERROR;
	p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	if (p == NULL) return ERROR;
	if (p->next == L)
	{
		*pre = p->next->next->data;
	}
	else
	{
		*pre = p->next->data;
	}
	return OK;
}

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
	if (p->next == NULL || j > i - 1) return ERROR;
	newp = (LinkList_R)malloc(sizeof(LNode));
	newp->data = e;
	newp->next = NULL;
	newp->next = p->next;
	p->next = newp;
	return OK;
}

//删除
Status DeleteLinkList_R(LinkList_R L, int i, ElemType *e) {
	int j = 0;
	LinkList_R p,q;
	if (L == NULL || L->next == L) return 0;
	p = L;
	while (p->next && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

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
Status InsertLinkList_R_H(LinkList_R *L, int n) {
	LinkList_R p;
	*L = (LinkList_R)malloc(sizeof(LNode));
	if (!*L) exit(OVERFLOW);
	(*L)->next = *L;
	for (int i = 1; i <= n; i++)
	{
		p = (LinkList_R)malloc(sizeof(LNode));
		if (!p) exit(OVERFLOW);
		p->data = i;
		p->next = NULL;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return OK;
}

//尾插法
Status InsertLinkList_R_N(LinkList_R *L, int n) {
	LinkList_R p,q;
	*L = (LinkList_R)malloc(sizeof(LNode));
	if (!*L) exit(OVERFLOW);
	(*L)->next = *L;
	q = (*L);
	for (int i = 1; i <= n; i++)
	{
		p = (LinkList_R)malloc(sizeof(LNode));
		if (!p) exit(OVERFLOW);
		p->data = i;
		p->next = *L;
		q->next = p;
		q = q->next;
	}
	return OK;
}

//合并
Status MergeLinkList_R(LinkList_R La, LinkList_R Lb, LinkList_R *Lc) {
	LinkList_R pc, pa, pb;
	if (La == NULL || Lb == NULL) return ERROR;
	*Lc = (LinkList_R)malloc(sizeof(LNode));
	if (!Lc) exit(OVERFLOW);
	(*Lc)->next = NULL;
	pc = (*Lc);
	pa = La->next;
	pb = Lb->next;
	while (pa && pb)
	{
		if (pa->data < pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			if (pa == La) break;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
			if (pb == Lb) break;
		}
	}
	//剩余连接
	while (pa != La)
	{
		pc->next = pa;
		pc = pa;
		pa = pa->next;
	}
	while (pb != Lb)
	{
		pc->next = pb;
		pc = pb;
		pb = pb->next;
	}
	//尾结点连接头结点
	pc->next = *Lc;
	return OK;
}

void main_SLink_R() {
	LinkList_R L, Lb, Lc;
	ElemType e;
	int i;
	printf("-----------循环单链表测试----------------\n");
	printf("-----------头插法----------------\n");
	InsertLinkList_R_H(&L, 10);
	TraverseLinkList_R(L, PrintElem);
	if (DestroyLinkList_R(&L)) printf("\n-----------链表销毁成功！----------------\n");

	printf("\n-----------尾插法----------------\n");
	InsertLinkList_R_N(&L, 10);
	TraverseLinkList_R(L, PrintElem);
	if (DestroyLinkList_R(&L)) printf("\n-----------链表销毁成功！----------------\n");
	InitLinkList_R(&L);

	if (InitLinkList_R(&L)) printf("\n-----------链表初始化成功！----------------\n");
	for (i = 1; i <= 10; i++)
	{
		InsertLinkList_R(L, i, i);
	}
	TraverseLinkList_R(L, PrintElem);
	printf("\n链表创建成功，长度为：%d\n", GetLengthLinkList_R(L));

	PriorElemLinkList_R(L, 8, &e);
	printf("\n元素8的前序是：%d\n", e);

	NextElemLinkList_R(L, 8, &e);
	printf("\n元素8的后继是：%d\n", e);

	printf("\n在第8位置插入8848\n", e);
	InsertLinkList_R(L, 8, 8848);
	TraverseLinkList_R(L, PrintElem);

	printf("\n删除第8个元素\n", e);
	DeleteLinkList_R(L, 8, &e);
	TraverseLinkList_R(L, PrintElem);
	printf("\n删除成功，删除元素为：e = %d\n", e);

	printf("\n第一个大于 \"8\" 的位置是:i = %d\n", LocateElemLinkList_R(L, 8, CmpGreater));

	printf("\n-----------初始化Lb----------------\n");
	InitLinkList_R(&Lb);
	for (i = 1; i <= 5; i++)
	{
		InsertLinkList_R(Lb, i, i * 3);
	}
	TraverseLinkList_R(Lb, PrintElem);
	printf("\n-----------L和Lb合并为Lc----------------\n");
	MergeLinkList_R(L, Lb, &Lc);
	TraverseLinkList_R(Lc, PrintElem);
	if (DestroyLinkList_R(&Lc)) printf("\n-----------链表销毁成功！----------------\n");
	printf("\n-----------链表销毁失败！----------------\n");
}
#include "stdafx.h"
#include "SLink_D.h"

//初始化
Status InitLinkList_D(LinkList_D *L) {
	*L = (LinkList_D)malloc(sizeof(LNode_D));
	if (!*L) exit(OVERFLOW);
	(*L)->prior = (*L)->next = *L;
	return OK;
}

//销毁
Status DestroyLinkList_D(LinkList_D *L) {
	if (EmptyLinkList_D(*L)) return ERROR;
	ClearLinkList_D(L);
	free(*L);
	*L = NULL;
	return OK;
}

//清空
Status ClearLinkList_D(LinkList_D *L) {
	LinkList_D p;
	if (EmptyLinkList_D(*L)) return ERROR;
	p = *L;
	while ((*L)->next != *L)
	{
		p = (*L)->next;
		(*L)->next = p->next;
		free(p);
	}
	(*L)->prior = (*L)->next = *L;
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
	if (EmptyLinkList_D(L)) return 0;
	p = L->next;
	while (p != L)
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
	while (p->next != L && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (p->next == L || j > i - 1) return 0;
	*e = p->next->data;
	return OK;
}

//获取指定e的位置
int LocateElemLinkList_D(LinkList_D L, ElemType e, Status(*Compare)(ElemType, ElemType)) {
	LinkList_D p;
	int i = 0;
	if (EmptyLinkList_D(L)) return 0;
	p = L->next;
	while (p && !Compare(e, p->data))
	{
		p = p->next;
		i++;
	}
	if (p != L) return i;
	else return 0;
}

//前驱
Status PriorElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre) {
	LinkList_D p;
	if (EmptyLinkList_D(L)) return ERROR;
	p = L->next;
	// 第1个元素没有前驱
	if (p->data == e) {
		return ERROR;
	}
	// 指向第2个元素
	p = p->next;
	while (p->data != e && p != L)
	{
		p = p->next;
	}
	if (p == L) return ERROR;
	*pre = p->prior->data;
	return OK;
}

//后继
Status NextElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre) {
	LinkList_D p;
	if (EmptyLinkList_D(L)) return ERROR;
	// 指向第1个元素
	p = L->next;
	// 从第1个元素开始，查找cur_e的位置，且保证该结点的后继不为L
	while (p->data != e && p->next != L)
	{
		p = p->next;
	}
	if (p->next == L) return ERROR;
	*pre = p->next->data;
	return OK;
}

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
Status InsertLinkList_D_H(LinkList_D *L, int n) {
	LinkList_D newp;
	if (!EmptyLinkList_D(*L)) DestroyLinkList_D(L);
	*L = (LinkList_D)malloc(sizeof(LNode_D));
	if (!*L) exit(OVERFLOW);
	(*L)->next = (*L)->prior = *L;
	for (int i = 1; i <= n; i++)
	{
		newp = (LinkList_D)malloc(sizeof(LNode_D));
		if (!newp) exit(OVERFLOW);
		newp->data = i;
		newp->next = (*L)->next;
		(*L)->next->prior = newp;
		(*L)->next = newp;
		newp->prior = (*L);
	}
	return OK;
}

//尾插法
Status InsertLinkList_D_N(LinkList_D *L, int n) {
	LinkList_D newp,q;
	if (!EmptyLinkList_D(*L)) DestroyLinkList_D(L);
	*L = (LinkList_D)malloc(sizeof(LNode_D));
	if (!*L) exit(OVERFLOW);
	(*L)->next = (*L)->prior = *L;
	q = *L;
	for (int i = 1; i <= n; i++)
	{
		newp = (LinkList_D)malloc(sizeof(LNode_D));
		if (!newp) exit(OVERFLOW);
		newp->data = i;
		newp->next = (*L);
		newp->prior = q;
		q->next = newp;
		(*L)->prior = newp;
		q = q->next;
	}
	return OK;
}

//合并
Status MergeLinkList_D(LinkList_D La, LinkList_D Lb, LinkList_D *Lc) {
	if (EmptyLinkList_D(La) || EmptyLinkList_D(Lb)) return ERROR;
	LinkList_D pa, pb, pc;
	*Lc = (LinkList_D)malloc(sizeof(LNode_D));
	if (!*Lc) exit(OVERFLOW);
	(*Lc)->next = (*Lc)->prior = *Lc;
	pc = *Lc;
	pa = La->next;
	pb = Lb->next;
	while (pa && pb && pa!=La && pb !=Lb)
	{
		if (pa->data < pb->data) {
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
	(*Lc)->prior = pc;
	return OK;
}

void main_SLink_D() {
	LinkList_D L,Lb,Lc;
	ElemType e;
	int i = 0;

	if(InitLinkList_D(&L)) printf("初始化成功\n");
	else printf("初始化失败\n");

	for (i = 1; i < 5; i++)
	{
		InsertLinkList_D(L, i, i);
	}
	TraverseLinkList_D(L, PrintElem);

	if (InitLinkList_D(&Lb)) printf("Lb初始化成功\n");
	else printf("Lb初始化失败\n");
	for (i = 1; i < 5; i++)
	{
		InsertLinkList_D(Lb, i, i * 3);
	}
	TraverseLinkList_D(Lb, PrintElem);

	if (MergeLinkList_D(L, Lb, &Lc)) {
		printf("L和Lb合并成功！\n");
		TraverseLinkList_D(L, PrintElem);
	}
	else printf("L和Lb合并失败！\n");

	printf("长度：%d\n",GetLengthLinkList_D(L));

	if (PriorElemLinkList_D(L, 1, &e)) printf("指定前驱为：e=%d\n", e);
	else printf("指定前驱获取失败！\n", e);

	if (NextElemLinkList_D(L, 1, &e)) printf("指定后继为：e=%d\n", e);
	else printf("指定后继获取失败！\n", e);

	if (DeleteLinkList_D(L, 2, &e)) printf("删除成功，e=%d\n",e);
	else printf("删除失败\n");
	TraverseLinkList_D(L, PrintElem);

	printf("长度：%d\n", GetLengthLinkList_D(L));

	if (GetElemLinkList_D(L, 2, &e)) printf("按位置获取元素：e=%d\n", e);
	else printf("按位置元素获取失败！\n", e);
	printf("元素%d的位置是：%d\n", e, LocateElemLinkList_D(L, e, CmpGreater));

	if (DestroyLinkList_D(&L)) printf("销毁成功\n");
	else printf("销毁失败\n");

	if (InitLinkList_D(&L)) {
		printf("头插法创建成功！\n"); 
		InsertLinkList_D_H(&L, 10);
		TraverseLinkList_D(L, PrintElem);
	}
	else printf("头插法创建失败！\n");

	if (DestroyLinkList_D(&L)) printf("销毁成功\n");
	else printf("销毁失败\n");
	if (InitLinkList_D(&L)) {
		printf("尾插法创建成功！\n");
		InsertLinkList_D_N(&L, 10);
		TraverseLinkList_D(L, PrintElem);
	}
	else printf("尾插法创建失败！\n");

}
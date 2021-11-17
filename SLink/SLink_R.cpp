#include "stdafx.h"
#include "SLink_R.h"

//��ʼ��
Status InitLinkList_R(LinkList_R *L) {
	*L = (LinkList_R)malloc(sizeof(LNode));
	if (!L) exit(OVERFLOW);
	(*L)->next = *L;
	return OK;
}

//����
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

//���
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

//�ж��Ƿ�Ϊ��
Status EmptyLinkList_R(LinkList_R L) {
	if (L != NULL && L->next == L) return TRUE;
	else return FALSE;
}

//��ȡ����
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

//��ȡָ��λ��id��e
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

//��ȡָ����һ��e��λ��
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

//ǰ��
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

//���
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

//����
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

//ɾ��
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

//��ӡ
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

//ͷ�巨
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

//β�巨
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

//�ϲ�
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
	//ʣ������
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
	//β�������ͷ���
	pc->next = *Lc;
	return OK;
}

void main_SLink_R() {
	LinkList_R L, Lb, Lc;
	ElemType e;
	int i;
	printf("-----------ѭ�����������----------------\n");
	printf("-----------ͷ�巨----------------\n");
	InsertLinkList_R_H(&L, 10);
	TraverseLinkList_R(L, PrintElem);
	if (DestroyLinkList_R(&L)) printf("\n-----------�������ٳɹ���----------------\n");

	printf("\n-----------β�巨----------------\n");
	InsertLinkList_R_N(&L, 10);
	TraverseLinkList_R(L, PrintElem);
	if (DestroyLinkList_R(&L)) printf("\n-----------�������ٳɹ���----------------\n");
	InitLinkList_R(&L);

	if (InitLinkList_R(&L)) printf("\n-----------�����ʼ���ɹ���----------------\n");
	for (i = 1; i <= 10; i++)
	{
		InsertLinkList_R(L, i, i);
	}
	TraverseLinkList_R(L, PrintElem);
	printf("\n�������ɹ�������Ϊ��%d\n", GetLengthLinkList_R(L));

	PriorElemLinkList_R(L, 8, &e);
	printf("\nԪ��8��ǰ���ǣ�%d\n", e);

	NextElemLinkList_R(L, 8, &e);
	printf("\nԪ��8�ĺ���ǣ�%d\n", e);

	printf("\n�ڵ�8λ�ò���8848\n", e);
	InsertLinkList_R(L, 8, 8848);
	TraverseLinkList_R(L, PrintElem);

	printf("\nɾ����8��Ԫ��\n", e);
	DeleteLinkList_R(L, 8, &e);
	TraverseLinkList_R(L, PrintElem);
	printf("\nɾ���ɹ���ɾ��Ԫ��Ϊ��e = %d\n", e);

	printf("\n��һ������ \"8\" ��λ����:i = %d\n", LocateElemLinkList_R(L, 8, CmpGreater));

	printf("\n-----------��ʼ��Lb----------------\n");
	InitLinkList_R(&Lb);
	for (i = 1; i <= 5; i++)
	{
		InsertLinkList_R(Lb, i, i * 3);
	}
	TraverseLinkList_R(Lb, PrintElem);
	printf("\n-----------L��Lb�ϲ�ΪLc----------------\n");
	MergeLinkList_R(L, Lb, &Lc);
	TraverseLinkList_R(Lc, PrintElem);
	if (DestroyLinkList_R(&Lc)) printf("\n-----------�������ٳɹ���----------------\n");
	printf("\n-----------��������ʧ�ܣ�----------------\n");
}
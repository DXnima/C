#include "stdafx.h"
#include "SLink.h"

//��ʼ��
Status InitLinkList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL) {
		exit(OVERFLOW);
		return ERROR;
	}
	(*L)->next = NULL;
	return OK;
}

//����
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

//���
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

//�ж��Ƿ�Ϊ��
Status EmptyLinkList(LinkList L) {
	if (L != NULL && L->next == NULL) return TRUE;
	else return FALSE;
}

//��ȡ����
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

//��ȡָ��λ��i��e
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

//��ȡָ��e��λ��
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
//ǰ��
Status PriorElemLinkList(LinkList L, ElemType e, ElemType *pre) {
	LinkList p, q;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L->next;
	//��һ��û��ǰ��
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

//���
Status NextElemLinkList(LinkList L, ElemType e, ElemType *pre) {
	LinkList p;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	//���һ��û�к��
	if (p == NULL || p->next == NULL) return ERROR;
	*pre = p->next->data;
	return OK;
}
//����
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

//ɾ��
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

//��ӡ
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

//ͷ�巨
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

//β�巨
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

//�ϲ�
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
	//��ʣ�ಿ��ֱ�ӽӵ����
	pc->next = pa ? pa : pb;
	//�ͷ�Lbͷ�ڵ�
	free(Lb);
	return OK;
}

void main_SLink() {
	LinkList L,Lb,Lc;
	ElemType e;
	int i;
	printf("-----------ͷ�巨----------------\n");
	InsertLinkList_H(&L, 10);
	TraverseLinkList(L, PrintElem);
	if (DestroyLinkList(&L)) printf("\n-----------�������ٳɹ���----------------\n");
	
	printf("\n-----------β�巨----------------\n");
	InsertLinkList_N(&L, 10);
	TraverseLinkList(L, PrintElem);
	if (InitLinkList(&L)) printf("\n-----------�������ٳɹ���----------------\n");
	DestroyLinkList(&L);
	
	if (InitLinkList(&L)) printf("\n-----------�����ʼ���ɹ���----------------\n");
	for (i = 1; i <= 10; i++)
	{
		InsertLinkList(L, i, i);
	}
	TraverseLinkList(L, PrintElem);
	printf("\n�������ɹ�������Ϊ��%d\n", GetLengthLinkList(L));
	
	PriorElemLinkList(L, 8, &e);
	printf("\nԪ��8��ǰ���ǣ�%d\n", e);
	
	NextElemLinkList(L, 8, &e);
	printf("\nԪ��8�ĺ���ǣ�%d\n", e);
	
	printf("\n�ڵ�8λ�ò���8848\n", e);
	InsertLinkList(L, 8, 8848);
	TraverseLinkList(L, PrintElem);
	
	printf("\nɾ����8��Ԫ��\n", e);
	DeleteLinkList(L, 8, &e);
	TraverseLinkList(L, PrintElem);
	printf("\nɾ���ɹ���ɾ��Ԫ��Ϊ��e = %d\n", e);
	
	printf("\n��һ������ \"8\" ��λ����:i = %d\n", LocateElemLinkList(L, 8, CmpGreater));
	
	printf("\n-----------��ʼ��Lb----------------\n");
	InitLinkList(&Lb);
	for (i = 1; i <= 5; i++)
	{
		InsertLinkList(Lb, i, i*3);
	}
	TraverseLinkList(Lb, PrintElem);
	printf("\n-----------L��Lb�ϲ�ΪLc----------------\n");
	MergeLinkList(L, Lb, &Lc, CmpGreater);
	TraverseLinkList(Lc, PrintElem);
	if (DestroyLinkList(&L)) printf("\n-----------�������ٳɹ���----------------\n");
}
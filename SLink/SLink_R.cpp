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
	*L = NULL;
	return OK;
}

//���
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

//�ж��Ƿ�Ϊ��
Status EmptyLinkList_R(LinkList_R L) {
	if (L != NULL && L->next == L) return TRUE;
	else return FALSE;
}

//��ȡ����
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

//��ȡָ��λ��id��e
Status GetElemLinkList_R(LinkList_R L, int i, ElemType *e);
//��ȡָ��e��λ��
Status LocateElemLinkList_R(LinkList_R L, ElemType e, Status(*Compare)(ElemType, ElemType));
//ǰ��
Status PriorElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre);
//���
Status NextElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre);
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
	if (p == NULL || j > i - 1) return ERROR;
	newp = (LinkList_R)malloc(sizeof(LNode));
	newp->data = e;
	newp->next = NULL;
	newp->next = p->next;
	p->next = newp;
	return OK;
}

//ɾ��
Status DeleteLinkList_R(LinkList_R L, int i, ElemType *e);
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
Status InsertLinkList_R_H(LinkList_R *L, int n);
//β�巨
Status InsertLinkList_R_N(LinkList_R *L, int n);
//�ϲ�
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
	if (DestroyLinkList_R(&L)) printf("���ٳɹ���");
	else printf("����ʧ�ܣ�");
}
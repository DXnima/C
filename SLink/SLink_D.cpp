#include "stdafx.h"
#include "SLink_D.h"

//��ʼ��
Status InitLinkList_D(LinkList_D *L) {
	*L = (LinkList_D)malloc(sizeof(LNode_D));
	if (!*L) exit(OVERFLOW);
	(*L)->prior = *L;
	(*L)->next = *L;
	return OK;
}

//����
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

//���
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

//�ж��Ƿ�Ϊ��
Status EmptyLinkList_D(LinkList_D L) {
	if (L == NULL || (L->prior = L->next) == L) return TRUE;
	return FALSE;
}

//��ȡ����
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

//��ȡָ��λ��id��e
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

//��ȡָ��e��λ��
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

//ǰ��
Status PriorElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre);
//���
Status NextElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre);

//����
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

//ɾ��
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

//��ӡ
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

//ͷ�巨
Status InsertLinkList_D_H(LinkList_D *L, int n);
//β�巨
Status InsertLinkList_D_N(LinkList_D *L, int n);
//�ϲ�
Status MergeLinkList_D(LinkList_D La, LinkList_D Lb, LinkList_D *Lc);

void main_SLink_D() {
	LinkList_D L;
	ElemType e;
	int i = 0;
	if(InitLinkList_D(&L)) printf("��ʼ���ɹ�\n");
	else printf("��ʼ��ʧ��\n");
	for (i = 1; i < 5; i++)
	{
		InsertLinkList_D(L, i, i);
	}
	TraverseLinkList_D(L, PrintElem);
	printf("���ȣ�%d\n",GetLengthLinkList_D(L));
	if (DeleteLinkList_D(L, 2, &e)) printf("ɾ���ɹ���e=%d\n",e);
	else printf("ɾ��ʧ��\n");
	TraverseLinkList_D(L, PrintElem);
	printf("���ȣ�%d\n", GetLengthLinkList_D(L));
	if (GetElemLinkList_D(L, 2, &e)) printf("��λ�û�ȡԪ�أ�e=%d\n", e);
	else printf("��λ��Ԫ�ػ�ȡʧ�ܣ�\n", e);
	printf("Ԫ��%d��λ���ǣ�%d\n", e, LocateElemLinkList_D(L, e, CmpGreater));
	if (DestroyLinkList_D(&L)) printf("���ٳɹ�\n");
	else printf("����ʧ��\n");
}
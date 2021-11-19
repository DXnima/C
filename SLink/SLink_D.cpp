#include "stdafx.h"
#include "SLink_D.h"

//��ʼ��
Status InitLinkList_D(LinkList_D *L) {
	*L = (LinkList_D)malloc(sizeof(LNode_D));
	if (!*L) exit(OVERFLOW);
	(*L)->prior = (*L)->next = *L;
	return OK;
}

//����
Status DestroyLinkList_D(LinkList_D *L) {
	if (EmptyLinkList_D(*L)) return ERROR;
	ClearLinkList_D(L);
	free(*L);
	*L = NULL;
	return OK;
}

//���
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

//�ж��Ƿ�Ϊ��
Status EmptyLinkList_D(LinkList_D L) {
	if (L == NULL || (L->prior = L->next) == L) return TRUE;
	return FALSE;
}

//��ȡ����
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

//��ȡָ��λ��id��e
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

//��ȡָ��e��λ��
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

//ǰ��
Status PriorElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre) {
	LinkList_D p;
	if (EmptyLinkList_D(L)) return ERROR;
	p = L->next;
	// ��1��Ԫ��û��ǰ��
	if (p->data == e) {
		return ERROR;
	}
	// ָ���2��Ԫ��
	p = p->next;
	while (p->data != e && p != L)
	{
		p = p->next;
	}
	if (p == L) return ERROR;
	*pre = p->prior->data;
	return OK;
}

//���
Status NextElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre) {
	LinkList_D p;
	if (EmptyLinkList_D(L)) return ERROR;
	// ָ���1��Ԫ��
	p = L->next;
	// �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ�ã��ұ�֤�ý��ĺ�̲�ΪL
	while (p->data != e && p->next != L)
	{
		p = p->next;
	}
	if (p->next == L) return ERROR;
	*pre = p->next->data;
	return OK;
}

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

//β�巨
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

//�ϲ�
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
	(*Lc)->prior = pc;
	return OK;
}

void main_SLink_D() {
	LinkList_D L,Lb,Lc;
	ElemType e;
	int i = 0;

	if(InitLinkList_D(&L)) printf("��ʼ���ɹ�\n");
	else printf("��ʼ��ʧ��\n");

	for (i = 1; i < 5; i++)
	{
		InsertLinkList_D(L, i, i);
	}
	TraverseLinkList_D(L, PrintElem);

	if (InitLinkList_D(&Lb)) printf("Lb��ʼ���ɹ�\n");
	else printf("Lb��ʼ��ʧ��\n");
	for (i = 1; i < 5; i++)
	{
		InsertLinkList_D(Lb, i, i * 3);
	}
	TraverseLinkList_D(Lb, PrintElem);

	if (MergeLinkList_D(L, Lb, &Lc)) {
		printf("L��Lb�ϲ��ɹ���\n");
		TraverseLinkList_D(L, PrintElem);
	}
	else printf("L��Lb�ϲ�ʧ�ܣ�\n");

	printf("���ȣ�%d\n",GetLengthLinkList_D(L));

	if (PriorElemLinkList_D(L, 1, &e)) printf("ָ��ǰ��Ϊ��e=%d\n", e);
	else printf("ָ��ǰ����ȡʧ�ܣ�\n", e);

	if (NextElemLinkList_D(L, 1, &e)) printf("ָ�����Ϊ��e=%d\n", e);
	else printf("ָ����̻�ȡʧ�ܣ�\n", e);

	if (DeleteLinkList_D(L, 2, &e)) printf("ɾ���ɹ���e=%d\n",e);
	else printf("ɾ��ʧ��\n");
	TraverseLinkList_D(L, PrintElem);

	printf("���ȣ�%d\n", GetLengthLinkList_D(L));

	if (GetElemLinkList_D(L, 2, &e)) printf("��λ�û�ȡԪ�أ�e=%d\n", e);
	else printf("��λ��Ԫ�ػ�ȡʧ�ܣ�\n", e);
	printf("Ԫ��%d��λ���ǣ�%d\n", e, LocateElemLinkList_D(L, e, CmpGreater));

	if (DestroyLinkList_D(&L)) printf("���ٳɹ�\n");
	else printf("����ʧ��\n");

	if (InitLinkList_D(&L)) {
		printf("ͷ�巨�����ɹ���\n"); 
		InsertLinkList_D_H(&L, 10);
		TraverseLinkList_D(L, PrintElem);
	}
	else printf("ͷ�巨����ʧ�ܣ�\n");

	if (DestroyLinkList_D(&L)) printf("���ٳɹ�\n");
	else printf("����ʧ��\n");
	if (InitLinkList_D(&L)) {
		printf("β�巨�����ɹ���\n");
		InsertLinkList_D_N(&L, 10);
		TraverseLinkList_D(L, PrintElem);
	}
	else printf("β�巨����ʧ�ܣ�\n");

}
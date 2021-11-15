#include "stdafx.h"
#include "SLink.h"

//��ʼ��
Status InitLink(LinkList* L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL) exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}

//����(�ṹ)
Status DestroyLink(LinkList* L) {
	LinkList p;
	// ȷ������ṹ����
	if (L == NULL || *L == NULL) {
		return ERROR;
	}
	p = *L;
	while (p != NULL)
	{
		p = (*L)->next;
		free(*L);
		(*L)->next = p;
	}
	*L = NULL;
	return OK;
}

// �ÿ�(����)
Status ClearLink(LinkList L) {
	LinkList pre,p;
	// ȷ������ṹ����
	if (L == NULL) {
		return ERROR;
	}
	p = L->next;
	while (p != NULL)
	{
		pre = p;
		p = p->next;
		free(pre);
	}
	L->next = NULL;
	return OK;
}

/*
* �п�
* �ж��������Ƿ������Ч���ݡ�
*/
Status LinkEmpty(LinkList L) {
	// ����ֻ��ͷ���ʱ����Ϊ������Ϊ��
	if (L != NULL && L->next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*
* ����
* ���������������ЧԪ�ص�������
*/
int LinkLength(LinkList L) {
	int num = 0;
	LinkList p;
	if (L == NULL || L->next == NULL)
		return 0;
	p = L->next;
	while (p!=NULL)
	{
		p = p->next;
		num++;
	}
	return num;
}

/*
* ȡֵ
* ��ȡ�����е�i��Ԫ�أ�����洢��e�С�
*/
Status GetElemLink(LinkList L, int i, ElemType* e) {
	LinkList p;
	int j=0;
	if (L == NULL || L->next == NULL)
		return ERROR;
	p = L->next;
	while (p!=NULL && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i - 1) return ERROR;
	*e = p->next->data;
	return OK;
}

/*
* ����
* �����������׸���e����Compare��ϵ��Ԫ��λ��
*/
int LocateElemLink(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
	int i=1;
	LinkList p;
	if (L == NULL || L->next == NULL)
		return ERROR;
	p = L->next;
	while (p != NULL && !Compare(p->data, e)) {
		p = p->next;
		i++;
	}
	if (p == NULL) return 0;
	else return i;
}

/*
* ǰ��
*/
Status PriorElemLink(LinkList L, ElemType cur_e, ElemType* pre_e) {
	LinkList p,next;
	if (L == NULL || L->next == NULL)
		return ERROR;
	p = L->next;
	// ��1��Ԫ��û��ǰ��
	if (p->data == cur_e) {
		return ERROR;
	}
	next = p->next;
	while (next !=NULL && next->data != cur_e)
	{
		p = next;
		next = next->next;
	}
	if (p == NULL) return ERROR;
	*pre_e = p->data;
	return OK;
}

/*
* ���
*/
Status NextElemLink(LinkList L, ElemType cur_e, ElemType* next_e) {
	LinkList p;
	if (L == NULL || L->next == NULL)
		return ERROR;
	p = L->next;
	while (p != NULL && p->data != cur_e)
	{
		p = p->next;
	}
	if (p==NULL || p->next == NULL) return ERROR;
	*next_e = p->next->data;
	return OK;
}

/*
* ����
* �������i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
*/
Status LinkInsert(LinkList L, int i, ElemType e) {
	LinkList p,s;
	int j = 0;
	if (L == NULL)
		return ERROR;
	p = L;
	while (p!=NULL && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

/*
* ɾ��
* ɾ�������i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
*/
Status LinkDelete(LinkList L, int i, ElemType* e) {
	LinkList p,q;
	int j=0;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L;
	while (p->next != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	*e = p->data;
	free(q);
	return OK;
}

/*
* ����
* ��visit������������L
*/
void LinkTraverse(LinkList L, void(Visit)(ElemType)) {
	LinkList p;
	if (L == NULL || L->next == NULL) return;
	p = L->next;
	while (p!=NULL)
	{
		Visit(p->data);
		p = p->next;
	}
	printf("\n");
}

/*
* ͷ�巨��������
*/
Status CreateLink_Head(LinkList* L, int n) {
	LinkList p;
	int i;
	// ����ͷ���
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	for (i = 1; i <= n; ++i) {
		// �����½��
		p = (LinkList)malloc(sizeof(LNode));
		// ������ݣ������뵽������
		p->data = i;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return OK;
}

/*
* β�巨��������
*/
Status CreateLink_Tail(LinkList* L, int n) {
	LinkList p,q;
	int i;
	// ����ͷ���
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	for (i = 1, q = *L; i <= n; ++i) {
		// �����½��
		p = (LinkList)malloc(sizeof(LNode));
		// ������ݣ������뵽������
		p->data = i;
		q->next = p;
		q = q->next;
	}
	return OK;
}

void main_SLink() {
	LinkList L;
	int i;
	ElemType e;
	printf("---------------��ʼ�������� L ...\n");
	InitLink(&L);
	for (i = 1; i <= 8; i++) {
		LinkInsert(L, i, 2 * i);
	}
	printf("L �е�Ԫ��Ϊ��L = ");
	LinkTraverse(L, PrintElem);

	printf("\nλ��8�����8848\n");
	LinkInsert(L, 9, 8848);
	LinkTraverse(L, PrintElem);
	printf("\nλ��8��ɾ��8848\n");
	LinkDelete(L, 9, &e);
	LinkTraverse(L, PrintElem);

	printf("\nԪ��12��ǰ����");
	PriorElemLink(L,12,&e);
	printf("%d\n",e);
	printf("\nԪ��12����̣�");
	NextElemLink(L, 12, &e);
	printf("%d\n", e);

	printf("\n---------------ͷ�巨\n");
	CreateLink_Head(&L, 10);
	LinkTraverse(L, PrintElem);
	printf("\n---------------β�巨\n");
	CreateLink_Tail(&L, 10);
	LinkTraverse(L, PrintElem);
	printf("\n---------------����...\n");
	DestroyLink(&L);
}
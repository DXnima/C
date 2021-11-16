// SList.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "SList.h"


//���������Ա�
Status InitList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

//���ٿ����Ա�
Status DestroyList(SqList *L) {
	// ȷ��˳���ṹ����
	if (L == NULL || (*L).elem == NULL) {
		return ERROR;
	}
	// �ͷ�˳����ڴ�
	free((*L).elem);
	// �ͷ��ڴ���ÿ�ָ��
	(*L).elem = NULL;
	// ˳����ȸ�����������
	(*L).length = 0;
	(*L).listsize = 0;
	return OK;
}

//�ж��Ƿ�Ϊ�ձ�
Status ListEmpty(SqList L) {
	return L.length == 0 ? TRUE : FALSE;
}

//��ȡԪ�ظ���
int ListLength(SqList L) {
	return L.length;
}

//���ص�һ����e�����Ԫ��λ��
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
	int i;
	ElemType* p;
	// ȷ��˳���ṹ����
	if (L.elem == NULL) {
		return ERROR;
	}
	/*
	* i�ĳ�ֵΪ��1��Ԫ�ص�λ��
	*/
	i = 1;
	// p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
	p = L.elem;
	// ����˳���
	while (i <= L.length && !Compare(*p++, e)) {
		++i;
	}
	if (i <= L.length) {
		return i;
	}
	else {
		return 0;
	}
}

//ǰ�� ��ȡԪ��cur_e��ǰ��
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e) {
	int i;
	// ȷ��˳���ṹ���ڣ������ٰ�������Ԫ��
	if (L.elem == NULL || L.length < 2) {
		return ERROR;
	}
	// �����i��ʼ��Ϊ��1��Ԫ�صġ�������
	i = 0;
	// �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ��
	while (i < L.length && L.elem[i] != cur_e) {
		++i;
	}
	// ���cur_e���׸�Ԫ��(û��ǰ��)������û�ҵ�Ԫ��cur_e������ERROR
	if (i == 0 || i >= L.length) {
		return ERROR;
	}
	// �洢cur_e��ǰ��
	*pre_e = L.elem[i - 1];
	return OK;
}

//��� ��ȡԪ��cur_e�ĺ��
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e) {
	int i;
	// ȷ��˳���ṹ���ڣ������ٰ�������Ԫ��
	if (L.elem == NULL || L.length < 2) {
		return ERROR;
	}
	// �����i��ʼ��Ϊ��1��Ԫ�صġ�������
	i = 0;
	// �ӵ�1��Ԫ�ؿ�ʼ������cur_e��λ��
	while (i < L.length - 1 && L.elem[i] != cur_e) {
		++i;
	}
	// ���cur_e������Ԫ��(û�к���)������û�ҵ�Ԫ��cur_e������ERROR
	if (i >= L.length - 1) {
		return ERROR;
	}
	// �洢cur_e��ǰ��
	*next_e = L.elem[i + 1];
	return OK;
}

//����
Status ListInsert(SqList *L, int i, ElemType e) {
	ElemType *newe, *p, *q;
	if (i<1 || i>(*L).length + 1) return ERROR;
	if ((*L).length >= (*L).listsize) {
		//����
		newe = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newe) exit(OVERFLOW);
		L->elem = newe;
		L->length += LISTINCREMENT;
	}
	q = &L->elem[i - 1];
	for (p = &(L->elem[L->length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L->length;
	return OK;
}

//ɾ��
Status ListDelete(SqList *L, int i, ElemType *e) {
	ElemType *p, *q;
	if (i<1 || i>(*L).length + 1) return ERROR;
	p = &L->elem[i - 1];
	*e = *p;
	// ��βԪ��λ��
	q = L->elem + L->length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L->length;
	return OK;
}

//���� ��visit��������˳���
void ListTraverse(SqList L, void (Visit)(ElemType)) {
	int i;
	for (i = 0; i < L.length; i++) {
		Visit(L.elem[i]);
	}
	printf("\n");
}

//�ϲ�
void MergeList(SqList La, SqList Lb, SqList *Lc) {
	ElemType *pa, *pa_last, *pb, *pb_last, *pc;
	pa = La.elem;
	pb = Lb.elem;
	Lc->listsize = Lc->length = La.listsize + Lb.length - 1;
	pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
	if (!pc) exit(OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}

void main_SList()
{
	SqList L, L1, Lc;
	ElemType e;
	//��ʼ����
	InitList(&L);
	//����
	for (int i = 1; i<LIST_INIT_SIZE; i++)
		ListInsert(&L, i, i);
	printf("----------------��ʼL----------------\n");
	printf("----------------������%d----------------\n", ListLength(L));
	ListTraverse(L, PrintElem);
	printf("----------------L.elem[0]��%d----------------\n", L.elem[0]);
	printf("\n----------------99λ�ò���8848----------------\n");
	//99λ�ò���8848
	ListInsert(&L, 98, 8848);
	ListTraverse(L, PrintElem);
	PriorElem(L, 8848, &e);
	printf("\n----------------8848ǰ��:%d\n", e);
	NextElem(L, 8848, &e);
	printf("\n----------------8848����:%d\n", e);
	//ɾ��99λ��Ԫ��
	ListDelete(&L, 98, &e);
	printf("\n----------------ɾ��99λ��Ԫ��----------------\n");
	ListTraverse(L, PrintElem);
	printf("\n----------------L1��----------------\n");
	InitList(&L1);
	for (int i = 1; i <= 5; i++)
		ListInsert(&L1, i, i * 100);
	ListTraverse(L1, PrintElem);
	//InitList(&Lc);
	MergeList(L, L1, &Lc);
	printf("\n----------------L��L1�ϲ�ΪLc----------------\n");
	ListTraverse(Lc, PrintElem);
	printf("\n----------------Lc�е�һ������ \"200\" ��λ����:%d----------------\n", LocateElem(Lc, 200, CmpGreater));
	printf("\n----------------����L��L1��Lc----------------\n");
	DestroyList(&L);
	DestroyList(&L1);
	DestroyList(&Lc);
}
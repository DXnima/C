#include "stdafx.h"
#include "SLink_Polyn.h"

//����m���ϵ����ָ��������һԪ����ʽ����
Status CreatPolyn(LinkList_Polyn *P, int m) {
	LinkList_Polyn p,q;
	*P = (LinkList_Polyn)malloc(sizeof(LNode));
	if (*P == NULL) {
		exit(OVERFLOW);
		return ERROR;
	}
	(*P)->next = NULL;
	p = *P;
	printf("���������ʽ��ϵ������ʽ��ϵ�� ָ�� ϵ�� ָ��...(�ո������ϵ�� ָ��Ϊһ��)\n");
	for (int i = 0; i < m; i++) {
		q = (LinkList_Polyn)malloc(sizeof(LNode));
		if (q == NULL) {
			exit(OVERFLOW);
			return ERROR;
		}
		q->next = NULL;
		scanf("%f%d", &q->data.coef, &q->data.expn);
		p->next = q;
		p = p->next;
	}
	return OK;
}

//����һԪ����ʽ
Status DestroyPolyn(LinkList_Polyn *P) {
	LinkList_Polyn p,q;
	if (P == NULL || *P == NULL) return ERROR;
	p = *P;
	while (p != NULL)
	{
		p = p->next;
		q = p;
		free(q);
	}
	P = NULL;
	return OK;
}

//�ж��Ƿ�Ϊ��
Status EmptyPolyn(LinkList_Polyn P) {
	if (P != NULL && P->next == NULL) return TRUE;
	else return FALSE;
}

//��ӡ���һԪ����ʽ
Status PrintPolyn(LinkList_Polyn P) {
	LinkList_Polyn p; int i = 0; ;
	if (EmptyPolyn(P)) return ERROR;
	p = P->next;
	printf("f(x) =");
	while (p)
	{
		if(i == 0 && p->data.coef > 0)
			printf(" %.2fx^%d", p->data.coef, p->data.expn);
		else
		{
			if (p->data.coef > 0)
				printf(" + %.2fx^%d", p->data.coef, p->data.expn);
			else
				printf(" %.2fx^%d", p->data.coef, p->data.expn);
		}
		p = p->next;
		i++;
	}
	printf("\n");
}

//����һԪ����ʽp�е�����
Status PolynLength(LinkList_Polyn P) {
	LinkList_Polyn p;
	int i = 0;
	if (EmptyPolyn(P)) return ERROR;
	p = P->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int comp(int a, int b) {
	if (a > b) return 1;
	else if (a = b) return 0;
	else return -1;
}

//����ʽ��� Pa = Pa + Pb��������һԪ����ʽPb
Status AddPolyn(LinkList_Polyn *Pa, LinkList_Polyn *Pb) {
	LinkList_Polyn pa, pb, pc, q;
	float sum = 0.0;
	if (EmptyPolyn(*Pa) || EmptyPolyn(*Pb)) return ERROR;
	pa = (*Pa)->next;
	pb = (*Pb)->next;
	pc = pa;
	while (pa && pb)
	{
		switch (comp(pa->data.expn, pb->data.expn))
		{
		//ָ����
		case 1:
			pc = pb->next;
			pc = pb;
			pb = pb->next;
			break;
		//ָ�����
		case 0:
			sum = pa->data.coef + pb->data.coef;
			if (sum == 0.0) {
				q = pa;
				pa = pa->next;
				free(q);
			}
			else
			{
				pa->data.coef = sum;
				pc->next = pa;
				pc = pa;
				pa = pa->next;
			}
			break;
		//ָ��С
		case -1:
			pc = pa->next;
			pc = pa;
			pa = pa->next;
			break;
		}
	}
	pc->next = pa ? pa : pb;
	free(pb);
	*Pb = NULL;
	return OK;
}

//����ʽ��� Pa = Pa - Pb,������һԪ����ʽPb
Status SubtractPolyn(LinkList_Polyn *Pa, LinkList_Polyn *Pb);
//����ʽ��� Pa = Pa * Pb,������һԪ����ʽPb
Status MultiplyPolyn(LinkList_Polyn *Pa, LinkList_Polyn *Pb);

void main_SLink_Polyn() {
	LinkList_Polyn P,Pb;
	CreatPolyn(&P, 3);
	CreatPolyn(&Pb, 3);
	printf("%d", PolynLength(P));
	PrintPolyn(P); PrintPolyn(Pb);
	AddPolyn(&P, &Pb);
	PrintPolyn(P);
}
#include "stdafx.h"
#include "SLink_Polyn.h"
#include<math.h>

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
	printf("���������ʽ����ʽ��ϵ�� ָ��...(�ո������2x^2����Ϊ��2 2)\n");
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

//���
Status ClearPolyn(LinkList_Polyn *P) {
	LinkList_Polyn p, q;
	if (P == NULL || (*P)->next == NULL) return ERROR;
	p = (*P)->next;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	(*P)->next = NULL;
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
	//printf("f(x) =");
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
	else if (a < b) return -1;
	else return 0;
}

//����ʽ��Ӽ� Pa = Pa �� Pb��������һԪ����ʽPb
Status AddorSubtractPolyn(LinkList_Polyn Pa, LinkList_Polyn Pb, char str) {
	LinkList_Polyn pa, pb, pc, q;
	float sum = 0.0;
	if (EmptyPolyn(Pa) || EmptyPolyn(Pb)) return ERROR;
	pa = (Pa)->next;
	pb = (Pb)->next;
	pc = Pa;
	while (pa && pb)
	{
		switch (comp(pa->data.expn, pb->data.expn))
		{
		//ָ����
		case 1:
			pc->next = pb;
			pc = pb;
			pb = pb->next;
			break;
		//ָ�����
		case 0:
			// +��Ϊ����ʽ���
			if(str == '+') sum = pa->data.coef + pb->data.coef;
			// -��Ϊ����ʽ���
			else if(str == '-') sum = pa->data.coef - pb->data.coef;
			else { 
				printf("�����������ֻ�� '+' ���� '-' "); 
				return ERROR;
			}
			//�жϸ������Ƿ�Ϊ0
			if (fabs(sum)< 1e-6) {
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
			/* �ͷ�qb��ָ��Ľ��Ŀռ� */
			q = pb;
			pb = pb->next;
			free(q);
			break;
		//ָ��С
		case -1:
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			break;
		}
	}
	pc->next = pa ? pa : pb;
	free(Pb);
	return OK;
}

//����ʽ��� Pa = Pa * Pb,������һԪ����ʽPb
LinkList_Polyn MultiplyPolyn(LinkList_Polyn Pa, LinkList_Polyn Pb) {
	LinkList_Polyn pa, pb, Pc,pc, q,sump=NULL, newp;
	float sumCoef = 0.0;
	int sumExpn = 0.0, index = 0;
	if (EmptyPolyn(Pa) || EmptyPolyn(Pb)) return ERROR;
	pa = (Pa)->next;
	pb = (Pb)->next;
	while (pb)
	{
		//���·���ռ� ���µ�Pc
		Pc = (LinkList_Polyn)malloc(sizeof(LNode));
		Pc->next = NULL;
		pc = Pc;
		while (pa)
		{
			sumCoef = pa->data.coef * pb->data.coef;//ϵ�����
			sumExpn = pa->data.expn + pb->data.expn;//ָ�����
			if (fabs(sumCoef)> 1e-6) {
				newp = (LinkList_Polyn)malloc(sizeof(LNode));
				newp->next = NULL;
				newp->data.coef = sumCoef;
				newp->data.expn = sumExpn;
				pc->next = newp;
				pc = newp;
			}
			pa = pa->next;
		}
		if (index == 0) {
			//��һ�� ��¼��һ��Pc
			sump = Pc;
		}
		else
		{
			//�����ۼ�
			AddorSubtractPolyn(sump, Pc, '+');
		}
		//pa���¿�ʼ
		pa = (Pa)->next;
		/* �ͷ�qb��ָ��Ľ��Ŀռ� */
		//q = pb;
		//ָ����һ��pb
		pb = pb->next;
		//free(q);
		index++;
	}
	if (EmptyPolyn(sump))
	{
		return ERROR;
	}
	else
	{
		return sump;
	}
}

void main_SLink_Polyn() {
	LinkList_Polyn P,Pb;
	printf("\n--------------��ʼ������f(x)--------------\n f(x) = x + x^2 + x^3\n");
	CreatPolyn(&P, 3);
	printf("\n--------------��ӡ����f(x)--------------\n f(x) =");
	PrintPolyn(P);
	printf("\n����f(x)����Ϊ��%d\n", PolynLength(P));

	printf("\n--------------��ʼ������g(x)--------------\n g(x) = 1 + x + x^2 +x^4\n");
	CreatPolyn(&Pb, 4);
	printf("\n--------------��ӡ����g(x)--------------\n g(x) =");
	PrintPolyn(Pb);
	printf("\n����g(x)����Ϊ��%d\n", PolynLength(Pb));

	printf("\n--------------������� h(x) = f(x) �� g(x) --------------\n");
	printf(" h(x) =");
	PrintPolyn(MultiplyPolyn(P, Pb));

	printf("\n--------------������� h(x) = f(x) + g(x) --------------\n");
	printf(" h(x) =");
	AddorSubtractPolyn(P, Pb,'+');
	PrintPolyn(P);
}
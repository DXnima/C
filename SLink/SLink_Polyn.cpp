#include "stdafx.h"
#include "SLink_Polyn.h"

//输入m项的系数和指数，建立一元多项式链表
Status CreatPolyn(LinkList_Polyn *P, int m) {
	LinkList_Polyn p,q;
	*P = (LinkList_Polyn)malloc(sizeof(LNode));
	if (*P == NULL) {
		exit(OVERFLOW);
		return ERROR;
	}
	(*P)->next = NULL;
	p = *P;
	printf("请输入多项式的系数，格式：系数 指数 系数 指数...(空格隔开，系数 指数为一组)\n");
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

//销毁一元多项式
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

//判断是否为空
Status EmptyPolyn(LinkList_Polyn P) {
	if (P != NULL && P->next == NULL) return TRUE;
	else return FALSE;
}

//打印输出一元多项式
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

//返回一元多项式p中的项数
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

//多项式相加 Pa = Pa + Pb，并销毁一元多项式Pb
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
		//指数大
		case 1:
			pc = pb->next;
			pc = pb;
			pb = pb->next;
			break;
		//指数相等
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
		//指数小
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

//多项式相减 Pa = Pa - Pb,并销毁一元多项式Pb
Status SubtractPolyn(LinkList_Polyn *Pa, LinkList_Polyn *Pb);
//多项式相乘 Pa = Pa * Pb,并销毁一元多项式Pb
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
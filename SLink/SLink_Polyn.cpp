#include "stdafx.h"
#include "SLink_Polyn.h"
#include<math.h>

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
	printf("请输入多项式，格式：系数 指数...(空格隔开，2x^2输入为：2 2)\n");
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

//清空
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
	else if (a < b) return -1;
	else return 0;
}

//多项式相加减 Pa = Pa ± Pb，并销毁一元多项式Pb
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
		//指数大
		case 1:
			pc->next = pb;
			pc = pb;
			pb = pb->next;
			break;
		//指数相等
		case 0:
			// +号为多项式相加
			if(str == '+') sum = pa->data.coef + pb->data.coef;
			// -号为多项式相加
			else if(str == '-') sum = pa->data.coef - pb->data.coef;
			else { 
				printf("运算符号有误，只能 '+' 或者 '-' "); 
				return ERROR;
			}
			//判断浮点数是否为0
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
			/* 释放qb所指向的结点的空间 */
			q = pb;
			pb = pb->next;
			free(q);
			break;
		//指数小
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

//多项式相乘 Pa = Pa * Pb,并销毁一元多项式Pb
LinkList_Polyn MultiplyPolyn(LinkList_Polyn Pa, LinkList_Polyn Pb) {
	LinkList_Polyn pa, pb, Pc,pc, q,sump=NULL, newp;
	float sumCoef = 0.0;
	int sumExpn = 0.0, index = 0;
	if (EmptyPolyn(Pa) || EmptyPolyn(Pb)) return ERROR;
	pa = (Pa)->next;
	pb = (Pb)->next;
	while (pb)
	{
		//重新分配空间 存新的Pc
		Pc = (LinkList_Polyn)malloc(sizeof(LNode));
		Pc->next = NULL;
		pc = Pc;
		while (pa)
		{
			sumCoef = pa->data.coef * pb->data.coef;//系数相乘
			sumExpn = pa->data.expn + pb->data.expn;//指数相加
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
			//第一次 记录上一次Pc
			sump = Pc;
		}
		else
		{
			//进行累加
			AddorSubtractPolyn(sump, Pc, '+');
		}
		//pa重新开始
		pa = (Pa)->next;
		/* 释放qb所指向的结点的空间 */
		//q = pb;
		//指向下一个pb
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
	printf("\n--------------初始化函数f(x)--------------\n f(x) = x + x^2 + x^3\n");
	CreatPolyn(&P, 3);
	printf("\n--------------打印函数f(x)--------------\n f(x) =");
	PrintPolyn(P);
	printf("\n函数f(x)项数为：%d\n", PolynLength(P));

	printf("\n--------------初始化函数g(x)--------------\n g(x) = 1 + x + x^2 +x^4\n");
	CreatPolyn(&Pb, 4);
	printf("\n--------------打印函数g(x)--------------\n g(x) =");
	PrintPolyn(Pb);
	printf("\n函数g(x)项数为：%d\n", PolynLength(Pb));

	printf("\n--------------函数相乘 h(x) = f(x) × g(x) --------------\n");
	printf(" h(x) =");
	PrintPolyn(MultiplyPolyn(P, Pb));

	printf("\n--------------函数相加 h(x) = f(x) + g(x) --------------\n");
	printf(" h(x) =");
	AddorSubtractPolyn(P, Pb,'+');
	PrintPolyn(P);
}
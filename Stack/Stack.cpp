// Stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Stack.h"

//��ʼ�� ������ջ
Status InitStack(SqStack &S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//����ջ
Status DestroyStack(SqStack &S) {
	if (S.base == NULL) {
		return ERROR;
	}
	free((S).base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
	return OK;
}

//���ջ
Status ClearStack(SqStack &S) {
	if (S.base == NULL) {
		return ERROR;
	}
	S.top = S.base;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	else return FALSE;
}

//����ջ�ĳ���
int StackLength(SqStack S) {
	if (S.base == NULL) {
		return 0;
	}
	return (int)(S.top - S.base);
}

//��ȡջ��Ԫ��
Status GetTop(SqStack S, SElemType &e) {
	if (S.base == NULL || S.top == S.base) {
		return 0;
	}
	// ����ı�ջ��Ԫ��
	e = *(S.top - 1);
	return OK;
}

//��ջ
Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
		//ջ��׷�Ӵ洢�ռ�
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

//��ջ
Status Pop(SqStack &S, SElemType &e) {
	if (S.base == S.top) return ERROR;
	e = *--S.top;
	return OK;
}

//����ջ����Ԫ��
Status StackTraverse(SqStack S, void(*visit)(SElemType)) {
	SElemType* p = S.base;
	if (S.base == NULL) {
		return ERROR;
	}
	while (p < S.top) {
		visit(*p++);
	}
	printf("\n");
	return OK;
}

//ʮ����ת����������
void Conversion() {
	SqStack S;
	SElemType e;
	int N=0, n=0;
	InitStack(S);
	printf("������Ǹ�ʮ��������ת�����ƣ��磺100 2\n");
	scanf("%d%d", &N, &n);
	printf("%d ��%d�������ǣ�\n", N, n);
	while (N)
	{
		Push(S, N%n);
		N = N / n;
	}
	while (!StackEmpty(S))
	{
		Pop(S, e);
		printf(" %d", e);
	}
	printf("\n");
	//����S
	DestroyStack(S);
}

void main_Stack() {
	SqStack S;
	SElemType e;
	printf("----------��ʼ��ջ----------\n");
	InitStack(S);
	printf("----------��ջ----------\n");
	for (int i = 1; i <= 10; i++)
	{
		Push(S,i);
	}
	printf("----------��ӡջ----------\n");
	StackTraverse(S,PrintElem);
	printf("----------��ȡջ��----------\n");
	GetTop(S, e);
	printf("ջ�� e = %d\n",e);
	printf("----------��ջ----------\n");
	Pop(S,e);
	printf("��ջ e = %d\n", e);
	if(DestroyStack(S)) printf("----------���ٳɹ�----------\n");
	else printf("----------����ʧ��----------\n");
	printf("----------����ʮ����ת��������----------\n");
	Conversion();
}


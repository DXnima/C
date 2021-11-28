// Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Stack.h"

//初始化 创建空栈
Status InitStack(SqStack &S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//销毁栈
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

//清空栈
Status ClearStack(SqStack &S) {
	if (S.base == NULL) {
		return ERROR;
	}
	S.top = S.base;
	return OK;
}

//判断栈是否为空
Status StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	else return FALSE;
}

//返回栈的长度
int StackLength(SqStack S) {
	if (S.base == NULL) {
		return 0;
	}
	return (int)(S.top - S.base);
}

//获取栈顶元素
Status GetTop(SqStack S, SElemType &e) {
	if (S.base == NULL || S.top == S.base) {
		return ERROR;
	}
	// 不会改变栈中元素
	e = *(S.top - 1);
	return OK;
}

//入栈
Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
		//栈满追加存储空间
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

//出栈
Status Pop(SqStack &S, SElemType &e) {
	if (S.base == S.top) return ERROR;
	e = *--S.top;
	return OK;
}

//遍历栈所有元素
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

//十进制转换其他进制
void Conversion() {
	SqStack S;
	SElemType e;
	int N=0, n=0;
	InitStack(S);
	printf("请输入非负十进制数和转换进制，如：100 2\n");
	scanf("%d%d", &N, &n);
	printf("%d 的%d进制数是：\n", N, n);
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
	//销毁S
	DestroyStack(S);
}

void PrintElemByChar(SElemType e) {
	printf("%c", e);
}

//括号匹配检验
void Bracket() {
	SqStack S;
	SElemType e;
	int a = '\n';
	InitStack(S);
	printf("输入字符(#结束):\n");
	while (a != '#')
	{
		a = getchar();
		if (a == '#' || a == '\n') continue;
		switch (a)
		{
		case 93://]
			GetTop(S, e);
			if (e == 91) Pop(S,e);
			else Push(S, a);
			break;
		case 62://>
			GetTop(S, e);
			if (e == 60) Pop(S, e);
			else Push(S, a);
			break;
		case 41://)
			GetTop(S, e);
			if (e == 40) Pop(S, e);
			else Push(S, a);
			break;
		case 125://}
			GetTop(S, e);
			if (e == 123) Pop(S, e);
			else Push(S, a);
			break;
		default:
			Push(S, a);
			break;
		}
	}
	if (StackEmpty(S)) printf("括号验证正确！");
	else 
	{ 
		printf("括号验证错误,错误位置:\n");
		StackTraverse(S, PrintElemByChar);
	}
}

//行编辑程序
void LineEdit() {
	SqStack S;
	SElemType e;
	int ch = getchar();
	InitStack(S);
	while (ch != '\0')
	{
		while (ch != '\0' && ch != '\n')
		{
			switch (ch) {
			case '@':ClearStack(S); break;
			case '#':Pop(S, ch); break;
			default:Push(S, ch); break;
			}
			ch = getchar();
		}
		// 清空之前输出当前栈的内容
		StackTraverse(S, PrintElemByChar);
		ClearStack(S);
		if (ch != '\0') ch = getchar();
	}
	DestroyStack(S);
}

void main_Stack() {
	SqStack S;
	SElemType e;
	printf("----------初始化栈----------\n");
	InitStack(S);
	printf("----------入栈----------\n");
	for (int i = 1; i <= 10; i++)
	{
		Push(S,i);
	}
	printf("----------打印栈----------\n");
	StackTraverse(S,PrintElem);
	printf("----------获取栈顶----------\n");
	GetTop(S, e);
	printf("栈顶 e = %d\n",e);
	printf("----------出栈----------\n");
	Pop(S,e);
	printf("出栈 e = %d\n", e);
	if(DestroyStack(S)) printf("----------销毁成功----------\n");
	else printf("----------销毁失败----------\n");
	printf("----------测试十进制转其他进制----------\n");
	//Conversion();
	//Bracket();
	LineEdit();
}


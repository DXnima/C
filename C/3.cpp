// 3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main3()
{
	int i = 3, j = 3;
	printf("i++:%d\n", i++);
	printf("i++:%d\n", i++);
	printf("++j:%d\n", ++j);
	printf("++j:%d\n", ++j);
	printf("377:%c\n", 377);
	printf("377:%2.7f\n", 123456789.1234567);
	double a;
	a = 10000 / 3.0;
	printf("a = %f\n", a);
	printf("e : %e\n", a);
	printf("g : %g\n", a);
	int b;
	b = -1;
	printf("%d\t%o\t%x\n", b << 2);
	printf("%d\t%d\t%d\t%d\n", 2 << 2, 8 >> 2, 9 & 5, 3 | 2);
	char c;
	for (; (c = getchar()) != '\n';)
		printf("%c", c);
	return 0;
}


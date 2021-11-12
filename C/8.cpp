#include "stdafx.h"

void test_point() {
	int a = 100, b = 10, c = 1;
	int *pa, *pb;
	pa = &a;
	pb = &b;
	printf("a,b:%d\t%d\n", a, b);
	printf("address a,b:%d\t%d\t%d\n", &a, &b, &c);
	printf("pa,pb:%d\t%d\n", pa, pb);
	*pa = 99;
	*pb = b;
	printf("pa,pb:%d\t%d\n", pa, pb);
	printf("*pa,*pb:%d\t%d\n", *pa, *pb);
}

void test_point2() {
	int a = 100;
	printf("&a=%d\n", &a);
	int *p1 = &a;
	printf("&*p1=%d, &p1=%d\n", &*p1, &p1);
	int **p2 = &p1;
	printf("&**p2=%d, &*p2=%d, &p2=%d\n", &**p2, &*p2, &p2);
	int ***p3 = &p2;
	printf("&***p3=%d, &**p3=%d, &*p3=%d, &p3=%d\n", &***p3, &**p3, &*p3, &p3);
	printf("a=%d, *p1=%d, **p2=%d, ***p3=%d\n", a, *p1, **p2, ***p3);
}

void swap(int *a, int *b) {
	int t;
	t = *a;
	printf("t=%d\n", &t);
	*a = *b;
	printf("*a=%d\n", a);
	*b = t;
	printf("*b=%d\n", b);
}

void swap1(int a, int b) {
	int t;
	t = a;
	printf("t=%d\n", &t);
	a = b;
	printf("*a=%d\n", &a);
	b = t;
	printf("*b=%d\n", &b);
}

//一维数组与指针
void arry() {
	int a[5] = { 1,2,3,4,5 };
	int *p = a;
	printf("%d\t%d", *(p + 1), *(a + 1));
}

//二维字符串与指针
void string() {
	char * name[] = { "ABC","DEF","GHI","JKL","MNP" };
	char **p;
	for (int i = 0; i < 5; i++) {
		p = name + i;
		printf("name+%d=%d\n", i, name + i);
		printf("p=%d,*p=%d,**p=%d\n", p, *p, **p);
		printf("%s,%s,%s\n", p, *p, **p);
	}
}

//指针数组
void arr_point() {
	int a[5] = { 1,2,3,4,5 };
	int * num[5];

	for (int i = 0; i < 5; i++) {
		num[i] = &a[i];
		printf("%d\t%d\n", num[i], *num[i]);
	}
	printf("%d", num);
}



int main8()
{
	//test_point();
	//arry();
	//string();
	return 0;
}
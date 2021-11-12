// 3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

//冒泡排序
void sort_mp(int a[], int n) {
	int i, j, t, c;
	printf("请输入降序或升序排序(0--降序|1--升序)：");
	scanf("%d", &c);
	printf("请输入数组%d个数：\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("\n");
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (!c) {
				if (a[j] > a[j + 1]) {
					t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
			else
			{
				if (a[j] < a[j + 1]) {
					t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}

		}
	}
	printf("排序结果为：\n");
	for (i = 0; i < 10; i++) {
		printf("%4d", a[i]);
	}
	printf("\n");
}

//选择排序
void sort_select(int a[], int n) {
	int i, j, k, t;
	for (i = 0; i < n; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[k]) k = j;
			t = a[k];
			a[k] = a[i];
			a[i] = t;
		}
	}
}

//测试字符数组
void strtest() {
	char c[13];
	//打印没有初始化字符串
	printf("%s\n", c);
	scanf("%s", c);
	//打印地址
	printf("%o\n", &c[0]);
	char str1[15] = "Peoples abc";
	char str2[] = "china abcd";
	//比较字符串
	printf("%d\t %d\t %d\n", strcmp(str1, str2), strcmp("abcd", "abcd"), strcmp("cat", "CAT"));
	//打印地址
	printf("%o\n", str1);
	//字符串连接打印地址
	printf("%o\n", strcat(str1, str2));
	//字符串连接
	printf("%s\n", strcat(str1, str2));
}

//计算字符串中 单词个数
void wordcount() {
	char a[50], c;
	int num = 0, word = 0;
	printf("请输入字符串：\n");
	gets_s(a, 50);
	for (int i = 0; (c = a[i]) != '\0'; i++) {
		if (c == ' ') word = 0;
		else if (word == 0)
		{
			word = 1;
			num++;
		}
	}
	printf("单词个数为：%d\n", num);
}

int main6()
{
	int a[10], n = 10;
	//sort(a,n);
	wordcount();
	return 0;
}


// 3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>

//ð������
void sort_mp(int a[], int n) {
	int i, j, t, c;
	printf("�����뽵�����������(0--����|1--����)��");
	scanf("%d", &c);
	printf("����������%d������\n", n);
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
	printf("������Ϊ��\n");
	for (i = 0; i < 10; i++) {
		printf("%4d", a[i]);
	}
	printf("\n");
}

//ѡ������
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

//�����ַ�����
void strtest() {
	char c[13];
	//��ӡû�г�ʼ���ַ���
	printf("%s\n", c);
	scanf("%s", c);
	//��ӡ��ַ
	printf("%o\n", &c[0]);
	char str1[15] = "Peoples abc";
	char str2[] = "china abcd";
	//�Ƚ��ַ���
	printf("%d\t %d\t %d\n", strcmp(str1, str2), strcmp("abcd", "abcd"), strcmp("cat", "CAT"));
	//��ӡ��ַ
	printf("%o\n", str1);
	//�ַ������Ӵ�ӡ��ַ
	printf("%o\n", strcat(str1, str2));
	//�ַ�������
	printf("%s\n", strcat(str1, str2));
}

//�����ַ����� ���ʸ���
void wordcount() {
	char a[50], c;
	int num = 0, word = 0;
	printf("�������ַ�����\n");
	gets_s(a, 50);
	for (int i = 0; (c = a[i]) != '\0'; i++) {
		if (c == ' ') word = 0;
		else if (word == 0)
		{
			word = 1;
			num++;
		}
	}
	printf("���ʸ���Ϊ��%d\n", num);
}

int main6()
{
	int a[10], n = 10;
	//sort(a,n);
	wordcount();
	return 0;
}


#include "stdafx.h"

//�ļ���д�ַ�
void file_rwc() {
	FILE *fp;
	char filename[10],ch;
	printf("�������ļ�����");
	scanf("%s", filename);
	fp = fopen(filename,"w");
	if (fp == NULL) {
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	printf("���������ݣ�#��������\n");
	ch = getchar();
	while (ch!='#')
	{
		fputc(ch, fp);
		ch = getchar();
	}
	fclose(fp);
	printf("�ļ�д��ɹ���\n");
}

//�ļ����ݸ���
void cp_file() {
	FILE *in, *out;
	char ch,infile[10] = "1.txt", outfile[10]="2.txt";
	in = fopen(infile, "r");
	out = fopen(outfile, "w");
	if (in == NULL || out == NULL) {
		printf("�޷��򿪴��ļ���\n");
		exit(0);
	}
	while (!feof(in))
	{
		ch = fgetc(in);
		fputc(ch, out);
		putchar(ch);
	}
	fclose(in);
	fclose(out);
	printf("\n�ļ����Ƴɹ���\n");
}

//�ļ�д�ַ���
void file_ws() {
	FILE *fp;
	char str[15] = "DXnima\nDXnima\n";
	fp = fopen("1.txt", "w");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	fputs(str, fp);
	fclose(fp);
	printf("\n�ļ�д��ɹ���\n");
}

//�ļ����ַ���
void file_rs() {
	FILE *fp;
	char str[15];
	fp = fopen("1.txt", "r");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	printf("�ļ�����Ϊ��\n");
	while (fgets(str, 30, fp)!=NULL) {
		printf("%s", str);
	}
	fclose(fp);
	
}

//��ʽ����д
void file_wr() {
	FILE *fp;
	char str[15];
	fp = fopen("1.txt", "r");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	fscanf(fp, "%s", str);
	printf("%s\n",str);
}

//�������ļ���д
#define SIZE 2

struct Student_type {
	char name[10];
	int age;
}stud[SIZE];

void file_wb() {
	FILE *fp;
	int i;
	printf("����ѧ����Ϣ��\n");
	for (i = 0; i < SIZE; i++)
		scanf("%s%d", stud[i].name, &stud[i].age);
	if ((fp = fopen("1b.txt", "wb")) == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	for (i = 0; i < SIZE; i++) {
		if (fwrite(&stud[i], sizeof(Student_type), 1, fp) != 1)
			printf("д����󣡡�n");
	}
	fclose(fp);
	printf("�ļ�д��ɹ�\n");
}

void file_rb() {
	FILE *fp;
	int i;
	if ((fp = fopen("1b.txt", "rb")) == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	printf("\n�ļ��������£�\n");
	for (i = 0; i < SIZE; i++) {
		fread(&stud[i], sizeof(Student_type), 1, fp);
		printf("%s %d\n", stud[i].name, stud[i].age);
	}
	fclose(fp);
}

//�����ȡ�ļ�����

int main10() {
	//file_rwc();
	//file_ws();
	//file_rs();
	//file_wr();
	//file_wb();
	//file_rb();
	return 0;
}
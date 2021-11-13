#include "stdafx.h"

//文件读写字符
void file_rwc() {
	FILE *fp;
	char filename[10],ch;
	printf("请输入文件名：");
	scanf("%s", filename);
	fp = fopen(filename,"w");
	if (fp == NULL) {
		printf("无法打开此文件！\n");
		exit(0);
	}
	printf("请输入内容（#结束）：\n");
	ch = getchar();
	while (ch!='#')
	{
		fputc(ch, fp);
		ch = getchar();
	}
	fclose(fp);
	printf("文件写入成功！\n");
}

//文件内容复制
void cp_file() {
	FILE *in, *out;
	char ch,infile[10] = "1.txt", outfile[10]="2.txt";
	in = fopen(infile, "r");
	out = fopen(outfile, "w");
	if (in == NULL || out == NULL) {
		printf("无法打开此文件！\n");
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
	printf("\n文件复制成功！\n");
}

//文件写字符串
void file_ws() {
	FILE *fp;
	char str[15] = "DXnima\nDXnima\n";
	fp = fopen("1.txt", "w");
	if (fp == NULL) {
		printf("文件打开失败！");
		exit(0);
	}
	fputs(str, fp);
	fclose(fp);
	printf("\n文件写入成功！\n");
}

//文件读字符串
void file_rs() {
	FILE *fp;
	char str[15];
	fp = fopen("1.txt", "r");
	if (fp == NULL) {
		printf("文件打开失败！");
		exit(0);
	}
	printf("文件内容为：\n");
	while (fgets(str, 30, fp)!=NULL) {
		printf("%s", str);
	}
	fclose(fp);
	
}

//格式化读写
void file_wr() {
	FILE *fp;
	char str[15];
	fp = fopen("1.txt", "r");
	if (fp == NULL) {
		printf("文件打开失败！");
		exit(0);
	}
	fscanf(fp, "%s", str);
	printf("%s\n",str);
}

//二进制文件读写
#define SIZE 2

struct Student_type {
	char name[10];
	int age;
}stud[SIZE];

void file_wb() {
	FILE *fp;
	int i;
	printf("输入学生信息：\n");
	for (i = 0; i < SIZE; i++)
		scanf("%s%d", stud[i].name, &stud[i].age);
	if ((fp = fopen("1b.txt", "wb")) == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}
	for (i = 0; i < SIZE; i++) {
		if (fwrite(&stud[i], sizeof(Student_type), 1, fp) != 1)
			printf("写入错误！、n");
	}
	fclose(fp);
	printf("文件写入成功\n");
}

void file_rb() {
	FILE *fp;
	int i;
	if ((fp = fopen("1b.txt", "rb")) == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}
	printf("\n文件内容如下：\n");
	for (i = 0; i < SIZE; i++) {
		fread(&stud[i], sizeof(Student_type), 1, fp);
		printf("%s %d\n", stud[i].name, stud[i].age);
	}
	fclose(fp);
}

//随机读取文件数据

int main10() {
	//file_rwc();
	//file_ws();
	//file_rs();
	//file_wr();
	//file_wb();
	//file_rb();
	return 0;
}
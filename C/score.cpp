#include "stdafx.h"
#include "score.h"


void creat_data() {
	FILE *fp;
	if ((fp = fopen("student.txt", "w")) == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}
	fputs("ѧ��    ����    ����1   ����2\n",fp);
	for (int i = 0; i < N; i++) {
		fprintf(fp, "%s %s %d %d\n", "10001", "DXnima", rand() % (100 - 50 + 1) + 50, rand() % (100 - 50 + 1) + 50);
	}
	fclose(fp);
}


//��ȡ�ļ�����ӡѧ����Ϣ
void file_print() {
	FILE *fp;
	char str[50];
	int sums1 = 0, sums2 = 0;
	float avgs1, avgs2;
	if ((fp = fopen("student.txt","r")) == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}
	fgets(str,50,fp);
	printf("%s", str);
	for (int i = 0; i < N; i++) {
		fscanf(fp, "%s%s%d%d", &student[i].num, &student[i].name, &student[i].score1, &student[i].score2);
		student[i].sumscore = student[i].score1 + student[i].score2;
		sums1 += student[i].score1;
		sums2 += student[i].score2;
		printf("%s %s %d %d\n", student[i].num, student[i].name, student[i].score1, student[i].score2);
	}
	fclose(fp);
	avgs1 = sums1 / N;
	avgs2 = sums2 / N;
}

//����ƽ����
float avg(Student *s) { 
	
	return 0.0; 
}

//���㷽��
float var(Student *s) { return 0.0; }

//����
void sort() { 
	int i, j, k;
	Student p;
	for (i = 0; i < N; i++)
	{
		k = i;
		for (j = i + 1; j < N; j++) {
			if (student[j].sumscore < student[k].sumscore) k = j;
			if (k != i) {
				p = student[i];
				student[i] = student[k];
				student[k] = p;
			}
		}
	}
	printf("�����\nѧ��    ����    ����1   ����2  �ܷ���  ����\n");
	for (i = 0; i < N; i++) {
		student[i].rank = i+1;
		printf("%s %s %d %d %.2f %d\n", student[i].num, student[i].name, student[i].score1, student[i].score2,student[i].sumscore,student[i].rank);
	}
}

//��ӡ��������
void bad(Student *s) {}

int score() {
	//creat_data();
	file_print();
	sort();
	return 0;
}
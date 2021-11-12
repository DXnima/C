#include "stdafx.h"

//结构体类型
struct Student {
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
};

void init_struct() {
	Student s = { 10101,"Lilin",'M',18,98.00,"123 Beijing Road" };
	printf("%s\t%d\n",s.name, &s.name);
	printf("%s\t%d\n", s.name, &s.name);
	Student s1 = { 10101 };
	strcpy(s1.name, "DXnima");
	s1.age = 18;
	printf("%s\t%d\n", s1.score, &s1.name);
}

//结构体数组
struct Person {
	char name[20];
	int count;
}leader[2] = {"Li",10,"Sun",20};


//结构体指针
void struct_point() {
	Person lea = { "Li",10 };
	Person *p = &lea;
	printf("%s\t%d\n", p->name, p->count);
	printf("%s\t%d\n", (*p).name, (*p).count);
}

//结构体数组的指针
void struct_point_arry() {
	Person *p;
	for (p = leader; p < leader+2; p++) {
		printf("%s\t,%d\n", p->name, p->count);
	}
}

int main9() {
	//init_struct();
	//struct_point();
	struct_point_arry();
	return 0;
}
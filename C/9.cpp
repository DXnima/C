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

//静态链表
struct Student_Link {
	int num;
	float score;
	struct Student_Link *next;
};
//静态链表
void init_link() {
	Student_Link a, b, c, *head, *p;
	a.num = 10101; a.score = 89.5;
	b.num = 10103; b.score = 90;
	c.num = 10107; c.score = 85;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	p = head;
	do {
		printf("%p %d %f %p\n", p,p->num, p->score, p->next);
		p = p->next;
	} while (p!=NULL);
}

//动态链表
#define LEN sizeof(struct Student_Link)

Student_Link * creat_link() {
	Student_Link * head,*p1,*p2;
	int n = 0;
	p1 = p2 = (Student_Link *)malloc(LEN);
	scanf("%d,%f", &p1->num, &p1->score);
	head = NULL;
	while (p1->num != 0)
	{
		n++;
		if (n == 1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (Student_Link *)malloc(LEN);
		scanf("%d,%f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return head;
	
}

//链表输出
void print_link(Student_Link * head) {
	while (head != NULL) {
		printf("%ld,%5.1f\n", head->num, head->score);
		head = head->next;
	}
}

//共用体
union Data {
	int i;
	char c;
	float f;
};

//枚举
enum Date {
	year,
	month,
	day
};

int main9() {
	//init_struct();
	//struct_point();
	//struct_point_arry();
	//init_link();
	//print_link(creat_link());
	printf("%d", Date(day));
	return 0;
}
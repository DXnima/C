#include "stdafx.h"
#include "score.h"

//������ĳ�ʼ��
Status  InitList_L(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));   //������ռ� 
	if (L == NULL)                       //�ж��Ƿ����㹻���ڴ�ռ� 
		printf("�����ڴ�ռ�ʧ��\n");
	L->next = NULL;                  //��next����ΪNULL,��ʼ����Ϊ0�ĵ����� 
	return OK;
}

void readFile(LinkList &L)          //��ȡ�ļ���Ϣ
{
	LinkList q, p;
	FILE *fp;
	p = L;
	q = (LNode*)malloc(sizeof(LNode));
	char name[20] = "ͨѶ¼.txt";
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("error\n");
		exit(0);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (fscanf(fp, "%s%s%s%s%s\n", q->data.num, q->data.name, q->data.sex, q->data.hostel, q->data.telephone) != EOF)
	{
		q->next = NULL;
		p->next = q;
		p = q;
		q = (LNode*)malloc(sizeof(LNode));
	}
	printf("                             �ļ���ȡ�ɹ���       \n");
	fclose(fp);
}

void Find_Name(LinkList &L) //��������ѯ    
{
	LinkList q, p;
	q = L->next;
	printf("����Ҫ��ѯ��������\n");
	p = (LNode*)malloc(sizeof(LNode));
	scanf("%s", p->data.name);
	while (q != NULL&&strcmp(q->data.name, p->data.name) != 0)
	{
		q = q->next;
	}
	if (q == NULL)
	{
		printf("ͨѶ¼��û�����������\n");
	}
	else
	{
		printf("�Ѿ��ҵ�����ϵ��!\n");
		printf("   ѧ��       ����      �Ա�         ����            �绰���� \n");
		printf("%s    %s\t %s\t     %s          %s\n", q->data.num, q->data.name, q->data.sex, q->data.hostel, q->data.telephone);
	}
}

void Find_Num(LinkList &L) //��ѧ�Ų�ѯ    
{
	LinkList q, p;
	q = L->next;
	printf("����Ҫ��ѯ�ı�ţ�\n");
	p = (LNode*)malloc(sizeof(LNode));
	scanf("%s", p->data.num);
	while (q != NULL&&strcmp(q->data.num, p->data.num) != 0)
	{
		q = q->next;
	}
	if (q == NULL)
	{
		printf("ͨѶ¼��û�������ţ�\n");
	}
	else
	{
		printf("�Ѿ��ҵ�����ϵ��!\n");
		printf("   ѧ��       ����      �Ա�         ����            �绰���� \n");
		printf("%s    %s\t %s\t     %s          %s\n", q->data.num, q->data.name, q->data.sex, q->data.hostel, q->data.telephone);
	}
}


Status  CreateFromTail(LinkList &L)     //����β�巨��β������Ԫ��
{
	LinkList r, s;
	r = L;   //rָ��ʼ�ն�ָ̬������ĵ�ǰ��β
	while (r->next)
	{//β�巨��ֱ�Ӱ�ָ����λ��β��  
		r = r->next;
	}
	s = (LinkList)malloc(sizeof(LNode));
	printf("��β���������ϵ����ϢΪ��\n");
	printf("   ѧ��    ����   �Ա�  ����  �绰���� \n");
	scanf("%s%s%s%s%s", s->data.num, s->data.name, s->data.sex, s->data.hostel, s->data.telephone);
	s->next = NULL;
	r->next = s;
	return OK;
}

//��ʼ���������Ա�L�Ѿ�����
//�ڵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��
Status ListInsert_L(LinkList &L)
{
	LinkList s, p = L;
	int  j = 0, i;
	printf("����Ҫ�����λ�ã�");
	scanf("%d", &i);
	while (p&&j < i)
	{  // Ѱ�ҵ�i�����
		p = p->next;
		++j;
	}
	if (!p || j > i) { printf("----�޴�λ�����ʧ��-----\n"); return ERROR; }      // iС��1���ߴ��ڱ�
	s = (LinkList)malloc(sizeof(LNode));  // �����½��
	printf("�������ϵ����ϢΪ��\n");
	printf("   ѧ��    ����   �Ա�  ����  �绰���� \n");
	scanf("%s%s%s%s%s", s->data.num, s->data.name, s->data.sex, s->data.hostel, s->data.telephone);
	s->next = p->next;      // ����L��
	p->next = s;
	return OK;
} // LinstInsert_L


Status Fund_LName(LinkList &L)  //Ѱ�Ҹ�������λ��
{
	LinkList s, p = L->next;
	int  i = 0;
	s = (LNode*)malloc(sizeof(LNode));
	scanf("%s", s->data.name);
	while (p != NULL&&strcmp(p->data.name, s->data.name) != 0)
	{
		p = p->next;
		++i;
	}
	return i + 1;
}

//�ڵ������Ա�L������Ԫ��֮ǰ����Ԫ��
Status ListInsert_LName(LinkList &L)
{
	LinkList s, s1, q = L, p = L->next;
	printf("����Ҫ��˭������֮ǰ�����Ϣ��");
	int j = 0, i = 0;
	s1 = (LNode*)malloc(sizeof(LNode));
	scanf("%s", s1->data.name);
	while (p != NULL&&strcmp(p->data.name, s1->data.name) != 0)
	{
		p = p->next;
		++i;
	}
	if (p == NULL) { printf("----���޴������ʧ��-----\n"); return ERROR; }      // ���û���ҵ�
	while (q&&j < i)
	{  // Ѱ�ҵ�i-1�����
		q = q->next;
		++j;
	}

	s = (LinkList)malloc(sizeof(LNode));  // �����½��
	printf("�������ϵ����ϢΪ��\n");
	printf("   ѧ��    ����   �Ա�  ����  �绰���� \n");
	scanf("%s%s%s%s%s", s->data.num, s->data.name, s->data.sex, s->data.hostel, s->data.telephone);
	s->next = q->next;      // ����L��
	q->next = s;
	return OK;
}

//��ʼ���������Ա�L�Ѿ�����
//ɾ����i��Ԫ��
Status ListDelete_L(LinkList &L)
{
	LinkList p = L, q;
	int  j = 0, i;
	printf("����Ҫɾ����λ�ã�");
	scanf("%d", &i);
	while (p->next && j < i)
	{  // Ѱ�ҵ�i����㣬����pָ����ǰ��
		p = p->next;    ++j;
	}
	if (!(p->next) || j > i) { printf("----���޴���ɾ��ʧ��-----\n"); return ERROR; }  // ɾ��λ�ò�����
	q = p->next;
	p->next = q->next;           // ɾ�����ͷŽ��  
	free(q);
	printf("----ɾ���ɹ�-----\n");
	return OK;
} // ListDelete_L

Status ListDelete_LName(LinkList &L)   //ɾ������Ϊ��XXX����ѧ����¼
{
	LinkList p = L, q;
	printf("����Ҫɾ����ѧ����������");
	int  j = 0, i = Fund_LName(L);
	while (p->next && j < i - 1)
	{  // Ѱ�ҵ�i����㣬����pָ����ǰ��
		p = p->next;    ++j;
	}
	if (!(p->next) || j > i - 1) { printf("----���޴���ɾ��ʧ��-----\n"); return ERROR; }  // ɾ��λ�ò�����
	q = p->next;
	p->next = q->next;           // ɾ�����ͷŽ��  
	free(q);
	printf("----ɾ���ɹ�-----\n");
	return OK;
}

//��ʼ���������Ա�L�Ѿ�����
//��ӡ������Ԫ��
void PrintElem(LinkList L)
{
	LinkList p = L->next;
	printf("��ǰ����ϢΪ��\n");
	while (p != NULL)
	{
		printf("%s    %s\t %s\t     %s          %s\n", p->data.num, p->data.name, p->data.sex, p->data.hostel, p->data.telephone);
		p = p->next;
	}
	printf("\n");
}

void saveFile(LinkList &L)  //����ͨѶ¼���ļ�  
{
	FILE*fp;
	LinkList p;
	p = L;
	if ((fp = fopen("ͨѶ¼.txt", "wt")) == NULL)   exit(0);   // "wt"��ʽ���ļ�ʱ�����Դ�ļ��������ݣ�׷��            
	if (p == NULL || p->next == NULL) //����Ϊ��    
		printf("���Ĳ���������ȷ������ͨѶ¼��Ϊ�գ�\n");
	else
	{
		p = p->next;
		while (p != NULL)
		{
			fprintf(fp, "%s    %s\t %s\t     %s          %s", p->data.num, p->data.name, p->data.sex, p->data.hostel, p->data.telephone);
			fprintf(fp, "\n");
			p = p->next;
		}
		fclose(fp);
		printf("ͨѶ¼�ѱ��棡\n");
	}
}

void List_free(LinkList L)  //��������
{
	LinkList p;
	while (L != NULL)
	{
		p = L;
		L = L->next;
		free(p);
	}
}

int score()
{
	int n = 1;
	LinkList L;
	InitList_L(L);
	readFile(L);
	while (n != 0)
	{
		printf("*****************************���ڵ�����İ༶ͨѶ¼*****************************\n");
		printf("           1:ͨ������������ϵ��        |      2:ͨ��ѧ�Ų�����ϵ��\n\n");
		printf("           3:��������ĳѧ����Ϣ      |      4:������ϵ�˼���ĳ����¼֮ǰ\n\n");
		printf("           5:������ϵ�˼�ĳ��ѧ��֮ǰ  |      6:ɾ����i����¼\n\n");
		printf("           7:������ɾ��                |      8:��ʾ���\n\n");
		printf("                             0:�˳����򲢱���              \n\n");
		printf("*********************************************************************************\n");
		printf("��ѡ�����<1-8>,�˳�<0>:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:Find_Name(L);
			system("pause");//�������������    
			system("cls");//����
			break;
		case 2:Find_Num(L);
			system("pause");//�������������    
			system("cls");//����
			break;
		case 3:CreateFromTail(L);
			system("pause");//�������������    
			system("cls");//����
			break;
		case 4:ListInsert_L(L);
			system("pause");//�������������    
			system("cls");//����
			break;
		case 5:ListInsert_LName(L);
			system("pause");//�������������    
			system("cls");//����
			break;
		case 6:ListDelete_L(L);
			system("pause");//�������������    
			system("cls");//����
			break;
		case 7:ListDelete_LName(L);
			system("pause");//�������������    
			system("cls");//����
			break;
		case 8:PrintElem(L);
			system("pause");//�������������    
			system("cls");//����
			break;
		case 0:saveFile(L); List_free(L);
			system("cls");//����
			break;
		}
	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK     1
#define ERROR  0
#define MIX    100
typedef int Status;
//��㶨��
typedef struct telebook    //ͨѶ¼���������  
{
	char num[MIX];         //ѧ��
	char name[MIX];        //����
	char sex[MIX];         //�Ա�
	char hostel[MIX];      //����
	char telephone[MIX];   //�绰����    
}telebook;

typedef struct LNode      //������
{
	telebook data; //���������   
	struct LNode *next;  //���ָ����  
}LNode, *LinkList;

//��ȡ�ı���Ϣ
void readFile(LinkList &L);

//������ĳ�ʼ�� 
Status  InitList_L(LinkList &L);

void Find_Name(LinkList &L); //��������ѯ

void Find_Num(LinkList &L); //��������ѯ

Status  CreateFromTail(LinkList &L);     //����β�巨��β������Ԫ��

										 //��ʼ���������Ա�L�Ѿ�����
										 //�ڵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��
Status ListInsert_L(LinkList &L);

//�ڵ������Ա�L������Ԫ��֮ǰ����Ԫ��
Status ListInsert_LName(LinkList &L);
Status Fund_LName(LinkList &L);  //Ѱ�Ҹ�������λ��

								 //��ʼ���������Ա�L�Ѿ�����
								 //ɾ����i��Ԫ��
Status ListDelete_L(LinkList &L);

Status ListDelete_LName(LinkList &L);   //ɾ������Ϊ��XXX����ѧ����¼

void saveFile(LinkList &L);  //����ͨѶ¼���ļ�

							 //��ʼ���������Ա�L�Ѿ�����
							 //��ӡ������Ԫ��
void PrintElem(LinkList L);

void List_free(LinkList L);  //��������

int score();
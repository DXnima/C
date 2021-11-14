typedef struct LNode {
	ElemType data;
	LNode *next;
}*Link;

// ָ���������ָ��
typedef LNode* LinkList;

//��ʼ��
Status InitLink(LinkList* L);

//����(�ṹ)
Status DestroyLink(LinkList* L);

// �ÿ�(����)
Status ClearLink(LinkList L);

/*
* �п�
* �ж��������Ƿ������Ч���ݡ�
*/
Status LinkEmpty(LinkList L);

/*
* ����
* ���������������ЧԪ�ص�������
*/
int LinkLength(LinkList L);

/*
* ȡֵ
* ��ȡ�����е�i��Ԫ�أ�����洢��e�С�
*/
Status GetElemLink(LinkList L, int i, ElemType* e);

/*
* ����
* �����������׸���e����Compare��ϵ��Ԫ��λ��
*/
int LocateElemLink(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
* ǰ��
*/
Status PriorElemLink(LinkList L, ElemType cur_e, ElemType* pre_e);

/*
* ���
*/
Status NextElemLink(LinkList L, ElemType cur_e, ElemType* next_e);

/*
* ����
* �������i��λ���ϲ���e������ɹ��򷵻�OK�����򷵻�ERROR��
*/
Status LinkInsert(LinkList L, int i, ElemType e);

/*
* ɾ��
* ɾ�������i��λ���ϵ�Ԫ�أ�������ɾ��Ԫ�ش洢��e�С�
*/
Status LinkDelete(LinkList L, int i, ElemType* e);

/*
* ����
* ��visit������������L
*/
void LinkTraverse(LinkList L, void(Visit)(ElemType));

/*
* ͷ�巨��������
*/
Status CreateLink_Head(LinkList* L, int n);

/*
* β�巨��������
*/
Status CreateLink_Tail(LinkList* L, int n);
typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode, *LinkList;

//��ʼ��
Status InitLinkList(LinkList *L);
//����
Status DestroyLinkList(LinkList *L);
//���
Status ClearLinkList(LinkList *L);
//�ж��Ƿ�Ϊ��
Status EmptyLinkList(LinkList L);
//��ȡ����
int GetLengthLinkList(LinkList L);
//��ȡָ��λ��id��e
Status GetElemLinkList(LinkList L, int i, ElemType *e);
//��ȡָ��e��λ��
Status LocateElemLinkList(LinkList L, ElemType e, Status(*Compare)(ElemType, ElemType));
//ǰ��
Status PriorElemLinkList(LinkList L, ElemType e, ElemType *pre);
//���
Status NextElemLinkList(LinkList L, ElemType e, ElemType *pre);
//����
Status InsertLinkList(LinkList L, int i, ElemType e);
//ɾ��
Status DeleteLinkList(LinkList L, int i, ElemType *e);
//��ӡ
Status TraverseLinkList(LinkList L, void(*visit)(ElemType));
//ͷ�巨
Status InsertLinkList_H(LinkList *L, int n);
//β�巨
Status InsertLinkList_N(LinkList *L, int n);
//�ϲ�
Status MergeLinkList(LinkList La, LinkList Lb, LinkList *Lc);
typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode, *LinkList_R;

//��ʼ��
Status InitLinkList_R(LinkList_R *L);
//����
Status DestroyLinkList_R(LinkList_R *L);
//���
Status ClearLinkList_R(LinkList_R *L);
//�ж��Ƿ�Ϊ��
Status EmptyLinkList_R(LinkList_R L);
//��ȡ����
int GetLengthLinkList_R(LinkList_R L);
//��ȡָ��λ��id��e
Status GetElemLinkList_R(LinkList_R L, int i, ElemType *e);
//��ȡָ��e��λ��
Status LocateElemLinkList_R(LinkList_R L, ElemType e, Status(*Compare)(ElemType, ElemType));
//ǰ��
Status PriorElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre);
//���
Status NextElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre);
//����
Status InsertLinkList_R(LinkList_R L, int i, ElemType e);
//ɾ��
Status DeleteLinkList_R(LinkList_R L, int i, ElemType *e);
//��ӡ
Status TraverseLinkList_R(LinkList_R L, void(*visit)(ElemType));
//ͷ�巨
Status InsertLinkList_R_H(LinkList_R *L, int n);
//β�巨
Status InsertLinkList_R_N(LinkList_R *L, int n);
//�ϲ�
Status MergeLinkList_R(LinkList_R La, LinkList_R Lb, LinkList_R *Lc);

typedef struct LNode_D {
	ElemType data;  //����
	LNode_D *prior;   //ָ��ǰһ������ָ��
	LNode_D *next;    //ָ���һ������ָ��
}LNode_D, *LinkList_D;

//��ʼ��
Status InitLinkList_D(LinkList_D *L);
//����
Status DestroyLinkList_D(LinkList_D *L);
//���
Status ClearLinkList_D(LinkList_D *L);
//�ж��Ƿ�Ϊ��
Status EmptyLinkList_D(LinkList_D L);
//��ȡ����
int GetLengthLinkList_D(LinkList_D L);
//��ȡָ��λ��id��e
Status GetElemLinkList_D(LinkList_D L, int i, ElemType *e);
//��ȡָ��e��λ��
int LocateElemLinkList_D(LinkList_D L, ElemType e, Status(*Compare)(ElemType, ElemType));
//ǰ��
Status PriorElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre);
//���
Status NextElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre);
//����
Status InsertLinkList_D(LinkList_D L, int i, ElemType e);
//ɾ��
Status DeleteLinkList_D(LinkList_D L, int i, ElemType *e);
//��ӡ
Status TraverseLinkList_D(LinkList_D L, void(*visit)(ElemType));
//ͷ�巨
Status InsertLinkList_D_H(LinkList_D *L, int n);
//β�巨
Status InsertLinkList_D_N(LinkList_D *L, int n);
//�ϲ�
Status MergeLinkList_D(LinkList_D La, LinkList_D Lb, LinkList_D *Lc);

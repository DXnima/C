typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode, *LinkList_R;

//初始化
Status InitLinkList_R(LinkList_R *L);
//销毁
Status DestroyLinkList_R(LinkList_R *L);
//清空
Status ClearLinkList_R(LinkList_R *L);
//判断是否为空
Status EmptyLinkList_R(LinkList_R L);
//获取长度
int GetLengthLinkList_R(LinkList_R L);
//获取指定位置id的e
Status GetElemLinkList_R(LinkList_R L, int i, ElemType *e);
//获取指定e的位置
Status LocateElemLinkList_R(LinkList_R L, ElemType e, Status(*Compare)(ElemType, ElemType));
//前驱
Status PriorElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre);
//后继
Status NextElemLinkList_R(LinkList_R L, ElemType e, ElemType *pre);
//插入
Status InsertLinkList_R(LinkList_R L, int i, ElemType e);
//删除
Status DeleteLinkList_R(LinkList_R L, int i, ElemType *e);
//打印
Status TraverseLinkList_R(LinkList_R L, void(*visit)(ElemType));
//头插法
Status InsertLinkList_R_H(LinkList_R *L, int n);
//尾插法
Status InsertLinkList_R_N(LinkList_R *L, int n);
//合并
Status MergeLinkList_R(LinkList_R La, LinkList_R Lb, LinkList_R *Lc);

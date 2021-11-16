typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode, *LinkList;

//初始化
Status InitLinkList(LinkList *L);
//销毁
Status DestroyLinkList(LinkList *L);
//清空
Status ClearLinkList(LinkList *L);
//判断是否为空
Status EmptyLinkList(LinkList L);
//获取长度
int GetLengthLinkList(LinkList L);
//获取指定位置id的e
Status GetElemLinkList(LinkList L, int i, ElemType *e);
//获取指定e的位置
Status LocateElemLinkList(LinkList L, ElemType e, Status(*Compare)(ElemType, ElemType));
//前驱
Status PriorElemLinkList(LinkList L, ElemType e, ElemType *pre);
//后继
Status NextElemLinkList(LinkList L, ElemType e, ElemType *pre);
//插入
Status InsertLinkList(LinkList L, int i, ElemType e);
//删除
Status DeleteLinkList(LinkList L, int i, ElemType *e);
//打印
Status TraverseLinkList(LinkList L, void(*visit)(ElemType));
//头插法
Status InsertLinkList_H(LinkList *L, int n);
//尾插法
Status InsertLinkList_N(LinkList *L, int n);
//合并
Status MergeLinkList(LinkList La, LinkList Lb, LinkList *Lc);
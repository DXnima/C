typedef struct LNode_D {
	ElemType data;  //数据
	LNode_D *prior;   //指向前一个结点的指针
	LNode_D *next;    //指向后一个结点的指针
}LNode_D, *LinkList_D;

//初始化
Status InitLinkList_D(LinkList_D *L);
//销毁
Status DestroyLinkList_D(LinkList_D *L);
//清空
Status ClearLinkList_D(LinkList_D *L);
//判断是否为空
Status EmptyLinkList_D(LinkList_D L);
//获取长度
int GetLengthLinkList_D(LinkList_D L);
//获取指定位置id的e
Status GetElemLinkList_D(LinkList_D L, int i, ElemType *e);
//获取指定e的位置
int LocateElemLinkList_D(LinkList_D L, ElemType e, Status(*Compare)(ElemType, ElemType));
//前驱
Status PriorElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre);
//后继
Status NextElemLinkList_D(LinkList_D L, ElemType e, ElemType *pre);
//插入
Status InsertLinkList_D(LinkList_D L, int i, ElemType e);
//删除
Status DeleteLinkList_D(LinkList_D L, int i, ElemType *e);
//打印
Status TraverseLinkList_D(LinkList_D L, void(*visit)(ElemType));
//头插法
Status InsertLinkList_D_H(LinkList_D *L, int n);
//尾插法
Status InsertLinkList_D_N(LinkList_D *L, int n);
//合并
Status MergeLinkList_D(LinkList_D La, LinkList_D Lb, LinkList_D *Lc);

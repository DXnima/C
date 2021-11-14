typedef struct LNode {
	ElemType data;
	LNode *next;
}*Link;

// 指向单链表结点的指针
typedef LNode* LinkList;

//初始化
Status InitLink(LinkList* L);

//销毁(结构)
Status DestroyLink(LinkList* L);

// 置空(内容)
Status ClearLink(LinkList L);

/*
* 判空
* 判断链表中是否包含有效数据。
*/
Status LinkEmpty(LinkList L);

/*
* 计数
* 返回链表包含的有效元素的数量。
*/
int LinkLength(LinkList L);

/*
* 取值
* 获取链表中第i个元素，将其存储到e中。
*/
Status GetElemLink(LinkList L, int i, ElemType* e);

/*
* 查找
* 返回链表中首个与e满足Compare关系的元素位序。
*/
int LocateElemLink(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
* 前驱
*/
Status PriorElemLink(LinkList L, ElemType cur_e, ElemType* pre_e);

/*
* 后继
*/
Status NextElemLink(LinkList L, ElemType cur_e, ElemType* next_e);

/*
* 插入
* 向链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
*/
Status LinkInsert(LinkList L, int i, ElemType e);

/*
* 删除
* 删除链表第i个位置上的元素，并将被删除元素存储到e中。
*/
Status LinkDelete(LinkList L, int i, ElemType* e);

/*
* 遍历
* 用visit函数访问链表L
*/
void LinkTraverse(LinkList L, void(Visit)(ElemType));

/*
* 头插法创建链表
*/
Status CreateLink_Head(LinkList* L, int n);

/*
* 尾插法创建链表
*/
Status CreateLink_Tail(LinkList* L, int n);
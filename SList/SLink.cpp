#include "stdafx.h"
#include "SLink.h"

//初始化
Status InitLink(LinkList* L) {
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL) exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}

//销毁(结构)
Status DestroyLink(LinkList* L) {
	LinkList p;
	// 确保链表结构存在
	if (L == NULL || *L == NULL) {
		return ERROR;
	}
	p = *L;
	while (p != NULL)
	{
		p = (*L)->next;
		free(*L);
		(*L)->next = p;
	}
	*L = NULL;
	return OK;
}

// 置空(内容)
Status ClearLink(LinkList L) {
	LinkList pre,p;
	// 确保链表结构存在
	if (L == NULL) {
		return ERROR;
	}
	p = L->next;
	while (p != NULL)
	{
		pre = p;
		p = p->next;
		free(pre);
	}
	L->next = NULL;
	return OK;
}

/*
* 判空
* 判断链表中是否包含有效数据。
*/
Status LinkEmpty(LinkList L) {
	// 链表只有头结点时，认为该链表为空
	if (L != NULL && L->next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*
* 计数
* 返回链表包含的有效元素的数量。
*/
int LinkLength(LinkList L) {
	int num = 0;
	LinkList p;
	if (L == NULL || L->next == NULL)
		return 0;
	p = L->next;
	while (p!=NULL)
	{
		p = p->next;
		num++;
	}
	return num;
}

/*
* 取值
* 获取链表中第i个元素，将其存储到e中。
*/
Status GetElemLink(LinkList L, int i, ElemType* e) {
	LinkList p;
	int j=0;
	if (L == NULL || L->next == NULL)
		return ERROR;
	p = L->next;
	while (p!=NULL && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i - 1) return ERROR;
	*e = p->next->data;
	return OK;
}

/*
* 查找
* 返回链表中首个与e满足Compare关系的元素位序。
*/
int LocateElemLink(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
	int i=1;
	LinkList p;
	if (L == NULL || L->next == NULL)
		return ERROR;
	p = L->next;
	while (p != NULL && !Compare(p->data, e)) {
		p = p->next;
		i++;
	}
	if (p == NULL) return 0;
	else return i;
}

/*
* 前驱
*/
Status PriorElemLink(LinkList L, ElemType cur_e, ElemType* pre_e) {
	LinkList p,next;
	if (L == NULL || L->next == NULL)
		return ERROR;
	p = L->next;
	// 第1个元素没有前驱
	if (p->data == cur_e) {
		return ERROR;
	}
	next = p->next;
	while (next !=NULL && next->data != cur_e)
	{
		p = next;
		next = next->next;
	}
	if (p == NULL) return ERROR;
	*pre_e = p->data;
	return OK;
}

/*
* 后继
*/
Status NextElemLink(LinkList L, ElemType cur_e, ElemType* next_e) {
	LinkList p;
	if (L == NULL || L->next == NULL)
		return ERROR;
	p = L->next;
	while (p != NULL && p->data != cur_e)
	{
		p = p->next;
	}
	if (p==NULL || p->next == NULL) return ERROR;
	*next_e = p->next->data;
	return OK;
}

/*
* 插入
* 向链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
*/
Status LinkInsert(LinkList L, int i, ElemType e) {
	LinkList p,s;
	int j = 0;
	if (L == NULL)
		return ERROR;
	p = L;
	while (p!=NULL && j<i-1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

/*
* 删除
* 删除链表第i个位置上的元素，并将被删除元素存储到e中。
*/
Status LinkDelete(LinkList L, int i, ElemType* e) {
	LinkList p,q;
	int j=0;
	if (L == NULL || L->next == NULL) return ERROR;
	p = L;
	while (p->next != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	*e = p->data;
	free(q);
	return OK;
}

/*
* 遍历
* 用visit函数访问链表L
*/
void LinkTraverse(LinkList L, void(Visit)(ElemType)) {
	LinkList p;
	if (L == NULL || L->next == NULL) return;
	p = L->next;
	while (p!=NULL)
	{
		Visit(p->data);
		p = p->next;
	}
	printf("\n");
}

/*
* 头插法创建链表
*/
Status CreateLink_Head(LinkList* L, int n) {
	LinkList p;
	int i;
	// 建立头结点
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	for (i = 1; i <= n; ++i) {
		// 生成新结点
		p = (LinkList)malloc(sizeof(LNode));
		// 填充数据，并插入到链表中
		p->data = i;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return OK;
}

/*
* 尾插法创建链表
*/
Status CreateLink_Tail(LinkList* L, int n) {
	LinkList p,q;
	int i;
	// 建立头结点
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	for (i = 1, q = *L; i <= n; ++i) {
		// 生成新结点
		p = (LinkList)malloc(sizeof(LNode));
		// 填充数据，并插入到链表中
		p->data = i;
		q->next = p;
		q = q->next;
	}
	return OK;
}

void main_SLink() {
	LinkList L;
	int i;
	ElemType e;
	printf("---------------初始化单链表 L ...\n");
	InitLink(&L);
	for (i = 1; i <= 8; i++) {
		LinkInsert(L, i, 2 * i);
	}
	printf("L 中的元素为：L = ");
	LinkTraverse(L, PrintElem);

	printf("\n位置8处添加8848\n");
	LinkInsert(L, 9, 8848);
	LinkTraverse(L, PrintElem);
	printf("\n位置8处删除8848\n");
	LinkDelete(L, 9, &e);
	LinkTraverse(L, PrintElem);

	printf("\n元素12处前驱：");
	PriorElemLink(L,12,&e);
	printf("%d\n",e);
	printf("\n元素12处后继：");
	NextElemLink(L, 12, &e);
	printf("%d\n", e);

	printf("\n---------------头插法\n");
	CreateLink_Head(&L, 10);
	LinkTraverse(L, PrintElem);
	printf("\n---------------尾插法\n");
	CreateLink_Tail(&L, 10);
	LinkTraverse(L, PrintElem);
	printf("\n---------------销毁...\n");
	DestroyLink(&L);
}
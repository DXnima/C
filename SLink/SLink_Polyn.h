//一元多项式的表示和相加
/* 元素类型定义 */
typedef struct {
	float coef;  //系数
	int expn;    //指数
}ElemType_Polyn;

typedef struct LNode {
	ElemType_Polyn data;
	LNode *next;
}LNode, *LinkList_Polyn;

//输入m项的系数和指数，建立一元多项式链表
Status CreatPolyn(LinkList_Polyn *P, int m);
//销毁一元多项式
Status DestroyPolyn(LinkList_Polyn *P);
//判断是否为空
Status EmptyPolyn(LinkList_Polyn P);
//打印输出一元多项式
Status PrintPolyn(LinkList_Polyn P);
//返回一元多项式p中的项数
Status PolynLength(LinkList_Polyn P);
//多项式相减 Pa = Pa ± Pb，并销毁一元多项式Pb
Status AddorSubtractPolyn(LinkList_Polyn Pa, LinkList_Polyn Pb, char str);
//多项式相乘 Pa = Pa * Pb,并销毁一元多项式Pb
Status MultiplyPolyn(LinkList_Polyn *Pa, LinkList_Polyn *Pb);
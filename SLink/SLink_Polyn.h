//һԪ����ʽ�ı�ʾ�����
/* Ԫ�����Ͷ��� */
typedef struct {
	float coef;  //ϵ��
	int expn;    //ָ��
}ElemType_Polyn;

typedef struct LNode {
	ElemType_Polyn data;
	LNode *next;
}LNode, *LinkList_Polyn;

//����m���ϵ����ָ��������һԪ����ʽ����
Status CreatPolyn(LinkList_Polyn *P, int m);
//����һԪ����ʽ
Status DestroyPolyn(LinkList_Polyn *P);
//�ж��Ƿ�Ϊ��
Status EmptyPolyn(LinkList_Polyn P);
//��ӡ���һԪ����ʽ
Status PrintPolyn(LinkList_Polyn P);
//����һԪ����ʽp�е�����
Status PolynLength(LinkList_Polyn P);
//����ʽ��� Pa = Pa �� Pb��������һԪ����ʽPb
Status AddorSubtractPolyn(LinkList_Polyn Pa, LinkList_Polyn Pb, char str);
//����ʽ��� Pa = Pa * Pb,������һԪ����ʽPb
Status MultiplyPolyn(LinkList_Polyn *Pa, LinkList_Polyn *Pb);
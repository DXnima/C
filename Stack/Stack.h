typedef struct {
	SElemType *base;  //ջ��
	SElemType *top;   //ջ��
	int stacksize;    //��ǰ�ѷ���洢��Ԫ
}SqStack;

//��ʼ�� ������ջ
Status InitStack(SqStack &S);
//����ջ
Status DestroyStack(SqStack &S);
//���ջ
Status ClearStack(SqStack &S);
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S);
//����ջ�ĳ���
int StackLength(SqStack S);
//��ȡջ��Ԫ��
Status GetTop(SqStack S, SElemType &e);
//��ջ
Status Push(SqStack &S,SElemType e);
//��ջ
Status Pop(SqStack &S, SElemType &e);
//����ջ����Ԫ��
Status StackTraverse(SqStack S, void(*visit)(SElemType));
//ʮ����ת����������
void Conversion();
//����ƥ�����
void Bracket();
//�б༭����
void LineEdit();

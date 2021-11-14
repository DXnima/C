#define LIST_INIT_SIZE 100 //���Դ洢�ռ��ʼ������
#define LISTINCREMENT 10 //��������

typedef struct {
	ElemType *elem; //�洢�ռ����ַ
	int length;     // ��ǰ����
	int listsize;   //����Ĵ洢����
}SqList;

//���������Ա�
Status InitList(SqList *L);

//���ٿ����Ա�
Status DestroyList(SqList *L);

//�ж��Ƿ�Ϊ�ձ�
Status ListEmpty(SqList L);

//��ȡԪ�ظ���
int ListLength(SqList L);

//���ص�һ����e�����Ԫ��λ��
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

//ǰ�� ��ȡԪ��cur_e��ǰ��
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e);

//��� ��ȡԪ��cur_e�ĺ��
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e);

//����
Status ListInsert(SqList *L, int i, ElemType e);

//ɾ��
Status ListDelete(SqList *L, int i, ElemType *e);

//���� ��visit��������˳���
void ListTraverse(SqList L, void (Visit)(ElemType));

//�ϲ�
void MergeList(SqList La, SqList Lb, SqList *Lc);

#define LIST_INIT_SIZE 100 //���Դ洢�ռ��ʼ������
#define LISTINCREMENT 10 //��������

typedef struct {
	ElemType *elem; //�洢�ռ����ַ
	int length;     // ��ǰ����
	int listsize;   //����Ĵ洢����
}SList;

//���������Ա�
Status InitList(SList *L);

//���ٿ����Ա�
Status DestroyList(SList *L);

//�ж��Ƿ�Ϊ�ձ�
Status ListEmpty(SList L);

//��ȡԪ�ظ���
int ListLength(SList L);

//���ص�һ����e�����Ԫ��λ��
int LocateElem(SList L, ElemType e, Status(Compare)(ElemType, ElemType));

//ǰ�� ��ȡԪ��cur_e��ǰ��
Status PriorElem(SList L, ElemType cur_e, ElemType* pre_e);

//��� ��ȡԪ��cur_e�ĺ��
Status NextElem(SList L, ElemType cur_e, ElemType* next_e);

//����
Status ListInsert(SList *L, int i, ElemType e);

//ɾ��
Status ListDelete(SList *L, int i, ElemType *e);

//���� ��visit��������˳���
void ListTraverse(SList L, void (Visit)(ElemType));

//�ϲ�
void MergeList(SList La, SList Lb, SList *Lc);
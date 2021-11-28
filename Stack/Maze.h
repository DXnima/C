#include <time.h>           // �ṩtimeԭ��

/* �궨�� */
#define M 15    // �Թ�������
#define N 15    // �Թ�������

#define X 4     // Xָʾ�Թ��ϰ����ֵĸ��ʡ����磬X=4����ζ�ű����Թ�ʱ�����ϰ��ĸ�����1/4=25%

#define SleepTime 3     //SleepTime�����ӡ��ͼʱ��ʱ����

/* �Թ����Ͷ��� */
typedef enum {
	Wall,                       // ��ǽ
	Obstacle,                   // �Թ��ڲ����ϰ�
	Way,                        // ͨ·
	Impasse,                    // ������ͬ��
	East, South, West, North    // ��ǰ̽�����򣺶�������
} MazeNode;

typedef int MazeType[M][N];     // �Թ�����

// �Թ�ͨ���������
typedef struct {
	int x;      // ͨ����ĺᡢ�����궨��
	int y;
} PosType;

/* ͨ������Ϣ�������Թ��㷨 */
typedef struct {
	int ord;        // ͨ����ġ���š�
	PosType seat;   // ͨ����ġ�����λ�á�
	int di;         // ��һ��Ӧ�����ʵġ�����
} SElemType_M;

// ˳��ջԪ�ؽṹ
typedef struct {
	SElemType_M* base;   // ջ��ָ��
	SElemType_M* top;    // ջ��ָ��
	int stacksize;     // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
} SqStack_M;

//��ʼ�� ������ջ
Status InitStack(SqStack_M &S);
//����ջ
Status DestroyStack(SqStack_M &S);
//���ջ
Status ClearStack(SqStack_M &S);
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack_M S);
//����ջ�ĳ���
int StackLength(SqStack_M S);
//��ȡջ��Ԫ��
Status GetTop(SqStack_M S, SElemType_M &e);
//��ջ
Status Push(SqStack_M &S, SElemType_M e);
//��ջ
Status Pop(SqStack_M &S, SElemType_M &e);
//����ջ����Ԫ��
Status StackTraverse(SqStack_M S, void(*visit)(SElemType_M));

/*
* �Թ�Ѱ·
*
* ʹ����ٷ����ҵ�һ������ͨ·������
*/
Status MazePath(MazeType maze, PosType start, PosType end);

/*
* ��ʼ��һ����ģΪN��N�Թ�
* start��end�ֱ�Ϊ�Թ����������ͳ�������
*/
void InitMaze(MazeType maze, PosType* start, PosType* end);

/*
* �жϵ�ǰλ���Ƿ��ͨ����Ҫ���λ���Ǵ�δ��̽����ͨ����
*/
Status Pass(MazeType maze, PosType seat);

/*
* ��ȡ��һ��Ӧ��̽����λ��
* diָʾ��ǰ����λ�õ�̽�����򣬰���East, South, West, North
*/
PosType NextPos(PosType seat, int di);

/*
* ���³�ʼ�����㼣
*
* ��ʼ�����㼣���򶫷���
*/
void FootPrint(MazeType maze, PosType seat);

/*
* ���Թ���seat������mark���
* �ú�����̲��ϵĺ���������
* �̲���ֻ���ô˺�������"����̽��"�ı��
* ���˴��ĺ����Ľ�Ϊ�������������ǣ�����̽������ı��
*/
void MarkPrint(MazeType maze, PosType seat, int mark);

/*
* ����һ��ͨ������Ϣ������
*/
SElemType_M Construct(int ord, PosType seat, int di);

/*
* �ж����������Ƿ����
*/
Status Equals(PosType a, PosType b);

/*
* �����Թ�
* ��ͼ�εķ�ʽ�����Թ���ǰ��״̬
* �˴����Ӹò�����Ŀ���ǹ۲�Ѱ·���̵�ÿһ��
*/
void PaintMaze(MazeType maze);

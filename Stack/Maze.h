#include <time.h>           // 提供time原型

/* 宏定义 */
#define M 15    // 迷宫的行数
#define N 15    // 迷宫的列数

#define X 4     // X指示迷宫障碍出现的概率。例如，X=4，意味着遍历迷宫时遇到障碍的概率是1/4=25%

#define SleepTime 3     //SleepTime代表打印地图时的时间间隔

/* 迷宫类型定义 */
typedef enum {
	Wall,                       // 外墙
	Obstacle,                   // 迷宫内部的障碍
	Way,                        // 通路
	Impasse,                    // “死胡同”
	East, South, West, North    // 当前探索方向：东南西北
} MazeNode;

typedef int MazeType[M][N];     // 迷宫类型

// 迷宫通道块的坐标
typedef struct {
	int x;      // 通道块的横、纵坐标定义
	int y;
} PosType;

/* 通道块信息，用于迷宫算法 */
typedef struct {
	int ord;        // 通道块的“序号”
	PosType seat;   // 通道块的“坐标位置”
	int di;         // 下一个应当访问的“方向”
} SElemType_M;

// 顺序栈元素结构
typedef struct {
	SElemType_M* base;   // 栈底指针
	SElemType_M* top;    // 栈顶指针
	int stacksize;     // 当前已分配的存储空间，以元素为单位
} SqStack_M;

//初始化 创建空栈
Status InitStack(SqStack_M &S);
//销毁栈
Status DestroyStack(SqStack_M &S);
//清空栈
Status ClearStack(SqStack_M &S);
//判断栈是否为空
Status StackEmpty(SqStack_M S);
//返回栈的长度
int StackLength(SqStack_M S);
//获取栈顶元素
Status GetTop(SqStack_M S, SElemType_M &e);
//入栈
Status Push(SqStack_M &S, SElemType_M e);
//出栈
Status Pop(SqStack_M &S, SElemType_M &e);
//遍历栈所有元素
Status StackTraverse(SqStack_M S, void(*visit)(SElemType_M));

/*
* 迷宫寻路
*
* 使用穷举法，找到一条可行通路即返回
*/
Status MazePath(MazeType maze, PosType start, PosType end);

/*
* 初始化一个规模为N×N迷宫
* start和end分别为迷宫的入口坐标和出口坐标
*/
void InitMaze(MazeType maze, PosType* start, PosType* end);

/*
* 判断当前位置是否可通过：要求该位置是从未曾探索的通道块
*/
Status Pass(MazeType maze, PosType seat);

/*
* 获取下一个应当探索的位置
* di指示当前所处位置的探索方向，包括East, South, West, North
*/
PosType NextPos(PosType seat, int di);

/*
* 留下初始访问足迹
*
* 初始访问足迹即向东访问
*/
void FootPrint(MazeType maze, PosType seat);

/*
* 在迷宫的seat处留下mark标记
* 该函数与教材上的函数有区别
* 教材上只是用此函数留下"不可探索"的标记
* 而此处的函数改进为可以留下任意标记，包括探索方向的标记
*/
void MarkPrint(MazeType maze, PosType seat, int mark);

/*
* 构造一个通道块信息并返回
*/
SElemType_M Construct(int ord, PosType seat, int di);

/*
* 判断两个坐标是否相等
*/
Status Equals(PosType a, PosType b);

/*
* 绘制迷宫
* 以图形的方式呈现迷宫当前的状态
* 此处增加该操作的目的是观察寻路过程的每一步
*/
void PaintMaze(MazeType maze);

#include "stdafx.h"
#include "Maze.h"

//初始化 创建空栈
Status InitStack(SqStack_M &S) {
	S.base = (SElemType_M*)malloc(STACK_INIT_SIZE * sizeof(SElemType_M));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	return OK;
}

//销毁栈
Status DestroyStack(SqStack_M &S) {
	if (S.base == NULL) return ERROR;
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
	return OK;
}

//清空栈
Status ClearStack(SqStack_M &S) {
	if (S.base == NULL) return ERROR;
	S.top = S.base;
	return OK;
}

//判断栈是否为空
Status StackEmpty(SqStack_M S) {
	if (S.base == S.top) return TRUE;
	else FALSE;
}

//返回栈的长度
int StackLength(SqStack_M S) {
	if (S.base == NULL) return 0;
	return S.top - S.base;
}

//获取栈顶元素
Status GetTop(SqStack_M S, SElemType_M &e) {
	if (S.base == NULL || S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

//入栈
Status Push(SqStack_M &S, SElemType_M e) {
	if (S.base == NULL || S.top == S.base) return ERROR;
	//判断栈满 扩容
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType_M*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType_M));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

//出栈
Status Pop(SqStack_M &S, SElemType_M &e) {
	if (StackEmpty(S)) return ERROR;
	e = *--S.top;
	return OK;
}

//遍历栈所有元素
Status StackTraverse(SqStack_M S, void(*visit)(SElemType_M)) {
	SElemType_M *p;
	if (S.base == NULL) return ERROR;
	p = S.base;
	while (p < S.top)
	{
		visit(*p++);
	}
	printf("\n");
	return OK;
}

/*
* 迷宫寻路
* 使用穷举法，找到一条可行通路即返回
*/
Status MazePath(MazeType maze, PosType start, PosType end) {
	SqStack_M S;              // 存储探索过的通道块
	SElemType_M e;            // e存储当前通道块信息
	PosType curPos;         // 当前位置
	int curStep;            // 当前通道块序号
	// 初始化轨迹栈
	InitStack(S);
	curPos = start;     // 设定当前位置为"出口位置"
	curStep = 1;        // 探索第一步

	do {
		// 如果当前位置可通过（要求改位置是从未曾探索的通道块）
		if (Pass(maze, curPos)) {
			// 留下初始足迹，即留下向东访问的标记
			FootPrint(maze, curPos);
			// 构造一个通道块信息并返回
			e = Construct(curStep, curPos, East);
			// 加入路径
			Push(S, e);
			// 如果到达终点
			if (Equals(curPos, end) == TRUE) {
				printf("\n寻路成功！！\n\n");
				return TRUE;
			}
			// 获取下一个应当探索的位置，即当前位置的东邻
			curPos = NextPos(curPos, East);
			// 探索下一步
			curStep++;
			// 如果当前位置已经探索过了，则考虑修改探索方向
		}
		else {
			// 如果栈不为空（存在探索的必要）
			if (!StackEmpty(S)) {
				// 回退到上一个位置
				Pop(S, e);
				// 如果待探索位置的4个方向都探索过，则需要做标记
				while (e.di == North && !StackEmpty(S)) {
					// 留下"死胡同"标记，即从该位置出发的路径都没有通路
					MarkPrint(maze, e.seat, Impasse);
					// 继续回退
					Pop(S, e);
				}
				// 如果待探索位置还有剩余可探索的方向
				if (e.di < North) {
					// 改变探索方向，按东南西北的方向轮询
					++e.di;
					// 在迷宫中留下访问标记，用来观察迷宫状态（教材中没有该步骤）
					MarkPrint(maze, e.seat, e.di);
					// 重新将该位置加入到路径中
					Push(S, e);
					// 获取下一个应当探索的位置
					curPos = NextPos(e.seat, e.di);
				}
			}
		}
		// 栈不为空，意味着还有探索的必要
	} while (!StackEmpty(S));
	printf("\n寻路失败！！\n\n");
	return FALSE;
}

/*
* 初始化一个规模为N×N迷宫
* start和end分别为迷宫的入口坐标和出口坐标
*/
void InitMaze(MazeType maze, PosType* start, PosType* end) {
	int i, j, tmp;

	srand((unsigned)time(NULL));                // 用系统时间做随机数种子

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {

			// 在迷宫最外层生成外墙
			if (i == 0 || j == 0 || i == M - 1 || j == N - 1) {
				maze[i][j] = Wall;

				// 迷宫内部的物件
			}
			else {
				tmp = rand() % X;   // 生成随机数[0, X-1]填充迷宫

				if (tmp == 0) {
					// 1/X的概率生成障碍
					maze[i][j] = Obstacle;
				}
				else {
					// 其它地方作为可遍历的通路
					maze[i][j] = Way;
				}
			}
		}
	}

	// 迷宫入口坐标
	(*start).x = 1;
	(*start).y = 0;

	// 迷宫出口坐标
	(*end).x = M - 2;
	(*end).y = N - 1;

	// 开放入口和出口
	maze[1][0] = maze[M - 2][N - 1] = Way;

	// 为了提高寻路成功率，将入口处和出口处临近的结点设为通路（非必须操作）
	maze[1][1] = maze[M - 2][N - 2] = Way;

	// 显示迷宫的初始状态
	PaintMaze(maze);
}

/*
* 判断当前位置是否可通过：要求该位置是从未曾探索的通道块
*/
Status Pass(MazeType maze, PosType seat) {
	int x = seat.x;
	int y = seat.y;
	// 首先检查是否越界，如果是越界了，当前位置肯定无法通过
	if (x < 0 || y < 0 || x > M - 1 || y > N - 1) {
		return FALSE;                    //越界
	}
	// 要求该位置必须是从未曾探索的通道块
	if (maze[x][y] != Way) {
		return FALSE;
	}
	return TRUE;
}

/*
* 获取下一个应当探索的位置
* di指示当前所处位置的探索方向，包括East, South, West, North
*/
PosType NextPos(PosType seat, int di) {
	PosType tmp = seat;
	switch (di) {
	case East:
		tmp.y++;            //向东
		break;
	case South:
		tmp.x++;            //向南
		break;
	case West:
		tmp.y--;            //向西
		break;
	case North:
		tmp.x--;            //向北
		break;
	}
	return tmp;
}

/*
* 留下初始访问足迹
*
* 初始访问足迹即向东访问
*/
void FootPrint(MazeType maze, PosType seat) {
	//初始设置向东探索
	MarkPrint(maze, seat, East);
}

/*
* 在迷宫的seat处留下mark标记
* 可以留下任意标记，包括探索方向的标记
*/
void MarkPrint(MazeType maze, PosType seat, int mark) {
	int x = seat.x;
	int y = seat.y;
	maze[x][y] = mark;//留下不能通过的标记
	// 绘制迷宫
	PaintMaze(maze);
}

/*
* 构造一个通道块信息并返回
*/
SElemType_M Construct(int ord, PosType seat, int di) {
	SElemType_M e;
	e.ord = ord;
	e.seat = seat;
	e.di = di;
	return e;
}

/*
* 判断两个坐标是否相等
*/
Status Equals(PosType a, PosType b) {
	if (a.x == b.x && a.y == b.y) {
		return TRUE;
	}
	else {
		return ERROR;
	}
}

/*
* 绘制迷宫
* 以图形的方式呈现迷宫当前的状态
* 此处增加该操作的目的是观察寻路过程的每一步
*/
void PaintMaze(MazeType maze) {
	int i, j;

	Wait(SleepTime);                // 暂停一下

	system("cls");					// 先清除屏幕现有内容 

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (maze[i][j] == Wall) {                   // 外墙
				printf("▇ ");
			}
			else if (maze[i][j] == Obstacle) {        // 迷宫内部的障碍
				printf("▓ ");
			}
			else if (maze[i][j] == East) {            // 正在朝东探索
				printf("→");
			}
			else if (maze[i][j] == South) {           // 正在朝南探索
				printf("↓");
			}
			else if (maze[i][j] == West) {            // 正在朝西探索
				printf("←");
			}
			else if (maze[i][j] == North) {           // 正在朝北探索
				printf("↑");
			}
			else if (maze[i][j] == Impasse) {         // 死胡同，即四个方向都探索过，但无法通过的位置
				printf("★");
			}
			else {                                   // 还未探索过的路径结点
				printf("　");
			}
			if (j != 0 && j % (N - 1) == 0) {           // 每隔N个结点换行
				printf("\n");
			}
		}
	}
	printf("\n");
}

void main_Maze() {
	MazeType maze;
	PosType start, end;
	char n, Re = 'Y';
	while (Re == 'Y' || Re == 'y') {
		InitMaze(maze, &start, &end);    // 初始化迷宫，包括出入口
		MazePath(maze, start, end);      // 迷宫寻路
		printf("重置？（Y/N）：");
		scanf("%c%c", &Re, &n);
		printf("\n");
	}
}
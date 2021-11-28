typedef struct {
	SElemType *base;  //栈底
	SElemType *top;   //栈顶
	int stacksize;    //当前已分配存储单元
}SqStack;

//初始化 创建空栈
Status InitStack(SqStack &S);
//销毁栈
Status DestroyStack(SqStack &S);
//清空栈
Status ClearStack(SqStack &S);
//判断栈是否为空
Status StackEmpty(SqStack S);
//返回栈的长度
int StackLength(SqStack S);
//获取栈顶元素
Status GetTop(SqStack S, SElemType &e);
//入栈
Status Push(SqStack &S,SElemType e);
//出栈
Status Pop(SqStack &S, SElemType &e);
//遍历栈所有元素
Status StackTraverse(SqStack S, void(*visit)(SElemType));
//十进制转换其他进制
void Conversion();
//括号匹配检验
void Bracket();
//行编辑程序
void LineEdit();

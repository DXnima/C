#include "stdafx.h"

int main() {
	int i = 1;
	while (i != 0)
	{
		printf("输入测试(按0结束)\n 1-线性表 | 2-单链表 | 3-循环单链表：");
		scanf("%d", &i);
		switch (i)
		{
		case 1:main_SList();
			break;
		case 2:main_SLink();
			break;
		case 3:main_SLink_R();
			break;
		default:printf("结束！\n");
			return 0;
		}
		system("pause");//输入任意键继续    
		system("cls");//清屏
	}
	return 0;
}
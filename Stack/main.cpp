#include "stdafx.h"

int main() {
	int i = 1;
	while (i != 0)
	{
		printf("�������(��0����)\n 1-ջ��");
		scanf("%d", &i);
		switch (i)
		{
		case 1:main_Stack();
			break;
		default:printf("������\n");
			return 0;
		}
		system("pause");//�������������    
		system("cls");//����
	}
	return 0;
}
#include "stdafx.h"

int main() {
	int i = 1;
	while (i != 0)
	{
		printf("�������(��0����)\n 1-���Ա� | 2-������ | 3-ѭ��������");
		scanf("%d", &i);
		switch (i)
		{
		case 1:main_SList();
			break;
		case 2:main_SLink();
			break;
		case 3:main_SLink_R();
			break;
		default:printf("������\n");
			return 0;
		}
		system("pause");//�������������    
		system("cls");//����
	}
	return 0;
}
// Image.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define BITMAPFILEHEADERLENGTH 14   // The bmp FileHeader length is 14
#define BM 19778                    // The ASCII code for BM
unsigned int OffSet = 0;

void bmpHeaderPartLength(FILE* fpbmp)
{
	fseek(fpbmp, 10L, SEEK_SET);
	fread(&OffSet, sizeof(char), 4, fpbmp);
	printf("The Header Part is of length %d.\n", OffSet);
}

int main()
{
	
}


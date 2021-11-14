// stdafx.cpp : 只包括标准包含文件的源文件
// SList.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

// 判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e) {
	return data > e ? TRUE : FALSE;
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
	printf("%d ", e);
}

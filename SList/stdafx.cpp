// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// SList.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������

// �ж�data>e�Ƿ����
Status CmpGreater(ElemType data, ElemType e) {
	return data > e ? TRUE : FALSE;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
	printf("%d ", e);
}

// W32D.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "W32D.h"


// ���ǵ���������һ��ʾ��
W32D_API int nW32D=0;

// ���ǵ���������һ��ʾ����
W32D_API int fnW32D(void)
{
	return 42;
}
W32D_API int factorial(int n){
	if (n<0)
	{
		return -1;
	}
	if (n == 0)
	{
		return 0;
	}
	int s = 1;
	for (int i = 1; i <= n; i++)
	{
		s = s*i;
	}
	return s;
}


// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� W32D.h
CW32D::CW32D()
{
	return;
}
float FAC::convert(float deg)
{
	return deg/180*PI;
}

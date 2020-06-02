#include"w32.h"
#include "stdafx.h"
int factorial(int n){
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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int sum_factor(int x) {//���������ӵĺ�
	
	int item=1, sum=0;
	while (item < x)
	{
		if (x % item == 0)
		{
			sum += item;
		}
		item++;
	}
	return sum;
}




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
void rank(int arr[], int n)
{
	int i, j, k, temp;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = k + 1; j < n ; j++)//找出最小值的下标，且赋给k
		{
			if (arr[k] > arr[j])
			{
				k = j;
			}
		}
		if (i != k)//若第i项不是最小值，则交换第i项和最小值
		{
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

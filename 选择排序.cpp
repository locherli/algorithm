#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
void rank(int arr[], int n)
{
	int i, j, k, temp;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = k + 1; j < n ; j++)//�ҳ���Сֵ���±꣬�Ҹ���k
		{
			if (arr[k] > arr[j])
			{
				k = j;
			}
		}
		if (i != k)//����i�����Сֵ���򽻻���i�����Сֵ
		{
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

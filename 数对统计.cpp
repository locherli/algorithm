#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>
int main()
{
	int arr1[20]={1,2,3,4,5}, arr2[20]={6,7,8,9}, k, sum, target;
	printf("输入想要查找的和值：");
	scanf("%d", &target);
	for (k = 0; k < 20; k++)
	{
		for (int j = k + 1; j < 20; j++)
		{
			sum = arr1[k] + arr2[j];
			if (sum==target)
			{
				printf("x=%d y=%d",arr1[k],arr2[j]);
			}
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int prime(int target) //�ж�����
{
    int i = 0;
    if (target <= 1) {
        printf("illegal input!\n");//��������
        return -1;
    }

    for (i = 2; i <= (int)sqrt(target); i++) {
        if (target % i == 0)
            return 0;//��������ֱ�ӷ���0
    }

    return 1;//����������1
}
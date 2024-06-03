#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int prime(int target) //判断素数
{
    int i = 0;
    if (target <= 1) {
        printf("illegal input!\n");//素数定义
        return -1;
    }

    for (i = 2; i <= (int)sqrt(target); i++) {
        if (target % i == 0)
            return 0;//不是素数直接返回0
    }

    return 1;//是素数返回1
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

#define MaxSize 255

/*��ģʽ��T��next����ֵ���������������next*/
void NextVal(char T[], int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            if (T[i] != T[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else {
            j = next[j];
        }
    }
}

/*����KMP�㷨ʵ��ģʽƥ��,����ģʽ��T��next����ֵ��T������S�е�pos���ַ�֮���λ�á�*/
int KMP(char S[], char T[], int pos, int next[]) {
    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

int main() {
    char S[MaxSize + 1], T[MaxSize + 1];
    char S1[MaxSize], S2[MaxSize];
    cin >> S1 >> S2;
    strcpy(&S[1], S1);
    strcpy(&T[1], S2);
    S[0] = strlen(S1);
    T[0] = strlen(S2);
    int* next = new int[T[0] + 1];
    NextVal(T, next);
    cout << KMP(S, T, 1, next);
    delete[] next;
    return 0;
}


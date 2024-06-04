#define _CRT_SECURE_NO_WARNINGS


//==================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TNode {
    char data;
    struct TNode* left;
    struct TNode* right;
};
TNode* InPreToTree(char* pa, char* ia, int p1, int p2, int i1, int i2);
void PrintPostTravel(TNode* t);
void DeleteTree(TNode* t);
int main()
{
    char pre[100], in[100];
    int n; //�����������г���
    TNode* t;//��������������ĸ�
    scanf("%s", pre);
    scanf("%s", in);
    n = 0; while (pre[n]) n++;
    t = InPreToTree(pre, in, 0, n - 1, 0, n - 1);
    printf("Post Travel Result��");
    PrintPostTravel(t);
    printf("\n");
    DeleteTree(t);
    return 0;
}

//=============================



/*
InPreToTree(): ��ǰ��������к�����������й��������
ǰ������Ϊpa[p1:p2]
��������Ϊia[i1:i2]
����������Ķ������ĸ�ָ��
*/
TNode* InPreToTree(char* pa, char* ia, int p1, int p2, int i1, int i2) {
    if (p1 > p2 || i1 > i2)
        return NULL;

    // Create a new node with the data from the pre-order sequence
   // TNode* newNode = (TNode*)malloc(sizeof(TNode));
    TNode* newNode = new TNode;
    newNode->data = pa[p1];
    newNode->left = NULL;
    newNode->right = NULL;

    // Find the position of the current node's data in the in-order sequence
    int pos;
    for (pos = i1; pos <= i2; pos++) {
        if (ia[pos] == pa[p1])
            break;
    }

    // Construct the left and right subtrees recursively
    newNode->left = InPreToTree(pa, ia, p1 + 1, p1 + pos - i1, i1, pos - 1);
    newNode->right = InPreToTree(pa, ia, p1 + pos - i1 + 1, p2, pos + 1, i2);

    return newNode;
}

void PrintPostTravel(TNode* t)
{
    if (t == NULL) return;
    if (t->left) PrintPostTravel(t->left);
    if (t->right) PrintPostTravel(t->right);
    printf("%c", t->data);
}

void DeleteTree(TNode* t)
{
    if (t == NULL) return;
    if (t->left) DeleteTree(t->left);
    if (t->right) DeleteTree(t->right);
    delete t;
}
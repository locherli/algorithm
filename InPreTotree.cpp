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
    int n; //用来保存序列长度
    TNode* t;//用来保存二叉树的根
    scanf("%s", pre);
    scanf("%s", in);
    n = 0; while (pre[n]) n++;
    t = InPreToTree(pre, in, 0, n - 1, 0, n - 1);
    printf("Post Travel Result：");
    PrintPostTravel(t);
    printf("\n");
    DeleteTree(t);
    return 0;
}

//=============================



/*
InPreToTree(): 由前序遍历序列和中序遍历序列构造二叉树
前序序列为pa[p1:p2]
中序序列为ia[i1:i2]
返回所构造的二叉树的根指针
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
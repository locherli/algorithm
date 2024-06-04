//#include <iostream>
//using namespace std;
//
//int main()
//{
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的节点结构
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 定义队列结构体
typedef struct {
    int front;
    int rear;
    TreeNode** data;
    int maxSize;
} Queue;

// 初始化队列
void initQueue(Queue* q, int maxSize) {
    q->front = q->rear = 0;
    q->maxSize = maxSize;
    q->data = (TreeNode**)malloc(sizeof(TreeNode*) * maxSize);
}

// 创建新节点的函数
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        return NULL;
    }
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 层次遍历二叉树的函数
void levelOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // 初始化队列
    Queue q;
    initQueue(&q, 100); // 假设队列的最大容量为100

    // 将根节点加入队列
    q.data[q.rear++] = root;

    while (q.front <= q.rear) {
        // 弹出队列的头部元素
        TreeNode* node = q.data[q.front++];

        // 访问当前节点
        printf("%d ", node->val);

        // 如果当前节点有左子节点，则将其加入队列
        if (node->left != NULL) {
            q.data[q.rear++] = node->left;
        }

        // 如果当前节点有右子节点，则将其加入队列
        if (node->right != NULL) {
            q.data[q.rear++] = node->right;
        }
    }
}


int main() {
    // 构建二叉树
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // 执行层次遍历
    levelOrder(root);

    // 释放二叉树占用的内存
    // ...

    return 0;

}


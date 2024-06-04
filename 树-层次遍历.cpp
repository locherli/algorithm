//#include <iostream>
//using namespace std;
//
//int main()
//{
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>

// ����������Ľڵ�ṹ
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ������нṹ��
typedef struct {
    int front;
    int rear;
    TreeNode** data;
    int maxSize;
} Queue;

// ��ʼ������
void initQueue(Queue* q, int maxSize) {
    q->front = q->rear = 0;
    q->maxSize = maxSize;
    q->data = (TreeNode**)malloc(sizeof(TreeNode*) * maxSize);
}

// �����½ڵ�ĺ���
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        return NULL;
    }
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ��α����������ĺ���
void levelOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // ��ʼ������
    Queue q;
    initQueue(&q, 100); // ������е��������Ϊ100

    // �����ڵ�������
    q.data[q.rear++] = root;

    while (q.front <= q.rear) {
        // �������е�ͷ��Ԫ��
        TreeNode* node = q.data[q.front++];

        // ���ʵ�ǰ�ڵ�
        printf("%d ", node->val);

        // �����ǰ�ڵ������ӽڵ㣬����������
        if (node->left != NULL) {
            q.data[q.rear++] = node->left;
        }

        // �����ǰ�ڵ������ӽڵ㣬����������
        if (node->right != NULL) {
            q.data[q.rear++] = node->right;
        }
    }
}


int main() {
    // ����������
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

    // ִ�в�α���
    levelOrder(root);

    // �ͷŶ�����ռ�õ��ڴ�
    // ...

    return 0;

}


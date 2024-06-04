#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
     
    return root;
}

void traverseInOrder(struct Node* root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        printf("%d ", root->data);
        traverseInOrder(root->right);
    }
}

Node* search(Node* root, int x)
{
    //check
    if (root->data == x)
        return root;

    if (root != NULL) {
        return search(root->left, x);
        return search(root->right,x);
    }
}

//undebug
void deleteNode(struct Node* root ,int x)
{
    Node* toDel = search(root, x);
    Node* current=root;
    while (current->right != NULL)
        current = current->right;
    toDel = current;
    free(current);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    printf("Binary Search Tree (In-order traversal): ");
    traverseInOrder(root);
    printf("\n");


    return 0;
}
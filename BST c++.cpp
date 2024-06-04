#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return node;
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void traverseInOrder(Node* node) {
        if (node != nullptr) {
            traverseInOrder(node->left);
            std::cout << node->data << " ";
            traverseInOrder(node->right);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void traverse() {
        traverseInOrder(root);
    }
};

int main() {
    BST bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    std::cout << "Binary Search Tree (In-order traversal): ";
    bst.traverse();
    std::cout << std::endl;

    return 0;
}
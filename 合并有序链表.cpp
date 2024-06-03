#include <stdio.h>
#include <stdlib.h>

// ����ڵ�Ľṹ�嶨��
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// �����µĽڵ�
Node* newNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// �ϲ�������������ĵݹ麯��
Node* mergeSorted(Node* a, Node* b) {
    Node* result = NULL;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    }
    else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return result;
}

// ��ӡ����
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// ���Ժϲ�������
int main() {
    Node* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    Node* mergedList = mergeSorted(l1, l2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}

//=====================================================//
//
//// ����ڵ�Ľṹ�嶨��
//typedef struct Node {
//    int data;
//    struct Node* next;
//} Node;
//
//// �����µĽڵ�
//Node* newNode(int data) {
//    Node* new_node = (Node*)malloc(sizeof(Node));
//    new_node->data = data;
//    new_node->next = NULL;
//    return new_node;
//}
//
//// �ϲ�������������ĵ�������
//Node* mergeSortedIterative(Node* a, Node* b) {
//    Node* result = NULL;
//    Node** lastPtrRef = &result;
//
//    while (a != NULL && b != NULL) {
//        if (a->data <= b->data) {
//            *lastPtrRef = a;
//            a = a->next;
//        }
//        else {
//            *lastPtrRef = b;
//            b = b->next;
//        }
//        lastPtrRef = &((*lastPtrRef)->next);
//    }
//
//    if (a == NULL)
//        *lastPtrRef = b;
//    else
//        *lastPtrRef = a;
//
//    return result;
//}
//
//// ��ӡ����
//void printList(Node* node) {
//    while (node != NULL) {
//        printf("%d ", node->data);
//        node = node->next;
//    }
//    printf("\n");
//}
//
//int main()
//{
//    Node* L1 = newNode(1);
//    L1->next = newNode(3);
//    L1->next->next = newNode(5);
//
//    Node* L2 = newNode(2);
//    L2->next = newNode(4);
//
//    Node* result = mergeSortedIterative(L1, L2);
//
//    printList(result);
//
//    return 0;
//}
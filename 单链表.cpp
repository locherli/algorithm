#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;           // 数据域
    struct Node* next;  // 指针域，指向下一个节点
} Node;
 
// 创建一个新的节点
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// 向链表末尾添加一个新节点
void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;  // 如果链表为空，新节点即为头节点
    }
    else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;  // 遍历到链表末尾
        }
        current->next = new_node;  // 在末尾添加新节点
    }
}

// 打印链表元素
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//查找链表元素
Node* find_list(Node* head, int target)
{
    Node* current = head;
    while (current!=NULL)
    {
        if (current->data==target)
        {
            return current;
        }
        current = current->next;
    }
    puts("not found");
    return NULL;
}

// 释放链表内存
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;  // 初始化链表为空

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);


    //printf("链表元素： ");
    //print_list(head);
    Node* result = find_list(head, 3);
    printf("%d", result->data);
    free_list(head);  // 释放链表内存


    return 0;
}

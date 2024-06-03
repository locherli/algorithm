#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
typedef struct Node {
    int data;           // ������
    struct Node* next;  // ָ����ָ����һ���ڵ�
} Node;
 
// ����һ���µĽڵ�
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// ������ĩβ���һ���½ڵ�
void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;  // �������Ϊ�գ��½ڵ㼴Ϊͷ�ڵ�
    }
    else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;  // ����������ĩβ
        }
        current->next = new_node;  // ��ĩβ����½ڵ�
    }
}

// ��ӡ����Ԫ��
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//��������Ԫ��
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

// �ͷ������ڴ�
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;  // ��ʼ������Ϊ��

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);


    //printf("����Ԫ�أ� ");
    //print_list(head);
    Node* result = find_list(head, 3);
    printf("%d", result->data);
    free_list(head);  // �ͷ������ڴ�


    return 0;
}

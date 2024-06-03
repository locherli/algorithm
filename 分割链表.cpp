#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
} Node;

Node* divideList(Node** head, int x)
{
    Node* current = *head;
    Node* smallerHead = nullptr;
    Node* smallerTail = nullptr;
    Node* greaterHead = nullptr;
    Node* greaterTail = nullptr;

    while (current != nullptr)//traverse the list
    {
        if (current->data < x)
        {
            if (smallerHead == nullptr)
            {
                smallerHead = current;
                smallerTail = current;
            }
            else
            {
                smallerTail->next = current;
                smallerTail = smallerTail->next;
            }
        }
        else
        {
            if (greaterHead == nullptr)
            {
                greaterHead = current;
                greaterTail = current;
            }
            else
            {
                greaterTail->next = current;
                greaterTail = greaterTail->next;
            }
        }
        current = current->next;
    }

    if (smallerTail != nullptr)//ensure that the end of a list point to "nullptr"
        smallerTail->next = nullptr;
    if (greaterTail != nullptr)
        greaterTail->next = nullptr;

    if (smallerHead == nullptr)//if no number is bigger than x 
        return greaterHead;

    smallerTail->next = greaterHead;//merge two list
    return smallerHead;
}

void printList(Node* p)
{
    while (p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    Node* head = new Node(13);
    head->next = new Node(2);
    head->next->next = new Node(34);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(56);
    int x = 10;
    head = divideList(&head, x);

    printList(head);

    return 0;
}
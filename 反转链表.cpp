#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
// ��������ڵ�ṹ��
typedef struct Node {
	int data;           // ������
	struct Node* next;  // ָ����ָ����һ���ڵ�
} Node;

//create a new node and return it's ptr.
Node* create_node(int data)
{
	Node* new_node = new Node;
	if (new_node !=  NULL)
	{
		new_node->data = data;
		new_node->next =  NULL;
		return new_node;
	}
	else
	{
		cout << "fail to allocate memory" << endl;
		exit(-1);
	}
}

//add a node to the tail of a list.
void add_node(Node** phead, int data)
{
	Node* new_node = create_node(data);
	if (*phead ==  NULL)
	{
		*phead = new_node;
	}
	else
	{
		Node* current = *phead;
		while (current->next !=  NULL)
		{
			current = current->next;
		}
		current->next = new_node; // Update the next pointer of the last node to the new node
	}
}

//reverse a linked list
Node* reverseList(Node** head) {
	Node* prev =  NULL;
	Node* current = *head;
	Node* next =  NULL;

	while (current !=  NULL) {
		next = current->next;      // Store the next node
		current->next = prev;      // Reverse the pointer
		// Move prev and current pointers one step forward
		prev = current;
		current = next;
	}

	return prev;     // Return the new head of the reversed list
}




int main()
{
	Node* head =  NULL;
	add_node(&head, 1);
	add_node(&head, 2);
	add_node(&head, 3);
	add_node(&head, 4);
	add_node(&head, 5);
	add_node(&head, 6);
	add_node(&head, 7);
	head = reverseList(&head);

	return 0;
}

#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* next;
	Node(int x) :data(x), next(nullptr) {}
}Node;

//Node* divideList(Node** head, int x)
//{
//	Node* current = *head;
//	Node* result=nullptr;
//	Node** lastptr = &result;
//	while (current->next != nullptr)
//	{
//		if (current->data < x)
//		{
//			*lastptr = current;//set current node into result
//			lastptr = &((*lastptr)->next);//ensure "lastptr"  point to the last location of result
//		}
//		current = current->next;
//	}
//
//	current = *head;
//	while (current->next != nullptr)
//	{
//		if (current->data >= x)
//		{
//			*lastptr = current;//set current node into result
//			lastptr = &((*lastptr)->next);//ensure "lastptr"  point to the last location of result
//		}
//		current = current->next;
//	}
//
//	return result;
//}

Node* divideList(Node** head, int x)
{
	Node* current = *head;
	Node* result = nullptr;
	Node** lastptr = &result;

	// Handle the case when the first node has a value less than x
	if (current != nullptr && current->data < x)
	{
		*lastptr = current;
		lastptr = &((*lastptr)->next);
		current = current->next;
	}

	while (current != nullptr)
	{
		if (current->data < x)
		{
			*lastptr = current;
			lastptr = &((*lastptr)->next);
		}
		current = current->next;
	}

	current = *head;
	while (current != nullptr)
	{
		if (current->data >= x)
		{
			*lastptr = current;
			lastptr = &((*lastptr)->next);
		}
		current = current->next;
	}

	// Terminate the second list
	*lastptr = nullptr;

	return result;
}
void printList(Node* p)
{
	while (p !=nullptr)
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
	divideList(&head, x);


	printList(head);
	return 0;
}
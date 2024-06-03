#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* next;
	Node(int x) :data(x), next(nullptr) {}
}Node;

int return_mid(Node* head)
{
	Node* slow = head;
	Node* fast = head;

	while (slow != nullptr && fast != nullptr)
	{
		if (fast->next == nullptr)
			break;
		slow = slow->next;

		fast = fast->next->next;
	}

	return slow->data;
}

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	//head->next->next->next->next = new Node(5);
	cout << return_mid(head) << endl;

	return 0;
}
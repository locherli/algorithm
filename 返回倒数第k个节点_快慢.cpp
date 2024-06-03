#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* next;
	Node(int x):data(x),next(nullptr) {}
}Node;

//return the K'th backwardly.
int retu_backward(Node* head,int k)
{
	Node* fast = head;
	Node* slow = head;

	while (k-1>0)
	{
		if (fast->next==nullptr)
		{
			cout << "k is larger than the lengh of the list." << endl;
			exit(-1);
		}
		fast = fast->next;
		k--;
	}

	while (fast->next!=nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow->data;
}

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	cout << retu_backward(head, 3) << endl;
	return 0;
}
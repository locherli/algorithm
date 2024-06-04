#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
	bool lTag = 0;
	bool rTag = 0;
}Node;


Node* createNode(int x)
{
	Node* newN = new Node;
	newN->data = x;
	return newN;
}

Node* previous = nullptr;
void preOrderThreadlize(Node* node)
{

	if (node == nullptr) { return; }

	if (node->left == nullptr) //set tag for node node
	{
		node->lTag = 1;
		node->left = previous;
	}
	if (previous != nullptr && node->right == nullptr) //set tag for previous node
	{
		previous->rTag = 1;
		previous->right = node;
	}
	previous = node;

	if (node->lTag == 0)
		preOrderThreadlize(node->left);
	if (node->rTag == 0)
		preOrderThreadlize(node->right);
}



void traversePreOrder(Node* root)
{
	Node* cur = root;

	while (cur != nullptr)
	{
		while (cur->lTag == 0) //to the leftmost
		{
			cout << cur->data << ' ';
			cur = cur->left;
		}

		cout << cur->data << ' ';

		while (cur->rTag == 1)
		{
			cur = cur->right;
			cout << cur->data << " ";
		}

		cur = cur->right;
	}

}


int main()
{

	Node* root = new Node;
	root = createNode(0);
	root->left = createNode(1);
	root->right = createNode(2);
	root->left->right = createNode(3);
	root->left->left = createNode(4);
	root->left->left->right = createNode(5);
	//instance
	//     0
	//    1  2
	//  4  3
	//   5
	//


	preOrderThreadlize(root);
	traversePreOrder(root);



	return 0;
}
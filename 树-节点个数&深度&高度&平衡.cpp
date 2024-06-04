#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct TreeNode {
	int val;
	struct TreeNode* left = nullptr;
	struct TreeNode* right = nullptr;
} TreeNode;

TreeNode* createNode(int value)
{
	TreeNode* newNode = new TreeNode;
	newNode->val = value;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

unsigned int countNode(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	return countNode(root->left) + countNode(root->right) + 1;
}

unsigned int getHeight(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int num_layer_k(TreeNode* root, int k)
{
	if (root == nullptr || k < 1)
		return 0;
	if (k == 1)
		return 1;

	return num_layer_k(root->left, k - 1) + num_layer_k(root->right, k - 1);
}

int numOfLeaves(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;
	return numOfLeaves(root->left) + numOfLeaves(root->right);
}

bool isSameTree(TreeNode* t1, TreeNode* t2)
{
	if (t1 == nullptr && t2 == nullptr)
		return true;
	else if (t1 == nullptr || t2 == nullptr) //if one is null but another not
		return false;

	return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

int toPositive(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

bool isAVL(TreeNode* root)
{
	if (root == nullptr)
		return true;
	if (toPositive(getHeight(root->left) - getHeight(root->right)) > 1)
		return false;

	return isAVL(root->left) && isAVL(root->right);
}

TreeNode* mirrorTree(TreeNode* root) //it'll destroy the tree passed into
{
	if (root == nullptr)
		return nullptr;

	TreeNode* left = mirrorTree(root->right);
	TreeNode* right = mirrorTree(root->left);
	root->left = left;
	root->right = right;

	return root;
}

TreeNode* CopyMirrorTree(TreeNode* root)
{
	if (root == nullptr)
		return nullptr;

	TreeNode* newNode = new TreeNode;
	newNode->val = root->val;
	newNode->left = CopyMirrorTree(root->right);
	newNode->right = CopyMirrorTree(root->left);

	return root;
}

void printTree(TreeNode* root)
{
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* current = q.front();
		q.pop();
		if (current->left != nullptr)
			q.push(current->left);
		if (current->right != nullptr)
			q.push(current->right);

		cout << current->val << ' ';
	}
}

int main()
{
	TreeNode* root;
	root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);

	cout << "num of node:" << countNode(root);
	cout << "height:" << getHeight(root);
	cout << "num of leaves:" << numOfLeaves(root);

	cout << "is AVL? " << isAVL(root);
	cout << endl << "print tree in order:" << endl;
	printTree(root);
	return 0;
}
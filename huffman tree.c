#include <stdio.h>
#include <stdlib.h>

// 定义哈夫曼树的节点结构
typedef struct HTnode {
	int weight;
	int parent, left, right;
}HTnode;

HTnode ht[1000];

// Function to find the two nodes with the smallest weights
void findMinWeight(HTnode ht[], int n, int* min1, int* min2) {
	int i;
	int minWeight1 = INT_MAX, minWeight2 = INT_MAX;

	// Find the two nodes with the smallest weights
	for (i = 0; i < n; i++) {
		if (ht[i].parent == -1) { // Only consider nodes without a parent
			if (ht[i].weight < minWeight1) {
				minWeight2 = minWeight1;
				*min2 = *min1;
				minWeight1 = ht[i].weight;
				*min1 = i;
			}
			else if (ht[i].weight < minWeight2) {
				minWeight2 = ht[i].weight;
				*min2 = i;
			}
		}
	}
}

// Function to create a Huffman tree
void createHT(int elem[], int n) {
	int i, j;
	for (i = 0; i <n; i++) {
		ht[i].weight = elem[i];
		ht[i].parent = -1;
		ht[i].left = -1;
		ht[i].right = -1;
	}
	for (i = n; i < 2 * n - 1; i++) //"i" represent the current node
	{
		int min1, min2;
		findMinWeight(ht, i, &min1, &min2);
		ht[i].weight = ht[min1].weight + ht[min2].weight;
		ht[i].left = min1;
		ht[i].right = min2;
		ht[min1].parent = i;
		ht[min2].parent = i;
		ht[i].parent = -1;
	}
}


void printHuffmanTree(HTnode ht[], int n) {
	printf("Node\tWeight\tParent\tLeft\tRight\n");
	for (int i = 0; i < 2 * n - 1; i++) {
		printf("%d\t%d\t%d\t%d\t%d\n", i, ht[i].weight, ht[i].parent, ht[i].left, ht[i].right);
	}
}

int main()
{
	int elem[5] = { 1,2,3,4,5 };
	createHT(elem, 5);

	printHuffmanTree(ht, 5);

	return 0;
}

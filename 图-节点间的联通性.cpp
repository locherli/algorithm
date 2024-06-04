#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_Node 128
using namespace std;

class Graph {
public:
	int num_node = 0;     //data of graph
	int num_edge = 0;
	int** matrix = new int*[MAX_Node];

	void createGraph() {
		std::cin >> num_node >> num_edge;      //input

		for (int i = 0; i < num_node; i++)   //assign memory for matrix
			matrix[i] = new int[num_node];

		for (int x = 0; x < num_node; x++)       //initialize the matrix
			for (int y = 0; y < num_node; y++)
				matrix[x][y] = 0;

		for (int e = 0; e < num_node; e++)    //it can access itself
			matrix[e][e] = 1;

		for (int i = 0; i < num_edge; i++)    //add edge into this graph
		{
			int v1 = 0, v2 = 0;
			scanf("%d%d", &v1, &v2);

			matrix[v1][v2] = 1;
			matrix[v2][v1] = 1;
		}
	}

	int isAccessible(int n1, int n2) {
		int** tem;
		for (int i = 1; i < num_node; i++)
		{
			tem = power(matrix, i);
			if (tem[n1][n2] != 0)	//means node[n1][n2] is accessible
				return i - 1;
		}
		return -1;
	}

	//calculate the matrix of power 'n'
	int** power(int** matrix, int n) {
		int** result = new int*[num_node];		//create two matrixs
		int** temp = new int*[num_node];

		for (int i = 0; i < num_node; i++) {   //allocate memory
			result[i] = new int[num_node];
			temp[i] = new int[num_node];
		}

		for (int x = 0; x < num_node; x++)       //initialize the matrix
			for (int y = 0; y < num_node; y++) {
				result[x][y] = 0;
				temp[x][y] = 0;
			}

		multiply(temp, matrix, matrix);

		if (n == 0 || n == 1)
			return matrix;

		if (n == 2)
			return temp;

		n -= 2;
		while (n--)
		{
			multiply(result, temp, matrix);
			//which means temp = result;
			for (int i = 0; i < num_node; i++)
				for (int j = 0; j < num_node; j++)
					temp[i][j] = result[i][j];
		}

		return result;
	}
	//multiply two matrixes
	void multiply(int**& result, int** mat1, int** mat2) {
		for (int i = 0; i < num_node; i++)
			for (int j = 0; j < num_node; j++)
				for (int k = 0; k < num_node; k++)
					result[i][j] += mat1[i][k] * mat2[k][j];
	}
};



int main()
{
	Graph G;
	G.createGraph();
	int N;
	int v1, v2;

	cin >> N;
	while (N--)
	{
		scanf("%d%d", &v1, &v2);
		//cin >> v1 >> v2;
		int numTranslator = G.isAccessible(v1, v2);
		cout << numTranslator << endl;
	}

	return 0;
}
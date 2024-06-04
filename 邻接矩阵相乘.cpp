#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<vector<int>>& result, const vector<vector<int>>& mat1, const vector<vector<int>>& mat2);
// 函数计算邻接矩阵的k次幂
vector<vector<int>> power(const vector<vector<int>>& adjacencyMatrix, int k) {
	int n = adjacencyMatrix.size();
	vector<vector<int>> result(n, vector<int>(n, 0));
	vector<vector<int>> temp(n, vector<int>(n, 0));

	multiply(temp, adjacencyMatrix, adjacencyMatrix);

	if (k == 2) { return temp; }
	else { k -= 2; }

	while (k--) {
		multiply(result, temp, adjacencyMatrix);
		temp = result;
	}

	return result;
}

// 矩阵乘法函数，用于计算两个矩阵的乘积
void multiply(vector<vector<int>>& result, const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
	int n = mat1.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

// 打印矩阵
void printMatrix(const vector<vector<int>>& matrix) {
	for (const auto& row : matrix) {
		for (int val : row) {
			cout << val << " ";
		}
		cout << endl;
	}
}

int main() {
	// 示例邻接矩阵
	vector<vector<int>> adjacencyMatrix = {
		{0, 1, 1, 0},
		{1, 0, 1, 1},
		{1, 1, 0, 1},
		{0, 1, 1, 0}
	};

	// 计算邻接矩阵的5次幂
	vector<vector<int>> adjacencyPower = power(adjacencyMatrix, 2);

	// 打印结果
	cout << "Adjacency Matrix Power:" << endl;
	printMatrix(adjacencyPower);

	return 0;
}

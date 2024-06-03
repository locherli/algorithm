#include <iostream>
using namespace std;
#define MAXSIZE 50000

typedef struct Node {
	int coef;  //系数
	int expo;  //指数
} ElementType;

typedef struct {
	ElementType* data;
	int length;
} SqList;

void Add(SqList LA, SqList LB, SqList& LC); //函数功能：多项式相加  LC=LA+LB
bool MakeEmpty(SqList& L); //顺序表初始化
void CreateList(SqList& L);  //输入顺序表
void Print(SqList L); //输出顺序表

void deleteVoid(SqList& L)
{
	a:

	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i].coef == 0)
		{
			for (int j = i; j < L.length - 1; j++)
			{
				L.data[j] = L.data[j + 1];
			}
			L.length--;
		}
	}
	for (int index = 0; index < L.length; index++)
	{
		if (L.data[index].coef == 0)
			goto a;
	}
}

void Add(SqList LA, SqList LB, SqList& LC)
{
	LC.length = LA.length + LB.length; // LC的长度是LA和LB的长度之和

	int i = 0, j = 0, k = 0;
	while (i < LA.length && j < LB.length) {
		if (LA.data[i].expo == LB.data[j].expo) { // 如果指数相同
			LC.data[k].coef = LA.data[i].coef + LB.data[j].coef; // 系数相加
			LC.data[k].expo = LA.data[i].coef;
			i++;
			j++;
		}
		else if (LA.data[i].expo < LB.data[j].expo) { // 如果LA的指数小于LB
			LC.data[k] = LA.data[i];
			i++;
		}
		else { // 如果LB的指数小于LA
			LC.data[k] = LB.data[j];
			j++;
		}
		k++;
	}

	// 处理剩余的元素
	while (i < LA.length) {
		LC.data[k] = LA.data[i];
		i++;
		k++;
	}

	while (j < LB.length) {
		LC.data[k] = LB.data[j];
		j++;
		k++;
	}
	deleteVoid(LC);
}

//顺序表初始化
bool MakeEmpty(SqList& L) {
	L.data = new ElementType[MAXSIZE];
	L.length = 0;
	return true;
}
//整体建立多项式
void CreateList(SqList& L) {
	ElementType x;
	int N;
	cin >> N;
	while (N--) {
		cin >> x.coef >> x.expo;  //读入对应的系数和指数
		L.data[L.length++] = x;
	}
}
//输出顺序表
void Print(SqList L) {
	int i;
	if (L.length == 0) {
		cout << "List Is Empty!" << endl;
		return;
	}
	cout << "List Is :" << "(" << L.data[0].coef << "," << L.data[0].expo << ")";
	for (i = 1; i < L.length; i++) {
		cout << ", (" << L.data[i].coef << "," << L.data[i].expo << ")";
	}
	cout << endl;
}
int main() {
	SqList A, B, C;
	int N, i;
	MakeEmpty(A); //初始化多项式A
	MakeEmpty(B); //初始化多项式B
	MakeEmpty(C); //初始化多项式C
	CreateList(A);
	//Print(A);
	CreateList(B);
	//Print(B);
	Add(A, B, C);
	Print(C);
	delete& A, & B, & C;
	return 0;
}
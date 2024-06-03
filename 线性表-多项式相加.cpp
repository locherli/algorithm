#include <iostream>
using namespace std;
#define MAXSIZE 50000

typedef struct Node {
	int coef;  //ϵ��
	int expo;  //ָ��
} ElementType;

typedef struct {
	ElementType* data;
	int length;
} SqList;

void Add(SqList LA, SqList LB, SqList& LC); //�������ܣ�����ʽ���  LC=LA+LB
bool MakeEmpty(SqList& L); //˳����ʼ��
void CreateList(SqList& L);  //����˳���
void Print(SqList L); //���˳���

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
	LC.length = LA.length + LB.length; // LC�ĳ�����LA��LB�ĳ���֮��

	int i = 0, j = 0, k = 0;
	while (i < LA.length && j < LB.length) {
		if (LA.data[i].expo == LB.data[j].expo) { // ���ָ����ͬ
			LC.data[k].coef = LA.data[i].coef + LB.data[j].coef; // ϵ�����
			LC.data[k].expo = LA.data[i].coef;
			i++;
			j++;
		}
		else if (LA.data[i].expo < LB.data[j].expo) { // ���LA��ָ��С��LB
			LC.data[k] = LA.data[i];
			i++;
		}
		else { // ���LB��ָ��С��LA
			LC.data[k] = LB.data[j];
			j++;
		}
		k++;
	}

	// ����ʣ���Ԫ��
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

//˳����ʼ��
bool MakeEmpty(SqList& L) {
	L.data = new ElementType[MAXSIZE];
	L.length = 0;
	return true;
}
//���彨������ʽ
void CreateList(SqList& L) {
	ElementType x;
	int N;
	cin >> N;
	while (N--) {
		cin >> x.coef >> x.expo;  //�����Ӧ��ϵ����ָ��
		L.data[L.length++] = x;
	}
}
//���˳���
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
	MakeEmpty(A); //��ʼ������ʽA
	MakeEmpty(B); //��ʼ������ʽB
	MakeEmpty(C); //��ʼ������ʽC
	CreateList(A);
	//Print(A);
	CreateList(B);
	//Print(B);
	Add(A, B, C);
	Print(C);
	delete& A, & B, & C;
	return 0;
}
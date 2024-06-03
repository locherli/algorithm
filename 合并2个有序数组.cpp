#include <iostream>
using namespace std;
#define MAXSIZE 50000
typedef int ElementType;
typedef struct LNode {
	ElementType* data;
	int length; /* �������Ա�������Ԫ�صĸ��� */
} SqList;

void Merge(SqList L1, SqList L2, SqList& L3) {
    int i = 0; // L1������
    int j = 0; // L2������
    int k = 0; // L3������

    // ������ʱ�洢�ռ�
    ElementType* temp = new ElementType[MAXSIZE];

    // ��L1��L2�е�Ԫ�ذ��������ŵ�temp��
    while (i < L1.length && j < L2.length) 
    {
        if (L1.data[i]==L2.data[j])
        {
            temp[k++] = L1.data[i];
            i++;
            j++;
        }
        else if (L1.data[i] < L2.data[j]) {
            temp[k++] = L1.data[i++];
        }
        else {
            temp[k++] = L2.data[j++];
        }
    }

    // ��L1ʣ���Ԫ�ش�ŵ�temp��
    while (i < L1.length) {
        temp[k++] = L1.data[i++];
    }

    // ��L2ʣ���Ԫ�ش�ŵ�temp��
    while (j < L2.length) {
        temp[k++] = L2.data[j++];
    }

    // ��temp�е�Ԫ�ظ��Ƶ�L3��
    for (int m = 0; m < k; m++) {
        L3.data[m] = temp[m];
    }

    // ����L3�ĳ���
    L3.length = k;

    // �ͷ���ʱ�洢�ռ�
    delete[] temp;
}


//˳����ʼ��
bool MakeEmpty(SqList& L) {
    L.data = new ElementType[MAXSIZE];
    if (L.data == NULL) return false;
    L.length = 0;
    return true;
}
//���彨������˳���
void CreateList(SqList& L) {
    ElementType x;
    int N;
    cin >> N;
    while (N--) {
        cin >> x;
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
    cout << "List Is :" << L.data[0];
    for (i = 1; i < L.length; i++) {
        cout << "," << L.data[i];
    }
    cout << endl;
}
int main() {
    SqList L1, L2, L3;            /*����˳���*/
    MakeEmpty(L1);    /*��ʼ��˳���*/
    MakeEmpty(L2);    /*��ʼ��˳���*/
    MakeEmpty(L3);    /*��ʼ��˳���*/
    CreateList(L1);     /*�����������*/
    //Print(L1);
    CreateList(L2);     /*�����������*/
    //Print(L2);
    Merge(L1, L2, L3);    /*����˳���ĺϲ�*/
    Print(L3);                  /*����±�*/
    return 0;
}
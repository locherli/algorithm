#include <iostream>
using namespace std;
#define MAXSIZE 50000
typedef int ElementType;
typedef struct LNode {
	ElementType* data;
	int length; /* 保存线性表中数据元素的个数 */
} SqList;

void Merge(SqList L1, SqList L2, SqList& L3) {
    int i = 0; // L1的索引
    int j = 0; // L2的索引
    int k = 0; // L3的索引

    // 申请临时存储空间
    ElementType* temp = new ElementType[MAXSIZE];

    // 将L1和L2中的元素按照升序存放到temp中
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

    // 将L1剩余的元素存放到temp中
    while (i < L1.length) {
        temp[k++] = L1.data[i++];
    }

    // 将L2剩余的元素存放到temp中
    while (j < L2.length) {
        temp[k++] = L2.data[j++];
    }

    // 将temp中的元素复制到L3中
    for (int m = 0; m < k; m++) {
        L3.data[m] = temp[m];
    }

    // 更新L3的长度
    L3.length = k;

    // 释放临时存储空间
    delete[] temp;
}


//顺序表初始化
bool MakeEmpty(SqList& L) {
    L.data = new ElementType[MAXSIZE];
    if (L.data == NULL) return false;
    L.length = 0;
    return true;
}
//整体建立有序顺序表
void CreateList(SqList& L) {
    ElementType x;
    int N;
    cin >> N;
    while (N--) {
        cin >> x;
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
    cout << "List Is :" << L.data[0];
    for (i = 1; i < L.length; i++) {
        cout << "," << L.data[i];
    }
    cout << endl;
}
int main() {
    SqList L1, L2, L3;            /*定义顺序表*/
    MakeEmpty(L1);    /*初始化顺序表*/
    MakeEmpty(L2);    /*初始化顺序表*/
    MakeEmpty(L3);    /*初始化顺序表*/
    CreateList(L1);     /*输入测试用例*/
    //Print(L1);
    CreateList(L2);     /*输入测试用例*/
    //Print(L2);
    Merge(L1, L2, L3);    /*有序顺序表的合并*/
    Print(L3);                  /*输出新表*/
    return 0;
}
#include <iostream>
using namespace std;

typedef struct node
{
    char data;
    struct node* lchild, * rchild;
} binnode, * bintree;

void CreateBinTree(bintree& T);
binnode* PreLast(bintree T);
binnode* PostFirst(bintree T);

binnode* PostFirst(bintree T)
{
    binnode* current = NULL;
    if (T != NULL)
    {
        binnode* leftChild = PostFirst(T->lchild);
        binnode* rightChild = PostFirst(T->rchild);
        if (leftChild != NULL)
            current = leftChild;
        else if (rightChild != NULL)
            current = rightChild;
        else
            current = T;
    }

    return current;
}

binnode* PreLast(bintree T)
{
    binnode* current = NULL;
    if (T != NULL)
    {
        current = T;
        binnode* leftChild = PreLast(T->lchild);
        binnode* rightChild = PreLast(T->rchild);
        if (rightChild != NULL)
            current = rightChild;
        else if (leftChild != NULL)
            current = leftChild;
    }

    return current;
}

void CreateBinTree(bintree& T)
{
    char ch;
    ch=getchar();
    if (ch == '#')
        T = NULL;
    else
    {
        T = new binnode;
        T->data = ch;
        CreateBinTree(T->lchild);
        CreateBinTree(T->rchild);
    }
}

int main()
{
    bintree t, p;
    CreateBinTree(t);
    cout << "The PreLast is: ";
    p = PreLast(t);
    if (p == NULL)
        cout << "null";
    else
        cout << p->data;
    cout << endl << "The PostFirst is: ";
    p = PostFirst(t);
    if (p == NULL)
        cout << "null";
    else
        cout << p->data;
    return 0;
}
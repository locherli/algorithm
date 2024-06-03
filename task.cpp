#include <iostream>
using namespace std;

typedef int datatype;
typedef struct ListNode {
	datatype data;
	struct ListNode* next;
}LNode, * LinkList;

/*单链表创建*/
void CreateList(LinkList& L);

/*其中L是用户传入的带头节点单链表的头指针,L是引用类型；函数Reverse将链表L逆置。*/
void Reverse(LinkList& L);

/*顺序输出链表每个结点，每个结点元素值以空格符间隔，以换行符结束。 */
void DispList(LinkList L);


/*其中L是用户传入的带头节点单链表的头指针,L是引用类型；函数Reverse将链表L逆置。*/
void Reverse(LinkList& L)
{

	LNode* current = L;
	LNode* prev = NULL;
	LNode* next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	L = prev;
}





int main()
{
    LinkList L;
    CreateList(L); //创建带头节点的单链表
    Reverse(L);
    DispList(L);
    return 0;
}
/*单链表创建*/
void CreateList(LinkList& L)
{
    LNode* r, * s;
    datatype x;
    L = r = new LNode;  //生成新节点作为头节点，用头指针L指向。
    cin >> x;
    while (x != -1)
    {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
}
/*顺序输出链表每个结点，每个结点元素值以逗号间隔，以换行符结束。 */
void DispList(LinkList L)
{
    LNode* p = L->next;
    if (p == NULL) cout << "The List is NULL!" << endl;
    else
    {
        cout << "The List is : " << p->data;
        for (p = p->next; p; p = p->next) cout << " , " << p->data;
        cout << endl;
    }
}
#include <iostream>
using namespace std;

typedef int datatype;
typedef struct ListNode {
	datatype data;
	struct ListNode* next;
}LNode, * LinkList;

/*��������*/
void CreateList(LinkList& L);

/*����L���û�����Ĵ�ͷ�ڵ㵥�����ͷָ��,L���������ͣ�����Reverse������L���á�*/
void Reverse(LinkList& L);

/*˳���������ÿ����㣬ÿ�����Ԫ��ֵ�Կո��������Ի��з������� */
void DispList(LinkList L);


/*����L���û�����Ĵ�ͷ�ڵ㵥�����ͷָ��,L���������ͣ�����Reverse������L���á�*/
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
    CreateList(L); //������ͷ�ڵ�ĵ�����
    Reverse(L);
    DispList(L);
    return 0;
}
/*��������*/
void CreateList(LinkList& L)
{
    LNode* r, * s;
    datatype x;
    L = r = new LNode;  //�����½ڵ���Ϊͷ�ڵ㣬��ͷָ��Lָ��
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
/*˳���������ÿ����㣬ÿ�����Ԫ��ֵ�Զ��ż�����Ի��з������� */
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
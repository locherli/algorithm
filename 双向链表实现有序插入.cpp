#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	string name;
	int age;
	Person* last;
	Person* next;

	// ���캯��
	Person(const string& name, int age) : name(name), age(age), last(NULL), next(NULL) {}

	// �Ƚ����������
	bool operator>(const Person& p) const { return this->age > p.age; }
	bool operator<(const Person& p) const { return this->age < p.age; }
	bool operator==(const Person& p) const { return this->age == p.age; }
};

// �����½ڵ�
Person* createNode(const string& name, int age)
{
	return new Person(name, age);
}

// ��ӽڵ㵽����
Person* addNode(Person** phead, string name, int age)
{
	Person* newNode = createNode(name, age);
	if (*phead == NULL) {
		// �������Ϊ�գ��½ڵ��Ϊͷ�ڵ�
		*phead = newNode;
		return newNode;
	}

	Person* current = *phead;
	while (current->next != NULL) {
		// �ҵ����ʵ�λ�ò����½ڵ�
		if (newNode->age < current->age)
		{
			newNode->next = current;
			newNode->last = current->last;
			current->last->next = newNode;
			current->last = newNode;
			return newNode;
		}
		current = current->next;
	}//������β�ڵ�����ѭ��
	if (current->age > newNode->age)//��β�ڵ���½ڵ��
	{
		newNode->next = current;
		newNode->last = current->last;
		current->last->next = newNode;
		current->last = newNode;
	}

	// ����½ڵ��������ڻ���ڵ�ǰ�ڵ�����䣬���ߵ�ǰ�ڵ���β�ڵ�
	newNode->next = NULL;
	current->next = newNode;
	newNode->last = current;
	return newNode;
}
//��ӡ����
void printList(Person* head)
{
	Person* current = head;
	while (current->next != NULL)
	{
		cout << current->name << " is " << current->age << " years old now" << endl;
		current = current->next;
	}
	cout << current->name << " is " << current->age << " years old now" << endl;
}

int main() {
	Person p1("a", 1);
	Person* head = &p1;
	addNode(&head, "c", 2);
	addNode(&head, "c", 2); 
	addNode(&head, "b", 23);
	addNode(&head, "mikk", 563);
	printList(head);
	return 0;
}

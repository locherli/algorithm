#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	string name;
	int age;
	Person* last;
	Person* next;

	// 构造函数
	Person(const string& name, int age) : name(name), age(age), last(NULL), next(NULL) {}

	// 比较运算符重载
	bool operator>(const Person& p) const { return this->age > p.age; }
	bool operator<(const Person& p) const { return this->age < p.age; }
	bool operator==(const Person& p) const { return this->age == p.age; }
};

// 创建新节点
Person* createNode(const string& name, int age)
{
	return new Person(name, age);
}

// 添加节点到链表
Person* addNode(Person** phead, string name, int age)
{
	Person* newNode = createNode(name, age);
	if (*phead == NULL) {
		// 如果链表为空，新节点成为头节点
		*phead = newNode;
		return newNode;
	}

	Person* current = *phead;
	while (current->next != NULL) {
		// 找到合适的位置插入新节点
		if (newNode->age < current->age)
		{
			newNode->next = current;
			newNode->last = current->last;
			current->last->next = newNode;
			current->last = newNode;
			return newNode;
		}
		current = current->next;
	}//遍历到尾节点跳出循环
	if (current->age > newNode->age)//若尾节点比新节点大
	{
		newNode->next = current;
		newNode->last = current->last;
		current->last->next = newNode;
		current->last = newNode;
	}

	// 如果新节点的年龄大于或等于当前节点的年龄，或者当前节点是尾节点
	newNode->next = NULL;
	current->next = newNode;
	newNode->last = current;
	return newNode;
}
//打印链表
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

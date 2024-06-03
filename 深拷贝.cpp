#include <iostream>
#include <string>
using namespace std;

class Person//define class
{
public:
	int m_age;
	int* m_height;
	Person()
	{
		cout << "default construct function" << endl;
	}
	Person(int age, int height)//construct
	{
		m_age = age;
		m_height = new int(height);
	}
	Person(const Person& p)//copy function
	{
		m_age = p.m_age;
		m_height = new int(*p.m_height);
	}
	~Person()//deconstruct
	{
		if (m_height != NULL)
		{
			delete(m_height);
			m_height = NULL;
			cout << "free the space of height" << endl;
		}
	}
};
int main()
{
	Person p1(18, 180);
	Person p2(p1);
	cout << p1.m_age << " " << *p1.m_height << endl;
	cout << p2.m_age << " " << *p2.m_height << endl;

	return 0;
}



















#include <iostream>
#include <string>
using namespace std;

template <typename nametype,typename agetype>
class Person
{
public:
	nametype m_name;
	agetype m_age;
	Person(nametype name, agetype age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	void showInfo()
	{
		cout << this->m_age << ' ' << this->m_name << endl;
	}
};
//HOW TO PASS A CLASS OBJECT TO A FUNCTION AS AN ARGUMENT.

//1.assign the type of arguments in the function you want to invoke.
void showInfo1(Person<string, int>& p)
{
	p.showInfo();
}


//2.use template function.(templatize the arguments)
template <typename T1,typename T2>
void showInfo2(Person<T1, T2>& p)
{
	p.showInfo();
}

//3.use template function.(templatize the whole class)
template <class C>
void showInfo3(C& p)
{
	p.showInfo();
}


int main()
{
	Person<string, int> alen("alen", 19);
	//invoke the function in class through class object.
	alen.showInfo();

	//invoke function in 1st method.
	showInfo1(alen);
	//invoke function in 2ed method.
	showInfo2(alen);
	//invoke function in 3rd method.
	showInfo3(alen);

	return 0;
}
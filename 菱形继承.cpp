#include <iostream>
using namespace std;

//definition 
class Animal
{
public:
	int m_age;
};
//when virtual inherit is used , there is only one piece of data. 
class Sheep :virtual public Animal { };
class Camel :virtual public Animal { };
class Alpaca : public Sheep,public Camel { };
int main()
{
	Alpaca alpaca;
	//or use scope name to avoid ambiguity.
	alpaca.Sheep::m_age = 10;
	alpaca.Camel::m_age = 20;
	cout << "sheep's age:" << alpaca.Sheep::m_age << endl;
	cout << "Camel's age:" << alpaca.Camel::m_age << endl;
		return 0;
}
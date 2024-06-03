#include <iostream>
using namespace std;

//class definition
class Animal
{
public:
	virtual void speak()
	{
		cout << "animal make a sound." << endl;
	}
};

class Cat:public Animal
{
public:
	void speak()
	{
		cout << "cat make a sound." << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "dog make a sound." << endl;
	}
};

void dospeak(Animal& species)
{
	species.speak();
}

int main()
{
	Cat cat;
	Dog dog;
	dospeak(cat);
	dospeak(dog);

	return 0;
}
#include <iostream>
using namespace std;

//virtual function was writen in basic class 
class abstractDrink
{
public:
	virtual void boil() = 0;

	virtual void brew() = 0;

	virtual void pourInCup() = 0;

	virtual void putInSomething() = 0;


	void makeDrink()
	{
		boil();
		brew();
		pourInCup();
		putInSomething();
	}
};

//spicific fuction was writen in subclass
class makeCoffee:public abstractDrink
{
	virtual void boil()
	{
		cout << "boil the water" << endl;
	}

	virtual void brew()
	{
		cout << "brew the coffee bean" << endl;
	}

	virtual void pourInCup()
	{
		cout << "Pour in cup " << endl;
	}

	virtual void putInSomething()
	{
		cout << "put in coffee bean" << endl;
	}
};

class makeTea :public abstractDrink
{
	virtual void boil()
	{
		cout << "boil the water" << endl;
	}

	virtual void brew()
	{
		cout << "brew the leave of tea" << endl;
	}

	virtual void pourInCup()
	{
		cout << "Pour in cup " << endl;
	}

	virtual void putInSomething()
	{
		cout << "put in leave of bean" << endl;
	}
};

int main()
{
	makeCoffee coffee;
	coffee.makeDrink();

	cout << endl;

	makeTea tea;
	tea.makeDrink();

	return 0;
}

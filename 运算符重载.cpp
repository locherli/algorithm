#include <iostream>
#include <string>
using namespace std;

class complexNumber
{
public://member of the class
	int real_part;
	int imaginary_part;

	complexNumber operator- (complexNumber& p)//overload of "+"
	{
		complexNumber result;
		result.imaginary_part = this->imaginary_part - p.imaginary_part;
		result.real_part = this->real_part - p.real_part;
		return result;
	}

	complexNumber operator* (complexNumber& p)//overload of "*"
	{
		complexNumber result;
		result.imaginary_part = this->imaginary_part * p.real_part + this->real_part * p.imaginary_part;
		result.real_part = this->real_part * p.real_part - this->imaginary_part * p.imaginary_part;
		return result;
	}
};

int main()
{
	complexNumber c1, c2, c3, c4;
	cin >> c1.real_part >> c1.imaginary_part >> c2.real_part >> c2.imaginary_part;
	c3 = c1 - c2;
	c4 = c1 * c2;
	cout << "c3 is " << c3.real_part << "+" << c3.imaginary_part << "i" << endl;
	cout << "c4 is " << c4.real_part << "+" << c4.imaginary_part << "i" << endl;

	return 0;
}
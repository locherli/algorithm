#include <cmath>
#include <iostream>
using namespace std;

int digit(int num);

bool is_power_num(int num) 
{
	int sum = 0;
	int a;
	int temp = num;
	int lenght = digit(num);
	while (temp)
	{
		a = temp % 10;
		sum += pow(a, lenght);
		temp /= 10;
	}
	if (num==sum)
	{
		return 1;
	}

	return 0;
}

int digit(int num)
{
	int count=0;
	while (num)
	{
		num /= 10;
		count++;
	}
	return count;
}

int main() {
	int m, n;
	bool is = true;

	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		is = is_power_num(i);
		if (is==1)
		{
			cout << i << " ";
		}
	}

	return 0;
}
	//cout << is_power_num(3)<<" "<< digit(3);
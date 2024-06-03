#include <iostream>
using namespace std;

template <typename T>
//sort the array ,from small to big
void sort_select(T arr[], int num)
{
	int k;
	T temp;
	for (int i = 0; i < num; i++)
	{
		k = i;
		for (int j = k + 1; j < num; j++)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			temp = arr[k];
			arr[k] = arr[i];
			arr[i] = temp;
		}
	}
}

int main()
{
	char target[5] = { 'b','t','a','c','d' };
	sort_select(target, sizeof(target));
	for (int i = 0; i < sizeof(target); i++)
	{
		cout << target[i];
	}

	return 0;
}
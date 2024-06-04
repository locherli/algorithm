#include <iostream>
#include <string>
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void sort_select(T arr[], int n)
{
	int k,j;
	for (int i = 0; i < n; i++)
	{
		k = i;
		for ( j = k + 1;j < n; j++)
		{
			if (arr[k] > arr[j])
				k = j;
		}
		if (k != i)
			Swap(arr[k], arr[i]);

	}


}

int main()
{
	char arr[5] = { 's','a','b','t','s'};
	sort_select(arr, 5);
	for (auto& elem : arr)
		cout << elem << " ";


	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

#define SIZE 100
int addString(const char *src,const char *target)
{
	FILE* p = fopen(target, "a");
	if (p==NULL)
	{
		cout << "error";
		return -1;
	}
	else
	{
		fprintf(p, "%s", src);
		fclose(p);
		return 0;
	}
}
int main()
{
	char src[SIZE];
	char target[SIZE];
	cout << "enter the string you want to add:";
	cin.getline(src, SIZE);

	cout << endl;
	cout << "enter the target file:";
	cin.getline(target, SIZE);
	cout << endl;
	int result=addString(src, target);

	return result;
}
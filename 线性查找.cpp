
int lookup(int a[], int target, int n)//返回对应数组的下标
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == target)
		{
			return i;
		}
	}
	return -1;
}
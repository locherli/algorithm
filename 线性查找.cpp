
int lookup(int a[], int target, int n)//���ض�Ӧ������±�
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
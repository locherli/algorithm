#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble(int arr[], int n)
{
	for (int j = n-1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
			}
		}
	}
}
int main()//√∞≈›≈≈–Ú
{
	int arr[20],n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)//input
	{
		scanf("%d", &arr[i]);
	}
	bubble(arr,n);
	for (int o = 0; o < n; o++)//output
	{
		printf("%d ", arr[o]);
	}
	return 0;
}
//AI ver.
//void swap(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void bubble(int arr[], int n) {
//    for (int j = n - 1; j > 0; j--) {
//        for (int i = 0; i < j; i++) {
//            if (arr[i] > arr[i + 1]) {
//                swap(&arr[i], &arr[i + 1]);
//            }
//        }
//    }
//}
//
//int main() {
//    int arr[20], n;
//    printf("Enter the number of elements: ");
//    scanf("%d", &n);
//    printf("Enter the elements: ");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//    bubble(arr, n);
//    printf("Sorted array: ");
//    for (int o = 0; o < n; o++) {
//        printf("%d ", arr[o]);
//    }
//    return 0;
//}
#include <stdio.h>

void find_two_smallest(int arr[], int size, int* smallest1, int* smallest2) {
    /*
     * Finds the two smallest values in the given array.
     *
     * Parameters:
     *   arr: the input array
     *   size: the size of the array
     *   smallest1: a pointer to store the first smallest value
     *   smallest2: a pointer to store the second smallest value
     */

    if (size < 2) {
        *smallest1 = arr[0];
        *smallest2 = (size == 1) ? arr[0] : arr[1];
        return;
    }

    if (arr[0] < arr[1]) {
        *smallest1 = arr[0];
        *smallest2 = arr[1];
    }
    else {
        *smallest1 = arr[1];
        *smallest2 = arr[0];
    }

    for (int i = 2; i < size; i++) {
        if (arr[i] < *smallest1) {
            *smallest2 = *smallest1;
            *smallest1 = arr[i];
        }
        else if (arr[i] < *smallest2) {
            *smallest2 = arr[i];
        }
    }
}

int main() {
    int my_array[] = { 5, 2, 0, 2, 7, 3 };
    int size = sizeof(my_array) / sizeof(my_array[0]);
    int smallest1, smallest2;

    find_two_smallest(my_array, size, &smallest1, &smallest2);

    printf("The two smallest values are: %d and %d\n", smallest1, smallest2);

    return 0;
}
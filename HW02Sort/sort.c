// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int* arr, int size)
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
    int ind;
    for (ind = 0; ind < (size - 1); ind++)
    {
        if (arr[ind] > arr[ind + 1])
        {
            return false;
        }
    }
    return true;
}
void Swap(int* arr_1, int* arr_2)
{
    int temp; // temporary blank to store the value of the first array given
    temp = *arr_1;
    *arr_1 = *arr_2;
    *arr_2 = temp;
}

// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int* arr, int size)
{
    int i; // first array value that we want to compare
    int j; // second comparable array value
    int swap_value; // array value to be swaped
    for (i = 0; i < size - 1; i++)
    {
        swap_value = i;
        for (j = i; j < size; j++)
        {
            // a second value in the array is less than the first compared value
            if (arr[j] < arr[i])
            {
                swap_value = j;
                Swap(&arr[swap_value], &arr[i]); // swap compared values
            }
        }

    }
}
#endif

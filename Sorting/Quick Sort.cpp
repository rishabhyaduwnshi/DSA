#include <bits/stdc++.h>
using namespace std;

int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low;
    int j = high + 1;  // Start `j` at `high + 1` for proper decrement

    do
    {
        do { i++; } while (i <= high && array[i] <= pivot);  // Increment `i` until finding an element greater than the pivot or reaching the end
        do { j--; } while (array[j] > pivot);                // Decrement `j` until finding an element less than or equal to the pivot

        if (i < j)
            swap(array[i], array[j]);                        // Swap elements if `i` is still less than `j`
    } while (i < j);
    
    swap(array[low], array[j]);  // Place the pivot in the correct position
    return j;  // Return the index of the pivot
}

void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {
        int j = partition(array, low, high);
        quick_sort(array, low, j - 1);
        quick_sort(array, j + 1, high);
    }
}

int main()
{
    int array[] = {1, 2, 5, 3, 6, 4, 10, 9, 8, 7};
    int size = sizeof(array) / sizeof(int);
    quick_sort(array, 0, size - 1);
    
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

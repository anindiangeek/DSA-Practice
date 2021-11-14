#include <bits/stdc++.h>
using namespace std;

/*
    * We select an index, and find a suitable element for it. (min/ max).
    * Only Algorithm with minimum number of swaps.
    * Intermediate results are useful, each scan will give kth smallest element (opposite to bubble sort).
    * it is not Adaptive it will always take a min of O(n) time even if list is sorted.
    * The order of elements does not affect the sorting time. In other words, even if the array is partially sorted,
        still each element is compared and there is no breaking out early. Hence Selection sort is non-adaptable.
   Selection sort is NOT a stable sorting algorithm.
    * inplace ; do not requires extra space
*/

void SelectionSort(int a[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++) // we are starting from i as all earlier elements have been sorted already.
            if (a[i] > a[j])
                swap(a[i], a[j]);
}

int main()
{
    int a[] = {4, -9, 0, 3, 2, 4, 8, 5, 9};
    int size = sizeof(a) / sizeof(int);

    SelectionSort(a, size);

    for (size_t i = 0; i < size; i++)
        cout << a[i] << " ";
}
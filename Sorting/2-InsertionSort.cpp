#include <bits/stdc++.h>
using namespace std;
/*
                                                          IDEA
    * we assume that there is only one element in the list, and we Insert the element one by one in sorted order as the
        name suggest.
    * we start the first pass with 1 not 0 as we assume there is already one element in list.
    * there is a second pointer that points on i-1 (just before the first pass element).
    * we compare it preveious if it matches the condition then we chamge the value.
    * we store the value of the ith element as key we we will insert we insert it if it is already been inserted at
        right place.
                                                    >-> PROPERTIES <-<
    * Average case : O(n^2);  Best case : O(n) | swaps O(1); Worst case : O(n^2)
    * Intermediate results are not useful as we do not know whether the next elemente's location/value which will come.
    * ADAPTIVE in nature it takes min o(n) time if the list is sorted.
    * Stable; i.e., does not change the relative order of elements with equal keys
    * In-place; i.e., only requires a constant amount O(1) of additional memory space
    * Online; i.e., can sort a list as it receives it
    * It is desiged for LINKED-LIST as we do not have to move data in list we can change the order, copying data is
      expensive.

*/

void InsertionSort(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1, key = A[i];
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int a[] = {1, 3, 2, 9, 6, 4, 5};
    int size = sizeof(a) / sizeof(int);

    InsertionSort(a, size);

    for (size_t i = 0; i < size; i++)
        cout << a[i] << " ";
}
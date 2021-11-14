#include <bits/stdc++.h>
using namespace std;
/*

    * O(nlogn)-O(n^2); Avg case-O(nlogn)
    * this depends upon selction of pivot is the pivot is last or first element in a sorted data then it will be worst
      case i.e O(n^2); the pivot is generally taken in randomly faishon.

    * Tail recurssion optimisation for QuickSort : =>
       https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/



    * Below Implimentation is when we take first element as pivot , here we have to take and elemet large at the end of
      the list. ( Edit: there are two schemes
       https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/?ref=rp)
    * there are many implimentation of Quick Sort, we can choose pivot in an random faishon, mid or end element.
    * we have done this in less number of swaps than in shown in https://www.geeksforgeeks.org/quick-sort/.
    * Default Implimentation is NOT STABLE.
    * As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra
      space only for storing recursive function calls but not for manipulating the input.

    * QuickSort is preffered for Arrays than Lists. Why?
    * MergeSort is preffered for Lists than arrays. Why?


    Refrences.
    * https://en.wikipedia.org/wiki/Quicksort
    * https://www.geeksforgeeks.org/quick-sort/  <-- this is recemmonded for beginners.
*/

int Partition(int a[], int low, int high)
{
    // selecting pivot
    int pivot = a[low];

    // using two pointers to swap elements across the pivots.
    int i = low;
    int j = high;

    do
    {
        // incrimenting i till we find element smaller/equal ot pivot.
        do
        {
            i++;
        } while (a[i] <= pivot);

        // decrimenting j till we find element greater than pivot
        do
        {
            j--;
        } while (a[j] > pivot);

        // swap elements after finding so that we can get elements lesser than pivot on left nad greater on right
        if (i < j)
            swap(a[i], a[j]);

    } while (i < j);

    // swapping pivot to its appropiate location.
    swap(a[low], a[j]);

    // the partition point
    return j;
}

void QuickSort(int a[], int low, int high)
{
    // checking if we have enough elements to perfom sort
    if (low < high)
    {
        // getting the partition point.
        int p = Partition(a, low, high);

        // for sub-range 1
        QuickSort(a, low, p);

        // for sub-range 2
        QuickSort(a, p + 1, high);
    }
}

int main()
{
    // in input we will always consider the end element as largest in this case/method of QuickSort.
    int a[] = {1, 3, 2, 9, 6, 4, 5, INT_MAX};
    int size = sizeof(a) / sizeof(int);

    QuickSort(a, 0, size - 1);

    for (size_t i = 0; i < size - 1; i++)
        cout << a[i] << " ";
}
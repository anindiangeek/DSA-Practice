#include <bits/stdc++.h>
using namespace std;

/*
    * Basic Idea is we consider a single element as sorted list and we merge them into one sorted array, we use divide
        and conquer stragety.
    * T.C => worst & average O(nlogn); we require extra space O(n) (with O(1) in,lists).
    * It is a stable algorithm.
    * I t is not adaptive in nature it will make O(nlogn) comparisons generally but Natural Merge Sort is adaptive.
    * There are 3 methods
       -> Natural
       -> Top down
       -> Bottom up
    * Good for External Sorting.

    * Better for lists : Merge Sort is useful for sorting linked lists in O(nLogn) time. In the case of linked lists,
        the case is different mainly due to the difference in memory allocation of arrays and linked lists. Unlike
        arrays, linked list nodes may not be adjacent in memory. Unlike an array, in the linked list, we can insert
   items in the middle in O(1) extra space and O(1) time. Therefore, the merge operation of merge sort can be
   implemented without extra space for linked lists. In arrays, we can do random access as elements are contiguous in
   memory. Let us say we have an integer (4-byte) array A and let the address of A[0] be x then to access A[i], we can
   directly access the memory at (x + i*4). Unlike arrays, we can not do random access in the linked list. Quick Sort
   requires a lot of this kind of access. In a linked list to access i’th index, we have to travel each and every node
   from the head to i’th node as we don’t have a continuous block of memory. Therefore, the overhead increases for
   quicksort. Merge sort accesses data sequentially and the need of random access is low.


*/

void Merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    int b[high + 1]; // this is important

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];

    for (int i = low; i <= high; i++) // middle condition is important.
        a[i] = b[i];
}

void MergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
}

int main()
{
    int a[] = {2, 4, 1, 3, 5};
    int size = sizeof(a) / sizeof(int);

    MergeSort(a, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}
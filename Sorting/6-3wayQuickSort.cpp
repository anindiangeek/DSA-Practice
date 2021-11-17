#include <bits/stdc++.h>
using namespace std;
/*
    https://www.geeksforgeeks.org/3-way-quicksort-dutch-national-flag/

    * We use the DNF algorithm in sort the arrays only consisting of 0s,1s,2s in O(n) & in-place sorting them i.e in
   O(1) space.
    * Similarily we will use it here if the pivots are repeated in array.
    * we will choose a pivot and if we find values equal to pivot we it transfer it to middle.
    *       *a[l...mid-1] elements less than pivots
    *       *a[mid...mid_end] equal parts
    *       *a[mid_end...high] elements greater than pivots.
    * We then will perform quicksort on the left and right arrays.
*/

void SimplePartition(int a[], int low, int high, int &i, int &j)
{
    // i is initial pointer pointing .
    i = low - 1;

    // j pointer points at high now.
    j = high;

    // setting a pivot value.

    int pivot = a[high];

    // p is the index equivalent to i it will used to track the digits same as pivots on the left side of the array.
    int p = low - 1, q = high;

    while (i <= j)
    {
        // moving i till we find element greater than pivot.
        while (a[++i] < pivot)
            ;

        // moving j till we find element greater than pivot.
        while (pivot < a[--j])
            if (j == low)
                break;

        // if they cross each other then we will stop.
        if (i >= j)
            break;

        // we find such i & j which fulfils such condition then we will swap them.
        swap(a[i], a[j]);

        // We are moving all the element equal to pivot to starting of the subarrys.
        // by doing this we know how many equal elements we have.

        // of left subarray
        if (a[i] == pivot)
            swap(a[++p], a[i]);

        // of right sub array.
        if (a[j] == pivot)
            swap(a[j], a[--q]);
    }

    // moving pivot to it's right position.
    swap(a[i], a[high]);

    // shifting back the equal elements to near pivot.

    // Note we change j = pivot's index -1;
    j = i - 1;
    for (int k = low; i < p; k++, j--)
        swap(a[k], a[j]);

    // Note we change j = pivot's index + 1;
    i = i + 1;
    for (int k = high - 1; k > q; k--, i++)
        swap(a[i], a[k]);

    // new subaarys will be low to j & i to high
    // and j to i will be elements equal to pivots.
}


void QuickSort(int a[], int low, int high)
{
    // base condition if there are 0 or 1 elements in array.
    if (high <= low)
        return;

    int i, j;

    // i and j are passed as refrence.

    SimplePartition(a, low, high, i, j);

    // Notice here in recursive call we have low to j and i to high.

    // // left subarry
    QuickSort(a, low, j);

    // // right subarray
    QuickSort(a, i, high);
}

void DNFPartition(int a[], int low, int high, int &i, int &j)
{

    // if there are 2 elements
    if (high - low <= 1)
    {
        if (a[high] < a[low])
            swap(a[high], a[low]);
        i = low;
        j = high;
        return;
    }

    int mid = low;
    int pivot = a[high];
    while (mid <= high)
    {
        // uisng Dutch National Flag algorithm.
        if (a[mid] < pivot)
            swap(a[low++], a[mid++]);
        else if (a[mid] > pivot)
            swap(a[mid], a[high--]);
        else if (a[mid] == pivot)
            mid++;
    }

    i = low - 1;
    j = mid;
}

void DNFQuickSort(int a[], int low, int high)
{
    // base condition if there are 0 or 1 elements in array.
    if (high <= low)
        return;

    int i, j;

    // i and j are passed as refrence.

    DNFPartition(a, low, high, i, j);

    // Notice here in recursive call we have low to i and j to high, unlike previous.

    // // left subarry
    DNFQuickSort(a, low, i);

    // // right subarray
    DNFQuickSort(a, j, high);
}

int main()
{
    int a[] = {2, 34, 35, 34, 3, 41, 4, 4, 3, 1, 2, 3, 2, 3, 4, 4, 4, 3, 2, 1, 4};
    int size = sizeof(a) / sizeof(int);

    DNFQuickSort(a, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}
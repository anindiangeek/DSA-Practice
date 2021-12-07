/*
    * there are inbuilt search options in STL
        : binary_search()  -returns bool
        : max_element()     - return an iterator over the mmaximum element in a container
        : min_element()     - same as max_element()
        ... and more.

    * Binary search follows a DAC(divide and conquer) stragety, it can be implented in a recursive manner as well.
 */

#include <bits/stdc++.h>
using namespace std;

bool LinerSearch(int a[], int size, int key) // O(n) --> works on unsorted array/ sorted array
{
    for (int i = 0; i < size; i++)
        if (a[i] = key)
            return key;
    return false;
}

bool BinarySearch(int a[], int size, int key) // O(logn) --> works on sorted set of data only.
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + (high)) / 2; // L+H can lead to overflow you have Manage it.
        if (a[mid] > key)
            high = mid - 1;
        else if (a[mid] < key)
            low = mid + 1;
        else
            return true;
    }
    return false;
}

// recursive Binary Search

bool recursiveBinarySearch(int a[], int low, int high, int key)
{
    if (low == high)
    {
        if (a[low] == key)
            return true;
        else
            return false;
    }
    else
    {
        int mid = (low + high) / 2;
        if(a[mid]==key)
            return true;
        else if (a[mid] < key)
            return recursiveBinarySearch(a, mid + 1, high, key);
        else
            return recursiveBinarySearch(a, low, mid -1, key);
    }
}

int main()
{
    int a[] = {12, 34, 56, 87, 43, 234, 112, 33, 11, 23, 442, 10, 30, 13, 45, 235, 21};

    int size = sizeof(a) / sizeof(int);

    sort(a, a + size);
    cout << BinarySearch(a, size, 32) << endl;
    cout << recursiveBinarySearch(a, 0, size-1, 33) << endl;
}
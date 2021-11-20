#include <bits/stdc++.h>
using namespace std;
#define max_element 100

/*

    * There is an simple method for it which involves counting the frequecy of elements and then rescanning the
        frequency aay to make the actual sorted aay.
        but we need to have a definitive size of frequency aay and it should be minimum of maximum element in the
        original aay. i.e freq[maximum element in oirignal aay].
    * O(n+k) T.C | O(n+k) space Complexity ; here k is the maximum element present in input aay.
    * Not in-place sorting algorithm.

    * if it is known that the value is not repeated then we can use bit aay (bitset STL) to make it effecient
    * or to remove duplicates we can also do this.


    * It is not stable by default but it can be made stable.
        -> After counting the frequency we will find the cumulative sum of the frequency, and store it in ajacent index.
            why?
        -> It will give the starting index of the element, and will make the sorting algorithm stable.
        -> for more see this explanation: https://www.youtube.com/watch?v=OKd534EWcdk


        Special Case:
    * As the index cannot be negative we can't apply this algorithm directly to set involving -ve ints, we can modify it
        -> We will find the minimum element and keep it at index 0 and we will adjust the rest of elements accordingly.



*/

void StableCountSort(int a[], int size)
{
    int b[max_element] = {0};
    int output[max_element];
    for (int i = 0; i < size; i++)
        b[a[i]]++;

    // finding prefix sum.
    for (int i = 1; i <= max_element; i++)
        b[i] += b[i + 1];

    // this function is incomplete and requires attention.
}

void BasicCountSort(int a[], int size)
{
    int b[max_element] = {0}; // to b the frequency of the element.
    for (int i = 0; i < size; i++)
        b[a[i]]++;

    for (int i = 0, j = 0; i < max_element; i++)
        while (b[i]--)
            a[j++] = i;
}

int main()
{
    int a[] = {4, 5, 3, 76, 9, 2, 3, 6, 1, 5, 7, 11, 2, 4, 4, 5, 2, 2};
    int size = sizeof(a) / sizeof(int);
    // CountSort(a, size);

    // Stable count sort is not complete and requires attention.
    // StableCountSort(a, size);

    for (int x : a)
        cout << x << " ";
}
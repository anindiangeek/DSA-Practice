#include <bits/stdc++.h>
using namespace std;
/*
    * Unlike Iterative Quick sort we do not have to use stack.
    * We use a bottom up approach : we consider a single element in the list sorted and merge it with another single
    element.
    * then we merge those list again by taking 2 sorted array of size 2... and continuw will we reach size of list.
    * Important thing to note is that if the n is odd then there will be an element left with us. which we have to merge
        later.
    * takes O(nlogn) time.
    * is stable.
*/
// simple 2-way merging function which merges two sorted arrays.
void Merge(int a[], int low, int mid, int high)
{

    int i = low, j = mid + 1, k = low;

    int temp[high + 1]; // this is important

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // if there are any elements left in either of the arrays.
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];

    // assigning the values to the array from temperary array
    for (int i = low; i <= high; i++) // middle condition is important.
        a[i] = temp[i];
}

void IterativeMerge(int a[], int n)
{
    int p;
    for (p = 2; p <= n; p *= 2) // log2(n) passes.

        // loops for merging.
        for (int i = 0; i + p - 1 < n; i += p)
        {
            int high = i + p - 1;
            int low = i;

            int mid = (low + high) / 2;

            Merge(a, low, mid, high);
        }

    // if there are elements left in case when n is odd(not a multiple of 2), an element will be left to merge,
    // we will merge it to the whole array.
    if (p / 2 < n) // if n was 8 then when the loop was stoped it would've been 16 so p/2<n here
        Merge(a, 0, p / 2 - 1,
              n); // mergin the left element. p/2-1 is the end of the sorted list and rest reamins our left element.
}

int main()
{
    int a[] = {4, 2, 1, 3, 2};

    int size = sizeof(a) / sizeof(int);

    IterativeMerge(a, 5);

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}


#include <bits/stdc++.h>
using namespace std;

/*
 * O(n)<=BubbleSort<=O(n*n) => Time Complexity
 * This can also be done in LinkedList.
 * Moving data is costly and if data is big we generally do not move data, so this is not recemmoneded in LinkedList.
 * We use Insertion Sort instead of this.
 * ADAPTIVE in nature it takes min o(n) time if the list is sorted.
 * Stable; i.e., does not change the relative order of elements with equal keys
 * In-place; i.e., only requires a constant amount O(1) of additional memory space
 * Intermediate Results are useful, i.e each pass gives the (n-1)th max/min element.
 */

void BubbleSort(int A[], int n)
{
    // n-1 because we have to make n-1 pases
    for (int i = 0; i < n - 1; i++)
        // n-1-i because they are already sorted. in each pass a comparison should reduce.
        for (int j = 0; j < n - 1 - i; j++)
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]); // swap function is an inbuilt function. did not impliment it.
}

int main()
{

    int a[] = {2, 56, 32, 4, 1, 0};

    // we can give any index as second parameter, function will sort till there.
    int size = sizeof(a) / sizeof(int);
    BubbleSort(a, size);

    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
}
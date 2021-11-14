#include <bits/stdc++.h>
using namespace std;

/*
    As we know QuickSort is an Recursive algorithm
    we have to use stack as recursiion usses stack interally
    we store the necessary information in stack and perfrom operation on it and pop.
    I have used different method in Partition.
    for detailed inforamation and different partition : https://www.geeksforgeeks.org/iterative-quick-sort/

    this requires extra space.
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

        // swap elements after finding so that we can get elements lesser than pivot on left and greater on right
        if (i < j)
            swap(a[i], a[j]);

    } while (i < j);

    // swapping pivot to its appropiate location.
    swap(a[low], a[j]);

    // the partition point
    return j;
}

void IterativeQuickSort(int a[], int low, int high)
{
    stack<int> s;

    // keep note how you push elements you have to pop in same(No literally) order(lifo).
    s.push(low);
    s.push(high);

    while (!s.empty())
    {

        int h = s.top();
        s.pop();
        int l = s.top();
        s.pop();

        // getting the partition index.
        int p = Partition(a, l, h);

        // checking if left subarray exists
        if (p > l)
        {
            s.push(l);
            s.push(p);
        }

        // checking if right subarry exists
        if (p + 1 < h)
        {
            s.push(p + 1);
            s.push(h);
        }
    }
}

int main()
{
    int a[] = {1, 3, 2, 9, 6, 4, 5, INT_MAX};
    int size = sizeof(a) / sizeof(int);

    IterativeQuickSort(a, 0, 7);

    for (size_t i = 0; i < size; i++)
        cout << a[i] << " ";
}
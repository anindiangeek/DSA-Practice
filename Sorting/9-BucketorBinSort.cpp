#include <bits/stdc++.h>
using namespace std;
#define Maxsize 100
/*
    we keep putting items in "bins or buckets".
    * we make a array of lists (or head pointers) and push elements in it, of they are dame then we increase the size of
        each list.
    * Thus making it a STABLE algorithm.
    * it is similar to Count Sort.
    * It is not Adaptive.
    * It takes O(n) time.
    * not a comparison based sort.
    *  REPRESENTATION
    *   0  1  2  3  4  <-- Indexes
    *  \ |  | \ |  | \ | <-- Array of lists / pointers '\' denotes null.
    *      1     3
    *      v     v
    *      1     \
    *      \
    * we iterate over the array again and poping elements and our array sorted.
    * we need size upto maximum element of the number which is a draback.
    * Radix sort optimises it.
*/

// Poorly implimented using STL.
void BucketSort(int a[], int n)
{
    vector<list<int>> v(Maxsize); // min size of array should be the size of maximum element in array.

    for (int i = 0; i < n; i++)
        v[a[i]].push_back(a[i]);

    int index = 0;

    for (auto i = 0; i < Maxsize && index < n; i++)
    {
        while (!v[i].empty())
        {
            a[index++] = v[i].front();
            v[i].pop_front();
        }
    }
}
int main()
{
    int a[] = {3, 12, 4, 1, 6, 3, 7, 9, 4, 1, 2};
    //            ^ maximum element
    int size = sizeof(a) / sizeof(int);

    BucketSort(a, size);

    for (int x : a)
        cout << x << " ";
}
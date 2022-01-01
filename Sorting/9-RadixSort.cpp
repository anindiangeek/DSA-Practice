#include "8-CountSort.cpp"
#include <bits/stdc++.h>
using namespace std;
/*
    * Radix Sort uses count sort as it's subroutine.
    * Radix sort can also be implimented using bucket/bin sort.
    * 
    * 



*/

void CountRadixSort(int a[], int size)
{
    int NumberOfDigitsOfMaximumElement = log10(*max_element(a, a + size)) + 1;
    while (NumberOfDigitsOfMaximumElement--)
    {
        BasicCountSort()
    }
}
void BinBucketRadixSort(int a[], int size)
{
    int NumberOfDigitsOfMaximumElement = log10(*max_element(a, a + size)) + 1;
}

int main()
{
    int a[] = {2, 3, 1, 3, 12, 4, 12, 3, 4, 2, 341, 3, 456, 64, 2};

    int size = sizeof(a) / sizeof(int);
    BinBucketRadixSort(a, size);
    for (int x : a)
        cout << x << " ";
}
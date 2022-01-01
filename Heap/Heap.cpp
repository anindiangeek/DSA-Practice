#include "C:\Users\anind\Desktop\DSA\debug.h"
#include <bits/stdc++.h>

using namespace std;

void MakeHeap(vector<int> &v) // note: NOT heapify.
{
    for (int i = 2; i < v.size(); i++)
    {
        if (v[i] > v[i / 2])
        {
            int j = i;
            while (v[j] > v[j / 2] && j > 1) // swap till parent is smaller than child.
            {
                swap(v[j], v[j / 2]);
                j /= 2;
            }
        }
    }
}
void InsertHeap(vector<int> &v, int data)
{
    v.push_back(data);

    int j = v[v.size() - 1];

    while (v[j] > v[j / 2])
    {
        swap(v[j], v[j / 2]);
        j /= 2;
    }
}

void Heapify(vector<int> &v) // heapify takes O(n) time anlyticaly. Proof
                             // http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf
{
    // it's a bottom up approach. skipping the leaf nodes as they are not useful to process.

    // getting first subtree from below or first non-leaf node.
    int index = (v.size() - 1) / 2; // first non-leaf node.

    // iterating tree in reverse level order traversal.
    for (int i = index; i > 0; i++)
    {
		
    }
}

int main()
{
    vector<int> Heap(8, 10);
    Heap[0] = -1;
    inclusive_scan(Heap.begin() + 1, Heap.end(), Heap.begin() + 1);
    debugvector(Heap);
    MakeHeap(Heap);
    debugvector(Heap);
}
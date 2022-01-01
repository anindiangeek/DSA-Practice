#include <bits/stdc++.h>
using namespace std;

template <typename T> void debugvector(vector<T> &v)
{
    cerr << "[ ";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it == v.end() - 1)
            cerr << *it;
        else
            cerr << *it << ", ";
    }
    cerr << " ]";
    cerr << endl;
}
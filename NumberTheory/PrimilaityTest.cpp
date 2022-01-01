#include <bits/stdc++.h>
using namespace std;

bool NaiveisPrime(int Number) // O(n) --> Time Complexity
{
    if (Number == 1)
        return false;

    for (size_t i = 2; i < Number; i++)
        if (Number % i == 0)
            return false;

    return true;
}

bool isPrime(int Number) // O(√n) -> Time Complexity
{
    if (Number == 1)
        return false;

    for (size_t i = 2; (i * (i * 1ll)) <= Number; i++)
        if (Number % i == 0)
            return false;

    return true;
}

int main()
{
    cout << isPrime(9991) << endl;
}
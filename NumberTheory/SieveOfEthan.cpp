#include <bits/stdc++.h>
using namespace std;

auto sieve = bitset<10000009>{}.set();
void solve()
{
    int Range = 0, answer = 0;
    cin >> Range;

    for (size_t i = 2; i <= sqrt(Range); i++)
        if (sieve[i])
            for (size_t j = (long long)i * (i * 1ll); j <= Range; j += i)
                sieve.set(j, 0);

    for (size_t i = 2; i <= Range; i++)
        if (sieve[i])
            answer++;

    cout << answer << endl;

    for (size_t i = 2; i <= Range; i++)
        if (sieve[i])
            cout << i << " ";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> tmp(n + 1);
    vector<int> primes;

    for (int i = 1; i <= n; i++)
        tmp[i] = i;

    for (int i = 2; i * i <= n; i++)
    {
        if (tmp[i] == 0)
            continue;

        for (int j = i * i; j <= n; j += i)
            tmp[j] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
        if (tmp[i] != 0)
            primes.push_back(i);
    }

    int l = 0, r = 0;
    int sum = 0;
    int cnt = 0;

    while (l <= r)
    {
        if (sum >= n)
        {
            if (sum == n)
                cnt++;
            sum -= primes[l];
            l++;
        }
        else if (r == primes.size())
        {
            break;
        }
        else
        {
            sum += primes[r];
            r++;
        }
    }

    cout << cnt << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int M = 1000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> prime(M + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 0; i * i <= M; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= M; j += i)
                prime[j] = false;
        }
    }

    int n;
    cin >> n;

    while (n)
    {
        for (int i = 3; i < n; i++)
        {
            if (!prime[i] || !prime[n - i])
                continue;

            cout << n << " = " << i << " + " << n - i << '\n';
            break;
        }

        cin >> n;
    }
}

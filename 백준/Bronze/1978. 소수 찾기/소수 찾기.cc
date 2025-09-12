#include <bits/stdc++.h>
using namespace std;

int M = 1000;

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

    int t, sum = 0;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (prime[n])
            sum++;
    }

    cout << sum << '\n';
}

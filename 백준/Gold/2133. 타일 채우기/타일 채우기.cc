#include <bits/stdc++.h>
using namespace std;

int dp[31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        int v = 4;

        while (v <= i)
        {
            dp[i] += (dp[i - v] * 2);
            v += 2;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, dp[1000001] = { 0, 0, 1, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    cout << dp[n] << '\n';

    return 0;
}

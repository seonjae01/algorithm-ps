#include <bits/stdc++.h>
using namespace std;

int t[16], p[16], dp[16];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, mx = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + t[i] <= n + 1)
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
    }

    for (int i = 1; i <= n+1; i++)
        mx = max(mx, dp[i]);
    cout << mx << '\n';

    return 0;
}

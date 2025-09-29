#include <bits/stdc++.h>
using namespace std;

int dp[100001] = { 0, 1, 2, 3 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, mn = 100001;
    cin >> n;

    if (n <= 3)
    {
        cout << dp[n] << '\n';
        return 0;
    }

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j <= sqrt(i); j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    cout << dp[n] << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int tri[501][501];
int dp[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> tri[i][j];
    
    dp[1][1] = tri[1][1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][1] + tri[i][1];
        for (int j = 2; j < i; j++)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
        dp[i][i] = dp[i - 1][i - 1] + tri[i][i];
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max(mx, dp[n][i]);
    cout << mx << '\n';

    return 0;
}

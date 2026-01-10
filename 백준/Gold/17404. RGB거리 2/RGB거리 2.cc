#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int color[1001][3];
int dp[1001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mn = INF;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> color[i][0] >> color[i][1] >> color[i][2];

    // 1 : R
    dp[1][0] = color[1][0];
    dp[1][1] = dp[1][2] = INF;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
    }
    mn = min(mn, min(dp[n][1], dp[n][2]));

    // 1 : G
    dp[1][1] = color[1][1];
    dp[1][0] = dp[1][2] = INF;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
    }
    mn = min(mn, min(dp[n][0], dp[n][2]));

    // 1 : B
    dp[1][2] = color[1][2];
    dp[1][0] = dp[1][1] = INF;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
    }
    mn = min(mn, min(dp[n][0], dp[n][1]));

    cout << mn << '\n';

    return 0;
}

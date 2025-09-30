#include <bits/stdc++.h>
using namespace std;

int rgb[1001][3];
int dp[1001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';

    return 0;
}

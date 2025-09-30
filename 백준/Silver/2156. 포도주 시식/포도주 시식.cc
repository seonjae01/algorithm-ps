#include <bits/stdc++.h>
using namespace std;

int grape[10001];
int dp[10001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> grape[i];

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = dp[i - 1][0] + grape[i];
        dp[i][2] = dp[i - 1][1] + grape[i];
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
    return 0;
}

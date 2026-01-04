#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int cost[21], cus[21];
int dp[2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, n;
    cin >> c >> n;

    fill(dp, dp + c + 101, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
        cin >> cost[i] >> cus[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = cus[i]; j <= c + 100; j++)
            dp[j] = min(dp[j], dp[j - cus[i]] + cost[i]);
    }

    int mn = INF;
    for (int i = c; i <= c + 100; i++)
        mn = min(mn, dp[i]);
    cout << mn << '\n';

    return 0;
}

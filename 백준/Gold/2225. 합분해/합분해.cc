#include <bits/stdc++.h>
using namespace std;

long long M = 1000000000;
long long dp[401][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    dp[0][1] = 1;

    for (int i = 1; i <= n + k; i++)
        for (int j = 1; j <= k; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;

    cout << dp[n + 1][k] << '\n';

    return 0;
}

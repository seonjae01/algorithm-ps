#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[101][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;

    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][1]) % 1000000000;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 1000000000;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % 1000000000;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % 1000000000;
        dp[i][4] = (dp[i - 1][3] + dp[i - 1][5]) % 1000000000;
        dp[i][5] = (dp[i - 1][4] + dp[i - 1][6]) % 1000000000;
        dp[i][6] = (dp[i - 1][5] + dp[i - 1][7]) % 1000000000;
        dp[i][7] = (dp[i - 1][6] + dp[i - 1][8]) % 1000000000;
        dp[i][8] = (dp[i - 1][7] + dp[i - 1][9]) % 1000000000;
        dp[i][9] = (dp[i - 1][8]) % 1000000000;
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5] + dp[n][6] + dp[n][7] + dp[n][8] + dp[n][9]) % 1000000000 << '\n';

    return 0;
}

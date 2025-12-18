#include <bits/stdc++.h>
using namespace std;

int stair[301];
int dp[301][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> stair[i];

    dp[1][0] = stair[1];
    dp[2][0] = stair[2];
    dp[2][1] = stair[1] + stair[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = stair[i] + max(dp[i - 2][0], dp[i - 2][1]);
        dp[i][1] = stair[i] + dp[i - 1][0];
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';

    return 0;
}

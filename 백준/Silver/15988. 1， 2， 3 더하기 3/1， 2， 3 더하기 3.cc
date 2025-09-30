#include <bits/stdc++.h>
using namespace std;

long long M = 1000000009;
long long dp[1000001] = { 0, 1, 2, 4 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    for (int i = 4; i <= 1000001; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % M;

    while (t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}

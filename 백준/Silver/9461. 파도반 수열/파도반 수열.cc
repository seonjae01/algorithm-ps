#include <bits/stdc++.h>
using namespace std;

long long dp[101] = { 0, 1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 3; i < 101; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}

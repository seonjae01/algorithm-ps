#include <bits/stdc++.h>
using namespace std;

long long dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    for (int i = 1; i <= n; i++)
        dp[i] = dp[i - 1] + nums[i];

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << '\n';
    }

    return 0;
}

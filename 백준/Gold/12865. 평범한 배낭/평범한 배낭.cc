#include <bits/stdc++.h>
using namespace std;

int W[101], V[101];
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> W[i] >> V[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= W[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        }
    }

    cout << dp[k] << '\n';

    return 0;
}

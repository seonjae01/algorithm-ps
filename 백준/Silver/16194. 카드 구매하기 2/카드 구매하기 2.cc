#include <bits/stdc++.h>
using namespace std;

int n, dp[1001];
vector<int> cards;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cards.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> cards[i];
        dp[i] = cards[i];

        for (int j = 1; j < i; j++)
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
    }

    cout << dp[n] << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int cnt = 0;
    vector<int> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end(), greater<int>());

    for (int coin : coins)
    {
        if (coin <= m)
        {
            cnt += (m / coin);
            m %= coin;
        }
    }

    cout << cnt << '\n';

    return 0;
}

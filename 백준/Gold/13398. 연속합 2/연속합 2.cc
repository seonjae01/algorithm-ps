#include <bits/stdc++.h>
using namespace std;

int dp[100001], dpDel[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    int mx = arr[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        dpDel[i] = max(dpDel[i - 1] + arr[i], dp[i - 1]);
        mx = max(mx, max(dp[i], dpDel[i]));
    }

    cout << mx << '\n';

    return 0;
}

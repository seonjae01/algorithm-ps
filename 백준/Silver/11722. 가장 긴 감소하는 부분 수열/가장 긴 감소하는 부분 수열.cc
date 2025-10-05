#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, mx = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] < arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        mx = max(mx, dp[i]);
    }

    cout << mx << '\n';

    return 0;
}

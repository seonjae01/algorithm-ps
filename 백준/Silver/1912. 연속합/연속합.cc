#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, mx;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    dp[0] = nums[0];
    mx = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        mx = max(mx, dp[i]);
    }

    cout << mx << '\n';

    return 0;
}

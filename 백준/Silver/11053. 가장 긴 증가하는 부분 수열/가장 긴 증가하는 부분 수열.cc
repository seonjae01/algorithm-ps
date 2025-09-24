#include <bits/stdc++.h>
using namespace std;

int n, mx, dp[1001];
vector<int> nums;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    nums.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        mx = max(mx, dp[i]);
    }

    cout << mx << '\n';

    return 0;
}

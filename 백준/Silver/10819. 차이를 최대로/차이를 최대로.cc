#include <bits/stdc++.h>
using namespace std;

int n, mx = 0;
vector<int> path, nums;
vector<bool> visited;

void solve()
{
    if (path.size() == n)
    {
        int sum = 0;

        for (int i = 0; i < n - 1; i++)
            sum += abs(nums[path[i]] - nums[path[i + 1]]);
        mx = max(mx, sum);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        path.push_back(i);
        solve();
        visited[i] = false;
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    nums.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    solve();
    cout << mx << '\n';

    return 0;
}

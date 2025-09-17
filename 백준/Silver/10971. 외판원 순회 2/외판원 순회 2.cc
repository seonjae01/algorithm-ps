#include <bits/stdc++.h>
using namespace std;

int n, mn = 1e9;
vector<int> path;
vector<vector<int>> nums;
vector<bool> visited;

void solve()
{
    if (path.size() == n)
    {
        if (nums[path[n - 1]][path[0]] == 0)
            return;

        int sum = nums[path[n - 1]][path[0]];

        for (int i = 0; i < n - 1; i++)
        {
            int r = nums[path[i]][path[i + 1]];
            if (r == 0)
                return;

            sum += r;
        }

        mn = min(mn, sum);
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

    nums.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> nums[i][j];

    solve();
    cout << mn << '\n';

    return 0;
}

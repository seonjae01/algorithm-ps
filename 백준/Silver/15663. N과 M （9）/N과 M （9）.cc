#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
vector<int> result;
vector<bool> visited;
vector<vector<int>> graph;

void solve(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    int prev = -1;

    for (int i = 0; i < n; i++)
    {
        if (prev == nums[i] || visited[i])
            continue;

        visited[i] = true;
        prev = nums[i];
        result[cnt] = nums[i];
        solve(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nums.assign(n, 0);
    result.assign(n, 0);
    visited.assign(n, false);
    graph.assign(n, {});

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    solve(0);

    return 0;
}

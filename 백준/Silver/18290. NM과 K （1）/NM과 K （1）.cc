#include <bits/stdc++.h>
using namespace std;

int mx = -1000001;
int n, m, k;
vector<vector<int>> nums;
vector<vector<bool>> visited;

void solve(int cur, int cnt)
{
    if (cnt == k)
    {
        mx = max(mx, cur);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                continue;
            if (i > 0 && visited[i - 1][j])
                continue;
            if (i < n - 1 && visited[i + 1][j])
                continue;
            if (j > 0 && visited[i][j - 1])
                continue;
            if (j < m - 1 && visited[i][j + 1])
                continue;

            visited[i][j] = true;
            solve(cur + nums[i][j], cnt + 1);
            visited[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    nums.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> nums[i][j];

    solve(0, 0);
    cout << mx << '\n';

    return 0;
}

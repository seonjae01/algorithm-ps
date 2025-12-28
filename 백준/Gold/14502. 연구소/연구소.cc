#include <bits/stdc++.h>
using namespace std;

int n, m, mx;
int grid[10][10];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

void solve()
{
    int cnt = 0;
    int temp[10][10];
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = grid[i][j];
            if (temp[i][j] == 2)
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if (temp[ny][nx] == 0)
            {
                q.push({ny, nx});
                temp[ny][nx] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
                cnt++;
        }
    }

    mx = max(mx, cnt);
}

void wall(int k)
{
    if (k == 3)
    {
        solve();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][j] = 1;
                wall(k + 1);
                grid[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    wall(0);
    cout << mx << '\n';

    return 0;
}

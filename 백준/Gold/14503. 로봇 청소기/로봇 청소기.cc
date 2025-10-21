#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<int>> grid;
vector<vector<bool>> visited;

map<int, pair<int, int>> dirMap = {
    {0, {-1, 0}}, {1, {0, 1}}, {2, {1, 0}}, {3, {0, -1}}
};

void solve()
{
    while (1)
    {
        if (!visited[r][c])
            visited[r][c] = true;

        bool nei = false;
        for (int i = 0; i < 4; i++)
        {
            int ny = r + dy[i];
            int nx = c + dx[i];
            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1)
                continue;

            if (grid[ny][nx] == 0 && !visited[ny][nx])
            {
                nei = true;
                break;
            }
        }

        if (!nei)
        {
            auto [y, x] = dirMap[d];
            int ny = r - y;
            int nx = c - x;

            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1 || grid[ny][nx] == 1)
                return;

            r = ny;
            c = nx;
        }
        else
        {
            d--;
            if (d < 0)
                d = 3;

            auto [y, x] = dirMap[d];
            int ny = r + y;
            int nx = c + x;

            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1)
                continue;

            if (grid[ny][nx] == 0 && !visited[ny][nx])
            {
                r = ny;
                c = nx;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r >> c >> d;
    grid.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    solve();
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                cnt++;
        }
    }

    cout << cnt << '\n';
}

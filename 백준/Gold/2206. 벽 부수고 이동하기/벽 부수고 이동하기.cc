#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1001][1001];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int visited[1001][1001][2];

int solve()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty())
    {
        auto [y, x, b] = q.front();
        q.pop();

        if (y == n - 1 && x == m - 1)
            return visited[y][x][b];

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if (grid[ny][nx] == '0' && visited[ny][nx][b] == 0)
            {
                visited[ny][nx][b] = visited[y][x][b] + 1;
                q.push({ny, nx, b});
            }

            if (grid[ny][nx] == '1' && b == 0 && visited[ny][nx][1] == 0)
            {
                visited[ny][nx][1] = visited[y][x][0] + 1;
                q.push({ny, nx, 1});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
            grid[i][j] = s[j];
    }

    cout << solve() << '\n';

    return 0;
}

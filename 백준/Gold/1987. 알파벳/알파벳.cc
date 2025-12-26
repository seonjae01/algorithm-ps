#include <bits/stdc++.h>
using namespace std;

int n, m, mx;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
char grid[21][21];
map<char, bool> visited;

void dfs(int y, int x, int cnt)
{
    visited[grid[y][x]] = true;
    mx = max(mx, cnt);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (visited[grid[ny][nx]])
            continue;

        visited[grid[ny][nx]] = true;
        dfs(ny, nx, cnt + 1);
        visited[grid[ny][nx]] = false;
    }
}

int main() {
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

    dfs(0, 0, 1);
    cout << mx << '\n';

    return 0;
}

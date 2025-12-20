#include <bits/stdc++.h>
using namespace std;

int n;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
vector<string> color;
vector<vector<int>> visited;

bool isSameColor(int y, int x, char c, bool isBlind)
{
    char cur = color[y][x];

    if (!isBlind)
    {
        return c == cur;
    }
    else
    {
        if (cur == 'B')
            return c == 'B';
        else
            return c != 'B';
    }
}

void bfs(int y, int x, bool isBlind)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = r + dy[i];
            int nx = c + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (visited[ny][nx] == 1 || !isSameColor(ny, nx, color[r][c], isBlind))
                continue;

            q.push({ny, nx});
            visited[ny][nx] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    color.assign(n, "");
    visited.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        cin >> color[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                bfs(i, j, false);
                cnt++;
            }
        }
    }

    cout << cnt << ' ';
    cnt = 0;
    visited.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                bfs(i, j, true);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}

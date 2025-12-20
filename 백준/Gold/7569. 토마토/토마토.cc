#include <bits/stdc++.h>
using namespace std;

struct Pos
{
    int x, y, z;
};

int tomato[101][101][101];
int dist[101][101][101];
int dx[6] = { 0, 0, -1, 0, 0, 1 };
int dy[6] = { 0, -1, 0, 0, 1, 0 };
int dz[6] = { -1, 0, 0, 1, 0, 0 };

void solve(int n, int m, int h)
{
    queue<Pos> q;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (tomato[i][j][k] == 1)
                {
                    q.push({i, j, k});
                    dist[i][j][k] = 1;
                }
            }
        }
    }

    while (!q.empty())
    {
        auto [z, y, x] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (tomato[nz][ny][nx] == -1 || dist[nz][ny][nx] != 0)
                continue;

            q.push({nz, ny, nx});
            dist[nz][ny][nx] = dist[z][y][x] + 1;
        }
    }

    int mx = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (tomato[i][j][k] == -1)
                    continue;

                if (dist[i][j][k] == 0)
                {
                    cout << -1 << '\n';
                    return;
                }
                else
                {
                    mx = max(mx, dist[i][j][k]);
                }
            }
        }
    }

    cout << mx - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, h;
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
                cin >> tomato[i][j][k];
        }
    }

    solve(n, m, h);

    return 0;
}

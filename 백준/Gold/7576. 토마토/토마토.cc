#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int y, x, cnt;
};

int n, m, mx = 0;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
vector<vector<int>> graph;

void solve()
{
    queue<Node> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 1)
                q.push({i, j, 0});
        }
    }

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        int u = p.y;
        int v = p.x;
        mx = max(mx, p.cnt);

        for (int i = 0; i < 4; i++)
        {
            int ny = u + dy[i];
            int nx = v + dx[i];

            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1)
                continue;

            if (graph[ny][nx] == 0)
            {
                graph[ny][nx] = 1;
                q.push({ny, nx, p.cnt + 1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> m >> n;
    graph.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];

    solve();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0)
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << mx << '\n';
    return 0;
}

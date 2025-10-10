#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int y, x, len;
};

int n, m;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
vector<vector<int>> graph;
vector<vector<bool>> visited;

void bfs()
{
    queue<Node> q;
    q.push({0, 0, 1});
    visited[0][0] = true;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        int u = p.y;
        int v = p.x;

        if (u == n - 1 && v == m - 1)
        {
            cout << p.len << ' ';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = u + dy[i];
            int nx = v + dx[i];

            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1)
                continue;

            if (!visited[ny][nx] && graph[ny][nx] == 1)
            {
                visited[ny][nx] = true;
                q.push({ny, nx, p.len + 1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> n >> m;
    graph.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            graph[i][j] = s[j] - '0';
    }

    bfs();
    return 0;
}

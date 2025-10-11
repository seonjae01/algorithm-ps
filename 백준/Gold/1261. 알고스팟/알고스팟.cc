#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int y, x, cnt;
};

int n, m;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

void solve()
{
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<int>> graph(n, vector<int>(m));
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            graph[i][j] = s[j] - '0';
    }

    deque<Node> q;
    q.push_back({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        auto [y, x, cnt] = q.front();
        q.pop_front();

        if (y == n - 1 && x == m - 1)
        {
            cout << cnt << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1)
                continue;

            if (!visited[ny][nx])
            {
                if (graph[ny][nx] == 0)
                    q.push_front({ny, nx, cnt});
                else
                    q.push_back({ny, nx, cnt + 1});
                visited[ny][nx] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    solve();
    return 0;
}

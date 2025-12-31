#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[101][101];
bool visited[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void bfs()
{
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({0, 0});

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

            if (grid[ny][nx] == 0 && !visited[ny][nx])
            {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
}

bool isContact(int y, int x)
{
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (grid[ny][nx] == 0 && visited[ny][nx])
            cnt++;
    }

    return cnt >= 2;
}

int solve()
{
    int time = 0;

    while (true)
    {
        bfs();
        vector<pair<int, int>> melt;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && isContact(i, j))
                    melt.push_back({i, j});
            }
        }

        if (melt.empty())
            return time;

        for (auto e : melt)
            grid[e.first][e.second] = 0;

        time++;
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
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    cout << solve() << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Shark
{
    int y, x, size, eatCnt, time;
} shark;

struct Fish
{
    int dist, y, x;
};

int n, grid[21][21];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

Fish bfs()
{
    int visited[21][21];
    memset(visited, -1, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({shark.y, shark.x});
    visited[shark.y][shark.x] = 0;

    vector<tuple<int, int, int>> candi;

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (visited[ny][nx] != -1 || grid[ny][nx] > shark.size)
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});

            if (grid[ny][nx] != 0 && grid[ny][nx] < shark.size)
                candi.push_back({visited[ny][nx], ny, nx});
        }
    }

    if (candi.empty())
        return { -1, -1, -1 };

    sort(candi.begin(), candi.end());
    auto [dist, y, x] = candi[0];
    return { dist, y, x };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 9)
            {
                shark = { i, j, 2, 0, 0 };
                grid[i][j] = 0;
            }
        }
    }

    while (true)
    {
        Fish target = bfs();

        if (target.dist == -1)
            break;

        shark.time += target.dist;
        shark.y = target.y;
        shark.x = target.x;
        shark.eatCnt++;

        if (shark.eatCnt == shark.size)
        {
            shark.size++;
            shark.eatCnt = 0;
        }

        grid[target.y][target.x] = 0;
    }

    cout << shark.time << '\n';

    return 0;
}

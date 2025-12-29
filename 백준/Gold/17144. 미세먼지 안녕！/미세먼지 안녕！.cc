#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int grid[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> t;
    pair<int, int> air = {-1, -1};

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == -1 && air.first == -1)
            {
                air.first = i;
                air.second = i + 1;
            }
        }
    }

    int temp[51][51];

    while (t--)
    {
        // PM
        memset(temp, 0, sizeof(temp));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] <= 0)
                    continue;

                int cnt = 0;
                int dust = floor(grid[i][j] / 5);

                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (ny < 0 || ny >= r || nx < 0 || nx >= c || grid[ny][nx] == -1)
                        continue;

                    temp[ny][nx] += dust;
                    cnt++;
                }

                grid[i][j] -= (dust * cnt);
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] != -1)
                    grid[i][j] += temp[i][j];
            }
        }

        // air - up
        for (int i = air.first - 1; i > 0; i--)
            grid[i][0] = grid[i - 1][0];

        for (int i = 0; i < c - 1; i++)
            grid[0][i] = grid[0][i + 1];

        for (int i = 0; i < air.first; i++)
            grid[i][c - 1] = grid[i + 1][c - 1];

        for (int i = c - 1; i > 1; i--)
            grid[air.first][i] = grid[air.first][i - 1];
        grid[air.first][1] = 0;

        // air - down
        for (int i = air.second + 1; i < r - 1; i++)
            grid[i][0] = grid[i + 1][0];

        for (int i = 0; i < c - 1; i++)
            grid[r - 1][i] = grid[r - 1][i + 1];

        for (int i = r - 1; i >= air.second + 1; i--)
            grid[i][c - 1] = grid[i - 1][c - 1];

        for (int i = c - 1; i > 1; i--)
            grid[air.second][i] = grid[air.second][i - 1];
        grid[air.second][1] = 0;
    }

    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] > 0)
                cnt += grid[i][j];
        }
    }

    cout << cnt << '\n';

    return 0;
}

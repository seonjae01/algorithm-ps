#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int grid[17][17];

void dfs(int y, int x, int type)
{
    if (y == n - 1 && x == n - 1)
    {
        cnt++;
        return;
    }

    if (type == 0 || type == 2)
    {
        if (x + 1 < n && grid[y][x + 1] == 0)
        {
            dfs(y, x + 1, 0);
        }
    }

    if (type == 1 || type == 2)
    {
        if (y + 1 < n && grid[y + 1][x] == 0)
        {
            dfs(y + 1, x, 1);
        }
    }

    if (y + 1 < n && x + 1 < n)
    {
        if (grid[y][x + 1] == 0 && grid[y + 1][x] == 0 && grid[y + 1][x + 1] == 0)
        {
            dfs(y + 1, x + 1, 2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    dfs(0, 1, 0);
    cout << cnt << '\n';

    return 0;
}

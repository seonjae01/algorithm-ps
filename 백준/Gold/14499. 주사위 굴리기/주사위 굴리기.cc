#include <bits/stdc++.h>
using namespace std;

enum { TOP, BOTTOM, LEFT, RIGHT, FRONT, BACK };

int n, m;
int x, y, k;
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };
int dice[6];
vector<vector<int>> grid;

void solve(int d)
{
    int ny = y + dy[d];
    int nx = x + dx[d];

    if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1)
        return;

    y = ny;
    x = nx;

    if (d == 1) // 동
    {
        int temp = dice[TOP];
        dice[TOP] = dice[LEFT];
        dice[LEFT] = dice[BOTTOM];
        dice[BOTTOM] = dice[RIGHT];
        dice[RIGHT] = temp; 
    }
    else if (d == 2) // 서
    {
        int temp = dice[TOP];
        dice[TOP] = dice[RIGHT];
        dice[RIGHT] = dice[BOTTOM];
        dice[BOTTOM] = dice[LEFT];
        dice[LEFT] = temp;
    }
    else if (d == 3) // 북
    {
        int temp = dice[TOP];
        dice[TOP] = dice[FRONT];
        dice[FRONT] = dice[BOTTOM];
        dice[BOTTOM] = dice[BACK];
        dice[BACK] = temp;
    }
    else if (d == 4) // 남
    {
        int temp = dice[TOP];
        dice[TOP] = dice[BACK];
        dice[BACK] = dice[BOTTOM];
        dice[BOTTOM] = dice[FRONT];
        dice[FRONT] = temp;
    }

    if (grid[y][x] == 0)
    {
        grid[y][x] = dice[BOTTOM];
    }
    else
    {
        dice[BOTTOM] = grid[y][x];
        grid[y][x] = 0;
    }

    cout << dice[TOP] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> n >> m >> y >> x >> k;
    grid.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    while (k--)
    {
        cin >> c;
        solve(c);
    }
}

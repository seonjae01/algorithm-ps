#include <bits/stdc++.h>
using namespace std;

bool solved;
int grid[9][9];
vector<pair<int, int>> blink;

bool check(int y, int x, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[y][i] == num)
            return false;

        if (grid[i][x] == num)
            return false;
    }

    int startY = y / 3 * 3;
    int startX = x / 3 * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (grid[i + startY][j + startX] == num)
                return false;
    }

    return true;
}

void solve(int idx)
{
    if (solved)
        return;

    if (idx == blink.size())
    {
        solved = true;
        return;
    }

    auto [y, x] = blink[idx];
    for (int i = 1; i <= 9; i++)
    {
        if (check(y, x, i))
        {
            grid[y][x] = i;
            solve(idx + 1);

            if (solved)
                return;
            grid[y][x] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 9; j++)
        {
            grid[i][j] = s[j] - '0';
            if (grid[i][j] == 0)
                blink.push_back({i, j});
        }
    }

    solve(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << grid[i][j];
        cout << '\n';
    }

    return 0;
}

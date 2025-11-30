#include <bits/stdc++.h>
using namespace std;

int n = 6;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<int>> grid;

struct Dice
{
    int u, d, f, b, l, r;
    //  0, 1, 2, 3, 4, 5
};

Dice roll(Dice dice, int dir)
{
    Dice next = dice;

    if (dir == 0)      // front
    {
        next.u = dice.f;
        next.d = dice.b;
        next.f = dice.d;
        next.b = dice.u;

    }
    else if (dir == 1) // back
    {
        next.u = dice.b;
        next.d = dice.f;
        next.f = dice.u;
        next.b = dice.d;
    }
    else if (dir == 2) // left
    {
        next.u = dice.r;
        next.d = dice.l;
        next.l = dice.u;
        next.r = dice.d;
    }
    else if (dir == 3) // right
    {
        next.u = dice.l;
        next.d = dice.r;
        next.l = dice.d;
        next.r = dice.u;
    }

    return next;
}

bool solve()
{
    int startY = -1;
    int startX = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                startY = i;
                startX = j;
                break;
            }
        }
    }

    if (startY == -1 || startX == -1)
        return false;

    bool visited[6][6] = {false};
    bool face[6] = {false};

    queue<pair<pair<int, int>, Dice>> q;
    Dice dice = {0, 1, 2, 3, 4 ,5};

    q.push({{startY, startX}, dice});
    visited[startY][startX] = true;
    face[dice.d] = true;
    int cnt = 1;

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        int y = p.first.first;
        int x = p.first.second;
        Dice d = p.second;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= 6 || nx < 0 || nx >= 6)
                continue;
            if (grid[ny][nx] == 0 || visited[ny][nx])
                continue;

            Dice next = roll(d, i);
            if (face[next.d])
                continue;

            q.push({{ny, nx}, next});
            visited[ny][nx] = true;
            face[next.d] = true;
            cnt++;
        }
    }

    return cnt == 6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 3;

    while (t--)
    {
        grid.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        cout << (solve() ? "yes" : "no") << '\n';
    }

    return 0;
}

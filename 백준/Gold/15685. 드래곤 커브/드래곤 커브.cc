#include <bits/stdc++.h>
using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int x, y, d, g;
    vector<int> directions;
    vector<vector<bool>> grid(101, vector<bool>(101));
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> d >> g;
        grid[y][x] = true;
        directions.clear();
        directions.push_back(d);

        for (int i = 0; i < g; i++)
        {
            int sz = directions.size();
            for (int j = sz - 1; j >= 0; j--)
            {
                int dir = directions[j];
                directions.push_back((dir + 1) % 4);
            }
        }

        for (int dir : directions)
        {
            y += dy[dir];
            x += dx[dir];
            grid[y][x] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1])
                cnt++;
        }
    }

    cout << cnt << '\n';
}

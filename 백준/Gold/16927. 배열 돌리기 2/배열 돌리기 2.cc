#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<vector<int>> grid;

void solve()
{
    int top = 0;
    int left = 0;
    int bottom = n - 1;
    int right = m - 1;

    while (top < bottom && left < right)
    {
        int len = 2 * (bottom - top + right - left);
        int rot = t % len;

        while (rot--)
        {
            int temp = grid[top][left];

            for (int i = left; i < right; i++)
                grid[top][i] = grid[top][i + 1];

            for (int i = top; i < bottom; i++)
                grid[i][right] = grid[i + 1][right];

            for (int i = right; i > left; i--)
                grid[bottom][i] = grid[bottom][i - 1];

            for (int i = bottom; i > top; i--)
                grid[i][left] = grid[i - 1][left];

            grid[top + 1][left] = temp;
        }

        top++;
        left++;
        bottom--;
        right--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> t;
    grid.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    solve();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j] << ' ';
        cout << '\n';
    }
}

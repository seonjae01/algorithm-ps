#include <bits/stdc++.h>
using namespace std;

int n, m, layer;
vector<vector<int>> grid, temp;

void solve()
{
    temp.assign(n, vector<int>(m, 0));
    for (int i = 0; i < layer; i++)
    {
        int top = i;
        int left = i;
        int bottom = n - i - 1;
        int right = m - i - 1;

        for (int j = top + 1; j < bottom + 1; j++)
            temp[j][left] = grid[j - 1][left];

        for (int j = left + 1; j < right + 1; j++)
            temp[bottom][j] = grid[bottom][j - 1];

        for (int j = top; j < bottom; j++)
            temp[j][right] = grid[j + 1][right];

        for (int j = left; j < right; j++)
            temp[top][j] = grid[top][j + 1];
    }
    grid = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> n >> m >> t;
    grid.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    layer = min(n, m) / 2;
    while (t--)
        solve();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j] << ' ';
        cout << '\n';
    }
}

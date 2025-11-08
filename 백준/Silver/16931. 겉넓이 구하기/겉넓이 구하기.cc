#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int area = n * m * 2;

    for (int i = 0; i < n; i++) {
        area += grid[i][0];
        for (int j = 1; j < m; j++)
            area += abs(grid[i][j] - grid[i][j - 1]);
        area += grid[i][m - 1];
    }

    for (int j = 0; j < m; j++) {
        area += grid[0][j];
        for (int i = 1; i < n; i++)
            area += abs(grid[i][j] - grid[i - 1][j]);
        area += grid[n - 1][j];
    }

    cout << area << '\n';
}

#include <bits/stdc++.h>
using namespace std;

int n, l, cnt;
vector<vector<int>> grid;

bool solve(vector<int>& line)
{
    vector<bool> visited(n);
    for (int i = 0; i < n - 1; i++)
    {
        int diff = line[i] - line[i + 1];

        if (diff == 0)
            continue;

        if (diff == -1)
        {
            for (int j = i; j > i - l; j--)
            {
                if (j < 0 || visited[j] || line[j] != line[i])
                    return false;
                visited[j] = true;
            }
        }
        else if (diff == 1)
        {
            for (int j = i + 1; j <= i + l; j++)
            {
                if (j > n - 1 || visited[j] || line[j] != line[i + 1])
                    return false;
                visited[j] = true;
            }
            i += (l - 1);
        }
        else
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> l;
    grid.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
    {
        vector<int> row = grid[i];
        vector<int> col(n);
        for (int j = 0; j < n; j++)
            col[j] = grid[j][i];

        if (solve(row)) cnt++;
        if (solve(col)) cnt++;
    }

    cout << cnt << '\n';
}

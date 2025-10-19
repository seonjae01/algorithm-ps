#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;

void calc_1()
{
    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[i][j] = grid[n - i - 1][j];
    grid = temp;
}

void calc_2()
{
    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[i][j] = grid[i][m - j - 1];
    grid = temp;
}

void calc_3()
{
    vector<vector<int>> temp(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[j][n - i - 1] = grid[i][j];
    grid = temp;

    int tmp = n;
    n = m;
    m = tmp;
}

void calc_4()
{
    vector<vector<int>> temp(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[m - j - 1][i] = grid[i][j];
    grid = temp;

    int tmp = n;
    n = m;
    m = tmp;
}

void calc_5()
{
    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < m / 2; j++)
            temp[i][m / 2 + j] = grid[i][j];

    for (int i = 0; i < n / 2; i++)
        for (int j = m / 2; j < m; j++)
            temp[n / 2 + i][j] = grid[i][j];

    for (int i = n / 2; i < n; i++)
        for (int j = m / 2; j < m; j++)
            temp[i][j - m / 2] = grid[i][j];

    for (int i = n / 2; i < n; i++)
        for (int j = 0; j < m / 2; j++)
            temp[i - n / 2][j] = grid[i][j];

    grid = temp;
}

void calc_6()
{
    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < n / 2; i++)
        for (int j = m / 2; j < m; j++)
            temp[i][j - m / 2] = grid[i][j];

    for (int i = n / 2; i < n; i++)
        for (int j = m / 2; j < m; j++)
            temp[i - n / 2][j] = grid[i][j];

    for (int i = n / 2; i < n; i++)
        for (int j = 0; j < m / 2; j++)
            temp[i][m / 2 + j] = grid[i][j];

    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < m / 2; j++)
            temp[n / 2 + i][j] = grid[i][j];

    grid = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, c;
    cin >> n >> m >> t;
    grid.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    while (t--)
    {
        cin >> c;
        if (c == 1)
            calc_1();
        else if (c == 2)
            calc_2();
        else if (c == 3)
            calc_3();
        else if (c == 4)
            calc_4();
        else if (c == 5)
            calc_5();
        else if (c == 6)
            calc_6();
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
            cout << grid[i][j] << ' ';
        cout << '\n';
    }
}

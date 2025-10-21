#include <bits/stdc++.h>
using namespace std;

const int LEFT = 6;
const int RIGHT = 2;

int n, m;
vector<vector<int>> grid;

void rotate(int a, int b)
{
    if (b == 1)
    {
        int temp = grid[a][7];
        for (int i = 7; i > 0; i--)
            grid[a][i] = grid[a][i - 1];
        grid[a][0] = temp;
    }
    else
    {
        int temp = grid[a][0];
        for (int i = 0; i < 7; i++)
            grid[a][i] = grid[a][i + 1];
        grid[a][7] = temp;
    }
}

void solve(int a, int b)
{
    int l = a - 1;
    int r = a + 1;
    int dirL = b;
    int dirR = b;
    bool left = true;
    bool right = true;

    vector<pair<int, int>> rot;
    rot.push_back({a, b});

    while (left || right)
    {
        if (l >= 0 && left && grid[l][RIGHT] != grid[l + 1][LEFT])
        {
            dirL = dirL == 1 ? -1 : 1;
            rot.push_back({l, dirL});
            l--;
        }
        else
            left = false;

        if (r < n && right && grid[r][LEFT] != grid[r - 1][RIGHT])
        {
            dirR = dirR == 1 ? -1 : 1;
            rot.push_back({r, dirR});
            r++;
        }
        else
            right = false;
    }
    
    for (auto r : rot)
        rotate(r.first, r.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> n;
    grid.assign(n, vector<int>(8));

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < 8; j++)
            grid[i][j] = s[j] - '0';
    }

    int a, b;
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        solve(a - 1, b);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
            cnt++;
    }

    cout << cnt << '\n';
}

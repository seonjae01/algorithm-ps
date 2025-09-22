#include <bits/stdc++.h>
using namespace std;

int n, m, mx = 0;
vector<vector<int>> nums;
vector<vector<bool>> visited;

int calc()
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
            {
                cur *= 10;
                cur += nums[i][j];
            }
            else
            {
                sum += cur;
                cur = 0;
            }
        }
        sum += cur;
    }

    for (int j = 0; j < m; j++)
    {
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i][j])
            {
                cur *= 10;
                cur += nums[i][j];
            }
            else
            {
                sum += cur;
                cur = 0;
            }
        }
        sum += cur;
    }

    return sum;
}

void solve(int count)
{
    if (count == n * m)
    {
        mx = max(mx, calc());
        return;
    }

    int u = count / m;
    int v = count % m;

    visited[u][v] = true;
    solve(count + 1);

    visited[u][v] = false;
    solve(count + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    nums.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            nums[i][j] = s[j] - '0';
    }

    solve(0);
    cout << mx << '\n';

    return 0;
}

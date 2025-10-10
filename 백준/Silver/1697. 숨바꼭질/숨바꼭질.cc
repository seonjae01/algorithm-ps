#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[200001];

void solve()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.first;

        if (x == m)
        {
            cout << p.second << '\n';
            return;
        }

        if (x > 0 && !visited[x - 1])
        {
            q.push({x - 1, p.second + 1});
            visited[x - 1] = true;
        }

        if (x < m && !visited[x + 1])
        {
            q.push({x + 1, p.second + 1});
            visited[x + 1] = true;
        }

        if (x * 2 < 200001 && !visited[x * 2])
        {
            q.push({x * 2, p.second + 1});
            visited[x * 2] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    if (n == m)
    {
        cout << 0 << '\n';
        return 0;
    }

    solve();
    return 0;
}

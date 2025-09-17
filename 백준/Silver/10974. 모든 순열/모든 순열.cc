#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> path;
vector<bool> visited;

void solve()
{
    if (path.size() == n)
    {
        for (auto p : path)
            cout << p << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        path.push_back(i);
        solve();
        visited[i] = false;
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    visited.resize(n, false);
    solve();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> path;

void solve()
{
    if (path.size() == m)
    {
        for (auto p : path)
            cout << p << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (path.size() > 0 && path.back() > i)
            continue;

        path.push_back(i);
        solve();
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    solve();

    return 0;
}

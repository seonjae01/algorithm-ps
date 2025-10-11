#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[200001];

void solve()
{
    deque<pair<int, int>> q;
    q.push_back({n, 0});
    visited[n] = true;

    while (!q.empty())
    {
        auto [x, cnt] = q.front();
        q.pop_front();

        if (x == m)
        {
            cout << cnt << '\n';
            return;
        }

        if (x * 2 < 200000 && !visited[x * 2])
        {
            q.push_front({x * 2, cnt});
            visited[x * 2] = true;
        }

        if (x > 0 && !visited[x - 1])
        {
            q.push_back({x - 1, cnt + 1});
            visited[x - 1] = true;
        }

        if (x < 200000 && !visited[x + 1])
        {
            q.push_back({x + 1, cnt + 1});
            visited[x + 1] = true;
        }
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

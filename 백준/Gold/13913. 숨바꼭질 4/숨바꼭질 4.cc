#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[200001];

void solve()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = -2;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        int x = p.first;
        int cnt = p.second;

        if (x == m)
        {
            cout << cnt << '\n';
            return;
        }

        if (x > 0 && visited[x - 1] == 0)
        {
            q.push({x - 1, cnt + 1});
            visited[x - 1] = -1;
        }

        if (x < m && visited[x + 1] == 0)
        {
            q.push({x + 1, cnt + 1});
            visited[x + 1] = 1;
        }

        if (x * 2 < 200001 && visited[x * 2] == 0)
        {
            q.push({x * 2, cnt + 1});
            visited[x * 2] = 2;
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
        cout << 0 << '\n' << n;
        return 0;
    }

    solve();
    vector<int> order;
    while (m != n)
    {
        order.push_back(m);
        switch (visited[m])
        {
            case -1:
                m++;
                break;
            case 1:
                m--;
                break;
            case 2:
                m /= 2;
                break;
        }
    }

    order.push_back(n);
    reverse(order.begin(), order.end());
    for (auto o : order)
        cout << o << ' ';
    return 0;
}

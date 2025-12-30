#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m, x;
int dist[1001];
vector<pair<int, int>> graph[1001];

void solve(int start, int target)
{
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [curT, cur] = pq.top();
        pq.pop();

        if (cur == target)
            return;

        if (dist[cur] < curT)
            continue;

        for (auto e : graph[cur])
        {
            int next = e.first;
            int nextT = e.second;

            if (dist[next] > curT + nextT)
            {
                dist[next] = curT + nextT;
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;

        int cnt = 0;
        solve(i, x);
        cnt += dist[x];

        solve(x, i);
        cnt += dist[i];

        mx = max(mx, cnt);
    }

    cout << mx << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 / 3;
int n, m;
int dist[801];
vector<pair<int, int>> graph[801];

int solve(int start, int target)
{
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cur == target)
            return dist[cur];

        if (dist[cur] < cost)
            continue;

        for (auto e : graph[cur])
        {
            int v = e.first;
            int w = e.second;

            if (dist[v] <= cost + w)
                continue;

            pq.push({cost + w, v});
            dist[v] = cost + w;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v, w;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cin >> u >> v;

    long long p1 = INF;
    int r1 = solve(1, u);
    int r2 = solve(u, v);
    int r3 = solve(v, n);
    if (r1 != -1 && r2 != -1 && r3 != -1)
        p1 = (long long)(r1 + r2 + r3);

    long long p2 = INF;
    int c1 = solve(1, v);
    int c2 = solve(v, u);
    int c3 = solve(u, n);
    if (c1 != -1 && c2 != -1 && c3 != -1)
        p2 = (long long)(c1 + c2 + c3);

    long long p = min(p1, p2);
    if (p >= INF)
        cout << -1 << '\n';
    else
        cout << p << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int dist[20001];
vector<pair<int, int>> graph[20001];

void solve(int start)
{
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

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
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v, w, start;
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    solve(start);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }

    return 0;
}

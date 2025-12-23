#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dist[1001];
vector<pair<int, int>> graph[1001];

void solve(int start)
{
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
            int next = e.first;
            int w = e.second;

            if (dist[next] <= w + cost)
                continue;

            dist[next] = w + cost;
            pq.push({dist[next], next});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;
    fill(dist, dist + 1001, INF);
    solve(start);
    cout << dist[end] << '\n';

    return 0;
}

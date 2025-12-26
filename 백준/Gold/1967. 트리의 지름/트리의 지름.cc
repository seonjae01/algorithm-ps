#include <bits/stdc++.h>
using namespace std;

int n;
int maxDist, maxNode;
bool visited[10001];
vector<vector<pair<int, int>>> graph;

void dfs(int node, int dist)
{
    visited[node] = true;

    if (dist > maxDist)
    {
        maxDist = dist;
        maxNode = node;
    }

    for (auto e : graph[node])
    {
        int next = e.first;
        int cost = e.second;

        if (visited[next])
            continue;

        dfs(next, dist + cost);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    graph.assign(n + 1, {});

    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dfs(1, 0);
    fill(visited, visited + n + 1, false);
    maxDist = 0;
    dfs(maxNode, 0);
    cout << maxDist << '\n';

    return 0;
}

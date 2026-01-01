#include <bits/stdc++.h>
using namespace std;

int n, maxNode;
long long maxDist;
bool visited[100001];
vector<pair<int, int>> graph[100001];

void dfs(int node, long long dist)
{
    visited[node] = true;

    if (dist > maxDist)
    {
        maxDist = dist;
        maxNode = node;
    }

    for (auto e : graph[node])
    {
        auto [next, cost] = e;

        if (visited[next])
            continue;

        dfs(next, dist + cost);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;

        while (true)
        {
            int v;
            cin >> v;

            if (v == -1)
                break;

            int w;
            cin >> w;

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
    }

    dfs(1, 0);
    fill(visited, visited + n + 1, false);
    maxDist = 0;
    dfs(maxNode, 0);
    cout << maxDist << '\n';

    return 0;
}

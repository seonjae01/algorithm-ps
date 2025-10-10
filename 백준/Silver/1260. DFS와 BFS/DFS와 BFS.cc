#include <bits/stdc++.h>
using namespace std;

bool visited[1001];
vector<vector<int>> graph;

void dfs(int x)
{
    visited[x] = true;
    cout << x << ' ';
    
    for (int u : graph[x])
    {
        if (!visited[u])
            dfs(u);
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        cout << p << ' ';

        for (int u : graph[p])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(v);
    memset(visited, 0, sizeof(visited));
    cout << '\n';
    bfs(v);
    return 0;
}

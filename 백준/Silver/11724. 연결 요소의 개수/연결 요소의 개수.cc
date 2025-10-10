#include <bits/stdc++.h>
using namespace std;

bool visited[1001];
vector<vector<int>> graph;

void dfs(int x)
{
    visited[x] = true;

    for (int u : graph[x])
    {
        if (!visited[u])
            dfs(u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, cnt = 0;
    cin >> n >> m;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}

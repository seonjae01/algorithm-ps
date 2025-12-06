#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int u : graph[p])
        {
            if (!visited[u])
            {
                q.push(u);
                visited[u] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (visited[i])
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<int> graph[100001];
int visited[100001];

void solve(int node)
{
    visited[node] = 1;

    for (auto e : graph[node])
    {
        if (visited[e] == 0)
        {
            solve(e);
            visited[node] += visited[e];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> q;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    solve(r);

    while (q--)
    {
        cin >> r;
        cout << visited[r] << '\n';
    }

    return 0;
}

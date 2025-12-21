#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> parent;

void solve()
{
    queue<int> q;
    q.push(1);
    parent[1] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int e : graph[cur])
        {
            if (parent[e] == 0)
            {
                parent[e] = cur;
                q.push(e);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    graph.assign(n + 1, vector<int>());
    parent.assign(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int r, c;
        cin >> r >> c;
        graph[r].push_back(c);
        graph[c].push_back(r);
    }

    solve();

    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';

    return 0;
}

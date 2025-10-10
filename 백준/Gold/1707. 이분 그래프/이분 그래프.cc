#include <bits/stdc++.h>
using namespace std;

bool bi;
vector<int> color;
vector<vector<int>> graph;

void dfs(int x, int c)
{
    color[x] = c;

    for (int n : graph[x])
    {
        if (color[n] == c)
        {
            bi = false;
            return;
        }

        if (color[n] == 0)
            dfs(n, c * -1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;
    cin >> t;

    while (t--)
    {
        int cnt = 0;
        cin >> n >> m;
        color.assign(n + 1, 0);
        graph.assign(n + 1, vector<int>());
        bi = true;

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
                dfs(i, 1);

            if (!bi)
                break;
        }

        cout << (bi ? "YES" : "NO") << '\n';
    }

    return 0;
}

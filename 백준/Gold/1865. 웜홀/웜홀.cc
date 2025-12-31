#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node
{
    int u, v, w;
};

int n, m, w;
int dist[501];
vector<Node> graph;

bool solve()
{
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            auto [cur, next, cost] = graph[j];

            if (dist[next] > dist[cur] + cost)
            {
                dist[next] = dist[cur] + cost;

                if (i == n)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int s, e, c;
        cin >> n >> m >> w;
        graph.clear();

        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> c;
            graph.push_back({s, e, c});
            graph.push_back({e, s, c});
        }

        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> c;
            graph.push_back({s, e, -c});
        }

        cout << (solve() ? "YES" : "NO") << '\n';
    }

    return 0;
}

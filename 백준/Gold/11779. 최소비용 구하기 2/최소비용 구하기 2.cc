#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
int dist[1001];
int visited[1001];
vector<pair<int, int>> graph[1001];

void solve(int start, int end)
{
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [curT, cur] = pq.top();
        pq.pop();

        if (cur == end)
            return;

        if (dist[cur] < curT)
            continue;

        for (auto e : graph[cur])
        {
            auto [next, nextT] = e;
            int cost = curT + nextT;

            if (dist[next] > cost)
            {
                pq.push({cost, next});
                dist[next] = cost;
                visited[next] = cur;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
    }

    int start, end;
    cin >> start >> end;
    solve(start, end);

    cout << dist[end] << '\n';

    int prev = -1;
    vector<int> path;
    path.push_back(end);

    while (prev != start)
    {
        prev = visited[end];
        path.push_back(prev);
        end = prev;
    }

    cout << path.size() << '\n';
    reverse(path.begin(), path.end());
    for (int p : path)
        cout << p << ' ';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, m, mx;
vector<pair<int, int>> graph[100001];
bool visited[100001];

long long solve()
{
    long long total = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;
        total += cost;
        mx = max(mx, cost);

        for (auto e : graph[cur])
        {
            auto [next, nextCost] = e;

            if (!visited[next])
            {
                pq.push({nextCost, next});
            }
        }
    }

    return total - mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cout << solve() << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m, r;
int W[101], dist[101];
vector<pair<int, int>> graph[101];

int solve(int start)
{
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [len, cur] = pq.top();
        pq.pop();

        if (dist[cur] < len)
            continue;

        for (auto v : graph[cur])
        {
            int next = v.first;
            int nextLen = v.second;

            if (m < len + nextLen)
                continue;

            pq.push({len + nextLen, next});
            dist[next] = len + nextLen;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
            cnt += W[i];
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
        cin >> W[i];

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max(mx, solve(i));

    cout << mx << '\n';

    return 0;
}

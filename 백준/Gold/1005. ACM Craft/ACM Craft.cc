#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[1001], D[1001], IN[1001];
vector<int> graph[1001];

int solve(int target)
{
    int time = 0;
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (IN[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (auto nx : graph[p])
        {
            dp[nx] = max(dp[nx], dp[p] + D[nx]);
            IN[nx]--;

            if (IN[nx] == 0)
            {
                q.push(nx);
            }
        }
    }

    return dp[target];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> D[i];
            graph[i].clear();
            dp[i] = D[i];
            IN[i] = 0;
        }

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            IN[y]++;
        }

        int target;
        cin >> target;
        cout << solve(target) << '\n';
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, mn = 1000001;
vector<vector<int>> startlink;
vector<int> start;
vector<bool> visited;

int sumEach(vector<int> path)
{
    int sum = 0;

    for (int i = 0; i < path.size(); i++)
    {
        for (int j = i + 1; j < path.size(); j++)
        {
            int u = path[i];
            int v = path[j];
            sum += (startlink[u][v] + startlink[v][u]);
        }
    }

    return sum;
}

void solve(int idx)
{
    if (start.size() == n / 2)
    {
        vector<int> link;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                link.push_back(i);
        }

        mn = min(mn, abs(sumEach(start) - sumEach(link)));
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        start.push_back(i);
        solve(i + 1);
        visited[i] = false;
        start.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    startlink.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> startlink[i][j];

    solve(0);
    cout << mn << '\n';

    return 0;
}

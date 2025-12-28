#include <bits/stdc++.h>
using namespace std;

int cnt, mn = 1e9;
int visited[200001];

void solve(int start, int target)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while (!q.empty())
    {
        auto [x, t] = q.front();
        q.pop();

        if (x == target)
        {
            mn = min(mn, t);
            cnt++;
        }

        if (x >= 1 && (visited[x - 1] == 0 || visited[x - 1] == visited[x] + 1))
        {
            q.push({x - 1, t + 1});
            visited[x - 1] = visited[x] + 1;
        }

        if (x <= 100000 && (visited[x + 1] == 0 || visited[x + 1] == visited[x] + 1))
        {
            q.push({x + 1, t + 1});
            visited[x + 1] = visited[x] + 1;
        }

        if (x * 2 <= 200000 && (visited[x * 2] == 0 || visited[x * 2] == visited[x] + 1))
        {
            q.push({x * 2, t + 1});
            visited[x * 2] = visited[x] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    solve(n, m);
    cout << mn << '\n' << cnt << '\n';

    return 0;
}

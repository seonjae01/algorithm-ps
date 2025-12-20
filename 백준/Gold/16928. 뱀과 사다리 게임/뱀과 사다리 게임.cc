#include <bits/stdc++.h>
using namespace std;

int board[101];

int solve()
{
    vector<int> visited(101, -1);
    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == 100)
            return visited[cur];

        for (int i = 1; i <= 6; i++)
        {
            int next = cur + i;
            if (next > 100)
                continue;

            int target = board[next];
            if (visited[target] == -1 || visited[target] > visited[cur] + 1)
            {
                q.push(target);
                visited[target] = visited[cur] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m;

    for (int i = 1; i <= 100; i++)
        board[i] = i;

    for (int i = 0; i < n + m; i++)
    {
        cin >> u >> v;
        board[u] = v;
    }

    cout << solve() << '\n';

    return 0;
}

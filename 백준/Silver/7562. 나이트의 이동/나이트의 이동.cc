#include <bits/stdc++.h>
using namespace std;

struct Node
{
    pair<int, int> pos;
    int cnt;
};

int n, mn;
pair<int, int> cur, tar;
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
vector<vector<bool>> visited;

void solve()
{
    queue<Node> q;
    q.push({cur, 1});
    visited[cur.first][cur.second] = true;

    if (cur.first == tar.first && cur.second == tar.second)
    {
        mn = 0;
        return;
    }

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ny = p.pos.first + dy[i];
            int nx = p.pos.second + dx[i];

            if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1)
                continue;
            if (visited[ny][nx])
                continue;

            if (ny == tar.first && nx == tar.second)
            {
                mn = min(mn, p.cnt);
                return;
            }

            q.push({{ny, nx}, p.cnt + 1});
            visited[ny][nx] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int a, b;
        cin >> a >> b;
        cur = make_pair(a, b);
        cin >> a >> b;
        tar = make_pair(a, b);

        mn = INT_MAX;
        visited.assign(n, vector<bool>(n, false));
        solve();
        cout << mn << '\n';
    }

    return 0;
}

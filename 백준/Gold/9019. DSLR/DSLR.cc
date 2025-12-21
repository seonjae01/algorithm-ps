#include <bits/stdc++.h>
using namespace std;

bool visited[10000];
int parent[10000];
char cmd[10000];

void solve(int start, int target)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == target)
        {
            string res = "";
            while (cur != start)
            {
                res += cmd[cur];
                cur = parent[cur];
            }

            reverse(res.begin(), res.end());
            cout << res << '\n';
            return;
        }

        // D
        int d = (cur * 2) % 10000;
        if (!visited[d])
        {
            q.push(d);
            visited[d] = true;
            parent[d] = cur;
            cmd[d] = 'D';
        }

        // S
        int s = cur == 0 ? 9999 : cur - 1;
        if (!visited[s])
        {
            q.push(s);
            visited[s] = true;
            parent[s] = cur;
            cmd[s] = 'S';
        }

        // L
        int l = (cur % 1000) * 10 + (cur / 1000);
        if (!visited[l])
        {
            q.push(l);
            visited[l] = true;
            parent[l] = cur;
            cmd[l] = 'L';
        }

        // R
        int r = (cur % 10) * 1000 + (cur / 10);
        if (!visited[r])
        {
            q.push(r);
            visited[r] = true;
            parent[r] = cur;
            cmd[r] = 'R';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        memset(visited, false, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        memset(cmd, 0, sizeof(cmd));
        solve(n, m);
    }

    return 0;
}

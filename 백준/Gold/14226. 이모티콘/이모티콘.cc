#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int mo, cl, cnt;
};

int n;
bool visited[2001][2001];

void solve()
{
    queue<Node> q;
    q.push({1, 0, 1});
    visited[1][0] = true;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        int mo = p.mo;
        int cl = p.cl;
        int cnt = p.cnt;

        if (mo + cl == n)
        {
            cout << cnt << '\n';
            return;
        }

        if (!visited[mo][mo])
        {
            q.push({mo, mo, cnt + 1});
            visited[mo][mo] = true;
        }

        if (mo + cl < 2001 && !visited[mo + cl][cl])
        {
            q.push({mo + cl, cl, cnt + 1});
            visited[mo + cl][cl] = true;
        }

        if (mo > 1 && !visited[mo - 1][cl])
        {
            q.push({mo - 1, cl, cnt + 1});
            visited[mo - 1][cl] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    solve();
    return 0;
}

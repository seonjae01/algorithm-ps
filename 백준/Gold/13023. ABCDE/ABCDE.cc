#include <bits/stdc++.h>
using namespace std;

bool found;
bool visited[2001];
vector<vector<int>> arr;

void solve(int x, int cnt)
{
    if (cnt == 5)
    {
        found = true;
        return;
    }

    visited[x] = true;
    for (int k : arr[x])
    {
        if (!visited[k])
        {
            solve(k, cnt + 1);
            if (found)
                return;
        }
    }
    visited[x] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    arr.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        solve(i, 1);
        if (found)
            break;
    }

    cout << found ? 1 : 0 << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int visited[26][26];
vector<vector<int>> graph;

int dfs(int u, int v, int c)
{
    int cnt = 1;
    visited[u][v] = c;
    for (int i = 0; i < 4; i++)
    {
        int ny = u + dy[i];
        int nx = v + dx[i];

        if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1)
            continue;

        if (visited[ny][nx] == 0 && graph[ny][nx])
            cnt += dfs(ny, nx, c);
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> n;
    graph.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            graph[i][j] = s[j] - '0';
    }

    int len = 1;
    multiset<int> arr;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && graph[i][j] == 1)
            {
                arr.insert(dfs(i, j, len));
                len++;
            }
        }
    }

    cout << len - 1 << '\n';
    for (int k : arr)
        cout << k << '\n';
    return 0;
}

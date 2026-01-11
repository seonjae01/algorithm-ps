#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1000001];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

bool unite(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB)
        return false;

    parent[rootB] = rootA;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    while (m--)
    {
        int cmd, u, v;
        cin >> cmd >> u >> v;

        if (cmd == 0)
            unite(u, v);
        else
            cout << (find(u) == find(v) ? "YES" : "NO") << '\n';
    }

    return 0;
}

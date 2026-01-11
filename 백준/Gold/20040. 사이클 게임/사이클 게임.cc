#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[500001];

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
    for (int i = 1; i < n; i++)
        parent[i] = i;

    bool isCycle = false;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if (find(u) == find(v))
        {
            isCycle = true;
            cout << i + 1 << '\n';
            return 0;
        }
        else
        {
            unite(u, v);
        }
    }

    cout << 0 << '\n';
    return 0;
}

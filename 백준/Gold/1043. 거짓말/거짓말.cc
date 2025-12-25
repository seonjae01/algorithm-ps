#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool truth[51];
vector<vector<int>> people;
vector<int> party[51];

void dfs(int cur)
{
    for (int next : people[cur])
    {
        if (truth[next])
            continue;

        truth[next] = true;
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v, prev;
    cin >> n >> m >> k;
    people.assign(n + 1, {});
    vector<int> truthInit;

    for (int i = 0; i < k; i++)
    {
        cin >> u;
        truth[u] = true;
        truthInit.push_back(u);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> prev;
        party[i].push_back(prev);

        for (int j = 1; j < u; j++)
        {
            cin >> v;
            people[prev].push_back(v);
            people[v].push_back(prev);
            party[i].push_back(v);
            prev = v;
        }
    }

    for (auto e : truthInit)
        dfs(e);

    int cnt = m;
    for (int i = 0; i < m; i++)
    {
        bool lie = true;
        for (auto e : party[i])
        {
            if (truth[e])
            {
                lie = false;
                break;
            }
        }

        if (!lie)
            cnt--;
    }

    cout << cnt << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, m;
int mn = 1e9;
bool selected[13];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int getDist(pair<int, int> r1, pair<int, int> r2)
{
    return abs(r1.first - r2.first) + abs(r1.second - r2.second);
}

void dfs(int idx, int cnt)
{
    if (cnt == m)
    {
        int dist = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int mnDist = 1e9;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (!selected[j])
                    continue;

                mnDist = min(mnDist, getDist(house[i], chicken[j]));
            }

            dist += mnDist;
        }

        mn = min(mn, dist);
        return;
    }

    for (int i = idx; i < chicken.size(); i++)
    {
        if (selected[i])
            continue;

        selected[i] = true;
        dfs(i + 1, cnt + 1);
        selected[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;

            if (k == 1)
                house.push_back({i, j});
            else if (k == 2)
                chicken.push_back({i, j});
        }
    }

    dfs(0, 0);
    cout << mn << '\n';

    return 0;
}

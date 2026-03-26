#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> sche(n);

    for (int i = 0; i < n; i++)
        cin >> sche[i].second >> sche[i].first;

    sort(sche.begin(), sche.end());
    auto cur = sche[0];
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (cur.first <= sche[i].second)
        {
            cur = sche[i];
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}

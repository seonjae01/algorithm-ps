#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
vector<int> result;

void solve(int cnt, int idx)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        result[cnt] = nums[i];
        solve(cnt + 1, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    result.assign(m, 0);
    set<int> temp;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        temp.insert(k);
    }

    for (auto t : temp)
        nums.push_back(t);
    solve(0, 0);

    return 0;
}

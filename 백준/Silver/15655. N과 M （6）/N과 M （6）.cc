#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
vector<int> path;
vector<bool> visited(10001);

void solve()
{
    if (path.size() == m)
    {
        for (auto p : path)
            cout << p << ' ';
        cout << '\n';
        return;
    }

    for (auto num : nums)
    {
        if (visited[num] || (path.size() > 0 && path.back() > num))
            continue;

        visited[num] = true;
        path.push_back(num);
        solve();
        visited[num] = false;
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    solve();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> path, nums;
vector<bool> visited;

void solve()
{
    if (path.size() == 6)
    {
        for (auto p : path)
            cout << p << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] || (path.size() > 0 && path.back() > nums[i]))
            continue;

        visited[i] = true;
        path.push_back(nums[i]);
        solve();
        visited[i] = false;
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while (n)
    {
        nums.resize(n);
        visited.resize(n, false);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        solve();
        cout << '\n';
        cin >> n;
    }

    return 0;
}

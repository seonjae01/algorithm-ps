#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
vector<int> path, nums;
vector<bool> visited;

int sumVec(vector<int> vec)
{
    int sum = 0;

    for (int i : vec)
        sum += i;
    return sum;
}

void solve(int idx)
{
    if (path.size() > 0 && sumVec(path) == m)
        cnt++;

    for (int i = idx + 1; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        path.push_back(nums[i]);
        solve(i);
        visited[i] = false;
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    nums.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    solve(-1);
    cout << cnt << '\n';

    return 0;
}

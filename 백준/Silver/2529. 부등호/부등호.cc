#include <bits/stdc++.h>
using namespace std;

int n;
long long mx = 0, mn = 10000000000;
vector<char> sign;
vector<int> path, mxstr, mnstr;
vector<bool> visited(10);

void solve()
{
    if (path.size() == n + 1)
    {
        long long num = path[0];
        vector<int> str = path;

        for (int i = 1; i <= n; i++)
        {
            num *= 10;
            num += path[i];
        }

        if (mx < num)
        {
            mx = num;
            mxstr = path;// str;
        }

        if (mn > num)
        {
            mn = num;
            mnstr = path; //str;
        }

        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (visited[i])
            continue;

        if (path.size() > 0)
        {
            char c = sign[path.size() - 1];

            if (c == '<' && path.back() > i)
                continue;
            if (c == '>' && path.back() < i)
                continue;
        }

        visited[i] = true;
        path.push_back(i);
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
    sign.resize(n);

    for(int i = 0; i < n; i++)
        cin >> sign[i];

    solve();
    for (auto c : mxstr)
        cout << c;
    cout << '\n';
    for (auto c : mnstr)
        cout << c;

    return 0;
}

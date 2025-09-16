#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<char> alpha;
vector<char> path;
vector<bool> visited;

void solve(int x, int y)
{
    if (path.size() == n)
    {
        if (x < 1 || y < 2)
            return;

        for (auto p : path)
            cout << p;
        cout << '\n';

        return;
    }

    for (int i = 0; i < m; i++)
    {
        if (visited[i] || (path.size() > 0 && path.back() > alpha[i]))
            continue;

        visited[i] = true;
        path.push_back(alpha[i]);

        if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
            solve(x + 1, y);
        else
            solve(x, y + 1);

        visited[i] = false;
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        alpha.push_back(c);
    }

    visited.resize(m, false);
    sort(alpha.begin(), alpha.end());
    solve(0, 0);

    return 0;
}

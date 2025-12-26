#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool col[35];
bool diag1[35], diag2[35];

void solve(int k)
{
    if (k == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (col[i] || diag1[k + i] || diag2[k - i + n])
            continue;

        col[i] = true;
        diag1[k + i] = true;
        diag2[k - i + n] = true;

        solve(k + 1);

        col[i] = false;
        diag1[k + i] = false;
        diag2[k - i + n] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    solve(0);
    cout << cnt << '\n';

    return 0;
}

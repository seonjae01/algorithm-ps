#include <bits/stdc++.h>
using namespace std;

int cnt;

void solve(int len, int r, int c)
{
    if (len == 1)
        return;

    int half = len / 2;

    // 1
    if (r < half && c < half)
    {
        solve(half, r, c);
    }
    // 2
    else if (r < half && c >= half)
    {
        cnt += (half * half);
        solve(half, r, c - half);
    }
    // 3
    else if (r >= half && c < half)
    {
        cnt += (2 * half * half);
        solve(half, r - half, c);
    }
    // 4
    else
    {
        cnt += (3 * half * half);
        solve(half, r - half, c - half);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;

    solve(pow(2, n), r, c);
    cout << cnt << '\n';

    return 0;
}

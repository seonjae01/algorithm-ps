#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 1;
    long long n, m;
    cin >> n >> m;

    while (m != n)
    {
        if (m < n)
        {
            cout << -1 << '\n';
            return 0;
        }

        if (m % 2 == 0)
            m /= 2;
        else if (m % 10 == 1)
            m /= 10;
        else
        {
            cout << -1 << '\n';
            return 0;
        }

        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}

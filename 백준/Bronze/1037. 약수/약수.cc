#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, k;
    int mn = 1000000;
    int mx = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> k;
        mn = min(mn, k);
        mx = max(mx, k);
    }

    cout << mx * mn << '\n';
}
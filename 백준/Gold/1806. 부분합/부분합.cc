#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int mn = 1e9 + 7;
    int sum = arr[0];
    int l = 0, r = 0;

    while (r < n && l <= r)
    {
        if (sum < m)
        {
            r++;
            sum += arr[r];
        }
        else
        {
            mn = min(mn, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }

    if (mn == 1e9 + 7)
        cout << 0 << '\n';
    else
        cout << mn << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dpInc[1001], dpDec[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, inc = 0, dec = 0, mx = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        dpInc[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] > arr[j])
                dpInc[i] = max(dpInc[i], dpInc[j] + 1);
        }
        inc = max(inc, dpInc[i]);
    }

    reverse(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        dpDec[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] > arr[j])
                dpDec[i] = max(dpDec[i], dpDec[j] + 1);
        }
        dec = max(dec, dpDec[i]);
    }

    for (int i = 0; i < n; i++)
        mx = max(mx, dpInc[i] + dpDec[n - i - 1]);
    cout << mx - 1 << '\n';

    return 0;
}

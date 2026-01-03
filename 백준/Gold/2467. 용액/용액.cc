#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> liq(n);
    for (int i = 0; i < n; i++)
        cin >> liq[i];

    sort(liq.begin(), liq.end());
    int l = 0, r = n - 1;
    int diff = INT_MAX;
    int diffL = 0, diffR = n - 1;

    while (l < r)
    {
        int sum = liq[l] + liq[r];

        if (abs(sum) < diff)
        {
            diff = abs(sum);
            diffL = l;
            diffR = r;
        }

        if (sum == 0)
            break;

        if (sum < 0)
            l++;
        else
            r--;
    }

    cout << liq[diffL] << ' ' << liq[diffR] << '\n';

    return 0;
}

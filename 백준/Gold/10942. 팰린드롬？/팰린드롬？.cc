#include <bits/stdc++.h>
using namespace std;

int arr[2001];
bool dp[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i][i] = true;
    }

    for (int i = 1; i < n; i++)
        dp[i][i + 1] = arr[i] == arr[i + 1];

    for (int len = 2; len <= n - 1; len++)
    {
        for (int i = 1; i <= n - len; i++)
        {
            int j = i + len;
            if (arr[i] == arr[j] && dp[i + 1][j - 1])
                dp[i][j] = true;
        }
    }

    int m;
    cin >> m;

    while (m--)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }

    return 0;
}

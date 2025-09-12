#include <bits/stdc++.h>
using namespace std;

int M = 1000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> vec(M + 1, 0);
    vector<long long> sum(M + 1, 0);

    for (int i = 1; i <= M; i++)
        for (int j = i; j <= M; j += i)
            vec[j] += i;

    for (int i = 1; i <= M; i++)
        sum[i] = sum[i - 1] + vec[i];

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << sum[n] << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

int stair[301];
int dp[301][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        map<string, int> clothes;

        for (int i = 0; i < n; i++)
        {
            string cloth;
            cin >> cloth >> cloth;
            clothes[cloth]++;
        }

        int cnt = 1;
        for (auto cloth : clothes)
            cnt *= (cloth.second + 1);

        cout << cnt - 1 << '\n';
    }

    return 0;
}

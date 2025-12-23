#include <bits/stdc++.h>
using namespace std;

int input[3], minDP[3], maxDP[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> input[0] >> input[1] >> input[2];
        int mxDP[3] = { maxDP[0], maxDP[1], maxDP[2] };
        int mnDP[3] = { minDP[0], minDP[1], minDP[2] };

        maxDP[0] = max(mxDP[0], mxDP[1]) + input[0];
        maxDP[1] = max(mxDP[0], max(mxDP[1], mxDP[2])) + input[1];
        maxDP[2] = max(mxDP[1], mxDP[2]) + input[2];

        minDP[0] = min(mnDP[0], mnDP[1]) + input[0];
        minDP[1] = min(mnDP[0], min(mnDP[1], mnDP[2])) + input[1];
        minDP[2] = min(mnDP[1], mnDP[2]) + input[2];
    }

    cout << max(maxDP[0], max(maxDP[1], maxDP[2])) << ' ' << min(minDP[0], min(minDP[1], minDP[2])) << '\n';

    return 0;
}

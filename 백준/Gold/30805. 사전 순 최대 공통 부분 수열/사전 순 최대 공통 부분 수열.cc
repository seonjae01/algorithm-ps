#include <bits/stdc++.h>
using namespace std;

int A[101], B[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> B[i];

    vector<int> res;
    int idxA = 0;
    int idxB = 0;

    while (true)
    {
        bool found = false;

        for (int k = 100; k >= 1; k--)
        {
            int a = -1, b = -1;

            for (int i = idxA; i < n; i++)
            {
                if (A[i] == k)
                {
                    a = i;
                    break;
                }
            }

            for (int i = idxB; i < m; i++)
            {
                if (B[i] == k)
                {
                    b = i;
                    break;
                }
            }

            if (a != -1 && b != -1)
            {
                res.push_back(k);
                idxA = a + 1;
                idxB = b + 1;
                found = true;
                break;
            }
        }

        if (!found)
            break;
    }

    cout << res.size() << '\n';
    for (int r : res)
        cout << r << ' ';

    return 0;
}

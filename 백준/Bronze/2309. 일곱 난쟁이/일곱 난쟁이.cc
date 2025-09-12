#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n = 9;
    int sum = 0;
    vector<int> man(n);

    for (int i = 0; i < n; i++)
    {
        cin >> man[i];
        sum += man[i];
    }

    sort(man.begin(), man.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (sum - man[i] - man[j] != 100)
                continue;

            for (int k = 0; k < n; k++)
                if (k != i && k != j)
                    cout << man[k] << '\n';

            return 0;
        }
    }
}

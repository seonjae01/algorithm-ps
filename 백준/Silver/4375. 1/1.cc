#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        int ll = 1;
        int len = 1;

        if (n == 1)
        {
            cout << 1 << '\n';
            break;
        }

        while (ll)
        {
            ll = (ll * 10 + 1) % n;
            len++;
        }

        cout << len << '\n';
    }
}
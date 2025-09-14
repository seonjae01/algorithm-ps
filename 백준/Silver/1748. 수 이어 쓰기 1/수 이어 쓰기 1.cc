#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long count = 0;
    long long digit = 10;
    int cnt = 1;
    int n;
    cin >> n;

    if (n < 10)
    {
        cout << n << '\n';
        return 0;
    }

    while (n)
    {
        if (n / digit > 0)
        {
            count += ((digit / 10) * 9 * cnt);
        }
        else
        {
            count += ((n - digit / 10 + 1) * cnt);
            break;
        }

        cnt++;
        digit *= 10;
    }

    cout << count << '\n';

    return 0;
}

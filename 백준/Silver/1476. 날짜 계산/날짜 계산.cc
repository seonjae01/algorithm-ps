#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int year = 0;
    int e, s, m;
    int y1 = 0, y2 = 0, y3 = 0;
    cin >> e >> s >> m;

    while (y1 != e || y2 != s || y3 != m)
    {
        y1++;
        y2++;
        y3++;
        year++;

        if (y1 > 15)
            y1 = 1;
        if (y2 > 28)
            y2 = 1;
        if (y3 > 19)
            y3 = 1;
    }

    cout << year << '\n';

    return 0;
}

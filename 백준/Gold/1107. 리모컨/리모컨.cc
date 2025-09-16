#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> pad = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mn = 1000001;
    int cha = 100;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        pad.erase(k);
    }

    if (n == 100)
    {
        cout << 0 << '\n';
        return 0;
    }

    mn = min(mn, abs(cha - n)); // 100 ~
    if (pad.count(0) > 0)
        mn = min(mn, n + 1);        // 0 ~

    for (auto p1 : pad)
    {
        if (p1 == 0)
            continue;

        cha = p1;
        mn = min(mn, abs(cha - n) + 1);

        for (auto p2 : pad)
        {
            int cha2 = cha * 10 + p2;
            mn = min(mn, abs(cha2 - n) + 2);

            for (auto p3 : pad)
            {
                int cha3 = cha2 * 10 + p3;
                mn = min(mn, abs(cha3 - n) + 3);

                for (auto p4 : pad)
                {
                    int cha4 = cha3 * 10 + p4;
                    mn = min(mn, abs(cha4 - n) + 4);

                    for (auto p5 : pad)
                    {
                        int cha5 = cha4 * 10 + p5;
                        mn = min(mn, abs(cha5 - n) + 5);

                        for (auto p6 : pad)
                        {
                            int cha6 = cha5 * 10 + p6;
                            mn = min(mn, abs(cha6 - n) + 6);
                        }
                    }
                }
            }
        }
    }

    cout << mn << '\n';

    return 0;
}

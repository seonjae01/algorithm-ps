#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    unsigned int mask = 0;
    cin >> n;

    while (n--)
    {
        int x;
        string cmd;
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> x;
            mask |= (1u << (x - 1));
        }
        else if (cmd == "remove")
        {
            cin >> x;
            mask &= ~(1u << (x - 1));
        }
        else if (cmd == "check")
        {
            cin >> x;
            cout << (mask & (1u << (x - 1)) ? 1 : 0) << '\n';
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            mask ^= (1u << (x - 1));
        }
        else if (cmd == "all")
        {
            mask = (1u << 20) - 1;
        }
        else if (cmd == "empty")
        {
            mask = 0;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        char cmd;
        int n, k;
        multiset<int> q;
        cin >> n;

        while (n--)
        {
            cin >> cmd >> k;

            if (cmd == 'I')
                q.insert(k);
            else
            {
                if (q.size() == 0)
                    continue;

                if (k == 1)
                {
                    auto it = q.end();
                    it--;
                    q.erase(it);
                }
                else
                {
                    q.erase(q.begin());
                }
            }
        }

        if (q.size() == 0)
            cout << "EMPTY" << '\n';
        else
            cout << *q.rbegin() << ' ' << *q.begin() << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    string cmd;
    deque<int> q;
    cin >> n;

    while (n--)
    {
        cin >> cmd;

        if (cmd == "push_front")
        {
            cin >> x;
            q.push_front(x);
        }
        else if (cmd == "push_back")
        {
            cin >> x;
            q.push_back(x);
        }
        else if (cmd == "pop_front")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.back() << '\n';
                q.pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << q.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "front")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }
        else if (cmd == "back")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string cmd,arr;
        int n;
        cin >> cmd >> n >> arr;

        for (char &c : arr)
        {
            if (c == '[' || c == ']' || c == ',')
                c = ' ';
        }

        stringstream ss(arr);
        deque<int> dq;
        int num;
        bool isReversed = false;
        bool isError = false;

        while (ss >> num)
            dq.push_back(num);

        for (char c : cmd)
        {
            if (c == 'R')
            {
                isReversed = !isReversed;
            }
            else if (c == 'D')
            {
                if (dq.empty())
                {
                    cout << "error" << '\n';
                    isError = true;
                    break;
                }

                if (!isReversed)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (isError)
            continue;

        cout << '[';

        if (!isReversed)
        {
            while (!dq.empty())
            {
                cout << dq.front();
                if (dq.size() != 1)
                    cout << ',';
                dq.pop_front();
            }
        }
        else
        {
            while (!dq.empty())
            {
                cout << dq.back();
                if (dq.size() != 1)
                    cout << ',';
                dq.pop_back();
            }
        }
        
        cout << "]\n";
    }

    return 0;
}

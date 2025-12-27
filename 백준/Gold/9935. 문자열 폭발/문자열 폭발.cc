#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str, bomb;
    cin >> str >> bomb;

    string ans = "";
    for (char c : str)
    {
        ans += c;

        if (ans.size() >= bomb.size())
        {
            bool isEqual = true;
            for (int i = 0; i < bomb.size(); i++)
            {
                if (ans[ans.size() - bomb.size() + i] != bomb[i])
                {
                    isEqual = false;
                    break;
                }
            }

            if (isEqual)
            {
                for (int i = 0; i < bomb.size(); i++)
                    ans.pop_back();
            }
        }
    }

    cout << (ans.empty() ? "FRULA" : ans) << '\n';

    return 0;
}

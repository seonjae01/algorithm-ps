#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> doc(n);
    unordered_map<string, int> idx(n);

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        doc[i] = name;
        idx[name] = i;
    }

    for (int i = 0; i < m; i++)
    {
        string cmd;
        cin >> cmd;

        if (isdigit(cmd[0]))
            cout << doc[stoi(cmd) - 1] << '\n';
        else
            cout << idx[cmd] + 1 << '\n';
    }

    return 0;
}

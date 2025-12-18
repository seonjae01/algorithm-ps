#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, bool> nolisten;
    set<string> unknown;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        nolisten[name] = true;
    }

    for (int i = 0; i < m; i++)
    {
        string name;
        cin >> name;

        if (nolisten[name])
            unknown.insert(name);
    }

    cout << unknown.size() << '\n';
    for (string name : unknown)
        cout << name << '\n';

    return 0;
}

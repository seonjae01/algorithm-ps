#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, string> sites;

    for (int i = 0; i < n; i++)
    {
        string url, password;
        cin >> url >> password;
        sites[url] = password;
    }

    for (int i = 0; i < m; i++)
    {
        string url;
        cin >> url;
        cout << sites[url] << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coms(n);

    for (int i = 0; i < n; i++)
        cin >> coms[i];
    sort(coms.begin(), coms.end());

    int timeStack = 0;
    int timeTotal = 0;

    for (int com : coms)
    {
        timeStack += com;
        timeTotal += timeStack;
    }

    cout << timeTotal << '\n';

    return 0;
}

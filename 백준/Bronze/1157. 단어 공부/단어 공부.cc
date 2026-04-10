#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    cin >> line;

    map<char, int> cmap;
    int mx = 0;
    int cnt = 0;
    char cmx;

    for (char l : line)
    {
        char upper = toupper(l);
        cmap[upper]++;
        mx = max(mx, cmap[upper]);
    }

    for (auto c : cmap)
    {
        if (c.second == mx)
        {
            cmx = c.first;
            cnt++;
        }
    }

    cout << (cnt == 1 ? cmx : '?') << '\n';
    return 0;
}

#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        bool seq = true;
        map<char, int> cmap;
        string line;
        cin >> line;
        cmap[line[0]]++;

        for (int i = 1; i < line.size(); i ++)
        {
            char c = line[i];
            if (cmap.count(c) != 0 && c != line[i - 1])
            {
                seq = false;
                break;
            }
            else
            {
                cmap[c]++;
            }
        }

        if (seq) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
